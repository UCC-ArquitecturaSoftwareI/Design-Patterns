#include <iostream>

using namespace std;

// Legacy component
class LegacyRectangle {
private:
    int x1;
    int y1;
    int x2;
    int y2;

public:
    LegacyRectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
        cout << "Rectangulo Viejo creado:\n";
        cout << "             (" << x1 << "," << y1 << ") => (" << x2 << "," << y2 << ")" << endl;
    }

    void render() {
        cout << "Rectangulo Viejo dibuja:\n";
        cout << "             (" << x1 << "," << y1 << ") => (" << x2 << "," << y2 << ")" << endl;
    }
};

class Rectangle {
public:
    virtual void draw() = 0;
};


class RectangleAdapter : public Rectangle, private LegacyRectangle {
public:
    RectangleAdapter(int x, int y, int w, int h) :
            LegacyRectangle(x, y, x + w, y + h) {
        cout << "Creando rectangulo Nuevo:\n";
        cout << "             (" << x << ", " << y << ") -> (" << w << ", " << h << ")\n";
    }

    void draw() override {
        cout << "Dibujando rectangulo nuevo" << endl;
        render();
    }

};


int main() {
    Rectangle *r = new RectangleAdapter(120, 200, 90, 40);

    r->draw();
}
