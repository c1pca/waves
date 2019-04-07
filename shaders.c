//
// Created by Yurii Tkachyshyn on 2019-03-30.
//
//MAC
#include <stdlib.h>
#include <OpenGL/gl.h>
#include "defs.h"
#include "shaders.h"

GLuint create_shaders(){
    //create shader
    const char * shader_vert_src =
            "attribute vec2 vertex2d;\n"
            "void main() {\n"
            "	gl_Position = vec4(vertex2d.x, vertex2d.y, 0, 1);\n"
            "}\n";

    const char *shader_frag_src =
            "#ifdef GL_ES\n"
            "precision mediump float;\n"
            "#endif\n"
            "void main() {\n"
            "	gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
            "}\n";

    GLint is_compiled;
    GLuint program, shader_vert, shader_frag;
    program = glCreateProgram();
    shader_vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader_vert, 1, &shader_vert_src, NULL);
    glCompileShader(shader_vert);
    glGetShaderiv(shader_vert, GL_COMPILE_STATUS, &is_compiled);
    printf("vert shader compiled %d\n", is_compiled);
    glAttachShader(program, shader_vert);
    shader_frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader_frag, 1, &shader_frag_src, NULL);
    glCompileShader(shader_frag);
    glGetShaderiv(shader_frag, GL_COMPILE_STATUS, &is_compiled);
    printf("frag shader compiled %d\n", is_compiled);
    glAttachShader(program, shader_frag);
    glLinkProgram(program);
    glUseProgram(program);
    return program;
}