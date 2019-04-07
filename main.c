#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "shaders.h"
#include <SDL2/SDL.h>
//MAC
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <time.h>

#  define sleep(s) Sleep((s)*1000)

GLint attribute_vertex2d;

int main() {
    //init SDL
    SDL_Window *sdl_window = init();
    GLuint program = create_shaders();

    attribute_vertex2d = glGetAttribLocation(program, "vertex2d");

    // create vbo
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 2000 * sizeof(struct point), NULL, GL_DYNAMIC_DRAW);
    struct point *graph = (struct point *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

    for (int i = 0; i < 2000; i++) {
        float x = (i - 1000.0) / 100.0;
        graph[i].x = x;
        graph[i].y = sin(x * 10.0) / (1.0 + x * x);
    }
    glUnmapBuffer(GL_ARRAY_BUFFER);

    // setup vertex attribs
    GLuint vertex2d = 0;
    glEnableVertexAttribArray(attribute_vertex2d);
    glVertexAttribPointer(vertex2d, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

    float a = 5.0;
    float x = ((float)rand()/(float)(RAND_MAX)) * a;

//////////////////////////////////////////////////////////////////////ASYNC///////////////////////////////////////////
//// Constants
//    const GLuint STREAM_BUFFER_CAPACITY = 8192*1024; // 8MBytes
//    GLuint *buffers      = NULL;
//    enum // OpenGLNames
//    {
//        // buffers
//                BUFFER_VERTEX_MD2 = 0,
//        BUFFER_COUNT,
//
//        // vertex arrays
//                VERTEX_ARRAY_MD2 = 0,
//        VERTEX_ARRAY_COUNT,
//
//        // textures
//                TEXTURE_SKIN_MD2 = 0,
//        TEXTURE_COUNT,
//
//        // programs
//                PROGRAM_RENDER_MD2 = 0,
//        PROGRAM_COUNT
//    };
//// configure buffer objects
//    glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTEX_MD2]);
//    glBufferData(GL_ARRAY_BUFFER,
//                 STREAM_BUFFER_CAPACITY,
//                 NULL,
//                 GL_STREAM_DRAW);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//    // stream variables
//    static GLuint streamOffset = 0;
//    static GLuint drawOffset   = 0;
//
//// bind the buffer
//    glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTEX_MD2]);
//// orphan the buffer if full
//    GLuint streamDataSize = next_power_of_two(md2->TriangleCount()
//                                                  *3*sizeof(Md2::Vertex));
//    if(streamOffset + streamDataSize > STREAM_BUFFER_CAPACITY)
//    {
//        // allocate new space and reset the vao
//        glBufferData( GL_ARRAY_BUFFER,
//                      STREAM_BUFFER_CAPACITY,
//                      NULL,
//                      GL_STREAM_DRAW );
//        glBindVertexArray(vertexArrays[VERTEX_ARRAY_MD2]);
//        glBindBuffer(GL_ARRAY_BUFFER, buffers[BUFFER_VERTEX_MD2]);
//        glVertexAttribPointer( 0, 3, GL_FLOAT, 0, sizeof(Md2::Vertex),
//                               FW_BUFFER_OFFSET(0) );
//        glVertexAttribPointer( 1, 3, GL_FLOAT, 0, sizeof(Md2::Vertex),
//                               FW_BUFFER_OFFSET(3*sizeof(GLfloat)));
//        glVertexAttribPointer( 2, 2, GL_FLOAT, 0, sizeof(Md2::Vertex),
//                               FW_BUFFER_OFFSET(6*sizeof(GLfloat)));
//        glBindVertexArray(0);
//        // reset offset
//        streamOffset = 0;
//    }
//
//// get memory safely
//    Md2::Vertex* vertices = (Md2::Vertex*)
//            (glMapBufferRange(GL_ARRAY_BUFFER,
//                              streamOffset,
//                              streamDataSize,
//                              GL_MAP_WRITE_BIT
//                              |GL_MAP_UNSYNCHRONIZED_BIT));
//// make sure memory is mapped
//    if(NULL == vertices)
//        throw std::runtime_error("Failed to map buffer.");
//
//// set final data
//    md2->GenVertices(vertices);
//
//// unmap buffer
//    glUnmapBuffer(GL_ARRAY_BUFFER);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//// compute draw offset
//    drawOffset = streamOffset/sizeof(Md2::Vertex);
//
//// increment offset
//    streamOffset += streamDataSize;
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

        glDrawArrays(GL_LINE_STRIP, 0, vbo.s);
        SDL_GL_SwapWindow(sdl_window);
    } while (running);

    glDeleteProgram(program);
    glDeleteBuffers(1, &vbo);

    close();

    return 0;
}