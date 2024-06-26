#include "shape.h"
#include "game.h"
#include "gameConfig.h"

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}

//void shape::move(int step, bool isVertical)
//{
//	if (isExceeded() == false) {
//		RefPoint.move(step, isVertical); // RefPoint = 30, ==> move ==> RefPoint = 60;
//		calcCorners();
//	}
//	else
//		return;
//}

int shape::getRotationAngle() { return iRotationAngle; }
int shape::getNumberOfResizeCalls() { return iResizeCalls; }
