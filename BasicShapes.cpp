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
	//calcCorners();
	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}


void Rect::calcCorners()
{
	
	//setRefPoint(RefPoint);
	
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
	
}

void Rect::flip()
{
	point temp = lowerBottom;
	lowerBottom.flip(upperLeft);
	upperLeft.flip(temp);
}

void Rect::resize()
{
	//calcCorners();
	wdth = wdth * 1.15;
	hght = hght * 1.15;
	calcCorners();
}

point* Rect::getUpperLeft() { return &upperLeft; }
point* Rect::getLowerBottom() { return &lowerBottom; }

//bool Rect::isExceeded()
//{
//	
//}