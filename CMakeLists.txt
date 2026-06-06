cmake_minimum_required(VERSION 4.1)
project(Program4)

set(CMAKE_CXX_STANDARD 20)

#Main
add_executable(Program4
        driver.cpp
        Movie.h
        Movie.cpp
        ComedyMovie.h
        ComedyMovie.cpp
        DramaMovie.h
        DramaMovie.cpp
        ClassicMovie.h
        ClassicMovie.cpp
        Transaction.h
        Transaction.cpp
        BorrowTransaction.h
        BorrowTransaction.cpp
        ReturnTransaction.h
        ReturnTransaction.cpp
        MovieList.h
        MovieList.cpp
        Inventory.h
        Inventory.cpp
        Customer.h
        Customer.cpp
        CustomerData.h
        CustomerData.cpp
        MovieFactory.h
        MovieFactory.cpp
        TransactionFactory.h
        TransactionFactory.cpp
        Company.h
        Company.cpp)

target_include_directories(Program4 PRIVATE ${CMAKE_SOURCE_DIR})

#Tests

#Movie Tests
add_executable(MovieTests
        Tests/MovieTests.cpp
        Movie.h
        Movie.cpp
        ComedyMovie.h
        ComedyMovie.cpp
        DramaMovie.h
        DramaMovie.cpp
        ClassicMovie.h
        ClassicMovie.cpp)

target_include_directories(MovieTests PRIVATE ${CMAKE_SOURCE_DIR})

# MovieList Tests
add_executable(MovieListTests
        Tests/MovieListTests.cpp
        MovieList.cpp
        MovieList.h
        Movie.cpp
        Movie.h
        ComedyMovie.cpp
        ComedyMovie.h
        DramaMovie.cpp
        DramaMovie.h
        ClassicMovie.cpp
        ClassicMovie.h
)

target_include_directories(MovieListTests PRIVATE ${CMAKE_SOURCE_DIR})

# Inventory Tests
add_executable(InventoryTests
        Tests/InventoryTests.cpp
        Movie.cpp
        ComedyMovie.cpp
        DramaMovie.cpp
        ClassicMovie.cpp
        MovieList.cpp
        Inventory.cpp)

target_include_directories(InventoryTests PRIVATE ${CMAKE_SOURCE_DIR})