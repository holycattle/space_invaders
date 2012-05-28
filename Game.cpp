#include <string>
#include <vector>

#include "sdlhelper/SDL_load.h"
#include "Sprite.h"
#include "Entity.h"

const int screenWidth = 800;
const int screenHeight = 600;
const int screenBPP = 32;

const char* title = "Galaxian Clone";

class Game {
	public:
		//the window

		SDL_Surface* screen;

		//event structure
		SDL_Event eventQueue;

		//game entities here:
		Entity* ship;

		//lists
		std::vector<Entity*> entityList;
		std::vector<Entity*> removeList;

		//functions
		bool initWindow();
		bool initEntities();
		Game();
};

bool Game::initWindow() {
	screen = NULL;

	//Initialize all SDL subsystems
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) {
		return false;
	}
	
	//Set up the screen
	screen = SDL_SetVideoMode(screenWidth, screenHeight, screenBPP, SDL_SWSURFACE);

	//If there was an error in setting up the screen
	if( screen == NULL ) {
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption( title, NULL );

	//If everything initialized fine
	return true;
}

bool Game::initEntities() {
	
}

Game::Game() {
	//initialize window
	initWindow(); //to-do: exception-handling

	//initialize objects
	initEntities(); //to-do: exception-handling
}

int main() {
	Game g = Game();
	//g.startLoop();
}
