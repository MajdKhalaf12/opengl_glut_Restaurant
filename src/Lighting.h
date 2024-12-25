#pragma once

#ifndef LIGHTING_H
#define LIGHTING_H


#include <stdlib.h>
#include <Windows.h>
#include <GL/glut.h>

void setupLighting();
void computeShadowMatrix(float shadowMat[4][4], const float groundplane[4], const float lightpos[4]);

#endif
