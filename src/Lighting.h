#pragma once

#ifndef LIGHTING_H
#define LIGHTING_H


#include <stdlib.h>
#include <Windows.h>
#include <GL/glut.h>

void setupLighting();
void computeShadowMatrix(GLfloat shadowMatrix[4][4], const GLfloat groundPlane[4], const GLfloat lightPos[4]);


#endif
