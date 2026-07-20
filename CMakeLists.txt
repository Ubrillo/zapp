cmake_minimum_required(VERSION 4.2)
project(zapp)

set(CMAKE_CXX_STANDARD 20)

add_executable(zapp main.cpp
        card/card.cpp
        card/card.h
        Area/Area.cpp
        Area/Area.h
        Area/AreaTester.cpp
        Bridge/Bridge.cpp
        Bridge/Bridge.h
        Bridge/BridgeTester.cpp
        park/park.cpp
        park/park.h
        park/zapp.h
        park/parkTester.cpp
        park/parkUI.cpp
        card/TouristCard.h
        card/ChildCard.h
        card/TouristCard.cpp
        card/ChildCard.cpp
        card/CompanyCard.cpp
        card/CompanyCard.h)
