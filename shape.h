#pragma once
#include <string>
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"
#include "gameConfig.h"
class game;     //forward declaration

struct point
{
	//game* pGame;
	int x, y;
	

	void rotate(point ref)
	{
		              
		
		int temp_virtual;  // virtual means that I want to test the result before use it.
		int x1 = x, y1 = y; // transformation matrix ==> 
		x1 -= ref.x;
		y1 -= ref.y;
		temp_virtual = x1;
		x1 = -y1;
		y1 = temp_virtual;
		x1 += ref.x;
		y1 += ref.y;
		bool what = isItExceeded(x1, y1);
		if (isItExceeded(x1, y1) == false) {
			x -= ref.x;
			y -= ref.y;

			int temp = x;
			x = -y;
			y = temp;

			x += ref.x;
			y += ref.y;
		}
		else
			return;
	}
	void move(bool isVertical)
	{
		int x1 = x, y1 = y;
		x1 += config.gridSpacing; y1 += config.gridSpacing;
		
		if (isItExceeded(x1, y1) == false) {
			if (isVertical == false)
				x += config.gridSpacing; //int = 30;
			else if(isVertical == true)
				y += config.gridSpacing;
		}
		else
			return;
	}

	void flip(point pnt)
	{
		int temp = y;
		y = pnt.y;
		pnt.y = temp;

	}

	bool isItExceeded(int xs, int ys)
	{
		if (xs > config.windWidth || xs < 0 || ys < 0 || ys > config.windHeight)
			return true;
		else
			return false;
	}
};

enum ShapeType
{
	RCT,
	SIGN,
	ShapeEnd,  // this must be the last one in the enum
};

enum ShapeOperations
{
	Rotate,
	Resize,
	OperationEnds,

};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
    game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
	int iRotationAngle = 0;
	int iResizeCalls = 0;
	//int iRotationCalls = 0;
public:
    shape(game* r_pGame, point ref);
    virtual void draw() = 0;//for a shape to draw itself on the screen
	void setRefPoint(point p);
	virtual void calcCorners() = 0;
	virtual void rotate() = 0;
	virtual void move(bool isVertical);
	virtual bool isExceeded() = 0;
	//virtual point* getBoundaryBox() = 0;
	virtual void flip() = 0;
	virtual void resize() = 0;
	int getRotationAngle();
	int getNumberOfResizeCalls();
	//int getNumberOfRotationCalls();
	//-- The following functions should be supported by the shape class
	//-- It should be overridden by each inherited shape
	//-- Decide the parameters that you should pass to each function	

	//Rotate the shape
	//virtual void resize() = 0;	//Resize the shape
	//virtual void move() = 0;		//Move the shape
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file

};




