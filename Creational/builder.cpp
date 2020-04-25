#include <iostream>
#include <vector>

using namespace std;

class DocumentBuilder {
protected:
    string result;
public:
    virtual DocumentBuilder &addTitle1(string t) = 0;

    virtual DocumentBuilder &addTitle2(string t) = 0;

    virtual DocumentBuilder &addLista(vector<string> items) = 0;

    string getResult() {
        return result;
    }
};

class HTMLDocument : public DocumentBuilder {
public:
    DocumentBuilder &addTitle1(string t) override {
        result += "<h1>" + t + "</h1>\n";
        return *this;
    }

    DocumentBuilder &addTitle2(string t) override {
        result += "<h2>" + t + "</h2>\n";
        return *this;
    }

    DocumentBuilder &addLista(vector<string> items) override {
        result += "<ul>\n";
        for (const auto &i: items) {
            result += "    <li>" + i + "</li>\n";
        }
        result += "</ul>\n";
        return *this;
    }
};


class MarkDownBuilder : public DocumentBuilder {
public:
    DocumentBuilder &addTitle1(string t) override {
        result += "# " + t + "\n\n";


        
        return *this;
    }

    DocumentBuilder &addTitle2(string t) override {
        result += "## " + t + "\n\n";
        return *this;
    }

    DocumentBuilder &addLista(vector<string> items) override {
        result += "\n";
        for (const auto &i: items) {
            result += "* " + i + "\n";
        }
        result += "\n";



        return *this;
    }
};

class Director {
    DocumentBuilder &builder;
public:
    Director(DocumentBuilder &builder) : builder(builder) {}

    void construct() {
        builder.addTitle1("Patrones de diseño").addTitle2("Builder")
        .addLista({"Motivación", "Intención", "Aplicabilidad", "Estructura"})
        .addTitle2("Motivación");
    }
};


int main() {
    HTMLDocument miBuilder;
    Director dire(miBuilder);
    dire.construct();

    cout << miBuilder.getResult();

    return 0;
}
