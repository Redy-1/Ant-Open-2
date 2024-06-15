#include "World.h"
#include "Grid.h"
#include "InputManager.h"
#include "pawn.h"
#include "cards.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;


World::World()
{

}

World::~World()
{

}

void World::draw() {
	SDL_RenderCopy(m_mainRenderer, m_backgroundTexture, NULL, NULL);
	
	m_rect.x = 100;
	m_rect.y = 100;
	m_rect.w = 100;
	m_rect.h = 100;
	

	SDL_RenderCopy(m_mainRenderer, m_Test, NULL, &m_rect);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			//cout << i << " " << j << " " << m_grid.arr_tiles[i][j].m_texture << " " 
			//	<< m_grid.arr_tiles[i][j].m_rect.x << " " << m_grid.arr_tiles[i][j].m_rect.y << endl;
			
			if (Grid::r_pos == i && Grid::c_pos == j) {
				SDL_RenderCopy(m_mainRenderer, m_Test, NULL, &m_grid.arr_tiles[i][j].m_rect);
			}
			if(m_grid.arr_tiles[i][j].available) {
				SDL_RenderCopy(m_mainRenderer, m_grid.arr_tiles[i][j].m_texture_available, NULL, &m_grid.arr_tiles[i][j].m_rect);
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		SDL_RenderCopy(m_mainRenderer, m_grid.m_p1_texture, NULL, &m_grid.m_team1_pawns[i].m_tile->m_rect);
		SDL_RenderCopy(m_mainRenderer, m_grid.m_p2_texture, NULL, &m_grid.m_team2_pawns[i].m_tile->m_rect);
		if (m_grid.card[m_grid.ra_card[i]].pos > 2) {
			SDL_RenderCopy(m_mainRenderer, m_grid.card[m_grid.ra_card[i]].m_r_texture, NULL, &m_grid.card[m_grid.ra_card[i]].m_rect);
		}
		else {
			SDL_RenderCopy(m_mainRenderer, m_grid.card[m_grid.ra_card[i]].m_texture, NULL, &m_grid.card[m_grid.ra_card[i]].m_rect);
		}
	}
	




	SDL_RenderPresent(m_mainRenderer);
} 

void World::exit() {

}
void World::update() {
	InputManager::mouse_pos();
	
	m_grid.update();

	//cout << InputManager::m_mouseCoor.x << "   " << InputManager::m_mouseCoor.y << endl;
}
void World::init() {
	initSDL();
	for (int i = 0; i < 5; i++) {
		m_grid.m_team1_pawns[i].m_tile = &m_grid.arr_tiles[i][0];
		m_grid.m_team1_pawns[i].m_tile = &m_grid.arr_tiles[i][0];

		m_grid.m_team2_pawns[i].m_tile = &m_grid.arr_tiles[i][4];
		m_grid.m_team2_pawns[i].m_tile = &m_grid.arr_tiles[i][4];

	}
	m_run = true;

	fstream out;
	
	string read;

	
	int i=0;
	out.open("config\\cards\\allCards.txt");
	if (!out) {
		cout << "error" << endl;
	}
	while (!out.eof()) {
		out >> read;
		m_grid.card[i].m_name = read;
		out >> read;
		string test = {"img\\CARDS\\" + m_grid.card[i].m_name + ".bmp" };
		SDL_Surface* sur   = SDL_LoadBMP(test.c_str());
		test = "img\\CARDS\\" + m_grid.card[i].m_name + "_reversed.bmp";
		SDL_Surface* r_sur = SDL_LoadBMP(test.c_str());

		m_grid.card[i].m_texture = SDL_CreateTextureFromSurface(m_mainRenderer, sur);
		m_grid.card[i].m_r_texture = SDL_CreateTextureFromSurface(m_mainRenderer, r_sur);

		SDL_FreeSurface(sur);
		SDL_FreeSurface(r_sur);

		while (read != ";") {
			int numb = stoi(read);
			out >> read;
			int numb2 = stoi(read);
			m_grid.card[i].m_offset.push_back(make_pair(numb, numb2));
			out >> read;
			//cout << read << endl;
			
		}
		i++;
	}

	// m_grid.ra_card[0] = rand() % 8;
	for (int i = 0; i < 5; i++) {
		m_grid.ra_card[i] = rand() % 8;
		for (int j = 0; j < i; j++) {
			if (m_grid.ra_card[i] == m_grid.ra_card[j]) {
				j = -1;
				m_grid.ra_card[i] = rand() % 8;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << m_grid.ra_card[i] << " ";
	}
	cout << endl;
	/*
	for (int i = 0; i < m_grid.card[m_grid.ra_card[0]].m_offset.size(); i++) {
		cout << m_grid.card[m_grid.ra_card[0]].m_offset[i].first << " " << m_grid.card[m_grid.ra_card[0]].m_offset[i].second << endl;
	}
	*/

	m_grid.card[m_grid.ra_card[0]].m_rect = { 118, 214, m_CARD_WIDTH, m_CARD_HEIGHT }; // Left Up
	m_grid.card[m_grid.ra_card[0]].pos = 0;
	m_grid.card[m_grid.ra_card[1]].m_rect = { 118,429,m_CARD_WIDTH,m_CARD_HEIGHT }; // Left Down
	m_grid.card[m_grid.ra_card[1]].pos = 1;
	m_grid.card[m_grid.ra_card[2]].m_rect = { 1491,214,m_CARD_WIDTH,m_CARD_HEIGHT }; // Right Up
	m_grid.card[m_grid.ra_card[2]].pos = 3;
	m_grid.card[m_grid.ra_card[3]].m_rect = { 1491,429,m_CARD_WIDTH,m_CARD_HEIGHT }; // Right Down
	m_grid.card[m_grid.ra_card[3]].pos = 4;
	//{800,912,m_CARD_WIDTH,m_CARD_HEIGHT }, // To Go Right
	m_grid.card[m_grid.ra_card[4]].m_rect = { 800, 12, m_CARD_WIDTH, m_CARD_HEIGHT };
	m_grid.card[m_grid.ra_card[4]].pos = 2;
	// To Go Left
	

	

	out.close();
}
void World::initSDL() {
	m_mainWindow = SDL_CreateWindow("GameName",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, 0);
	
	m_mainRenderer = SDL_CreateRenderer(m_mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	//SDL_SetWindowFullscreen(m_mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

	improveRenderer();

	SDL_Surface* loadingSurface = SDL_LoadBMP("img\\game\\background.bmp");
	m_backgroundTexture = SDL_CreateTextureFromSurface(m_mainRenderer, loadingSurface);

	SDL_Surface* loadingSurface1 = SDL_LoadBMP("img\\game\\hover.bmp");
	m_Test = SDL_CreateTextureFromSurface(m_mainRenderer, loadingSurface1);
	
	SDL_Surface* loadingSurface6 = SDL_LoadBMP("img\\game\\gridPossMove.bmp");

	m_grid.createGrid();
	SDL_Surface* loadingSurface2 = SDL_LoadBMP("img\\game\\unused.bmp");
	SDL_Surface* loadingSurface4 = SDL_LoadBMP("img\\pawns\\pawn1.bmp");
	SDL_Surface* loadingSurface5 = SDL_LoadBMP("img\\pawns\\pawn2.bmp");


/*
	SDL_Surface* dragon = SDL_LoadBMP("img\\CARDS\\dragon.bmp");
	SDL_Surface* rabbit = SDL_LoadBMP("img\\CARDS\\rabbit.bmp");
	SDL_Surface* eagle = SDL_LoadBMP("img\\CARDS\\eagle.bmp");
	SDL_Surface* monkey = SDL_LoadBMP("img\\CARDS\\monkey.bmp");
	SDL_Surface* tiger = SDL_LoadBMP("img\\CARDS\\tiger.bmp");
	SDL_Surface* turtle = SDL_LoadBMP("img\\CARDS\\turtle.bmp");
	SDL_Surface* goose = SDL_LoadBMP("img\\CARDS\\goose.bmp");
	SDL_Surface* dog = SDL_LoadBMP("img\\CARDS\\dog.bmp");
	SDL_Surface* giraffe = SDL_LoadBMP("img\\CARDS\\giraffe.bmp");
	
	SDL_Surface* r_dragon = SDL_LoadBMP("img\\CARDS\\dragon_reversed.bmp");
	SDL_Surface* r_rabbit = SDL_LoadBMP("img\\CARDS\\rabbit_reversed.bmp");
	SDL_Surface* r_eagle = SDL_LoadBMP("img\\CARDS\\eagle_reversed.bmp");
	SDL_Surface* r_monkey = SDL_LoadBMP("img\\CARDS\\monkey_reversed.bmp");
	SDL_Surface* r_tiger = SDL_LoadBMP("img\\CARDS\\tiger_reversed.bmp");
	SDL_Surface* r_turtle = SDL_LoadBMP("img\\CARDS\\turtle_reversed.bmp");
	SDL_Surface* r_goose = SDL_LoadBMP("img\\CARDS\\goose_reversed.bmp");
	SDL_Surface* r_dog = SDL_LoadBMP("img\\CARDS\\dog_reversed.bmp");
	SDL_Surface* r_giraffe = SDL_LoadBMP("img\\CARDS\\giraffe_reversed.bmp");
*/
	

	SDL_Surface* loadingSurface3 = SDL_LoadBMP("img\\game\\player1OnTurn.bmp");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {			
			m_grid.arr_tiles[i][j].m_texture = SDL_CreateTextureFromSurface(m_mainRenderer, loadingSurface2);		
			m_grid.arr_tiles[i][j].m_texture_available = SDL_CreateTextureFromSurface(m_mainRenderer, loadingSurface6);		
		}
	}
	m_grid.m_p1_texture= SDL_CreateTextureFromSurface(m_mainRenderer, loadingSurface4);
	m_grid.m_p2_texture= SDL_CreateTextureFromSurface(m_mainRenderer, loadingSurface5);
	

	SDL_FreeSurface(loadingSurface1);
	SDL_FreeSurface(loadingSurface2);
	SDL_FreeSurface(loadingSurface3);
	SDL_FreeSurface(loadingSurface4);
	SDL_FreeSurface(loadingSurface5);
	SDL_FreeSurface(loadingSurface6);
	SDL_FreeSurface(loadingSurface);
	
	/*
	SDL_FreeSurface(dragon);
	SDL_FreeSurface(rabbit);
	SDL_FreeSurface(eagle);
	SDL_FreeSurface(monkey);
	SDL_FreeSurface(tiger);
	SDL_FreeSurface(turtle);
	SDL_FreeSurface(goose);
	SDL_FreeSurface(dog);
	SDL_FreeSurface(giraffe);

	SDL_FreeSurface(r_dragon);
	SDL_FreeSurface(r_rabbit);
	SDL_FreeSurface(r_eagle);
	SDL_FreeSurface(r_monkey);
	SDL_FreeSurface(r_tiger);
	SDL_FreeSurface(r_turtle);
	SDL_FreeSurface(r_goose);
	SDL_FreeSurface(r_dog);
	SDL_FreeSurface(r_giraffe);

	SDL_Surface* r_dragon = SDL_LoadBMP("img\\CARDS\\dragon_reversed.bmp");
	SDL_Surface* r_rabbit = SDL_LoadBMP("img\\CARDS\\rabbit_reversed.bmp");
	SDL_Surface* r_eagle = SDL_LoadBMP("img\\CARDS\\eagle_reversed.bmp");
	SDL_Surface* r_monkey = SDL_LoadBMP("img\\CARDS\\monkey_reversed.bmp");
	SDL_Surface* r_tiger = SDL_LoadBMP("img\\CARDS\\tiger_reversed.bmp");
	SDL_Surface* r_turtle = SDL_LoadBMP("img\\CARDS\\turtle_reversed.bmp");
	SDL_Surface* r_goose = SDL_LoadBMP("img\\CARDS\\goose_reversed.bmp");
	SDL_Surface* r_dog = SDL_LoadBMP("img\\CARDS\\dog_reversed.bmp");
	SDL_Surface* r_giraffe = SDL_LoadBMP("img\\CARDS\\giraffe_reversed.bmp");
	*/
}

void World::improveRenderer()
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);

	auto desktopWidth = DM.w;
	auto desktopHeight = DM.h;

	if (SDL_SetWindowFullscreen(m_mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP) < 0)
	{
		cout << "SDL_IMPROVE_RENDERER FAILED: %s\n" << SDL_GetError() << endl;
	}

	SDL_RenderSetLogicalSize(m_mainRenderer, SCREEN_W, SCREEN_H);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
}