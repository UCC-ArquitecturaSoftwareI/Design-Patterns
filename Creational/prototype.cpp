#include <iostream>
#include <vector>
using namespace std;

class Shape{
private:
    Shape(const string &type) : type(type) {}

public:
    string type;

    Shape() {

    }

    Shape *clone(){
        return new Shape(type);
    }
};



int main() {
    Shape circulo;
    Shape rectangulo;

    circulo.type = "Circulo";
    rectangulo.type= "Rectangulo";

    Shape *cir = circulo.clone();
    Shape *rec = rectangulo.clone();


    cout << cir->type << endl;
    cout << rec->type << endl;


    return 0;
}
