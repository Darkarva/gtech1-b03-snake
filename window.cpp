#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "window.hpp"

Window::Window(){

}

Window::~Window(){
    SDL_DestroyRenderer(pgRenderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Window::ExitWithError(const char *message){
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
}

SDL_Renderer *Window::GetRenderer(void){
    return this->pgRenderer;
}

void Window::InitWin(){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        ExitWithError("SDL init failed.");
    }

    this->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    if(this->window == NULL){
        ExitWithError("Window creation failed.");
    }

    pgRenderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

     if(pgRenderer == NULL){
        ExitWithError("Window creation failed.");
    }
}

