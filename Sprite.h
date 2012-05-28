#include <map>
#include <vector>

class Sprite {
	//stateless
	SDL_Surface* image;

	int getWidth();
	int getHeight();
	void draw(SDL_Surface* screen, int x, int y);
	Sprite(std::string filename);
};

Sprite::Sprite(std::string filename) {
	image = (SDL_Surface*)malloc(sizeof(SDL_Surface));
	image = loadOptimizedSurface(filename.c_str());
}

int Sprite::getWidth() {
	return image->w;
}

int Sprite::getHeight() {
	return image->h;
}

void Sprite::draw(SDL_Surface* screen, int x, int y) {
	applySurface(image, screen, x, y);
}

class SpriteStore {
	private:
		static SpriteStore single;
		map<std::string, Sprite*> spriteMap;
	public:
		static SpriteStore get();
		Sprite getSprite(std::string);
};

SpriteStore SpriteStore::get() {
	return single;
}

Sprite SpriteStore::getSprite(std::string key) {
	std::map<std::string,Sprite*>::iterator itr;
	itr = spriteMap.find(key);
	if(itr == spriteMap.end()) {
		//
	}
}
