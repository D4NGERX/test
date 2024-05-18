#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
#include <iostream>
Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
	calcCorners();
	
}


void Rect::draw()
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}


void Rect::calcCorners()
{
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;
}

#include <iostream>

void Rect::rotate()
{
	
	lowerBottom.rotate(RefPoint);
	upperLeft.rotate(RefPoint);
	if (iRotationAngle < 360)
		iRotationAngle += 90;
	else
		iRotationAngle = 0;
}

void Rect::flip()
{
	point temp = lowerBottom;
	lowerBottom.flip(upperLeft);
	upperLeft.flip(temp);
}

void Rect::resize()
{
	if (iResizeCalls < 4) {
		wdth = int(wdth * 2);
		hght = int(hght * 2);
		calcCorners();
		//ReCalcRefPoint();
		iResizeCalls++;
	}
	else
		return;
}

point* Rect::getUpperLeft() { return &upperLeft; }
point* Rect::getLowerBottom() { return &lowerBottom; }
void Rect::ReCalcRefPoint()
{
	RefPoint.x = upperLeft.x + wdth / 2;
	RefPoint.y = upperLeft.x + hght / 2;
	std::cout << "Ref" << RefPoint << " " << "\n";
	//std::cout << "Ref.y: " << RefPoint.y << " ";
}
bool Rect::isExceeded()
{
	if (lowerBottom.isItExceeded(lowerBottom.x, lowerBottom.y) == true
		|| upperLeft.isItExceeded(upperLeft.x, upperLeft.y) == true)
		return true;
	else
		return false;

}

void Rect::move(int step, bool isVertical)
{
	//if (isExceeded() == false) {
		lowerBottom.move(step, isVertical);
		upperLeft.move(step, isVertical);
		RefPoint.move(step, isVertical); // RefPoint = 30, ==> move ==> RefPoint = 60;
		calcCorners();
	//}
	/*else
	{
		lowerBottom = lowerBottom;
		upperLeft = upperLeft;
	}*/
}