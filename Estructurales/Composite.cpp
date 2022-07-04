#include <iostream>
#include <vector>

using namespace std;

class GraphicObject {
public:
    int x;
    int y;

    virtual void draw() = 0;
};

class Circle : public GraphicObject {
public:
    void draw() override {
        cout << "Circle: " << x << ", " << y << endl;
    }
};

class Square : public GraphicObject {
public:
    void draw() override {
        cout << "Square: " << x << ", " << y << endl;
    }
};

class Group : public GraphicObject {
    vector<GraphicObject *> shapes;

public:
    void addShape(GraphicObject *sh) {
        shapes.push_back(sh);
    }

    void deleteShape(GraphicObject *sh) {

    }

    void getShape(int id) {

    }

    void draw() override {
        cout << "Group: " << x << ", " << y << endl;
        for (auto s: shapes) {
            cout << "     ";
            s->draw();
        }
    }
};


int main() {
    Group raiz;
    Circle c1, c2;
    Square s1, s2;

    raiz.addShape(&c1);
    raiz.addShape(&c2);
    raiz.addShape(&s1);
    raiz.addShape(&s2);

    raiz.x = 200;
    raiz.y = 200;
    c1.x = 250;
    c2.x = 270;
    s1.x = 100;
    s2.x = 300;
    c2.y = 250;
    c1.y = 270;
    s2.y = 100;
    s1.y = 300;

    raiz.draw();


}