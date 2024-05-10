#pragma once
#include "shape.h"
#include "BasicShapes.h"
#include "CompositeShapes.h"
#include "operations.h"

class RandomShape
{
	int n;
	ShapeType PickedShapes[3];
	game* pGame;
	//operation* op;
public:
	RandomShape(game* r_pGame, int N = 0);
	void draw();
	void getRandomShapeTypes();
	int getNumberOfShapes();
	point getRandomPoint();
};

