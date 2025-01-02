#include "raylib.h"

class JaxonVoxel {
private:
    
public:
    Model topm = LoadModel("res/jaxon/JVX-TOP.obj");
    Model btm = LoadModel("res/jaxon/JVX-BTM.obj");
    Model lft = LoadModel("res/jaxon/JVX-LFT.obj");
    Model rgt = LoadModel("res/jaxon/JVX-RGT.obj");
    Model frt = LoadModel("res/jaxon/JVX-FRT.obj");
    Model bck = LoadModel("res/jaxon/JVX-BCK.obj");
    Vector3 pos;
    JaxonVoxel(float dx, float dy, float dz, Texture2D left, Texture2D bottom, Texture2D right, Texture2D front, Texture2D back, Texture2D top) {
        lft.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = left;
        btm.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = bottom;
        rgt.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = right;
        frt.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = front;
        bck.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = back;
        topm.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = top;
        pos = {dx, dy, dz};
    }
    JaxonVoxel(Texture2D left, Texture2D bottom, Texture2D right, Texture2D front, Texture2D back, Texture2D top) {
        lft.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = left;
        btm.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = bottom;
        rgt.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = right;
        frt.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = front;
        bck.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = back;
        topm.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = top;
    }
    void DrawVoxel(Color col) {
        DrawModel(topm, pos, 0.5, col);
        DrawModel(btm, pos, 0.5, col);
        DrawModel(lft, pos, 0.5, col);
        DrawModel(rgt, pos, 0.5, col);
        DrawModel(frt, pos, 0.5, col);
        DrawModel(bck, pos, 0.5, col);
    }
};