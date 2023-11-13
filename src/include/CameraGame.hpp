#pragma once
#include "Libraries.hpp"

class CameraGame {
private: 
    CameraGame() {}
    static Camera3D* cam;
public: 
    static Camera3D* getCamera()  {
        if (cam) return (cam);
        cam = new Camera3D();
        cam -> position = (Vector3){ -3.0f, -30.0f, 20.0f }; // Camera position
        cam -> target = (Vector3){ -3.0f, 0.0f, 0.0f };      // Camera looking at point
        cam -> up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
        cam -> fovy = 45.0f;                                // Camera field-of-view Y
        cam -> projection = CAMERA_PERSPECTIVE;   
        return (cam);   
    }
}; 
//singleton