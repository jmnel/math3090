cmake_minimum_required( VERSION 3.9.2 FATAL_ERROR )
project( math3090-assignment1 VERSION 0.1 LANGUAGES CXX )

set( CMAKE_CXX_COMPILER_LAUNCHER )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${math3090-assignment1_SOURCE_DIR}/../bin/ )
#set( CMAKE_MODULE_PATH ${Math4171_SOURCE_DIR}/../cmake/modules )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

# Run `find_package` modules here for dependencies
#find_package(PythonLibs 3.6.2 REQUIRED )
#target_include_directories( Math4171 PRIVATE ${PYTHON_INCLUDE_DIRS} )
#find_package(Boost 1.64 COMPONENTS iostreams system filesystem REQUIRED )

#add_subdirectory( ./arcmath )
#add_subdirectory( ./arcpython )
#add_subdirectory( ./arcplot )
#add_subdirectory( ./assignment1-src )
add_subdirectory( ./coffee )
