#include "stdafx.h"
#include "Engine.h"

int main()
{
	srand(time(0));

	Engine game(700, 700);

	game.run();

	return 0;
}