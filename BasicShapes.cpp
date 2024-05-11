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
		wdth = int(wdth * 1.15);
		hght = int(hght * 1.15);
		calcCorners();
		iResizeCalls++;
	}
	else
		return;
}

point* Rect::getUpperLeft() { return &upperLeft; }
point* Rect::getLowerBottom() { return &lowerBottom; }

bool Rect::isExceeded()
{
	if (lowerBottom.isItExceeded(lowerBottom.x, lowerBottom.y) == true
		|| upperLeft.isItExceeded(upperLeft.x, upperLeft.y) == true)
		return true;
	else
		return false;

}