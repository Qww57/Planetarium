cmake_minimum_required ( VERSION 2.6 )
project ( Detection )

# sources extension
set(SRCEXT "cpp")

# required packages
find_package ( OpenCV REQUIRED )

macro( config_project PROJNAME LIBNAME )
       include_directories( ${${LIBNAME}_INCLUDE_DIR} )
       target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()

add_executable( Detection main.cpp detection_etoiles.cpp testRRDM.cpp writeText.cpp star.cpp utilitaires.cpp)

target_link_libraries(
    Detection
    ${OpenCV_LIBS}
)

