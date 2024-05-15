# CMakeList.txt: projekt CMake dla elementu CMakeProject1, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (SortingAlgorithms "SortingAlgorithms.cpp" "SortingAlgorithms.h" "Algorithms.cpp" "Algorithms.h")

target_link_libraries(SortingAlgorithms ${CMAKE_SOURCE_DIR}/library/sfml-graphics.lib)
target_link_libraries(SortingAlgorithms ${CMAKE_SOURCE_DIR}/library/sfml-audio.lib)
target_link_libraries(SortingAlgorithms ${CMAKE_SOURCE_DIR}/library/sfml-network.lib)
target_link_libraries(SortingAlgorithms ${CMAKE_SOURCE_DIR}/library/sfml-system.lib)
target_link_libraries(SortingAlgorithms ${CMAKE_SOURCE_DIR}/library/sfml-window.lib)


include_directories(${CMAKE_SOURCE_DIR}/include)

set_property(TARGET SortingAlgorithms PROPERTY CXX_STANDARD 17)
set_property(TARGET SortingAlgorithms PROPERTY CXX_STANDARD_REQUIRED ON)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SortingAlgorithms PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
