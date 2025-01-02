#pragma once

#ifndef OBJECTS_H
#define OBJECTS_H


void drawChandelier(float x, float y, float z);
void initializeSkyboxTextures(); 
void drawSkybox(float cameraX, float cameraY, float cameraZ);
void initializeTextures();
void drawFloor();
void drawWalls();
void drawTable(float x, float z);
void drawChair(float x, float z, float angle);
#endif
