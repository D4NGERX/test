#include "RandomShape.h"
#include <cstdlib>
#include <time.h>

RandomShape::RandomShape(game* r_pGame, int N)
{
	pGame = r_pGame;
	n = N;
}

void RandomShape::draw()
{
	for (int i = 0; i < getNumberOfShapes(); i++) {
		switch (PickedShapes[i])
		{
		case SIGN:
			Sign* NewSign = new Sign(pGame, getRandomPoint());
			NewSign->calcCorners();
			NewSign->draw();
			break;
		case RCT:
			Rect* NewRect = new Rect(pGame, getRandomPoint(), config.Rectangle.hieght, config.Rectangle.Width);
			NewRect->calcCorners();
			NewRect->draw();
			break;


		}
	}
}

void RandomShape::getRandomShapeTypes()
{
	srand(time(0));
	int Min = 0;
	int Max = ShapeEnd;
	for (int i = 0; i < getNumberOfShapes(); i++)
	{
		PickedShapes[i] = ShapeType(Min + rand() % (Max - Min + 1));
	}

}

int RandomShape::getNumberOfShapes()
{
	return n;
}

point RandomShape::getRandomPoint()
{
	point rndmPoint;
	int constant = 100;
	rndmPoint.x = rand() % (config.windWidth - constant + 1);
	rndmPoint.y = config.gridHeight + rand() % (config.windHeight - config.gridHeight + 1);
}