//
// Created by Yurii Tkachyshyn on 2019-03-30.
//

#ifndef ECG_DEFS_H
#define ECG_DEFS_H
#include <OpenGL/gl.h>

typedef int bool;
#define true 1
#define false 0

#define bufferSize 2000 * sizeof(struct point)

struct point { //TODO : GLfloat vertex2d[2];
    GLfloat x;
    GLfloat y;
};

struct buffer
{
    GLuint address;
    size_t size_bytes;
    size_t num_elements;
    struct point* data;
};

#endif //ECG_DEFS_H
