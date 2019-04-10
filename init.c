//
// Created by Yurii Tkachyshyn on 2019-03-30.
//
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl3.h>
#include "init.h"
#include "defs.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const Uint32 window_flags = SDL_WINDOW_OPENGL;

const uint32_t countVBOs = 2;

SDL_Window *sdl_window;
SDL_GLContext sdl_gl_context;

SDL_Window *init(){
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
#ifdef USE_OPENGLES
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
	SDL_GL_CONTEXT_PROFILE_ES);
#endif
        //Create window
        sdl_window = SDL_CreateWindow(
                "ECG",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                SCREEN_WIDTH, SCREEN_HEIGHT,
                window_flags);

        if(!sdl_window)
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            exit(1);
        }

        sdl_gl_context = SDL_GL_CreateContext(sdl_window);
        if(!sdl_gl_context){
            printf( "Failed to create OpenGL window: %s\n", SDL_GetError() );
            exit(2);
        }
    }
    return sdl_window;
}

void close(){
    //Quit SDL subsystems
    SDL_GL_DeleteContext(sdl_gl_context);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}
