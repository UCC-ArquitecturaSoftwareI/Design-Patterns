#include <iostream>
#include <vector>

using namespace std;

class Button {
public:
    virtual void draw() = 0;
};

class TextBox {
public:
    virtual void draw() = 0;
};


class LightButton : public Button {
public:
    void draw() override {
        cout << "Dibujando un LightButton" << endl;
    }
};

class DarkButton : public Button {
public:
    void draw() override {
        cout << "Dibujando un DarkButton" << endl;
    }
};


class LightTextBox : public TextBox {
public:
    void draw() override {
        cout << "Dibujando un LightTextBox" << endl;
    }
};

class DarkTextBox : public TextBox {
public:
    void draw() override {
        cout << "Dibujando un DarkTextBox" << endl;
    }
};

class ThemeFactory {
public:
    virtual Button *createButton() = 0;

    virtual TextBox *createTextBox() = 0;
};

class LightThemeFactory : public ThemeFactory {
public:
    Button *createButton() override {
        return new LightButton;
    }

    TextBox *createTextBox() override {
        return new LightTextBox;
    }
};

class DarkThemeFactory : public ThemeFactory {
public:
    Button *createButton() override {
        return new DarkButton;
    }

    TextBox *createTextBox() override {
        return new DarkTextBox;
    }
};


int main() {
    ThemeFactory *tf;
    int tema;

    cout << "Que tema prefiere" << endl;
    cout << "0. Claro" << endl;
    cout << "1. Oscuro" << endl;

    cin >> tema;

    if (tema == 0)
        tf = new LightThemeFactory;
    else
        tf = new DarkThemeFactory;

    Button *btn = tf->createButton();
    TextBox *tb = tf->createTextBox();

    btn->draw();
    tb->draw();


    return 0;
}
