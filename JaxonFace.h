#ifndef JAXON_FACE_H
#define JAXON_FACE_H

#include "raylib.h"

class JaxonFace {
private:
    Texture2D VoxelTexture; // Field to store the texture

public:
    Vector3 pos;
    float scl;
    Mesh plane;
    Model mdl;

    // Constructors
    JaxonFace(float dx, float dy, float dz);
    JaxonFace(float dx, float dy, float dz, Texture2D tex);
    JaxonFace();

    // Setter for VoxelTexture that supports chaining
    JaxonFace& VoxelTextureSetter(Texture2D texture);

    // Method to draw the face
    void DrawFace(Color col);
};

#endif // JAXON_FACE_H
