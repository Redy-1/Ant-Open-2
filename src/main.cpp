#include <iostream>
#include "World.h"

#undef main

using namespace std;

World world;

int main(int* argc, char* argv[])
{
	// Welcome to our Masterclass :) - Nite Games

	srand(time(NULL));

	world.init();
	
	//cout << world.m_run;
	while (world.m_run)
	{
		//cout << "agag";

		world.update();

		world.draw();
	}


	return 0;
}