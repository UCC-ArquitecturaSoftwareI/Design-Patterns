#include <iostream>

using namespace std;

class Shape {

public:
    virtual void draw() = 0;
};

class Circulo : public Shape {
    float radio;
public:
    Circulo(float radio) : radio(radio) {}

    void draw() override {
        cout << "Soy un Circulo de radio " << radio;
    }
};

class Cuadrado : public Shape {
    float lado;
public:
    Cuadrado(float lado) : lado(lado) {}

    void draw() override {
        cout << "Soy un Cuadrado de radio " << lado;
    }
};

class ShapeColor : public Shape {
    string color;
    Shape &shape;
public:
    ShapeColor(const string &color, Shape &shape) : color(color), shape(shape) {}

    void draw() override {
        shape.draw();
        cout << " de color " << color;
    }
};

class ShapeTransparente : public Shape{
    int transp;
    Shape &shape;

public:
    ShapeTransparente(int transp, Shape &shape) : transp(transp), shape(shape) {}

    void draw() override {
        shape.draw();
        cout << " transparente al " << transp << "%";
    }
};

int main() {

    Circulo c(20);
    Cuadrado cuadrado(10);

    c.draw();
    cout << endl;
    cuadrado.draw();
    cout << endl;

    ShapeColor scolor("rojo", c);

    scolor.draw();
    cout << endl;

    ShapeTransparente strap(50, cuadrado);

    strap.draw();
    cout << endl;

    ShapeTransparente circulo_rojo_transparente(20, scolor);

    circulo_rojo_transparente.draw();
    cout << endl;

    return 0;
}
