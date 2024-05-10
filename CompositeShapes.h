#pragma once
#include "Basicshapes.h"


class Sign :public shape
{
	Rect* base;
	Rect* top;
	point topRef;
	point baseRef;
public:
	Sign(game* r_pGame, point ref);
	virtual void draw() override;
	virtual void rotate() override;
	virtual void calcCorners() override;
	virtual void flip() override;
	virtual void resize() override;

};

