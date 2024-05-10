#include "CompositeShapes.h"
#include "gameConfig.h"

Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	
	topRef = ref;	//top rect ref is the same as the sign
	baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	setRefPoint(topRef);
	//calcCorners();
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
	
}
#include <iostream>
void Sign::draw()
{
	base->draw();
	top->draw();
	std::cout << "drawn" << endl;
}

void Sign::calcCorners()
{
	
	topRef = RefPoint;
	baseRef = { RefPoint.x, RefPoint.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top->calcCorners();
	base->calcCorners();
	
}

void Sign::rotate()
{
	top->rotate();
	base->getLowerBottom()->rotate(topRef);
	base->getUpperLeft()->rotate(topRef);
	
}

void Sign::flip()
{
	point temp = *(top->getUpperLeft());
	top->getUpperLeft()->flip(*(base->getLowerBottom()));
	base->getLowerBottom()->flip(temp);
}

void Sign::resize()
{
	top->resize();
	base->resize();
	top->getLowerBottom();
	top->getUpperLeft();
	base->getLowerBottom();
	base->getUpperLeft();
	calcCorners();
}