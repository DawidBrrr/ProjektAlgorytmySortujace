cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# Aby pobraæ i skonfigurowaæ Google Test
FetchContent_MakeAvailable(googletest)

# Dodaj plik testowy
add_executable(SortingAlgorithmsTest1 SortingAlgorithmsTest1.cpp)

# Linkuj testy z bibliotek¹ SortingAlgorithmsLib i Google Test
target_link_libraries(SortingAlgorithmsTest1 SortingAlgorithmsLib gtest gtest_main)








# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)
#FETCHCONTENT_MAKEAVAILABLE(googletest)

#add_library(GTest::GTest INTERFACE IMPORTED)
#target_link_libraries(GTest::GTest INTERFACE gtest_main)

#add_executable(SortingAlgorithmsTest1 "SortingAlgorithmsTest1.cpp")

#target_link_libraries(SortingAlgorithmsTest1
 #PRIVATE
  #GTest::GTest
  #SortingAlgorithms)

