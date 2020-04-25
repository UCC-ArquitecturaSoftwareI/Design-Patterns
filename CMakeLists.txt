cmake_minimum_required(VERSION 3.15)
project(Creacionales)

set(CMAKE_CXX_STANDARD 17)

add_executable(Builder Creational/builder.cpp)
add_executable(Singleton Creational/singleton.cpp)
add_executable(FactoryMethod Creational/factory_method.cpp)
add_executable(AbstractFactory Creational/abstract_factory.cpp)
add_executable(Prototype Creational/prototype.cpp)


add_executable(Adapter Estructurales/adapter.cpp)
add_executable(Bridge Estructurales/bridge.cpp)