#pragma once
#include "gameConfig.h"
class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);
	virtual void Act() = 0;
};


class operAddSign:public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};

class operRotate : public operation
{
public:
	operRotate(game* r_pGame);
	virtual void Act();

};

class AddRect : public operation
{
public:
	AddRect(game* r_pGame);
	virtual void Act();
};

class operMove : public operation
{
	bool isVertical;
	int step;
public:
	operMove(game* r_pGame, int stp = 0);
	virtual void Act();
	void isItVertical(bool isIt); // set isVertical
	void moveStep(int stp);
};


class operFlip : public operation
{
public:
	operFlip(game* r_pGame);
	virtual void Act();
};

class operResize : public operation
{
public:
	operResize(game* r_pGame);
	virtual void Act();
};


