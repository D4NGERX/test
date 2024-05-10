#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame):operation(r_pGame)
{
}

void operAddSign::Act()
{
	window* pw = pGame->getWind();
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;
	point signShapeRef = { xGrid,yGrid };
	shape* psh = new Sign(pGame, signShapeRef);
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operRotate::operRotate(game* r_pGame) : operation(r_pGame)
{

}


void operRotate::Act()
{
	window* pRotate = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->getActiveShape()->rotate();
	//pGrid->getActiveShape()->calcCorners();
	//pGrid->draw();
}


AddRect::AddRect(game* r_pGame) : operation(r_pGame)
{}

void AddRect::Act()
{
	window* pw = pGame->getWind();
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;
	point RectRef = { xGrid,yGrid };
	shape* psh = new Rect(pGame, RectRef, config.Rectangle.hieght, config.Rectangle.Width);
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}


operMove::operMove(game* r_pGame) : operation(r_pGame)
{

}

void operMove::Act()
{
	//window* pWind = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->getActiveShape()->move(isVertical);
}

void operMove::isItVertical(bool isIt)
{
	isVertical = isIt;
}

operFlip::operFlip(game* r_pGame) : operation(r_pGame)
{

}

void operFlip::Act()
{
	window* pWind = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->getActiveShape()->flip();
}

operResize::operResize(game* r_pGame) : operation(r_pGame)
{

}

void operResize::Act()
{
	window* pWind = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->getActiveShape()->resize();
}

//BuildRandomShape::BuildRandomShape(game* r_pGame) : operation(r_pGame)
//{}
//
//void BuildRandomShape::Act()
//{
//
//}