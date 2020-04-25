#include <iostream>
using namespace std;


class Renderer {
public:
    virtual void render_circle(float x, float y, float radio) = 0;
};

class Shape {
protected:
    Renderer &renderer;
public:
    Shape(Renderer &renderer) : renderer(renderer) {}

    virtual void draw() = 0;
};

class Circulo : Shape {
    float x, y, radio;
public:
    Circulo(Renderer &renderer, float x, float y, float radio) : Shape(renderer), x(x), y(y), radio(radio) {}

    void draw() override {
        renderer.render_circle(x, y, radio);
    }
};

class RasterRender : public Renderer{
    void render_circle(float x, float y, float radio) override {
        cout << "Raster de circulo " << x <<  " " << y << " " << radio << endl;
    }
};

class VectorRender : public Renderer{
    void render_circle(float x, float y, float radio) override {
        cout << "Vectorial de circulo " << x <<  " " << y << " " << radio << endl;
    }
};


int main() {
    RasterRender rr;
    Circulo r_cir(rr, 5 , 3 ,4);
    r_cir.draw();

    VectorRender vr;
    Circulo v_cir(vr, 50 , 30,4);
    v_cir.draw();

}