#ifndef TextureManager_h
#define TextureManager_h

#include "Game.h"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* filename);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst);
};

#endif /* TextureManager_h */

