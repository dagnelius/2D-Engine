#ifndef TextureManager_h
#define TextureManager_h

#include "Game.h"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* filename);
};

#endif /* TextureManager_h */

