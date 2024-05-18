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

void Sign::draw()
{
	base->draw();
	top->draw();
}

void Sign::calcCorners()
{
	top->calcCorners();
	base->calcCorners();
	topRef = RefPoint;
	baseRef = { RefPoint.x, RefPoint.y + config.sighShape.topHeight / 4 + config.sighShape.baseHeight / 4 };
	
	
}

void Sign::rotate()
{
	top->rotate();
	base->getLowerBottom()->rotate(topRef);
	base->getUpperLeft()->rotate(topRef);
	if (iRotationAngle < 360)
		iRotationAngle += 90;
	else
		iRotationAngle = 0;
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
	calcCorners();
	//ReCalcRefPoint();
}

void Sign::ReCalcRefPoint()
{
	//baseRef = topRef + 0.5*
}

bool Sign::isExceeded()
{
	if (top->isExceeded() == true || base->isExceeded() == true)
		return true;
	else
		return false;
}

void Sign::move(int step, bool isVertical)
{
	if (isExceeded() == false) {
		RefPoint.move(step, isVertical); // RefPoint = 30, ==> move ==> RefPoint = 60;
		calcCorners();
	}
	else
		return;
}