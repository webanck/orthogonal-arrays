# in order to propoer work, you have to set this env variable to point to your Qt install dir
# CMAKE_PREFIX_PATH
project(orthogonal_arrays)

set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 2.8.12)



# executable
include_directories(include)
#aux_source_directory(src)
add_executable(orthogonal_arrays
	src/Misc.cpp
	src/OA.cpp
	src/OACMJND.cpp
	src/main.cpp
)
