#include "raylib.h"

class JaxonVoxel {
private:
    
public:
    Model topm = LoadModel("jaxon/res/JVX-TOP.obj");
    Model btm = LoadModel("jaxon/res/JVX-BTM.obj");
    Model lft = LoadModel("jaxon/res/JVX-LFT.obj");
    Model rgt = LoadModel("jaxon/res/JVX-RGT.obj");
    Model frt = LoadModel("jaxon/res/JVX-FRT.obj");
    Model bck = LoadModel("jaxon/res/JVX-BCK.obj");
    Vector3 pos;
    bool RendTop;
    bool RendBottom;
    bool RendLeft;
    bool RendRight;
    bool RendFront;
    bool RendBack;
    JaxonVoxel(float dx, float dy, float dz, Texture2D left, Texture2D bottom, Texture2D right, Texture2D front, Texture2D back, Texture2D top, bool RendTop, bool RendBottom, bool RendLeft, bool RendRight, bool RendFront, bool RendBack) {
        lft.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = left;
        btm.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = bottom;
        rgt.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = right;
        frt.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = front;
        bck.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = back;
        topm.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = top;
        pos = {dx, dy, dz};
        this->RendTop = RendTop;
        this->RendBottom = RendBottom;
        this->RendLeft = RendLeft;
        this->RendRight = RendRight;
        this->RendFront = RendFront;
        this->RendBack = RendBack;
    }
    void DrawVoxel(Color col) {
        if (RendTop) {
            DrawModel(topm, pos, 0.5, col);
        }
        if (RendBottom) {
            DrawModel(btm, pos, 0.5, col);
        }
        if (RendLeft) {
            DrawModel(lft, pos, 0.5, col);
        }
        if (RendRight) {
            DrawModel(rgt, pos, 0.5, col);
        }
        if (RendFront) {
            DrawModel(frt, pos, 0.5, col);
        }
        if (RendBack) {
            DrawModel(bck, pos, 0.5, col);
        }
    }
};