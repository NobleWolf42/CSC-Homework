cmake_minimum_required(VERSION 3.24)
project(CSC-Homework)

set(CMAKE_CXX_STANDARD 17)

set(CXXTEST_INCLUDE_DIR c:/cxxtest)

set(CXXTEST_PYTHON_TESTGEN_EXECUTABLE c:/cxxtest/bin/cxxtestgen)

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    #[[CXXTEST_ADD_TEST(unittest runner.cpp  # THIS IS GENERATED BUT YOU NEED TO ADD IT HERE
            ${CMAKE_CURRENT_SOURCE_DIR}/Templates/cxxtest/Restaurant.cpp  # add source files
            ${CMAKE_CURRENT_SOURCE_DIR}/Templates/cxxtest/newCxxTest.h  # YOUR TEST DESCRIPTION FILE
            )]]

    #[[CXXTEST_ADD_TEST(7-29test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.29\ Triangle\ area\ comparison/Triangle.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.29\ Triangle\ area\ comparison/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(7-30test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.30\ Car\ value/Car.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.30\ Car\ value/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(7-31test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.31\ Winning\ team/Team.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.31\ Winning\ team/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(7-32test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.32\ Nutritional\ information/FoodItem.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.32\ Nutritional\ information/TestCases.h
            )]]
    
    #[[CXXTEST_ADD_TEST(7-33test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.33\ Artwork\ label/Artwork.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.33\ Artwork\ label/Artist.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.33\ Artwork\ label/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(7-38test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.38\ Online\ shopping\ cart\ Part\ 1/ItemToPurchase.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.38\ Online\ shopping\ cart\ Part\ 1/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(7-39test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.39\ Online\ shopping\ cart\ Part\ 2/ItemToPurchase.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.39\ Online\ shopping\ cart\ Part\ 2/ShoppingCart.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.39\ Online\ shopping\ cart\ Part\ 2/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(7-27test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.27\ CH07\ EXAM1\ SP24/Address.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 7/7.27\ CH07\ EXAM1\ SP24/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(6-72test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 6/6.72\ Two\ dimensional\ array\ using\ pointer\ arithmetic/TwoDArray.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 6/6.72\ Two\ dimensional\ array\ using\ pointer\ arithmetic/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(8-15test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.15\ Playlist/PlaylistNode.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.15\ Playlist/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(8-17test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.17\ Mileage\ tracker\ for\ a\ runner/MileageTrackerNode.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.17\ Mileage\ tracker\ for\ a\ runner/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(8-19test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.19\ Inventory2\ \(linked\ lists\ -\ insert\ at\ the\ front\ of\ a\ list\)/InventoryNode.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.19\ Inventory2\ \(linked\ lists\ -\ insert\ at\ the\ front\ of\ a\ list\)/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(8-22test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.22\ Grocery\ shopping\ list2\ \(linked\ list\ -\ inserting\ at\ the\ end\ of\ a\ list\)/ItemNode.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.22\ Grocery\ shopping\ list2\ \(linked\ list\ -\ inserting\ at\ the\ end\ of\ a\ list\)/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(8-29test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.29\ Exam2\ CH08\ SP24/PhoneList.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.29\ Exam2\ CH08\ SP24/PhoneNode.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 8/8.29\ Exam2\ CH08\ SP24/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(9-22test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 9/9.22\ Overload\ operator\ \(greaterthangreaterthan\)\ for\ ostream/Number.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 9/9.22\ Overload\ operator\ \(greaterthangreaterthan\)\ for\ ostream/TestCases.h
            )]]

    #[[CXXTEST_ADD_TEST(9-24test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/Book.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/BookNode.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/VectorLibrary.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/LinkedListLibrary.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/TestCases.h
            )]]

    CXXTEST_ADD_TEST(9-31test runner.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 9/9.31\ CH09\ EXAM\ SP24/Course.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 9/9.31\ CH09\ EXAM\ SP24/Student.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CSC\ 109-01/Chapter\ 9/9.31\ CH09\ EXAM\ SP24/TestCases.h
            )

endif()

#[[add_executable(CH07EXAMPLE1 runner.cpp
        Templates/cxxtest/Restaurant.cpp
        Templates/cxxtest/Restaurant.h)]]

#[[add_executable(CH07-29 runner.cpp
        CSC\ 109-01/Chapter\ 7/7.29\ Triangle\ area\ comparison/Triangle.cpp
        CSC\ 109-01/Chapter\ 7/7.29\ Triangle\ area\ comparison/Triangle.h)]]

#[[add_executable(CH07-30 runner.cpp
        CSC\ 109-01/Chapter\ 7/7.30\ Car\ value/Car.cpp
        CSC\ 109-01/Chapter\ 7/7.30\ Car\ value/Car.h)]]

#[[add_executable(CH07-31 runner.cpp
        CSC\ 109-01/Chapter\ 7/7.31\ Winning\ team/Team.cpp
        CSC\ 109-01/Chapter\ 7/7.31\ Winning\ team/Team.h)]]

#[[add_executable(CH07-32 runner.cpp
        CSC\ 109-01/Chapter\ 7/7.32\ Nutritional\ information/FoodItem.cpp
        CSC\ 109-01/Chapter\ 7/7.32\ Nutritional\ information/FoodItem.h)]]

#[[add_executable(CH07-33 runner.cpp
        CSC\ 109-01/Chapter\ 7/7.33\ Artwork\ label/Artist.cpp
        CSC\ 109-01/Chapter\ 7/7.33\ Artwork\ label/Artist.h
        CSC\ 109-01/Chapter\ 7/7.33\ Artwork\ label/Artwork.cpp
        CSC\ 109-01/Chapter\ 7/7.33\ Artwork\ label/Artwork.h)]]

#[[add_executable(CH07-38 runner.cpp
        CSC\ 109-01/Chapter\ 7/7.38\ Online\ shopping\ cart\ Part\ 1/ItemToPurchase.cpp
        CSC\ 109-01/Chapter\ 7/7.38\ Online\ shopping\ cart\ Part\ 1/ItemToPurchase.h)]]

#[[add_executable(CH07-39 runner.cpp
        CSC\ 109-01/Chapter\ 7/7.39\ Online\ shopping\ cart\ Part\ 2/ShoppingCart.cpp
        CSC\ 109-01/Chapter\ 7/7.39\ Online\ shopping\ cart\ Part\ 2/ShoppingCart.h
        CSC\ 109-01/Chapter\ 7/7.39\ Online\ shopping\ cart\ Part\ 2/ItemToPurchase.cpp
        CSC\ 109-01/Chapter\ 7/7.39\ Online\ shopping\ cart\ Part\ 2/ItemToPurchase.h)]]

#[[add_executable(CH07-27 
        CSC\ 109-01/Chapter\ 7/7.27\ CH07\ EXAM1\ SP24/main.cpp
        CSC\ 109-01/Chapter\ 7/7.27\ CH07\ EXAM1\ SP24/Address.cpp
        CSC\ 109-01/Chapter\ 7/7.27\ CH07\ EXAM1\ SP24/Address.h)]]

#[[add_executable(CH06-72 
        CSC\ 109-01/Chapter\ 6/6.72\ Two\ dimensional\ array\ using\ pointer\ arithmetic/main.cpp
        CSC\ 109-01/Chapter\ 6/6.72\ Two\ dimensional\ array\ using\ pointer\ arithmetic/TwoDArray.cpp
        CSC\ 109-01/Chapter\ 6/6.72\ Two\ dimensional\ array\ using\ pointer\ arithmetic/TwoDArray.h)]]

#[[add_executable(CH08-15 
        CSC\ 109-01/Chapter\ 8/8.15\ Playlist/main.cpp
        CSC\ 109-01/Chapter\ 8/8.15\ Playlist/PlaylistNode.cpp
        CSC\ 109-01/Chapter\ 8/8.15\ Playlist/PlaylistNode.h)]]

#[[add_executable(CH08-17 
        CSC\ 109-01/Chapter\ 8/8.17\ Mileage\ tracker\ for\ a\ runner/main.cpp
        CSC\ 109-01/Chapter\ 8/8.17\ Mileage\ tracker\ for\ a\ runner/MileageTrackerNode.cpp
        CSC\ 109-01/Chapter\ 8/8.17\ Mileage\ tracker\ for\ a\ runner/MileageTrackerNode.h)]]

#[[add_executable(CH08-19 
        CSC\ 109-01/Chapter\ 8/8.19\ Inventory2\ \(linked\ lists\ -\ insert\ at\ the\ front\ of\ a\ list\)/main.cpp
        CSC\ 109-01/Chapter\ 8/8.19\ Inventory2\ \(linked\ lists\ -\ insert\ at\ the\ front\ of\ a\ list\)/InventoryNode.cpp
        CSC\ 109-01/Chapter\ 8/8.19\ Inventory2\ \(linked\ lists\ -\ insert\ at\ the\ front\ of\ a\ list\)/InventoryNode.h)]]

#[[add_executable(CH08-22 
        CSC\ 109-01/Chapter\ 8/8.22\ Grocery\ shopping\ list2\ \(linked\ list\ -\ inserting\ at\ the\ end\ of\ a\ list\)/main.cpp
        CSC\ 109-01/Chapter\ 8/8.22\ Grocery\ shopping\ list2\ \(linked\ list\ -\ inserting\ at\ the\ end\ of\ a\ list\)/ItemNode.cpp
        CSC\ 109-01/Chapter\ 8/8.22\ Grocery\ shopping\ list2\ \(linked\ list\ -\ inserting\ at\ the\ end\ of\ a\ list\)/ItemNode.h)]]

#[[add_executable(CH08-29 
        CSC\ 109-01/Chapter\ 8/8.29\ Exam2\ CH08\ SP24/main.cpp
        CSC\ 109-01/Chapter\ 8/8.29\ Exam2\ CH08\ SP24/PhoneNode.cpp
        CSC\ 109-01/Chapter\ 8/8.29\ Exam2\ CH08\ SP24/PhoneNode.h
        CSC\ 109-01/Chapter\ 8/8.29\ Exam2\ CH08\ SP24/PhoneList.cpp
        CSC\ 109-01/Chapter\ 8/8.29\ Exam2\ CH08\ SP24/PhoneList.h)]]

#[[add_executable(CH09-22 
        CSC\ 109-01/Chapter\ 9/9.22\ Overload\ operator\ \(greaterthangreaterthan\)\ for\ ostream/main.cpp
        CSC\ 109-01/Chapter\ 9/9.22\ Overload\ operator\ \(greaterthangreaterthan\)\ for\ ostream/Number.cpp
        CSC\ 109-01/Chapter\ 9/9.22\ Overload\ operator\ \(greaterthangreaterthan\)\ for\ ostream/Number.h)]]

#[[add_executable(CH09-24 
        CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/main.cpp
        CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/Book.cpp
        CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/Book.h
        CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/BookNode.cpp
        CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/BookNode.h
        CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/VectorLibrary.cpp
        CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/VectorLibrary.h
        CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/LinkedListLibrary.cpp
        CSC\ 109-01/Chapter\ 9/9.24\ Library\ book\ sorting\ \(Long\ Long\ ISBN\)/LinkedListLibrary.h)]]

add_executable(CH09-31 
        CSC\ 109-01/Chapter\ 9/9.31\ CH09\ EXAM\ SP24/main.cpp
        CSC\ 109-01/Chapter\ 9/9.31\ CH09\ EXAM\ SP24/Course.cpp
        CSC\ 109-01/Chapter\ 9/9.31\ CH09\ EXAM\ SP24/Course.h
        CSC\ 109-01/Chapter\ 9/9.31\ CH09\ EXAM\ SP24/Student.cpp
        CSC\ 109-01/Chapter\ 9/9.31\ CH09\ EXAM\ SP24/Student.h)