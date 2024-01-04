#include <Storer.hpp>

void TrashBin::Process() {
    if (ks) {
        KitchenState* tmp = ks -> getState(state);
        if (tmp) {
        tmp -> setDisplay();
    }   
    }
    // if (state == State::rest) {
    //     setFile("fridge1.glb");
    //     setAxis({1.0f, 0.0f, 0.0f});
    //     setDirection(90.0f);
    //     setPos({-7.0f, -4.0f, 4.0f});
    //     setScale({2.7f, 2.7f, 2.7f});
    //     return;
    // }
    // setFile("fridge2.glb");
    // setAxis(Axis::Oz);
    // setDirection(-165.0f);
    // setPos({-5.0f, 3.0f, 4.0f});
    // setScale({3.0f, 3.0f, 3.0f});
    // std::cerr << "Opening State" << '\n';
    if (state != State::functioning) return;
    std::cerr << "Functioning State" << '\n';
    Object* temp = m -> getAttachmentfrom();
    m -> drop();
    // temp = new Food(temp, fi -> get());
    // m -> assignBack(temp);
    delete temp;
    temp = nullptr;
    // state = State::rest;
    return;
}

void Storer_2::init() {
    std::ifstream in;
    in.open((food_description + "2.txt").c_str());
    if (!in.is_open()) {
        std::cout << "cannot open " << food_description << ".txt"<< '\n';
        return;
    }
    KitchenState* temp = nullptr;
    ks = loadState(in, temp);
    temp = ks;
    KitchenState* cont = loadState(in, temp);
    while (cont) {
        temp -> setNextState(cont);
        temp = temp -> getNextState();
        cont = loadState(in, temp);
    };
}

std::string Storer::getFile() {
    // std::cout << state << '\n';
    // std::cout << ks -> getState(state) -> getFile() << '\n';
    ks -> getState(state) -> setDisplay();
    return ks -> getState(state) -> getFile();
}

KitchenState* Storer::loadState(std::ifstream &in, KitchenState* &ks) {
    int cont;
    in >> cont;
    if (cont == -1) {
        in.close();
        return nullptr;
    }
    int state = cont;
    std::string file; in >> file;
    char c_axis; in >> c_axis;
    Vector3 axis;
    if (c_axis == 'x') axis = Axis::Ox;
    else if (c_axis == 'y') axis = Axis::Oy;
    else if (c_axis == 'z') axis = Axis::Oz;
    float direction;
    in >> direction;
    float x, y, z;
    in >> x >> y >> z;
    Vector3 scale = {x, y, z};
    in >> x >> y >> z;
    Vector3 pos = {x, y, z};
    float rx; in >> rx;
    float ry; in >> ry;
    float width; in >> width;
    float height; in >> height;
    KitchenState* temp = new KitchenState(this, state, file, axis, direction, scale, pos, rx, ry, width, height);
    // Storer::ks = ks;
    return temp;
}

// initialize with map and mediator, tightly coupling

void Storer::init() {
    std::ifstream in;
    in.open((food_description + ".txt").c_str());
    if (!in.is_open()) {
        std::cout << "cannot open " << food_description << ".txt"<< '\n';
        return;
    }
    KitchenState* temp = nullptr;
    ks = loadState(in, temp);
    temp = ks;
    KitchenState* cont = loadState(in, temp);
    while (cont) {
        temp -> setNextState(cont);
        temp = temp -> getNextState();
        cont = loadState(in, temp);
    };
}

void Storer::display() {
    setModel();
    if (model) DrawModelEx(*model, position, axis, direction, scale, WHITE);
}

void Storer::setMediator(Mediator* m) {
    this -> m = m;
    m -> registerObject(this);
}

void Storer::update(float x, float y) {
    // if (state == State::functioning) {
    //     if (isInArea(x, y) && IsKeyPressed(KEY_SPACE)) state = State::open;
    //     return;
    // }
    state = State::rest;
    if (isInArea(x, y)) {
        state = State::activated;
        if (IsKeyPressed(KEY_RIGHT) && fi) fi -> next();
        if (IsKeyPressed(KEY_LEFT) && fi) fi -> back();
        displayFoodList();
    }
    if (isInArea(x, y) && IsKeyPressed(KEY_SPACE)) {
        state = State::functioning;
    }
    return;
}

void Storer::update(char key) {
    // if (isInArea(x, y) && key == KEY_RIGHT) fi -> next();
    // how to let this store receive a lot of/ any piece information it wants  in the update function and we do not have to make many update functions
    // pull information mode
    // update space key associated to controller but not just in storer or cooker...
    // controller -> all control
}

bool Storer::isInArea(float x, float y) {
    return area -> isInArea(x, y);
}

void Storer::displayFoodList() {
    if (fi) fi -> display();
}

void Storer::Process() {
    if (ks) {
        KitchenState* tmp = ks -> getState(state);
        if (tmp) {
        tmp -> setDisplay();
    }   
    }
    // if (state == State::rest) {
    //     setFile("fridge1.glb");
    //     setAxis({1.0f, 0.0f, 0.0f});
    //     setDirection(90.0f);
    //     setPos({-7.0f, -4.0f, 4.0f});
    //     setScale({2.7f, 2.7f, 2.7f});
    //     return;
    // }
    // setFile("fridge2.glb");
    // setAxis(Axis::Oz);
    // setDirection(-165.0f);
    // setPos({-5.0f, 3.0f, 4.0f});
    // setScale({3.0f, 3.0f, 3.0f});
    // std::cerr << "Opening State" << '\n';
    if (state != State::functioning) return;
    std::cerr << "Functioning State" << '\n';
    Object* temp = m -> getAttachmentfrom();
    m -> drop();
    temp = new Food(temp, fi -> get());
    m -> assignBack(temp);
    // state = State::rest;
    return;
}

