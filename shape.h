#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"
#include "gameConfig.h"
class game;     //forward declaration

enum BoundaryViolationImage
{
	X_isExceedingRight,
	X_isExceedingLeft,
	Y_isExceedingUp,
	Y_isExceedingDown,
};

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
	void move(int step, bool isVertical)
	{
		BoundaryViolationImage bviDetector;
		int x1 = x, y1 = y;
		x1 += config.gridSpacing; y1 += config.gridSpacing;
		
		if (isItExceeded(x1, y1) == false) {
			if (isVertical == false)
				x += step; //int = 30;
			else if(isVertical == true)
				y += step;
		}
		else
		{
			if (x1 > config.windWidth)
				x -= config.gridSpacing;
			if (x1 < 30)
				x += config.gridSpacing;
			if (y1 > 500)
				y -= config.gridSpacing;
			if (y1 < 100)
				y += config.gridSpacing;
		}
	}

	void flip(point pnt)
	{
		int temp = y;
		y = pnt.y;
		pnt.y = temp;

	}

	bool isItExceeded(int xs, int ys)
	{
		if (xs > config.windWidth || xs < 0 || ys < config.toolBarHeight || ys > config.windHeight - config.statusBarHeight)
			return true;
		else
			return false;
	}

	friend std::ostream& operator <<(std::ostream& out, const point &other)
	{
		out << "x: " << other.x << " " << "y: " << other.y;
		return out;
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
	virtual void move(int step, bool isVertical) = 0;
	virtual bool isExceeded() = 0;
	//virtual point* getBoundaryBox() = 0;
	virtual void flip() = 0;
	virtual void resize() = 0;
	virtual int getRotationAngle();
	virtual int getNumberOfResizeCalls();
	virtual void ReCalcRefPoint() = 0;
	
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file

};




