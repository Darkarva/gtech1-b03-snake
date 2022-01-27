#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

void ExitWithError(const char *message);

int main(int argc, char **argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        ExitWithError("Erreur d'initialisation de la SDL");
    }

    if(SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0){
        ExitWithError("Erreur création fenetre et rendu");
    }

    SDL_bool program_launched = SDL_TRUE;

    while(program_launched){
        SDL_Event event_quit;

        while(SDL_PollEvent(&event_quit)){
            switch(event_quit.type)
            {
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;
                
                default:
                    break;
            }
        }
    }

    SDL_RenderPresent(renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void ExitWithError(const char *message){
    SDL_Log("Erreur : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}