cmake_minimum_required(VERSION 3.0)
project(projeto-escultor)

add_executable(projeto-escultor 
               src/Main.cpp
               src/Sculptor.cpp
               src/PutVoxel.cpp
               src/CutVoxel.cpp
               src/PutBox.cpp
               src/CutBox.cpp
               src/PutSphere.cpp
               src/CutSphere.cpp
               src/PutEllipsoid.cpp
               src/CutEllipsoid.cpp
               )
set_target_properties(projeto-escultor PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)