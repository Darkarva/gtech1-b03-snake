#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "classe.hpp"

MainSDLWindow::MainSDLWindow(){
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit;
}
