
#pragma once
#include "shape.h"



class Rect : public shape
{
	int hght, wdth;
	point upperLeft, lowerBottom;
public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);
	virtual void draw();
	virtual void calcCorners();
	virtual bool isExceeded();
	virtual void rotate();
	virtual void flip();
	virtual void resize();
	point* getUpperLeft();
	point* getLowerBottom(); // base.upperLeft.move()
	

};


