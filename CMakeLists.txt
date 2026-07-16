cmake_minimum_required(VERSION 4.2)
project(zapp)

set(CMAKE_CXX_STANDARD 20)

add_executable(zapp main.cpp
        Card/Card.cpp
        Card/Card.h
        Area/Area.cpp
        Area/Area.h
        Area/AreaTester.cpp
        Card/CardTester.cpp
        Bridge/Bridge.cpp
        Bridge/Bridge.h
        Bridge/BridgeTester.cpp
        park/park.cpp
        park/park.h
        park/zapp.h
        park/parkTester.cpp
        park/parkUI.cpp)
