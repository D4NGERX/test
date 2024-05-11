#include "RandomShape.h"
#include <cstdlib>
#include <time.h>

RandomShape::RandomShape(game* r_pGame, int N)
{
	pGame = r_pGame;
	n = N;
	PickedShapes = new ShapeType[n];
	for (int i = 0; i < n; i++)
	{
		PickedShapes[i] = getRandomShapeTypes();
	}
}

void RandomShape::draw()
{
	for (int i = 0; i < getNumberOfShapes(); i++) {
		switch (PickedShapes[i])
		{
		case SIGN:
		{
			Sign* NewSign = new Sign(pGame, getRandomPoint());
			NewSign->calcCorners();
			NewSign->draw();
			break;
		}
		case RCT:
		{
			Rect* NewRect = new Rect(pGame, getRandomPoint(), config.Rectangle.hieght, config.Rectangle.Width);
			NewRect->calcCorners();
			NewRect->draw();
			break;
		}

		}
	}
}

ShapeType RandomShape::getRandomShapeTypes()
{
	srand(time(0));
	int Min = 0;
	int Max = ShapeEnd;
	ShapeType stShape = ShapeType(Min + rand() % (Max - Min + 1));
	return stShape;

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
	return rndmPoint;
}

void RandomShape::MakeRandomOperation(shape* sh)
{
	ShapeOperations RandomOperation = ShapeOperations(rand() % (OperationEnds + 1));
	switch (RandomOperation)
	{
	case Rotate:
		sh->rotate();
		break;
	case Resize:
		sh->resize();
	}

}



