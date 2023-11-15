#include <Object.hpp>
#include <CameraGame.hpp>

int Object::getState() {
    return 0;
}

std::string Object::selfAssess() {
    return "";
}

int Object::getID() {
    return -1;
}

std::string Object::getFile() {
    return file;
}

void Object::Process() {}

void Object::update(float x, float y) {}

void Object::removeArea(Vector2 root, float height, float width) {
    area-> removeArea(root, height, width);
}

void Object::setSpace(Vector3 space) {
    this -> space = space;
}

Vector3 Object::getSpace() {
    return space;
}

Object* Object::getAttachment() {
    return att;
}

void Object::deattach() {
    att = NULL;
}

void Object::attach(Object* o) {
    att = o;
    if (!o) return;
    o -> setPos(Vector3Add(getPos(), getSpace()));
    // knife transform, multiply matrix as parameters
}

BoundingBox Object::getBoundingBox() {
    return GetMeshBoundingBox(model.meshes[0]);
}

std::string Object::getDescription(){
    std::cout << "Object's description" << '\n';
    return description;
}

void Object::update(const char event) {
    
}

Vector3 Object::getPos() {
    return position;
} 
Vector3 Object::getAxis() {
    return axis;
}
float Object::getDirection() {
    return direction;
}
Model Object::getModel() {
    return model;
}
Vector3 Object::getScale() {
    return scale;
}
void Object::set() {
    activated = true;
}
void Object::unset() {
    activated = false;
}
void Object::setPos(Vector3 pos) {
      position = pos;
}
void Object::setAxis(Vector3 axis) {
    this -> axis = axis;
}
void Object::setDirection(float dir) {
    direction = dir;
}
void Object::setModel() {
    std::cerr << file << " loaded successfully!" << '\n'; 
    model = LoadModel(getFile().c_str());
    // model.transform = MatrixTranslate(axis.x, axis.y, axis.z);
    // model.transform = MatrixMultiply(MatrixRotateX(-PI/2), model.transform);
}
void Object::rotate(char rotation, float angle) {
    if (rotation == 'x') model.transform = MatrixMultiply(MatrixRotateX(angle), model.transform);
    else if (rotation == 'y') model.transform = MatrixMultiply(MatrixRotateY(angle), model.transform);
    else if (rotation == 'z') model.transform = MatrixMultiply(MatrixRotateZ(angle), model.transform);
}
void Object::setScale(Vector3 scale) {
    this -> scale = scale;
}
void Object::setFile(const std::string path) {
    file = path;
}
void Object::display() {
    // setModel();
    // BeginMode3D(getCamera());
    DrawModelEx(model, position, axis, direction, scale, WHITE);
    // DrawBoundingBox(getBoundingBox(), GREEN);
    // DrawGrid(50, 1);
    // EndMode3D();
}
void Object::setCamera() {
    cam = *CameraGame::getCamera();
}
Camera3D Object::getCamera() {
    setCamera();
    return cam;
}