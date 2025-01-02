#pragma once

#ifndef TEXTURES_H
#define TEXTURES_H

#include <stdlib.h>

#include <Windows.h>

#include <GL/freeglut.h>
#include <string>

// Function to load a texture
GLuint loadTexture(const std::string& filepath);

#endif // TEXTURES_H
