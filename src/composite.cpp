#include <iostream>
#include <vector>

using namespace std;

class CItem {
protected:
    std::string name;
    bool isHidden;
public:
    CItem(std::string name) : name(name), isHidden(false) {}
    std::string getName() {
        return name;
    }
    virtual void add(CItem* item) {

    }
    virtual void print(bool isPrintHiddenItems) {

    }
    virtual CItem* findByName(std::string file_name) {

    }
    virtual CItem* removeByName(std::string file_name) {

    }
    virtual void setHidden(bool isHidden, bool isAlsoApplyToChildren) {

    }
};

class CFolder : public CItem {
private:
    std::vector <CItem*> items;
public:
    CFolder(std::string name) : CItem(name), items({}) {}
    void add(CItem* item) {
        items.push_back(item);
    }
    void print(bool isPrintHiddenItems) {
        for (int i = 0; i < items.size(); i++) {
            items[i] -> print(isPrintHiddenItems);
        }
    }
    CItem* findByName(std::string file_name) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i] -> getName() == (file_name)) return items[i];
        }
        for (int i = 0; i < items.size(); i++) {
            if (items[i] -> findByName(file_name)) return items[i];
        }
        return nullptr;
    }
    CItem* removeByName(std::string file_name) {
        for (auto it = items.begin(); it != items.end(); it++) {
            if ((*it) -> getName() == file_name) {
                CItem* temp = *it;
                items.erase(it);
                return temp;
            }
        }
        return nullptr;
    }
    void setHidden(bool isHidden, bool isAlsoApplyToChildren) {
        CItem::isHidden = isHidden;
        for (int i = 0; i < items.size(); i++) {
            items[i] -> setHidden(isHidden, isAlsoApplyToChildren);
        }
    }
};

class CFile : public CItem {
private:
    int number;
public:
    CFile(std::string name, int number) : CItem(name), number(number) {}
    void print(bool isPrintHiddenItems) {
        if (!isPrintHiddenItems && CItem::isHidden) {}
        else std::cout << CItem::getName() << '\n';
    }
    void setHidden(bool isHidden, bool isAlsoApplyToChildren) {
        CItem::isHidden = isHidden;
    }
    CItem* findByName(std::string file_name) {
        if (CItem::getName() == file_name) return this;
        return nullptr;
    }
};

int main() {
    CFolder C("C"); // (1)
    CFolder System("System");
    CFolder Windows("Windows");
    CFile a_txt("a.txt", 123); // (2)
    CFile b_doc("b.doc", 456);
    System.add(&a_txt); // (3)
    Windows.add(&b_doc);
    C.add(&System); // (4)
    C.add(&Windows);
    cout << "Content of folder C ->" << endl;
    bool isPrintHiddenItems = false;
    C.print(isPrintHiddenItems); // print hidden items or not? 1/0 (5)
    CItem* p = C.removeByName("System"); // return first removed item (6)
    cout << "Content of folder C afer removing folder System ->" << endl;
    C.print(false);
    p = C.findByName("b.doc"); // return first founded item (7)
    if (p != NULL) {
    cout << "b.doc is found in folder C" << endl;

    }
    else {
    cout << "b.doc is not found" << endl;
    }
    p = C.findByName("a.txt");
    if (p != NULL) {
    cout << "a.txt is found" << endl;
    }
    else {
    cout << "a.txt is not found" << endl;
    }
    p = C.findByName("Windows"); // (8)
    bool isHidden;
    bool isAlsoApplyToChildren;
    if (p != NULL) {
    cout << "Folder Windows is folder. Content of folder Windows ->" << endl;

    isHidden = true; isAlsoApplyToChildren = true;
    // set HIDDEN to folder p and do not change hidden attributes of its sub-items

    p->setHidden(isHidden, isAlsoApplyToChildren); // (9)
    p->print(true);

    // set HIDDEN to folder p and all its items
    isHidden = false; isAlsoApplyToChildren = false;
    p->setHidden(isHidden, isAlsoApplyToChildren); // (10)
    p->print(false);
    }
    else {
    cout << "Folder Windows is not found" << endl;
    }
return 0;
}