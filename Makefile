game:	Game.cpp Sprite.h Entity.h
	g++ `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf Game.cpp -o game

clean:
	rm game
