#include <iostream>
#include <vector>

using namespace std;

class Imagen {
protected:
    string data;
public:
    virtual string getData() = 0;
};

class ImagenGif : public Imagen {
public:
    ImagenGif(string file) {
        data = "Soy un Gif";
        cout << "Estoy leyendo un Gif " << file << endl;
    }

    string getData() override {
        return data;
    }
};

class ImagenJpg : public Imagen {

public:
    string getData() override {
        return data;
    }

    ImagenJpg(string file) {
        data = "Soy un JPG";
        cout << "Estoy leyendo un JPG " << file << endl;
    }
};

class ImagenFactory {
public:
    static Imagen *crearImagen(string file) {
        if (file.find(".gif") != string::npos) {
            return new ImagenGif(file);
        }
        if (file.find(".jpg") != string::npos) {
            return new ImagenJpg(file);
        }
    }
};


int main() {
    Imagen *img[3];

    int i = 0;
    for (auto file: {"auto.jpg", "moto.gif", "avion.jpg"}) {
        img[i] = ImagenFactory::crearImagen(file);
        i++;
    }

    for (auto im: img) {
        cout << im->getData() << endl;
    }

    return 0;
}
