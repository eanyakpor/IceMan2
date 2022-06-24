#include "StudentWorld.h"
#include "GraphObject.h"
#include "Actor.h"
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <math.h> 
#include <time.h>
#include <map>
#include < algorithm >
#include <iomanip>
using namespace std;

vector<pair<pair<int, int>, int >> iceVis;// a vector of the x, y coordinates of the ice  and a corresponding 0 or 1 to say whether or not it's visible : iceVis = ice visibility
//void makeIceField();

GameWorld* createStudentWorld(string assetDir)
{
    return new StudentWorld(assetDir);
}

void StudentWorld::removeIce()
{

    int x = IceMn->getX();
    // int altX = x+4;
    int y = IceMn->getY();
    int dir = IceMn->getDirection();
    GraphObject::Direction dn = GraphObject::Direction::down;
    GraphObject::Direction up = GraphObject::Direction::up;
    GraphObject::Direction lt = GraphObject::Direction::left;
    GraphObject::Direction rt = GraphObject::Direction::right;



    if (Ice1[y][x] != NULL && dir == lt)
    {
        //delete Ice1[y][x];// this is not dynamically allocating 
        //Ice1[y][x] = NULL;
        Ice1[y][x]->setVisible(false);// this is not dynamically allocating 

        if (y < 60) {
            //delete Ice1[y + 1][x];// this is not dynamically allocating 
            //Ice1[y + 1][x] = NULL;
            //delete Ice1[y + 2][x];// this is not dynamically allocating 
            //Ice1[y + 2][x] = NULL;
            //delete Ice1[y + 3][x];// this is not dynamically allocating 
            //Ice1[y + 3][x] = NULL;
            Ice1[y + 1][x]->setVisible(false);// this is not dynamically allocating                        
            Ice1[y + 2][x]->setVisible(false);// this is not dynamically allocating                            
            Ice1[y + 3][x]->setVisible(false);// this is not dynamically allocating 

            for (auto& i : iceVis)
            {
                if ((i.first.first == x && i.first.second == y) || (i.first.first == x && i.first.second == y + 1) || (i.first.first == x && i.first.second == y + 2) || (i.first.first == x && i.first.second == y + 3))
                {
                    if (i.second == 1) { playSound(SOUND_DIG); }
                    i.second = 0;
                }
            }
        }


        cout << "xy:" << x << " " << y << "  " << isIceVisible(x, y) << " ";
        return;
    }

    if (Ice1[y][x] != NULL /*|| Ice1[y][x]*/ && dir == rt)
    {

        //delete Ice1[y][x + 3];// this is not dynamically allocating 
        //Ice1[y][x + 3] = NULL;
        Ice1[y][x + 3]->setVisible(false);// this is not dynamically allocating 

        if (y < 60) {
            //delete Ice1[y + 1][x + 3];// this is not dynamically allocating 
            //Ice1[y + 1][x + 1] = NULL;
            //delete Ice1[y + 2][x + 3];// this is not dynamically allocating 
            //Ice1[y + 2][x + 1] = NULL;
            //delete Ice1[y + 3][x + 3];// this is not dynamically allocating 
            //Ice1[y + 3][x + 1] = NULL;
            Ice1[y + 1][x + 3]->setVisible(false);// this is not dynamically allocating 
            Ice1[y + 2][x + 3]->setVisible(false);// this is not dynamically allocating                           
            Ice1[y + 3][x + 3]->setVisible(false);// this is not dynamically allocating 

            for (auto& i : iceVis)
            {
                if ((i.first.first == x + 3 && i.first.second == y) || (i.first.first == x + 3 && i.first.second == y + 1) || (i.first.first == x + 3 && i.first.second == y + 2) || (i.first.first == x + 3 && i.first.second == y + 3))
                {
                    if (i.second == 1) { playSound(SOUND_DIG); }
                    i.second = 0;


                }
            }
        }

        cout << "xy:" << x << " " << y << " " << isIceVisible(x, y) << " ";
        return;
    }

    if (Ice1[y][x] != NULL && dir == dn)
    {
        //delete Ice1[y][x];// this is not dynamically allocating 
        //Ice1[y][x] = NULL;
        //delete Ice1[y ][x+1];// this is not dynamically allocating 
        //Ice1[y][x+1] = NULL;
        //delete Ice1[y][x+2];// this is not dynamically allocating 
        //Ice1[y][x+2] = NULL;
        //delete Ice1[y][x + 3];// this is not dynamically allocating 
        //Ice1[y][x + 3] = NULL;
        Ice1[y][x]->setVisible(false);// this is not dynamically allocating 

        Ice1[y][x + 1]->setVisible(false);// this is not dynamically allocating 

        Ice1[y][x + 2]->setVisible(false);// this is not dynamically allocating 

        Ice1[y][x + 3]->setVisible(false);// this is not dynamically allocating 

        for (auto& i : iceVis)
        {
            if ((i.first.first == x && i.first.second == y) || (i.first.first == x + 1 && i.first.second == y) || (i.first.first == x + 2 && i.first.second == y) || (i.first.first == x + 3 && i.first.second == y))
            {
                if (i.second == 1) { playSound(SOUND_DIG); }
                i.second = 0;
            }
        }
        cout << "xy:" << x << " " << y << " " << isIceVisible(x, y) << " ";
        return;
    }
    if (Ice1[y][x] != NULL || Ice1[y][x] == NULL && dir == up)
    {
        //delete Ice1[y+3][x ];// this is not dynamically allocating 
        //Ice1[y+3][x ] = NULL;
        //delete Ice1[y + 3][x+1];// this is not dynamically allocating 
        //Ice1[y + 3][x+1] = NULL;
        //delete Ice1[y + 3][x+2];// this is not dynamically allocating 
        //Ice1[y + 3][x+2] = NULL;
        //delete Ice1[y + 3][x + 3];// this is not dynamically allocating 
        //Ice1[y + 3][x + 3] = NULL;

        Ice1[y + 3][x]->setVisible(false);// this is not dynamically allocating 


        Ice1[y + 3][x + 1]->setVisible(false);// this is not dynamically allocating 

        Ice1[y + 3][x + 2]->setVisible(false);// this is not dynamically allocating 

        Ice1[y + 3][x + 3]->setVisible(false);// this is not dynamically allocating     

        //I can create a function for this loop with a switch or with all the ifs so it's not ugly 
        for (auto& i : iceVis)
        {
            if ((i.first.first == x && i.first.second == y + 3) || (i.first.first == x + 1 && i.first.second == y + 3) || (i.first.first == x + 2 && i.first.second == y + 3) || (i.first.first == x + 3 && i.first.second == y + 3))
            {
                if (i.second == 1) { playSound(SOUND_DIG); }
                i.second = 0;
            }
        }

        cout << "xy:" << x << " " << y << " " << isIceVisible(x, y) << " ";
        return;
    }

}




// uses sstream to group all ints and strings into single string for display
void StudentWorld::updateGameStatText() {
    stringstream shtring;
    // "Lvl: 52 Lives: 3 Hlth: 80% Wtr: 20 Gld: 3 Oil Left: 2 Sonar: 1 Scr: 321000 " from the packet +

    int lvl = getLevel(), Lives = getLives(),
        HP = hp, oil = barSizeHolder.size(), water = squirtAmt, sonar = sonarAmt,
        score = getScore();

    shtring << "Lvl: " << setw(2) << lvl
        << " Lives: " << setw(1) << Lives
        << " Hlth: " << setw(3) << HP
        << " Wtr: " << setw(2) << water
        << " Gld: " << setw(2) << iceManNuggets.size()
        << " Oil Left: " << setw(2) << oil
        << " Sonar: " << setw(2) << sonar
        << " Score: " << setw(6) << score;

    setGameStatText(shtring.str());
}


int StudentWorld::init()
{
    // StudentWorld* s = 0;
    ticksToWaitToAddProtester = ticksSinceLastProtester = max<unsigned int>(25, 200 - getLevel());
    nProtesters = 0;//

    GraphObject::Direction dr = GraphObject::Direction::right;// forthe iceman
    IceMn = unique_ptr<IceMan>(new IceMan(IID_PLAYER, 30, 60, dr, this));
    sonarAmt = 1;

    //IceMn->setVisible(true);
    // which way should i implement it? Should i create the ice first, then create the boulders and delete the ice underneath it, or should i create the boulders then place the ice around the boulders
    // I had trouble not getting ice in the center toyed with the x and y values, made the mistake of changing the y instead of x values when it came to putting objects in the field
   // string s = "uhhhh";

    //CAN CREATE A VECTOR PAIR W FIRST BEING A 2D ARRAY, AND SECOND BEING A BOOL T/F , OR  INT: 0, 1

    int current_level_number = getLevel();
    int b = min(int(current_level_number / 2) + 2, 9),
        n = max(5 - current_level_number / 2, 2),
        ba = min(2 + current_level_number, 21), i = 0;// j = 0, k = 0; b = boulder amount n = nuggets etc
    int G = (current_level_number * 25 + 300); // this is the % chance that sonar or waterPools should spawn.  
    int totalObj = b + n + ba;
    int y1;
    int x3;
    updateGameStatText();

    vector<pair<int, int>> xyHolder;

    int coordTracker = 0; // keeps track of how many objects were put into xyholder in order to go thru all of the elements necessary
    dr = GraphObject::Direction::down;// for the boulders
    // GET TOTAL NUMBER OF OBJECTS TO CREATE, THEN SET THE WHILE LOOP TO THE SIZE OF EVERYTHING, THIS WAY YOU CAN HAVE 1 LOOP FOR ALL OBJECT CREATION
    // for the boulders
    while (i != totalObj)
    {
        std::srand((unsigned)time(0));
        do
        {
            int x1 = (rand() % (56 - 4 + 1)) + 4;
            x3 = x1;
        } while (x3 >= 26 && x3 <= 34);//(x3 <= 4 || (x3 >= 26 && x3 <= 34) || x3 >= 56);

        int y1 = (rand() % (56 - 20 + 1)) + 20;

        if (xyHolder.empty())
        {
            xyHolder.push_back(make_pair(x3, y1));
            bolda.push_back(new boulder(IID_BOULDER, x3, y1, dr, this, 1, 1));
            bolda.at(0)->setVisible(true);

            i += 1;
            /// to not let teh boulders spawn in the middle line maybe a while this is not   
        }
        else
        {
            for (int z = 0; z < xyHolder.size(); z++)
            {
                if (distanceFormula(x3, y1, xyHolder.at(z).first, xyHolder.at(z).second) >= 6)
                {
                    coordTracker += 1;
                    if (coordTracker == xyHolder.size())
                    {
                        xyHolder.push_back(make_pair(x3, y1));
                        bolda.push_back(new boulder(IID_BOULDER, x3, y1, dr, this, 1, 1));
                        bolda.at(coordTracker)->setVisible(true);
                        i += 1;
                    }
                }
                //if (distanceFormula(x3,y1,z.first, z.second) >= 6 )//&& distanceFormula(x3, y1, z.first, z.second) != 0 not needed 
                //{
                //    xyHolder.push_back(make_pair(x3, y1));
                //    b1 = unique_ptr<boulder>(new boulder(IID_BOULDER, x3, y1, dr, 1, 1));
                //    b1->setVisible(true);
                //    bolda.push_back(b1);
                //    //create the object at this position, do i have to name the object to set it visible?
                //    i += 1;
                //}
            }
        }

    }
    //vector<pair<pair<int, int>, int >> iceVis;
    dr = GraphObject::Direction::right;
    //making the ice
    for (int i = 0; i < 64; i++)// Y
    {
        for (int j = 0; j < 64; j++) //X
        {

            if ((bolda.at(0)->getY() == i && bolda.at(0)->getX() == j) || bolda.at(0)->getY() + 1 == i && bolda.at(0)->getX() == j ||
                bolda.at(0)->getY() + 2 == i && bolda.at(0)->getX() == j || (bolda.at(0)->getY() + 3 == i && bolda.at(0)->getX() == j) ||
                (bolda.at(1)->getY() == i && bolda.at(1)->getX() == j) || (bolda.at(1)->getY() + 1 == i && bolda.at(1)->getX() == j) ||
                (bolda.at(1)->getY() + 2 == i && bolda.at(1)->getX() == j) || (bolda.at(1)->getY() + 3 == i && bolda.at(1)->getX() == j)) // takes the boulder position and its surroundings
            {
                if ((bolda.at(0)->getY() >= 56 && j >= 56) || (bolda.at(1)->getY() >= 56 && j >= 56)) {
                    Ice1[i][j] = new Ice(IID_ICE, j, i, dr, this, .25, 3);
                    Ice1[i][j]->setVisible(false);
                    iceVis.push_back(make_pair(make_pair(j, i), 0));
                }
                else {
                    Ice1[i][j] = new Ice(IID_ICE, j, i, dr, this, .25, 3);
                    Ice1[i][j]->setVisible(false);
                    iceVis.push_back(make_pair(make_pair(j, i), 0));
                    j += 1;
                    Ice1[i][j] = new Ice(IID_ICE, j, i, dr, this, .25, 3);
                    Ice1[i][j]->setVisible(false);
                    iceVis.push_back(make_pair(make_pair(j, i), 0));
                    j += 1;
                    Ice1[i][j] = new Ice(IID_ICE, j, i, dr, this, .25, 3);
                    Ice1[i][j]->setVisible(false);
                    iceVis.push_back(make_pair(make_pair(j, i), 0));
                    j += 1;
                    Ice1[i][j] = new Ice(IID_ICE, j, i, dr, this, .25, 3);
                    Ice1[i][j]->setVisible(false);
                    iceVis.push_back(make_pair(make_pair(j, i), 0));
                    j += 1;
                    Ice1[i][j] = new Ice(IID_ICE, j, i, dr, this, .25, 3);
                    Ice1[i][j]->setVisible(false);
                    iceVis.push_back(make_pair(make_pair(j, i), 0));
                }
            }
            if (i > 59 || j >= 64)
            {
                Ice1[i][j] = new Ice(IID_ICE, j, i, dr, this, .25, 3);
                Ice1[i][j]->setVisible(false);
                iceVis.push_back(make_pair(make_pair(j, i), 0));
            }
            else if (j > 29 && j < 34 && i > 3)
            {
                Ice1[i][j] = new Ice(IID_ICE, j, i, dr, this, .25, 3);
                Ice1[i][j]->setVisible(false);
                iceVis.push_back(make_pair(make_pair(j, i), 0));
            }
            else {
                Ice1[i][j] = new Ice(IID_ICE, j, i, dr, this, .25, 3);
                iceVis.push_back(make_pair(make_pair(j, i), 1));
            }
        }
    }

    //Print coordinates
    //for (auto& i : iceVis)
    //{
    //    cout << "yx: " << i.first.first << " "<< i.first.second << "  " << i.second << endl;
    //}
    //   ---------------------------------------------------------------------------------------------

    i = 0;
    coordTracker = 0;
    int nuggetCount = 0;

    while (i != n) {
        while (i != n)
        {
            coordTracker = 0;
            std::srand((unsigned)time(0));
            do
            {
                int x1 = (rand() % (56 - 4 + 1)) + 4;
                x3 = x1;
            } while (x3 >= 26 && x3 <= 34);

            int y1 = rand() % 56;

            for (int z = 0; z < xyHolder.size(); z++)
            {
                if (distanceFormula(x3, y1, xyHolder.at(z).first, xyHolder.at(z).second) >= 6 && distanceFormula(x3, y1, xyHolder.at(z).first, xyHolder.at(z).second) != 0)
                {
                    coordTracker += 1;
                    if (coordTracker == xyHolder.size())
                    {
                        xyHolder.push_back(make_pair(x3, y1));
                        nuggets.push_back(new gold(IID_GOLD, x3, y1, dr, this, 1, 2));
                        nuggets.at(nuggetCount)->setVisible(false);// here
                        Goodies.push_back(nuggets.at(nuggetCount));
                        nuggetCount += 1;
                        i += 1;
                        break;
                    }
                }

            }


        }

    }

    i = 0;
    coordTracker = 0;
    int barrelCount = 0;
    while (i != ba) {
        while (i != ba)
        {
            coordTracker = 0;
            std::srand((unsigned)time(0));
            do
            {
                int x1 = (rand() % (56 - 4 + 1)) + 4;
                x3 = x1;
            } while (x3 >= 26 && x3 <= 34);
            int y1 = rand() % 56;

            for (int z = 0; z < xyHolder.size(); z++)
            {
                if (distanceFormula(x3, y1, xyHolder.at(z).first, xyHolder.at(z).second) >= 6 && distanceFormula(x3, y1, xyHolder.at(z).first, xyHolder.at(z).second) != 0)
                {
                    coordTracker += 1;
                    if (coordTracker == xyHolder.size())
                    {
                        xyHolder.push_back(make_pair(x3, y1));
                        barrels.push_back(new barrel(IID_BARREL, x3, y1, dr, this, 1, 00));
                        barrels.at(barrelCount)->setVisible(false); // here
                        barSizeHolder.resize(barrels.size());
                        Goodies.push_back(barrels.at(barrelCount));
                        barrelCount += 1;
                        i += 1;
                        break;
                    }
                }

            }


        }

    }



    return GWSTATUS_CONTINUE_GAME;
}
int StudentWorld::move()
{
    IceMn->doSomething();

    for (auto& i : nuggets) {
        i->doSomething();
    }
    //auto& i = iceManNuggets(iceManNuggets.size() - 1);
    //i
    for (auto& i : barrels) {
        i->doSomething();
    }
    createActor();
    for (auto& i : waterPools) {
        i->doSomething();
    }

    for (auto& i : Sonars) {
        i->doSomething();
    }
    //for (auto& i : bolda) {
    //    i->doSomething();
    //}
    for (auto& i : fakeNuggets) {
        i->doSomething();
    }
    for (auto& i : bolda)
    {
        i->doSomething();
    }

    int occurenceOfHardcore = min<unsigned int>(90, getLevel() * 10 + 30);
    int G = getLevel() * 25 + 300;

    //add protestors
    if (canAddProtester())
    {
        int n = rand() % 100 + 1;
        if (n <= occurenceOfHardcore)
            hardCoreP.push_back(new HardCoreProtester(this)); //create hardcore
        else
            regP.push_back(new RegularProtesters(this));
    }
    if (IceMn->isAlive() == false)
    {
        return GWSTATUS_PLAYER_DIED;
    }

    removeDeadGameObjects();
    updateGameStatText();

    if (barSizeHolder.size() == 0)
    {

        return GWSTATUS_FINISHED_LEVEL;
    }

    return GWSTATUS_CONTINUE_GAME;

}
// maybe we can templat this for each class
void StudentWorld::cleanUp()
{

    resetLevel();
}

bool StudentWorld::isNearBoulder(int x, int y, GraphObject::Direction z) {

    int X = x, Y = y; // icemans position from parameters ^
    int dir = z;

    if (dir == GraphObject::Direction::right)
    { // we add +1 to his position at the tip of the boulder +1 at the point before the middle and 
        for (auto& i : bolda)
        {   // if iceman is moving to the right and runs into a boulder, he cannot walk thru it he is stopped at the coordinates below 
            if ((i->getX() == X + 1 && i->getY() == Y - 3) || (i->getX() == X + 2 && i->getY() == Y - 2) || (i->getX() == X + 3 && i->getY() == Y - 1) ||
                (i->getX() == X + 3 && i->getY() == Y) || (i->getX() == X + 3 && i->getY() == Y + 1) || (i->getX() == X + 3 && i->getY() == Y + 2))
            {
                return true;
            }
        }
    }
    // When iceman moves to the left we have to use the boulders x position + 3, since its hit box starts in the bottom left corner 3 spaces away, and icemans is moving to the left and has his hitbox of 4 spaces around him.
    if (dir == GraphObject::Direction::left)
    {
        for (auto& i : bolda)
        {
            if ((i->getX() + 1 == X && i->getY() == Y - 3) || (i->getX() + 2 == X && i->getY() == Y - 2) || (i->getX() + 3 == X && i->getY() == Y - 1) ||
                (i->getX() + 3 == X && i->getY() == Y) || (i->getX() + 3 == X && i->getY() == Y + 1) || (i->getX() + 2 == X && i->getY() == Y + 2))
            {
                return true;
            }
        }

    }
    if (dir == GraphObject::Direction::up)
    {
        for (auto& i : bolda)
        {
            if ((i->getX() == X - 3 && i->getY() == Y + 1) || (i->getX() == X - 2 && i->getY() == Y + 2) || (i->getX() == X - 1 && i->getY() == Y + 3) || (i->getX() == X && i->getY() == Y + 3) || (i->getX() == X && i->getY() == Y + 3) ||
                (i->getX() == X + 1 && i->getY() == Y + 3) || (i->getX() == X + 2 && i->getY() == Y + 2) || (i->getX() == X + 3 && i->getY() == Y + 1))
            {
                return true;
            }
        }
    }
    if (dir == GraphObject::Direction::down)
    {
        for (auto& i : bolda)
        {
            if ((i->getX() == X - 3 && i->getY() == Y - 1) || (i->getX() == X - 2 && i->getY() == Y - 2) || (i->getX() == X - 1 && i->getY() == Y - 3) || (i->getX() == X && i->getY() == Y - 4)
                || (i->getX() == X + 1 && i->getY() == Y - 3) || (i->getX() == X + 2 && i->getY() == Y - 2) || (i->getX() == X + 3 && i->getY() == Y - 1))
            {
                return true;
            }
        }
    }

    return false;

}

void StudentWorld::isNearGoodie(int x, int y) {

    int X = x, Y = y;

    for (auto& i : Goodies) {
        if (i->getpickUpable() == 0) // 0 1 2 3 --> 0 , 1 -->  2-->   3--> 
        {
            if ((distanceFormula(IceMn->getX(), IceMn->getY(), i->getX(), i->getY()) <= 12))
            {
                i->setVisible(false);// here
                i->setpickUpable(1);
            }
        }

    }

}

void StudentWorld::createActor() {
    //random number
    int iceXrand, iceYrand;
    int tickGoal = int(getLevel()) * 25 + 300;
    int T = std::max(100, 300 - 10 * int(getLevel()));
    tickCountForCreation += 1;
    if (tickCountForCreation == tickGoal) {

        int rando = rand() % 5;

        if (waterPools.size() == 0 && (rando == 0 || rando == 1 || rando == 2 || rando == 3))
        {
            /* do {
                 iceXrand = rand() % 58; iceYrand = rand() % 61;
             } while (is4x4IceVisible(iceXrand, iceYrand)==true);*/

            auto c = new waterPool(IID_WATER_POOL, 0, 60, GraphObject::Direction::right, this, 1, 2);
            c->setVisible(true);//here
            c->setTicks(T);
            waterPools.push_back(c);
            tickCountForCreation = 0;
            // dont forget to create is alive set it dead when ticks elapse then have cleanup clear it from containers: actor and waterPools
        }
        if (Sonars.size() == 0 && rando == 4)
        {
            auto c = new sonar(IID_SONAR, 0, 60, GraphObject::Direction::right, this, 1, 2);
            c->setVisible(true);//here
            c->setTicks(T);
            Sonars.push_back(c);
            tickCountForCreation = 0;
        }

    }

}
//template<typename T>
//bool isNearGoodie(int x, int y, GraphObject::Direction z, vector<T> v) {}

//vector<pair<pair<int, int>, int >> iceVis;
bool StudentWorld::isIceVisible(int x, int y) {

    int bolX = x, bolY = y;

    for (auto& i : iceVis)
    {
        if (i.first.first == bolX && i.first.second == bolY && i.second == 0)// if the x and y of the pair match the given x and y from parameter then check the true or false 
        {
            //cout << "false";
            return false;
        }
    }
    // cout << "TRUE";
    return true;
}

void StudentWorld::squirtWater(int x, int y, GraphObject::Direction dr)
{

    squirt.push_back(new Squirt(IID_WATER_SPURT, x, y, dr, this));
    //  setTicks()
    playSound(SOUND_PLAYER_SQUIRT);
}


//bool StudentWorld::is4x4IceVisible(int x, int y) {
// /*   int X = x,  Y = y;
//    srand((unsigned)time(0));
//    int count = 0;
//    for (int i = 0; i < 4; i++) {
//        for (int j = 0; j < 4; j++) {
//            if (Ice1[X+j][Y+i]->isVisible()==true)
//            {
//                return true;
//            }
//            else
//            {
//                if (Ice1[X+j][Y+i]==false)
//                {
//                    count += 1;
//                }
//            }
//        }
//    }
//    if (count == 16)
//    {
//        return false;
//    }
//    return true;*/
//    int counter = 0;
//    for (int i = x; i < x + 4; i++) {
//
//        for (int j = y; j < y + 4; j++) {
//
//            if (Ice1[i][j]->isVisible() == true)
//                return true;
//
//        }
//    }
//    return false;
//    
//}
//StudentWorld* StudentWorld::getWorld() { return this; };

//-------------------------------------------------------------------------------------------------------------------------

// I had to create nugget counter/ barrel counter to display the current nugget that I was at because if I used coordTracker it would be incremented one more 
    //than the object that I was in in it's container and I would get a loop where the same object was being printed on the same spot
    //I had to tinker around with rand to get it to give me the proper range ended up finding the formula (rand() % (max - min + 1)) + min;, anlso needed std::srand((unsigned)time(0));
//for (int  j = 0; j < i; j++)
//{
//
//}

//int distanceFormula(int xx1, int yy1, int xx2, int yy2) {
//    int x3 = xx1, y1 = yy1, x2 = xx2, y2 = yy2, result;
//    result = sqrt((x2 - x3) ^ 2 + (y2 - y1) ^ 2);
//    return result;
//}
//void iceField() {
//    GraphObject::Direction dr = GraphObject::Direction::right;
//
//    for (int i = 0; i < 60; i++) // rows
//    {
//        for (int j = 0; j < 60; j++) //colums
//        {
//            if (j > 25 && j < 30)
//            {
//                j += 8;
//            }
//            Ice1[i][j] = new Ice(IID_ICE, j, i, dr);
//            Ice1[i][j]->setVisible(true);
//
//        }
//    }
//}
//void StudentWorld::makeIceField() {}

bool StudentWorld::canAddProtester()
{
    if (ticksSinceLastProtester >= ticksToWaitToAddProtester && nProtesters < min<unsigned int>(15, 2 + getLevel() * 1.5))
    {
        ticksSinceLastProtester = 0;
        nProtesters++;
        return true;
    }
}

void StudentWorld::resetLevel() {
    delete Ice1;
    IceMn.reset();
    bolda.clear();
    nuggets.clear();
    iceManNuggets.clear();
    fakeNuggets.clear();
    barrels.clear();
    barSizeHolder.clear();
    Goodies.clear();
    allActors.clear(); // except boulders 
    waterPools.clear();
    Sonars.clear();
    hardCoreP.clear();
    regP.clear();
    squirt.clear();

}

void StudentWorld::removeDeadGameObjects() {  // this uses a range based for loop to delete  // also the c++ poster said this is not thread safe 
    std::vector<Goodie*>::iterator current = Sonars.begin();//allActors.begin();
    for (Goodie* index : Sonars)
    {
        if (!index->isAlive())
        {
            delete index;
        }
        else
        {
            *current++ = index;
        }
    }
    Sonars.erase(current, Sonars.end());

    std::vector<Goodie*>::iterator current2 = waterPools.begin();//allActors.begin();
    for (Goodie* index : waterPools)
    {
        if (!index->isAlive())
        {
            delete index;
        }
        else
        {
            *current2++ = index;
        }
    }
    waterPools.erase(current2, waterPools.end());

    std::vector<gold*>::iterator current3 = iceManNuggets.begin();//allActors.begin();
    for (gold* index : iceManNuggets)
    {
        if (!index->isAlive())
        {
            delete index;
        }
        else
        {
            *current3++ = index;
        }
    }
    iceManNuggets.erase(current3, iceManNuggets.end());

    std::vector<boulder*>::iterator current4 = bolda.begin();//allActors.begin();
    for (boulder* index : bolda)
    {
        if (!index->isAlive())
        {
            delete index;
        }
        else
        {
            *current4++ = index;
        }
    }
    bolda.erase(current4, bolda.end());
}

