#include "raylib.h"
#include <string>
namespace Axis {
    const Vector3 Ox = {1.0f, 0.0f, 0.0f};
    const Vector3 Oy = {0.0f, 1.0f, 0.0f};
    const Vector3 Oz = {1.0f, 0.0f, 1.0f};
}

// set a camera
class CameraGame {
private: 
    CameraGame() {}
    static Camera3D* cam;
public: 
    static Camera3D getCamera() {
        if (cam) return (*cam);
        cam = new Camera3D();
        cam -> position = (Vector3){ 0.0f, -30.0f, 20.0f };  // Camera position
        cam -> target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
        cam -> up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
        cam -> fovy = 45.0f;                                // Camera field-of-view Y
        cam -> projection = CAMERA_PERSPECTIVE;   
        return (*cam);   
    }
}; //singleton
class Object {
private: 
    std::string description;
    Vector3 activePos;
    bool activated;
    Vector3 position;
    Vector3 axis;
    Vector3 scale;
    float direction;
    std::string file;
    Model model;
    Camera3D cam;
public: 
    Object() {}
    Object(std::string file, Vector3 position, Vector3 axis, float direction, Vector3 scale): file(file), position(position), axis(axis), direction(direction), scale(scale), description("") {}
    Vector3 getPos() {
        return position;
    } 
    Vector3 getAxis() {
        return axis;
    }
    float getDirection() {
        return direction;
    }
    Model getModel() {
        return model;
    }
    Vector3 getScale() {
        return scale;
    }
    void set() {
        activated = true;
    }
    void unset() {
        activated = false;
    }
    void setPos(Vector3 pos) {
        position = pos;
    }
    void setAxis(Vector3 axis) {
        this -> axis = axis;
    }
    void setDirection(float dir) {
        direction = dir;
    }
    void setModel() {
        model = LoadModel(file.c_str());
    }
    void setScale(Vector3 scale) {
        this -> scale = scale;
    }
    virtual void setFile(const std::string path) {
        file = path;
    }
    // virtual void display();
    void display() {
        // setModel();
        BeginMode3D(getCamera());
        DrawModelEx(model, position, axis, direction, scale, WHITE);
        EndMode3D();
    }
    void setCamera() {
        cam = CameraGame::getCamera();
    }
    Camera3D getCamera() {
        setCamera();
        return cam;
    }
    // void animate() {}
};

class ObjectController {

};



class ControllableObject: public Object
{
private:
    std::string description;
    int moving;
    char left;
    char right;
    char up;
    char down;
    const float speed = 0.05f;
public:
    ControllableObject(): left('a'), right('d'), up('w'), down('s'), description("controllable") {}
    ControllableObject(char left, char right, char up, char down): left(left), right(right), up(up), down(down), description("controllable") {}
    void setKeyLeft(char x) {
        left = x;
    }
    void setKeyRight(char x) {
        right = x;
    }
    void setKeyUp(char x) {
        up = x;
    }
    void setKeyDown(char x) {
        down = x;
    }
    char keyLeft() {
        return left;
    }
    char keyRight() {
        return right;
    }
    char keyUp() {
        return up;
    }
    char keyDown() {
        return down;
    }
    void setLeft() {
        setDirection(getDirection() - 90.0f);
    }
    void setRight() {
        setDirection(getDirection() + 90.0f);
    }
    void setUp() {
        setDirection(getDirection() + 180.0f);
    }
    void setDown() {
        
    }
    void setMove() {

    }
};

// class KeyboardController {
//     Object obj;
//     cooker.invoke(material)
// };
// class Animation {};
// add an object controller, it will use position to track if to invoke which one, and let the object invocation do their things by Observer Pattern
// will I use a decorator pattern to attach a dish to a controllable object, and track down recursively to check all objects attached until you see a controllable, which interacts another way.
// 2 relationships: attachment material - controllable, material - cooker
// what about an object attach to another object - answered
// material - material display on manual choice
// attachable.attach(object) must have their space defined (where to attach), values to change the location of the attached.

class Cooker : public Object {};



