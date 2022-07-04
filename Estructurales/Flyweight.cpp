#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <string.h>

using namespace std;


class Arbol {
    int id;
    int color;
    string *textura;
public:
    Arbol(int id, int color, string *textura) : id(id), color(color), textura(textura) {

    }

    void draw() {
        cout << textura << endl;
    };
};

int getValue();

void llenar(char *c, unsigned size, char l);

int main() {
    char tex1[32768];
    char tex2[32768];
    llenar(tex1, 32768, 'A');
    llenar(tex2, 32768, 'B');

    string s[] = {tex1,tex2};

    vector<Arbol> bosque;

    for (int i = 0; i < 1000000; i++) {
        bosque.emplace_back( 1,1, &s[i%2]);
    }

    cout << getValue() << "Kb";
    return 0;
}

void llenar(char *c, unsigned size, char l) {
    for (int i = 0; i < size; i++) {
        c[i] = l;
    }
    c[size - 1] = '\0';
}


int parseLine(char *line) {
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char *p = line;
    while (*p < '0' || *p > '9') p++;
    line[i - 3] = '\0';
    i = atoi(p);
    return i;
}

int getValue() { //Note: this value is in KB!
    FILE *file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL) {
        if (strncmp(line, "VmSize:", 7) == 0) {
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}