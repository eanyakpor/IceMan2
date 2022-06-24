
#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include <memory>
#include <math.h> 
#include <vector> 



// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
	//Ice* myIce;
	Ice* Ice1[64][64];
	std::unique_ptr<IceMan> IceMn;
	std::vector<boulder*>bolda;
	std::vector<gold*>nuggets;
	std::vector<gold*>iceManNuggets;
	std::vector<gold*>fakeNuggets;
	std::vector<barrel*>barrels;
	std::vector<barrel*>barSizeHolder;
	std::vector<Goodie*>Goodies;
	std::vector<Actor*>allActors; // except boulders 
	std::vector<Goodie*> waterPools;
	std::vector<Goodie*> Sonars;
	std::vector<HardCoreProtester*>hardCoreP;
	std::vector<Protester*>regP;
	std::vector<Squirt*>squirt;

	void removeDeadGameObjects();
	bool canAddProtester();
	int ticksSinceLastProtester;
	int ticksToWaitToAddProtester;
	int nProtesters;




	int sonarAmt = 1;
	int squirtAmt = 5;
	int tickCountForCreation = 0;
	int hp = 100;
	// created this global so that i could have a starting point for the ticks for creation because if included this in create goodei it would always =0 and not move

	StudentWorld(std::string assetDir)
		: GameWorld(assetDir)
	{
	}

	//StudentWorld* getWorldPointer() {
	//	StudentWorld* swP = this;
	//	return swP;
	//};

	virtual int init();
	virtual int move();
	// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
	// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
	//decLives();;

	virtual void cleanUp();

	int distanceFormula(int xx1, int yy1, int xx2, int yy2) {
		int x1 = xx1, y1 = yy1, x2 = xx2, y2 = yy2, result;

		result = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		return result;
	}
	void resetLevel(); // IMPORTANT
	void updateGameStatText();
	void removeIce();
	bool isIceVisible(int x, int y);
	//bool is4x4IceVisible(int x, int y);

	bool isNearBoulder(int x, int y, GraphObject::Direction z);
	void isNearGoodie(int x, int y);
	void createActor();
	void squirtWater(int x, int y, GraphObject::Direction dr);


	//template<typename T>
	//bool isNearGoodie(int x, int y, GraphObject::Direction z, vector<T> v);
	/*void setDisplayText()
{   int level = getCurrentGameLevel();
int lives = getNumLivesLeft();
int health = getCurrentHealth();
int squirts = getSquirtsLeftInSquirtGun();
int gold = getPlayerGoldCount();
int barrelsLeft = getNumberOfBarrelsRemainingToBePickedUp();
22

int sonar = getPlayerSonarChargeCount();  int score = getCurrentScore();
 //  Next, create a string from your statistics, of the form:  // Lvl: 52 Lives: 3 Hlth: 80% Wtr: 20 Gld: 3 Oil Left: 2 Sonar: 1 Scr: 321000

string s = someFunctionYouUseToFormatThingsNicely(level, lives, health,
squirts, gold, barrelsLeft, sonar, score);  //  Finally, update the display text at the top of the screen with your  //  newly created stats
setGameStatText(s); // calls our provided GameWorld::setGameStatText  } */

	virtual ~StudentWorld()
	{
		this->cleanUp();
	}


};

#endif // STUDENTWORLD_H_



