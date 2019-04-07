//
// Created by Yurii Tkachyshyn on 2019-03-30.
//

#include "display.h"
#include <SDL2/SDL.h>
#include <OpenGL/gl.h>
#include "defs.h"

void Display(){

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    gVertexBufferData = (SVertex2D*)glMapBufferRange(GL_ARRAY_BUFFER, 0, bufferSize, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
//
//    const int MAX_ITERS = 1;
//    float tx, ty, an;
//    for (int iter = 0; iter < MAX_ITERS; ++iter)
//    {
//        for (size_t i(0); i != gParamTriangleCount * 3; ++i)
//        {
//            tx = gReferenceTrianglePosition[(i / 3) * 3].x + 0.01f;
//            ty = gReferenceTrianglePosition[(i / 3) * 3].y + 0.01f;
//            an = gAngle*sinf(tx*3.0f) + ty;
//            gVertexBufferData[i].x = (gReferenceTrianglePosition[i].x - tx) * cosf(an) - (gReferenceTrianglePosition[i].y - ty) * sinf(an) + tx;
//            gVertexBufferData[i].y = (gReferenceTrianglePosition[i].x - tx) * sinf(an) + (gReferenceTrianglePosition[i].y - ty) * cosf(an) + ty;
//        }
//    }
//
//    glBufferData(GL_ARRAY_BUFFER, bufferSize, NULL, GL_DYNAMIC_DRAW);
//    glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, glBufferData);
//    //Draw using the vertex buffer
//    for (int iter = 0; iter < MAX_ITERS; ++iter)
//        glDrawArrays(GL_TRIANGLES, 0, gParamTriangleCount * 3);
//
//    glutSwapBuffers();
//    gFrameCount++;
}

