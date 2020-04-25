#include <iostream>
#include <fstream>

using namespace std;

class SingletonLogger {
private:
    SingletonLogger() {
        log_file.open("log.txt");
    }

    ofstream log_file;

public:
    SingletonLogger(SingletonLogger const &) = delete;

    void operator=(SingletonLogger const &) = delete;

    static SingletonLogger &get() {
        static SingletonLogger logger;
        return logger;
    }

    void info(string i) {
        log_file << "Info: " << i << endl;
    }

    void error(string e) {
        log_file << "Error: " << e << endl;
    }

};

class Test1 {
public:
    Test1() {
        SingletonLogger::get().info("Creé Test1");
    }

    void error() {
        SingletonLogger::get().error("problema en Test1");
    }
};

class Test2 {
    SingletonLogger *logger;
public:
    Test2() {
        logger = &SingletonLogger::get();
        logger->info("Creé Test2");
    }

    void error() {
        logger->error("problema en Test2");
    }
};


int main() {
    SingletonLogger &log = SingletonLogger::get();

    log.info("Info desde main");

    Test1 t1;
    t1.error();
    Test2 t2;
    t2.error();
    t1.error();
    t1.error();
    t1.error();
    t1.error();
    t1.error();
    t1.error();


    return 0;
}
