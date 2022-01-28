#include <SDL2/SDL.h>

#ifndef CLASSE_HPP
#define CLASSE_HPP

class MainSDLWindow{
    public:
        MainSDLWindow();
        ~MainSDLWindow();

        int Init(int, int, int);

        void GetRenderer();
        
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        
};

#endif