cmake_minimum_required(VERSION 3.17)
project(css343lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(css343lab4
        actionFactory.h
        author.h
        bintree.cpp
        bintree.h
        book.h
        checkout.h
        childrensBook.h
        date.h
        displayHistory.h
        displayLibrary.h
        fiction.h
        item.h
        itemFactory.h
        library.h
        main.cpp
        nodedata.cpp
        nodedata.h
        patron.h
        patronAction.h
        periodicals.h
        person.h
        return.h)
