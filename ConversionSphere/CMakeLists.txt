cmake_minimum_required ( VERSION 2.6 )
project ( Projection )

# sources extension
set(SRCEXT "cpp")

# required packages
find_package (GeographicLib REQUIRED)
find_package ( OpenCV REQUIRED )

macro( config_project PROJNAME LIBNAME )
       include_directories( ${${LIBNAME}_INCLUDE_DIR} )
       target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()

add_definitions (${GeographicLib_DEFINITIONS})

include_directories (${GeographicLib_INCLUDE_DIRS}) 

add_executable (Projection main_conversion.cpp)

target_link_libraries (Projection ${GeographicLib_LIBRARIES} ${OpenCV_LIBS} ) 

