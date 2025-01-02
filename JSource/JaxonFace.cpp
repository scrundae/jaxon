#include "../headers/jaxon/JaxonFace.h"
#include <stdexcept>

// Constructor with position arguments
JaxonFace::JaxonFace(float dx, float dy, float dz)
    : pos{dx, dy, dz}, scl(1.0f), plane(GenMeshPlane(1.0f, 1.0f, 1, 1)),
      mdl(LoadModelFromMesh(plane)) {
}

JaxonFace::JaxonFace(float dx, float dy, float dz, Texture2D tex)
    : pos{dx, dy, dz}, scl(1.0f), plane(GenMeshPlane(1.0f, 1.0f, 1, 1)),
      VoxelTexture(tex),
      mdl(LoadModelFromMesh(plane)) {
}

// Default constructor
JaxonFace::JaxonFace() 
    : scl(1.0f), plane(GenMeshPlane(1.0f, 1.0f, 1, 1)),
      mdl(LoadModelFromMesh(plane)) {
}

// Setter for VoxelTexture with chaining support
JaxonFace& JaxonFace::VoxelTextureSetter(Texture2D texture) {
        this->VoxelTexture = texture; // Store the texture
        return *this; // Return the current JaxonFace instance for chaining
}

// Draw the face with a given color
void JaxonFace::DrawFace(Color col) {
    if (VoxelTexture.id != 0) { // Check if the texture is valid
        mdl.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = VoxelTexture;
        SetTextureFilter(mdl.materials[0].maps[MATERIAL_MAP_ALBEDO].texture, TEXTURE_FILTER_BILINEAR);
    }
    DrawModel(mdl, pos, scl, col);
    // DrawModelWires(mdl, pos, scl, DARKBLUE);
}
