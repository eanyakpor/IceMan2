#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameWorld.h"
#include <math.h> 
#include <algorithm>

//class Actor : public GraphObject {
//public:
//	Actor(int imageID, int startX, int startY, Direction startDirection, float size = 1.0, unsigned int depth = 0);
//	//Actor();
//	~Actor() {};
//
//	//void doSomething() {};
//	
//};
//forward decleration
class StudentWorld;

class Actor : public GraphObject
{
public:
	Actor(int img_id, int m_x, int m_y, GraphObject::Direction dr, StudentWorld* sw, double size = 1.0, unsigned int depth = 0)
		: GraphObject(img_id, m_x, m_y, dr, size, depth)
	{
		p = sw;
	}
	virtual void doSomething() = 0;

	StudentWorld* getWorld()
	{
		return p;
	}
	//virtual ~Actor();
	bool isAlive() { //alive == true ? true : false; 
		if (alive == true)
		{
			return true;
		}
		return false;
	};
	void setDead() { alive = false; };
	int waitTicker; // time of boulder

	//virtual bool isAlive() { return alive; }

private:
	StudentWorld* p;
	bool alive = true;


};

class IceMan : public Actor
{
public:
	IceMan(int img_id, int m_x, int m_y, GraphObject::Direction dr, StudentWorld* sw, double size = 1.0, unsigned int depth = 0)
		: Actor(IID_PLAYER, m_x, m_y, dr, sw, size, depth)
	{
		setVisible(true);
	}
	void doSomething();


	//~IceMan();
};

class Ice : public Actor
{
public:
	Ice(int img_id, int m_x, int m_y, GraphObject::Direction dr, StudentWorld* sw, double size = 1.0, unsigned int depth = 0)
		: Actor(IID_ICE, m_x, m_y, dr, sw, size, depth)
	{
		setVisible(true);
	}
	void doSomething();
	//~Ice();
};

class Goodie : public Actor
{
public:
	Goodie(int img_id, int m_x, int m_y, GraphObject::Direction dr, StudentWorld* sw, double size = 1.0, unsigned int depth = 0)
		: Actor(img_id, m_x, m_y, dr, sw, size, depth)
	{
		p = sw;
	}
	virtual void doSomething() = 0;
	int pickUpable = 0;
	// should i use virtual here cause all the inherited classes need it but what's the point 
	void setpickUpable(int n) { pickUpable = n; };
	int getpickUpable() { return pickUpable; };
private:
	StudentWorld* p;
};

class gold : public Goodie
{
public:gold(int img_id, int m_x, int m_y, GraphObject::Direction dr, StudentWorld* sw, double size = 1.0, unsigned int depth = 0)
	: Goodie(img_id, m_x, m_y, dr, sw, size, depth) {}
	  void doSomething();
	  int pickUpable = 0;
	  void setpickUpable(int n) { pickUpable = n; };
	  int getpickUpable() { return pickUpable; };
	  int T = 0;
	  void setTicks(int i) { T = i; };
	  //int x= m_x, y = m_y;
};
class barrel : public Goodie
{
public:
	barrel(int img_id, int m_x, int m_y, GraphObject::Direction dr, StudentWorld* sw, double size = 1.0, unsigned int depth = 0)
		: Goodie(img_id, m_x, m_y, dr, sw, size, depth) {}
	void doSomething();
	int pickUpable = 0;
	void setpickUpable(int n) { pickUpable = n; };
	int getpickUpable() { return pickUpable; };
};

class boulder : public Actor
{
public:
	enum BoulderStates { Stable, UnStable, Falling };
	boulder(int img_id, int m_x, int m_y, GraphObject::Direction dr, StudentWorld* sw, double size = 1.0, unsigned int depth = 0)
		: Actor(img_id, m_x, m_y, dr, sw, size, depth) {}
	void doSomething();
	//int calculateDistanceFromIceman();
	BoulderStates myCurrentState = BoulderStates::Stable;
};

class sonar : public Goodie
{
public:sonar(int img_id, int m_x, int m_y, GraphObject::Direction dr, StudentWorld* sw, double size = 1.0, unsigned int depth = 0)
	: Goodie(img_id, m_x, m_y, dr, sw, size, depth) {}
	  void doSomething();
	  int pickUpable = 1;
	  void setpickUpable(int n) { pickUpable = n; };
	  int getpickUpable() { return pickUpable; };
	  int T = 0;
	  void setTicks(int i) { T = i; };
	  //int x= m_x, y = m_y;
};

class waterPool : public Goodie
{
public:

	waterPool(int img_id, int m_x, int m_y, GraphObject::Direction dr, StudentWorld* sw, double size = 1.0, unsigned int depth = 0)
		: Goodie(img_id, m_x, m_y, dr, sw, size, depth) {
	}
	void doSomething();
	//is alive is dead stuff
	//the max ticks that the pool can be alive;
	int pickUpable = 1;
	void setpickUpable(int n) { pickUpable = n; };
	int getpickUpable() { return pickUpable; };
	int T = 0;
	void setTicks(int i) { T = i; };
	//int T = std::max(100, 300 - 10 * int(p->getLevel()));
private:

	//StudentWorld* p;
	 // every waterpool goodie that is created should have a max life of T ticks. 

};


class Protester : public Actor
{
public:
	Protester(int img_id, int m_x, int m_y, StudentWorld* sw, Direction dr, float size, unsigned int depth)
		: Actor(img_id, m_x, m_y, dr, sw, size, depth)
	{

	}
	void doSomething() = 0;
};

class RegularProtesters : public Protester
{
public:
	RegularProtesters(StudentWorld* sw) : Protester(IID_PROTESTER, 60, 60, sw, left, 1.0, 0)
	{
		setVisible(true);
	}

	void doSomething();

	//virtual void Bribed();
};

class HardCoreProtester : public Protester
{
public:
	HardCoreProtester(StudentWorld* sw) : Protester(IID_HARD_CORE_PROTESTER, 60, 60, sw, left, 1.0, 0)
	{
		setVisible(true);
	}

	void doSomething();

	//virtual void Bribed();*/

};

class Squirt : public Actor
{
public:
	Squirt(int img_id, int m_x, int m_y, GraphObject::Direction dr, StudentWorld* sw, double size = 1.0, unsigned int depth = 1)
		: Actor(img_id, m_x, m_y, dr, sw, size, depth)
	{
		setVisible(true);
	}
	int pickUpable = 1;
	void setpickUpable(int n) { pickUpable = n; };
	int getpickUpable() { return pickUpable; };
	int T = 0;
	void setTicks(int i) { T = i; };
	void doSomething();
};



#endif // ACTOR_H_



