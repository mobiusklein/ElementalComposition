# CMakeList.txt : CMake project for ChemicalCompostion, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 11)

set(sources_list_h
Element.h
PeriodicTable.h
ElementalComposition.h)

set(sources_list_cpp
Element.cpp
PeriodicTable.cpp
ElementalComposition.cpp)

add_library (ChemicalCompostion ${sources_list_h} ${sources_list_cpp})
set_target_properties(ChemicalCompostion PROPERTIES LINKER_LANGUAGE CXX)
add_executable (ChemicalCompostionTest "Test.cpp")
target_link_libraries(ChemicalCompostionTest ChemicalCompostion)
