#include "Actor.h"
#include "StudentWorld.h"
#include <math.h> 
#include "GameWorld.h"
#include "GameController.h"
#include <ctime>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
//Ice::Ice(int Xpos, int Ypos);
//void doSomething();

//Ice(int startX, int startY) :  Actor(IID_ICE, startX, startY, right, nullptr, .25, 0) {}

//Actor::Actor(int imageID, int startX, int startY, Direction startDirection, float size, unsigned int depth) : GraphObject(imageID, startX, startY, startDirection, size, depth) {}
////
//Ice::Ice(int imageID, int startX, int startY, Direction startDirection, float size, unsigned int depth ) : Actor(imageID, startX, startY, startDirection, size, depth) {}

void Ice::doSomething() {}

int Dcount = 0;
int Lcount = 0;
int Rcount = 0;
int Ucount = 0;
int tickCounter = 30;
int count = 0;


void IceMan::doSomething()
{
    //enum Direction { none, up, down, left, right };
    GraphObject::Direction dn = GraphObject::Direction::down;
    GraphObject::Direction up = GraphObject::Direction::up;
    GraphObject::Direction lt = GraphObject::Direction::left;
    GraphObject::Direction rt = GraphObject::Direction::right;
    const int KEY_PRESS_Z = 8;
    int ch;

    if (getWorld()->getKey(ch) == true)
    {  // user hit a key this tick! 
        switch (ch)
        {
            //col,row
        case KEY_PRESS_DOWN:
            // need to some how check if its ice than its blocked and you can't go in that direction 
            //need to be able to destory ice so i can dig through it 
            GraphObject::setDirection(dn);
            Dcount += 1;
            Lcount = 0;
            Rcount = 0;
            Ucount = 0;
            // Dcount -= 1;
            if (getY() > 0 && Dcount >= 2)
            {
                if (getWorld()->isNearBoulder(getX(), getY(), dn))
                {
                    moveTo(getX(), getY());
                    getWorld()->isIceVisible(getX(), getY());
                }
                else {
                    moveTo(getX(), getY() - 1);
                    getWorld()->removeIce();
                }
            }
            break;

        case KEY_PRESS_UP: //works
            Ucount += 1;
            Lcount = 0;
            Rcount = 0;
            Dcount = 0;
            GraphObject::setDirection(up);
            if (getY() < 60 && Ucount >= 2) {
                if (getWorld()->isNearBoulder(getX(), getY(), up))
                {
                    moveTo(getX(), getY());
                }
                else {
                    moveTo(getX(), 1 + getY());
                    getWorld()->removeIce();
                }
            }
            break;


        case KEY_PRESS_LEFT:
            // Lcount -= 1;
            Lcount += 1;
            Ucount = 0;
            Rcount = 0;
            Dcount = 0;
            GraphObject::setDirection(lt);
            if (getX() > 0 && Lcount >= 2) {
                if (getWorld()->isNearBoulder(getX(), getY(), lt))
                {
                    moveTo(getX(), getY());
                }
                else {
                    moveTo(getX() - 1, getY());
                    getWorld()->removeIce();
                }
            }
            break;


        case KEY_PRESS_RIGHT: //works
            //Rcount += 1;
            Rcount += 1;
            Ucount = 0;
            Lcount = 0;
            Dcount = 0;
            GraphObject::setDirection(rt);
            if (getX() < 60 && Rcount >= 2) {
                if (getWorld()->isNearBoulder(getX(), getY(), rt))
                {
                    moveTo(getX(), getY());
                }
                else
                {
                    moveTo(getX() + 1, getY());
                    getWorld()->removeIce();
                }

            }
            break;

        case KEY_PRESS_TAB:

            if (getWorld()->iceManNuggets.size() > 0)
            {

                auto it = new gold(IID_GOLD, getX(), getY(), right, getWorld(), 1, 2);
                getWorld()->fakeNuggets.push_back(it);
                it->setVisible(true);
                it->setpickUpable(2);
                it->setTicks(100);
                getWorld()->iceManNuggets.pop_back();
                //Sleep(30);
                //delete it;

            }
            break;

        case 'Z':

            if (getWorld()->sonarAmt > 0)
            {
                getWorld()->isNearGoodie(getX(), getY());
                getWorld()->sonarAmt -= 1;
                getWorld()->playSound(SOUND_SONAR);
            }
            // spawn every so many ticks below here if(){} etc.

            break;

        case  'z':
            if (getWorld()->sonarAmt > 0) {
                getWorld()->isNearGoodie(getX(), getY());
                getWorld()->sonarAmt -= 1;
                getWorld()->playSound(SOUND_SONAR);
            }
            break;
        case  KEY_PRESS_SPACE:
            // have a count that keeps track the usage of iceman. At the start the iceman only has 5 squirts 
            count++;
            if (count < 6) // limits the amount of time squirt, packet says iceman at first can only squirt 5 times
            {
                int x = getWorld()->IceMn->getX();
                int y = getWorld()->IceMn->getY();
                //each direction the iceman should squirt 4 spaces stated in the packet pg 28
                auto dr = getWorld()->IceMn->getDirection();
                if (dr == right)
                {
                    getWorld()->squirtWater(x + 4, y, dr);


                }
                if (dr == left)
                {
                    getWorld()->squirtWater(x - 4, y, dr);
                }
                if (dr == down)
                {
                    getWorld()->squirtWater(x, y - 4, dr); // important we subtract after the variable so we dont get negative numbers
                }
                if (dr == up)
                {
                    getWorld()->squirtWater(x, 4 + y, dr);
                }
                /*StudentWorld* s = nullptr;
                 squirtWater.push_back(new Squirt(IID_WATER_SPURT, x, y, dr, s, 1.0, 1));*/
                 //function that follows iceman and points squirt to where iceman is facing 
            }

            break;

        case  'Q':
            quick_exit;
            break;
        case  'q':
            quick_exit;
            break;
        case KEY_PRESS_ESCAPE:
            if (getWorld()->getLives() == 1)
            {
                getWorld()->decLives();
                quick_exit;


            }
            else
            {
                getWorld()->decLives();

            }

            // Maybe I will need a function to reset all containers then continue the game and if they have no lives left to exit. 
            break;

        }
    }

}

//void boulder::doSomething() {}

void gold::doSomething() {
    ////6 by 6 box 
    // this reveals a goodie if iceman is 2 units away from its perimeter.
    //if (getpickUpable()==3)
    //{
    //    tickCount += 1;
    //}
    //if (tickCount==30)
    //{
    //    setVisible(false);
   // setAlive
    //} /// dont need direction here: 
    if (getpickUpable() == 2)
    {
        T -= 1;
        if (T == 0)
        {
            setDead();
            setVisible(false);//here
            setpickUpable(3);

        }
    }
    for (int i = 4; i > -5; i--)
    {
        //UP
        if (/*getWorld()->IceMn->getDirection() == GraphObject::Direction::up &&*/ getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) == 4 && this->getpickUpable() == 0)
            //(getX() + i == getWorld()->IceMn->getX() && getY() == getWorld()->IceMn->getY() + 4) && this->getpickUpable() == 0) // must be in state 0 to have it's state transfered here.
        {
            // std::cout << getX() << std::endl;
            this->setVisible(true);// set to true in real game false is for testing to see the gold.
            this->setpickUpable(1); // 4 states  0 1 2 3, 0: Iceman cant see it till hes near it then it becomes--> 1:Iceman can pick up 2: ICeman dropped it, and can only be picked up by protestors , 3: nobody can acess it.
            return;
        }
        //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                //If icemans position is 3 spaces away from a revealed goodie(which has a pickupable of 1), then add it to his stash of nuggets
        if (/*getWorld()->IceMn->getDirection() == GraphObject::Direction::up &&*/ getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) <= 3 && this->getpickUpable() == 1)
            //(getX() + i == getWorld()->IceMn->getX() && getY() == getWorld()->IceMn->getY() + 3) && getpickUpable() == 1) // pickupable has to = 1 to qualify for adding to the vector 
        {   // if its the first into the vector just add it
            if (getWorld()->iceManNuggets.size() == 0) {
                getWorld()->iceManNuggets.push_back(this);


                std::cout << "\niceManNugSize: " << getWorld()->iceManNuggets.size() << std::endl;
                getWorld()->increaseScore(25);
                this->setVisible(false);
                this->setpickUpable(3);
                getWorld()->playSound(SOUND_GOT_GOODIE);

            }// if it's not the first in the vector, check to see if it's a copy, (which it will be if iceman stands on the object), if it is a copy return, if it's unique add it to the vector.
            else if (std::find(getWorld()->iceManNuggets.begin(), getWorld()->iceManNuggets.end(), this) != getWorld()->iceManNuggets.end() && getpickUpable() != 1)
                return;

            else {

                getWorld()->iceManNuggets.push_back(this);
                getWorld()->increaseScore(25);
                getWorld()->playSound(SOUND_GOT_GOODIE);
                this->setVisible(false);
                this->setpickUpable(3);
                std::cout << "\niceManNugSize: " << getWorld()->iceManNuggets.size() << std::endl;
                return;
            }
        }
        //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //    //DOWN
    //    if (getWorld()->IceMn->getDirection() == GraphObject::Direction::down && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) == 4 && this->getpickUpable() == 0)
    //       // (getX() + i == getWorld()->IceMn->getX() && getY() + 4 == getWorld()->IceMn->getY()) && this->getpickUpable() == 0)
    //    {
    //        //std::cout << getX() << std::endl;
    //        this->setVisible(true);
    //        this->setpickUpable(1);
    //        return;
    //    }
    //    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //    if (getWorld()->IceMn->getDirection() == GraphObject::Direction::down && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) <= 3 && this->getpickUpable() == 1)
    //        //(getX() + i == getWorld()->IceMn->getX() && getY() + 3 == getWorld()->IceMn->getY()) && getpickUpable() == 1)
    //    {
    //        if (getWorld()->iceManNuggets.size() == 0) {
    //            getWorld()->iceManNuggets.push_back(this);
    //            std::cout << "\niceManNugSize: " << getWorld()->iceManNuggets.size() << std::endl;
    //            getWorld()->increaseScore(25);
    //            getWorld()->playSound(SOUND_GOT_GOODIE);
    //            this->setVisible(false);
    //            this->setpickUpable(3);
    //        }
    //        else if (std::find(getWorld()->iceManNuggets.begin(), getWorld()->iceManNuggets.end(), this) != getWorld()->iceManNuggets.end() && getpickUpable() != 1)
    //            return;
    //        else {
    //            getWorld()->iceManNuggets.push_back(this);
    //            getWorld()->increaseScore(25);
    //            getWorld()->playSound(SOUND_GOT_GOODIE);
    //            this->setVisible(false);
    //            this->setpickUpable(3);
    //            std::cout << "\niceManNugSize: " << getWorld()->iceManNuggets.size() << std::endl;
    //            return;

    //        }
    //    }
    //}
    //    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //    //LEFT
    //for (int i = 3; i > -3; i--)
    //{
    //    if (getWorld()->IceMn->getDirection() == GraphObject::Direction::left && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) == 4 && this->getpickUpable() == 0)
    //        //(getX() + 4 == getWorld()->IceMn->getX() && getY() + i == getWorld()->IceMn->getY()) && this->getpickUpable() == 0)
    //    {
    //        //  std::cout << getX() << std::endl;
    //        this->setVisible(true);
    //        this->setpickUpable(1);
    //        return;
    //    }
    //    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //    if (getWorld()->IceMn->getDirection() == GraphObject::Direction::left && getWorld()->distanceFormula(getX(),getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY())<=3 && getpickUpable() == 1)
    //        //(getX() + 3 == getWorld()->IceMn->getX() && getY() - i == getWorld()->IceMn->getY()) && getpickUpable() == 1)
    //    {
    //        if (getWorld()->iceManNuggets.size() == 0) {
    //            getWorld()->iceManNuggets.push_back(this);
    //            std::cout << "\niceManNugSize: " << getWorld()->iceManNuggets.size() << std::endl;
    //            getWorld()->increaseScore(25);
    //            getWorld()->playSound(SOUND_GOT_GOODIE);
    //            this->setVisible(false);
    //            this->setpickUpable(3);
    //        }
    //        else if (std::find(getWorld()->iceManNuggets.begin(), getWorld()->iceManNuggets.end(), this) != getWorld()->iceManNuggets.end() && getpickUpable() != 1)
    //            return;
    //        else {
    //            getWorld()->iceManNuggets.push_back(this);
    //            std::cout << "\niceManNugSize: " << getWorld()->iceManNuggets.size() << std::endl;
    //            this->setVisible(false);
    //            this->setpickUpable(3);
    //            getWorld()->increaseScore(25);
    //            getWorld()->playSound(SOUND_GOT_GOODIE);
    //            return;
    //        }
    //    }
    //    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //    //RIGHT
    //    if (getWorld()->IceMn->getDirection() == GraphObject::Direction::right && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) == 4 && this->getpickUpable() == 0)
    //       // (getX()-4 == getWorld()->IceMn->getX() && getY() +i  == getWorld()->IceMn->getY()) && this->getpickUpable() == 0)
    //    {
    //        // std::cout << getX() << std::endl;
    //        this->setVisible(true);
    //        this->setpickUpable(1);
    //        return;
    //    }
    //    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //    if (getWorld()->IceMn->getDirection() == GraphObject::Direction::right && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) <= 3 && this->getpickUpable() == 1)
    //       // (getX() - 3 == getWorld()->IceMn->getX() && getY() - i == getWorld()->IceMn->getY()) && getpickUpable() == 1)
    //    {
    //        if (getWorld()->iceManNuggets.size() == 0) {
    //            getWorld()->iceManNuggets.push_back(this);
    //            getWorld()->increaseScore(25);
    //            getWorld()->playSound(SOUND_GOT_GOODIE);
    //            std::cout << "\niceManNugSize: " << getWorld()->iceManNuggets.size() << std::endl;
    //            this->setVisible(false);
    //            this->setpickUpable(3);
    //        }
    //        else if (std::find(getWorld()->iceManNuggets.begin(), getWorld()->iceManNuggets.end(), this) != getWorld()->iceManNuggets.end() && getpickUpable() != 1)
    //            return;
    //        else {
    //            getWorld()->iceManNuggets.push_back(this);
    //            getWorld()->increaseScore(25);
    //            getWorld()->playSound(SOUND_GOT_GOODIE);
    //            this->setVisible(false);
    //            this->setpickUpable(3);
    //            std::cout << "\niceManNugSize: " << getWorld()->iceManNuggets.size() << std::endl;
    //            return;
    //        }
    //    }
    }

    return;
}

void barrel::doSomething() {
    for (int i = 4; i > -5; i--)
    {
        //UP
        if (getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) == 4 && this->getpickUpable() == 0)
            //(getX() + i == getWorld()->IceMn->getX() && getY() == getWorld()->IceMn->getY() + 4) && this->getpickUpable() == 0) // must be in state 0 to have it's state transfered here.
        {
            // std::cout << getX() << std::endl;
            this->setVisible(true);// set to true in real game false is for testing to see the gold.
            this->setpickUpable(1); // 4 states  0 1 2 3, 0: Iceman cant see it till hes near it then it becomes--> 1:Iceman can pick up 2: ICeman dropped it, and can only be picked up by protestors , 3: nobody can acess it.
            return;
        }
        //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                //If icemans position is 3 spaces away from a revealed goodie(which has a pickupable of 1), then add it to his stash of nuggets
        if (getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) <= 3 && this->getpickUpable() == 1)
            //  (getX() + i == getWorld()->IceMn->getX() && getY() == getWorld()->IceMn->getY() + 3) && getpickUpable() == 1) // pickupable has to = 1 to qualify for adding to the vector 
        {   // if its the first into the vector just add it
           // if it's not the first in the vector, check to see if it's a copy, (which it will be if iceman stands on the object), if it is a copy return, if it's unique add it to the vector.
            getWorld()->increaseScore(1000);
            this->setVisible(false);
            this->setpickUpable(3);
            getWorld()->barSizeHolder.pop_back();
            getWorld()->playSound(SOUND_FOUND_OIL);
            return;
        }
        //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //DOWN
        //if (getWorld()->IceMn->getDirection() == GraphObject::Direction::down && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) == 4 && this->getpickUpable() == 0)
        //    //(getX() + i == getWorld()->IceMn->getX() && getY() + 4 == getWorld()->IceMn->getY()) && this->getpickUpable() == 0)
        //{
        //    //std::cout << getX() << std::endl;
        //    this->setVisible(true);
        //    this->setpickUpable(1);
        //    return;
        //}
        ////------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //if (getWorld()->IceMn->getDirection() == GraphObject::Direction::down && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) <= 3 && this->getpickUpable() == 1)
        //   // (getX() + i == getWorld()->IceMn->getX() && getY() + 3 == getWorld()->IceMn->getY()) && getpickUpable() == 1)
        //{
        //    getWorld()->increaseScore(1000);
        //    this->setVisible(false);
        //    this->setpickUpable(3);
        //    getWorld()->barSizeHolder.pop_back();
        //    getWorld()->playSound(SOUND_FOUND_OIL);
        //    return;
        //}
        ////------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        ////LEFT
        //if (getWorld()->IceMn->getDirection() == GraphObject::Direction::left && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) == 4 && this->getpickUpable() == 0)
        //    //(getX() + 4 == getWorld()->IceMn->getX() && getY() + i == getWorld()->IceMn->getY()) && this->getpickUpable() == 0)
        //{
        //    //  std::cout << getX() << std::endl;
        //    this->setVisible(true);
        //    this->setpickUpable(1);
        //    return;
        //}
        ////------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //if (getWorld()->IceMn->getDirection() == GraphObject::Direction::left && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) <= 3 && this->getpickUpable() == 1)
        //    //(getX() + 3 == getWorld()->IceMn->getX() && getY() + i == getWorld()->IceMn->getY()) && getpickUpable() == 1)
        //{
        //    getWorld()->increaseScore(1000);
        //    this->setVisible(false);
        //    this->setpickUpable(3);
        //    getWorld()->barSizeHolder.pop_back();
        //    getWorld()->playSound(SOUND_FOUND_OIL);
        //    return;
        //}
        ////------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        ////RIGHT
        //if (getWorld()->IceMn->getDirection() == GraphObject::Direction::right && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) == 4 && this->getpickUpable() == 0)
        //   // (getX() - 4 == getWorld()->IceMn->getX() && getY() + i == getWorld()->IceMn->getY()) && this->getpickUpable() == 0)
        //{
        //    // std::cout << getX() << std::endl;
        //    this->setVisible(true);
        //    this->setpickUpable(1);
        //    return;
        //}
        ////------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //if (getWorld()->IceMn->getDirection() == GraphObject::Direction::right && getWorld()->distanceFormula(getX(), getY(), getWorld()->IceMn->getX(), getWorld()->IceMn->getY()) <= 3 && this->getpickUpable() == 1)
        //   // (getX() - 3 == getWorld()->IceMn->getX() && getY() + i == getWorld()->IceMn->getY()) && getpickUpable() == 1)
        //{
        //    getWorld()->increaseScore(1000);
        //    this->setVisible(false);
        //    this->setpickUpable(3);
        //    getWorld()->barSizeHolder.pop_back();
        //    getWorld()->playSound(SOUND_FOUND_OIL);
        //    return;
        //}

    }
    return;
}

void waterPool::doSomething() {

    //count down a tick 
    T -= 1;
    if (T == 0)
    {
        //set status to dead,
        setVisible(false);
        setpickUpable(3);
        setDead();

    }

    if (getWorld()->distanceFormula(getWorld()->IceMn->getX(), getWorld()->IceMn->getY(), getX(), getY()) <= 3)
    {
        //setState(dead) 0 or 1
        getWorld()->playSound(SOUND_GOT_GOODIE);
        getWorld()->squirtAmt += 5;
        getWorld()->increaseScore(100);
        setpickUpable(3);
        setVisible(false);
        setDead();
    }

}

void sonar::doSomething() {


    T -= 1;
    if (T == 0)
    {
        //set status to dead,
        setVisible(false);
        setpickUpable(3);
        setDead();
        //setPickupable 3()
    }
    if (getWorld()->distanceFormula(getWorld()->IceMn->getX(), getWorld()->IceMn->getY(), getX(), getY()) <= 3)
    {
        //setState(dead) 0 or 1
        getWorld()->playSound(SOUND_GOT_GOODIE);
        getWorld()->sonarAmt += 1;
        getWorld()->increaseScore(75);
        setpickUpable(3);
        setVisible(false);
        setDead();
    }

}

void boulder::doSomething()
{
    if (!isAlive())
    {
        return;
    }
    if (waitTicker > 0) {
        waitTicker--;

        return;
    }
    switch (myCurrentState)
    {
    case Stable:
        /* for (auto& i : getWorld()->bolda)
         {*/

         //int j = 1;


     // ||getWorld()->isIceVisible(this->getX() + 2, this->getY() - 1) == 0 && getWorld()->isIceVisible(this->getX() + 2, this->getY() - 1) == 0

        if (getWorld()->isIceVisible(this->getX(), this->getY() - 1) == 1 && getWorld()->isIceVisible(this->getX() + 1, this->getY() - 1) == 1 && getWorld()->isIceVisible(this->getX() + 2, this->getY() - 1 == 1) && getWorld()->isIceVisible(this->getX() + 3, this->getY() - 1 == 1)) // if theres ice under rock
        {
            waitTicker = 30; // ice found back to waiting
            return;


        }
        // }

        myCurrentState = UnStable; //No ice found, make it unstable and begin countdown.
        waitTicker = 30;
        return;


    case UnStable:
        myCurrentState = Falling;
        GameController::getInstance().playSound(SOUND_FALLING_ROCK);

        return;
    case Falling:
        /*for (auto& i : getWorld()->bolda)
        {*/

        int x = getWorld()->IceMn->getX();
        int y = getWorld()->IceMn->getY();

        int xx2 = this->getX();
        int yy2 = this->getY();
        if (getWorld()->isIceVisible(this->getX(), this->getY() - 1) == 0)
        {


            this->moveTo(this->getX(), this->getY() - 1); // moves boulder 
            if (getY() <= -1) { //Bottom of oil field
                //isDead = true;
                setDead();
                // isAlive() = false;
                return;
            }
            // need to add to code to delete the protestor too            

            if (getWorld()->distanceFormula(x, y, xx2, yy2) <= 3) // if iceman is near bouldder
            {
                getWorld()->IceMn->setDead(); // set it to ded

            }

            //pretty ass ngl
            if (getWorld()->isIceVisible(this->getX(), this->getY() - 1) == 1) // if theres ice underneath the rock 
            {

                //isDead = true; // it should be dead
                setDead();

            }


            // if i put isDead here it'll instantly delete before moving all the way down

              /* removeRock = this;
               if (removeRock != nullptr)
               {


               delete removeRock;
               removeRock = nullptr;
               }*/



        }

        return;

        //myCurrentState = Dead;

        //   case Dead:
        ///* if (getWorld()->isIceVisible(this->getX(), this->getY() - 1) == 1) 
        // {*/

        //     isDead = true;
        //   
        // //}
        return;
        //if (getWorld()->isIceVisible(this->getX(), this->getY() - 1) == false && getWorld()->IceMn->getX() == this->getX()
        //    && getWorld()->IceMn->getY() == this->getY() - 1 ||
        //    getWorld()->isIceVisible(this->getX() + 2, this->getY() - 1) == getWorld()->IceMn->getX()
        //    && getWorld()->isIceVisible(this->getX() + 2, this->getY() - 1) == getWorld()->IceMn->getY())
        //{
        //    this->setVisible(false); // we got set it dead here

        //}
       // there was a return here
//
//myCurrentState = Dead;
//return;
//        
//    case Dead:
//        if (getWorld()->isIceVisible(this->getX(), this->getY() - 1) == 1)
//        {
// isDead = true;
//
//        }
//       
//// }
//   }
// return;
    }
}

void RegularProtesters::doSomething() {}

void HardCoreProtester::doSomething() {}


void Squirt::doSomething() {

    if (true)
    {
        moveTo(getX() + 16, getY());

    }

    // if it hits terrain or if it hits a protestor do somethin else

}



