#include <MediatorChecker.hpp>

void MediatorChecker::setChef(ControllableObject* chef) {
    this -> chef = chef;
}

void MediatorChecker::notifyChecker(std::string description) {
    checker -> update(description);
    std::cerr << "Notify checker" << std::endl;
}

void MediatorChecker::drop() {
    att = NULL;
}

Object* MediatorChecker::getAttachment() {
    return att;
}

Object* MediatorChecker::getAttachmentfrom() {
    att = chef -> getAttachment();
    chef -> deattach();
    return att;
}

void MediatorChecker::notifyObjects() {
    if (!(checker -> isTimeleft())) {
        // call destructor for this mediator;
        // std::cout << "end game" << std::endl;
        return;
    }
    for (int i = 0; i < obj.size(); i++) {
        // obj[i] -> update(getChefX(), getChefY());
        if (obj[i] -> getState() != Customers::outdated) obj[i] -> Process();
        // if (obj[i] -> getState() == Customers::outdated) {
        //     notifyChecker(obj[i] -> selfAssess());
        //     deregisterObject(obj[i] -> getID());
        //     i--;
        // } // destroy obj by holder, deregister
    }
}

float MediatorChecker::getChefX() {
    return chef -> getPos().x;
}

float MediatorChecker::getChefY() {
    return chef -> getPos().y;
}

void MediatorChecker::deregisterObject(int id) {
    for (int i = 0; i < obj.size(); i++) {
        if (obj[i] -> getID() == id) {
            obj.erase(obj.begin() + i);
            std::cerr << "erased" << std::endl;
            return;
        }
    }
}

void MediatorChecker::registerObject(Object* o) {
    obj.push_back(o); // caution of null
}