cmake_minimum_required(VERSION 3.15)
project(Creacionales)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib 2.6 QUIET) # Let CMake search for a raylib-config.cmake

add_executable(Builder Creational/builder.cpp)
add_executable(Singleton Creational/singleton.cpp)
add_executable(FactoryMethod Creational/factory_method.cpp)
add_executable(AbstractFactory Creational/abstract_factory.cpp)
add_executable(Prototype Creational/prototype.cpp)


add_executable(Adapter Estructurales/adapter.cpp )
add_executable(Bridge Estructurales/bridge.cpp)
add_executable(Composite Estructurales/Composite.cpp)
add_executable(Decorator Estructurales/Decorator.cpp)

add_executable(Flyweight Estructurales/Flyweight.cpp)
