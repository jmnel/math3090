# ---------------------------------------------------
# -- CMakeLists.txt for `arcplot` static library --
# ---------------------------------------------------
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_FLAGS "-Wall -Wextra" )

set( COFFEE_SRC 
    ChangingRoomTemp.cpp
    Common.cpp
    Main.cpp
    WhenToAddMilk.cpp )

include_directories( ${Boost_INCLUDE_DIR} )
add_executable( coffee ${COFFEE_SRC} )

set( DEBUG_FLAGS "-Wall" "-Wextra" "-O3" )
target_compile_options( coffee PUBLIC ${DEBUG_FLAGS} )

target_link_libraries( coffee LINK_PUBLIC ${Boost_LIBRARIES} )
include_directories( ../gnuplot-iostream )
