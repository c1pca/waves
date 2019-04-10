#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "shaders.h"
#include <SDL2/SDL.h>
//MAC
#include <OpenGL/gl3.h>
#include <time.h>
#include "buffer.h"


GLint attribute_vertex2d;

int main() {
    //init SDL
    SDL_Window *sdl_window = init();
    GLuint program = create_shaders();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR)
    {
        printf("Error1 %d\r\n", err);
        // Process/log the error.
    }
    GLuint buffers;
    int NUM_DRAWS = 2000;
    glGenBuffers(1, &buffers);
    while((err = glGetError()) != GL_NO_ERROR)
    {
        printf("Error2 %d\r\n", err);
        // Process/log the error.
    }
    glBindBuffer(GL_ARRAY_BUFFER, buffers);
    while((err = glGetError()) != GL_NO_ERROR)
    {
        printf("Error3 %d\r\n", err);
        // Process/log the error.
    }
    glBufferData(GL_ARRAY_BUFFER,
                 NUM_DRAWS * 4 * 2,
                 NULL,
                 GL_STREAM_DRAW);
    while((err = glGetError()) != GL_NO_ERROR)
    {
        printf("Error4 %d\r\n", err);
        // Process/log the error.
    }
    struct point *ptr = (struct point*)glMapBufferRange(GL_ARRAY_BUFFER, 0, NUM_DRAWS * 4 * 2, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
    while((err = glGetError()) != GL_NO_ERROR)
    {
        printf("Error5 %d\r\n", err);
        // Process/log the error.
    }
    GLint size = 0;
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    if(NUM_DRAWS * 4 * 2 != size)
    {
        glDeleteBuffers(1, &buffers);
        // Log the error
        return printf("Size is different and it is:%d\n", size);
    }
    for (int i = 0; i < NUM_DRAWS; i++) {
        ptr[i].x = 0.5;
        ptr[i].y = 0.5;
    }
    glUnmapBuffer(GL_ARRAY_BUFFER);
    while((err = glGetError()) != GL_NO_ERROR)
    {
        printf("Error6 %d\r\n", err);
        // Process/log the error.
    }
    // fill *ptr with data


//    attribute_vertex2d = glGetAttribLocation(program, "vertex2d");

    ///////////////////

//    GLuint vbo;
//    glGenBuffers(1, &vbo);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    struct point* buffers = malloc(2000 * sizeof(struct point));
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    buffers = (struct point*)glMapBufferRange(GL_ARRAY_BUFFER, 0, 2000 * sizeof(struct point), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
//
//    for (int i = 0; i < 2000; i++) {
//        float x = (i - 1000.0) / 100.0;
//        buffers[i].x = x;
//        buffers[i].y = (x * 10.0) / (1.0 + x * x);
//    }
//    glUnmapBuffer(GL_ARRAY_BUFFER);
//
//
//    glBufferData(GL_ARRAY_BUFFER, bufferSize, NULL, GL_DYNAMIC_DRAW);
//    glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, glBufferData);
    //////////////////

    // create vbo
//    GLuint vbo;
//
//    glGenBuffers(1, &vbo);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    glBufferData(GL_ARRAY_BUFFER, 2000 * sizeof(struct point), NULL, GL_DYNAMIC_DRAW);
//    struct point *buffers = (struct point *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
//
//    for (int i = 0; i < 2000; i++) {
//        float x = (i - 1000.0) / 100.0;
//        buffers[i].x = x;
//        buffers[i].y = sin(x * 10.0) / (1.0 + x * x);
//    }
//    glUnmapBuffer(GL_ARRAY_BUFFER);
//
//    // setup vertex attribs
//    GLuint vertex2d = 0;
//    glEnableVertexAttribArray(attribute_vertex2d);
//    glVertexAttribPointer(vertex2d, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

//////////////////////////////////////////////////////////////////////ASYNC///////////////////////////////////////////
//    GLuint buffers;
//    const GLuint STREAM_BUFFER_CAPACITY = 8192*1024; // 8MBytes
//    int NUM_DRAWS = 4;
//    glGenBuffers(1, &buffers);
//    glBindBuffer(GL_ARRAY_BUFFER, buffers);
//    glBufferData(GL_ARRAY_BUFFER,
//                 STREAM_BUFFER_CAPACITY,
//                 NULL,
//                 GL_STREAM_DRAW);
//    struct point* ptr = glMapBufferRange(GL_ARRAY_BUFFER, 0, NUM_DRAWS * sizeof(GLFloat)*2, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
//    // fill *ptr with data
//    for (int i = 0; i < NUM_DRAWS; i++)
//    {
//        ptr[i].x = 1;
//        ptr[i].y = i;
//
//    }
//    glUnmapBuffer(GL_ARRAY_BUFFER);
//
//    ////////////////////////////////////////////////////END///////////////////////////////////////////////

    glClearColor(0.4, 0.6, 0.8, 1.0);
    bool running = true;
    do {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            running = !(event.type == SDL_QUIT
                        || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE));
        }

        glLineWidth(3.0);

        glDrawArrays(GL_LINE_STRIP, 0, 2000);
        SDL_GL_SwapWindow(sdl_window);
    } while (running);

    glDeleteProgram(program);
    glDeleteBuffers(1, &buffers);

    close();

    return 0;
}
