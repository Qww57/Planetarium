# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/brunathan/Téléchargements/Planetarium-master/Exemple

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build

# Include any dependencies generated for this target.
include CMakeFiles/Detection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Detection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Detection.dir/flags.make

CMakeFiles/Detection.dir/main.cpp.o: CMakeFiles/Detection.dir/flags.make
CMakeFiles/Detection.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Detection.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Detection.dir/main.cpp.o -c /home/brunathan/Téléchargements/Planetarium-master/Exemple/main.cpp

CMakeFiles/Detection.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Detection.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brunathan/Téléchargements/Planetarium-master/Exemple/main.cpp > CMakeFiles/Detection.dir/main.cpp.i

CMakeFiles/Detection.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Detection.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brunathan/Téléchargements/Planetarium-master/Exemple/main.cpp -o CMakeFiles/Detection.dir/main.cpp.s

CMakeFiles/Detection.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/Detection.dir/main.cpp.o.requires

CMakeFiles/Detection.dir/main.cpp.o.provides: CMakeFiles/Detection.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Detection.dir/build.make CMakeFiles/Detection.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Detection.dir/main.cpp.o.provides

CMakeFiles/Detection.dir/main.cpp.o.provides.build: CMakeFiles/Detection.dir/main.cpp.o

CMakeFiles/Detection.dir/detection_etoiles.cpp.o: CMakeFiles/Detection.dir/flags.make
CMakeFiles/Detection.dir/detection_etoiles.cpp.o: ../detection_etoiles.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Detection.dir/detection_etoiles.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Detection.dir/detection_etoiles.cpp.o -c /home/brunathan/Téléchargements/Planetarium-master/Exemple/detection_etoiles.cpp

CMakeFiles/Detection.dir/detection_etoiles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Detection.dir/detection_etoiles.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brunathan/Téléchargements/Planetarium-master/Exemple/detection_etoiles.cpp > CMakeFiles/Detection.dir/detection_etoiles.cpp.i

CMakeFiles/Detection.dir/detection_etoiles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Detection.dir/detection_etoiles.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brunathan/Téléchargements/Planetarium-master/Exemple/detection_etoiles.cpp -o CMakeFiles/Detection.dir/detection_etoiles.cpp.s

CMakeFiles/Detection.dir/detection_etoiles.cpp.o.requires:
.PHONY : CMakeFiles/Detection.dir/detection_etoiles.cpp.o.requires

CMakeFiles/Detection.dir/detection_etoiles.cpp.o.provides: CMakeFiles/Detection.dir/detection_etoiles.cpp.o.requires
	$(MAKE) -f CMakeFiles/Detection.dir/build.make CMakeFiles/Detection.dir/detection_etoiles.cpp.o.provides.build
.PHONY : CMakeFiles/Detection.dir/detection_etoiles.cpp.o.provides

CMakeFiles/Detection.dir/detection_etoiles.cpp.o.provides.build: CMakeFiles/Detection.dir/detection_etoiles.cpp.o

CMakeFiles/Detection.dir/testRRDM.cpp.o: CMakeFiles/Detection.dir/flags.make
CMakeFiles/Detection.dir/testRRDM.cpp.o: ../testRRDM.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Detection.dir/testRRDM.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Detection.dir/testRRDM.cpp.o -c /home/brunathan/Téléchargements/Planetarium-master/Exemple/testRRDM.cpp

CMakeFiles/Detection.dir/testRRDM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Detection.dir/testRRDM.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brunathan/Téléchargements/Planetarium-master/Exemple/testRRDM.cpp > CMakeFiles/Detection.dir/testRRDM.cpp.i

CMakeFiles/Detection.dir/testRRDM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Detection.dir/testRRDM.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brunathan/Téléchargements/Planetarium-master/Exemple/testRRDM.cpp -o CMakeFiles/Detection.dir/testRRDM.cpp.s

CMakeFiles/Detection.dir/testRRDM.cpp.o.requires:
.PHONY : CMakeFiles/Detection.dir/testRRDM.cpp.o.requires

CMakeFiles/Detection.dir/testRRDM.cpp.o.provides: CMakeFiles/Detection.dir/testRRDM.cpp.o.requires
	$(MAKE) -f CMakeFiles/Detection.dir/build.make CMakeFiles/Detection.dir/testRRDM.cpp.o.provides.build
.PHONY : CMakeFiles/Detection.dir/testRRDM.cpp.o.provides

CMakeFiles/Detection.dir/testRRDM.cpp.o.provides.build: CMakeFiles/Detection.dir/testRRDM.cpp.o

CMakeFiles/Detection.dir/writeText.cpp.o: CMakeFiles/Detection.dir/flags.make
CMakeFiles/Detection.dir/writeText.cpp.o: ../writeText.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Detection.dir/writeText.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Detection.dir/writeText.cpp.o -c /home/brunathan/Téléchargements/Planetarium-master/Exemple/writeText.cpp

CMakeFiles/Detection.dir/writeText.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Detection.dir/writeText.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brunathan/Téléchargements/Planetarium-master/Exemple/writeText.cpp > CMakeFiles/Detection.dir/writeText.cpp.i

CMakeFiles/Detection.dir/writeText.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Detection.dir/writeText.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brunathan/Téléchargements/Planetarium-master/Exemple/writeText.cpp -o CMakeFiles/Detection.dir/writeText.cpp.s

CMakeFiles/Detection.dir/writeText.cpp.o.requires:
.PHONY : CMakeFiles/Detection.dir/writeText.cpp.o.requires

CMakeFiles/Detection.dir/writeText.cpp.o.provides: CMakeFiles/Detection.dir/writeText.cpp.o.requires
	$(MAKE) -f CMakeFiles/Detection.dir/build.make CMakeFiles/Detection.dir/writeText.cpp.o.provides.build
.PHONY : CMakeFiles/Detection.dir/writeText.cpp.o.provides

CMakeFiles/Detection.dir/writeText.cpp.o.provides.build: CMakeFiles/Detection.dir/writeText.cpp.o

CMakeFiles/Detection.dir/star.cpp.o: CMakeFiles/Detection.dir/flags.make
CMakeFiles/Detection.dir/star.cpp.o: ../star.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Detection.dir/star.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Detection.dir/star.cpp.o -c /home/brunathan/Téléchargements/Planetarium-master/Exemple/star.cpp

CMakeFiles/Detection.dir/star.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Detection.dir/star.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brunathan/Téléchargements/Planetarium-master/Exemple/star.cpp > CMakeFiles/Detection.dir/star.cpp.i

CMakeFiles/Detection.dir/star.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Detection.dir/star.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brunathan/Téléchargements/Planetarium-master/Exemple/star.cpp -o CMakeFiles/Detection.dir/star.cpp.s

CMakeFiles/Detection.dir/star.cpp.o.requires:
.PHONY : CMakeFiles/Detection.dir/star.cpp.o.requires

CMakeFiles/Detection.dir/star.cpp.o.provides: CMakeFiles/Detection.dir/star.cpp.o.requires
	$(MAKE) -f CMakeFiles/Detection.dir/build.make CMakeFiles/Detection.dir/star.cpp.o.provides.build
.PHONY : CMakeFiles/Detection.dir/star.cpp.o.provides

CMakeFiles/Detection.dir/star.cpp.o.provides.build: CMakeFiles/Detection.dir/star.cpp.o

CMakeFiles/Detection.dir/utilitaires.cpp.o: CMakeFiles/Detection.dir/flags.make
CMakeFiles/Detection.dir/utilitaires.cpp.o: ../utilitaires.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Detection.dir/utilitaires.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Detection.dir/utilitaires.cpp.o -c /home/brunathan/Téléchargements/Planetarium-master/Exemple/utilitaires.cpp

CMakeFiles/Detection.dir/utilitaires.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Detection.dir/utilitaires.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/brunathan/Téléchargements/Planetarium-master/Exemple/utilitaires.cpp > CMakeFiles/Detection.dir/utilitaires.cpp.i

CMakeFiles/Detection.dir/utilitaires.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Detection.dir/utilitaires.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/brunathan/Téléchargements/Planetarium-master/Exemple/utilitaires.cpp -o CMakeFiles/Detection.dir/utilitaires.cpp.s

CMakeFiles/Detection.dir/utilitaires.cpp.o.requires:
.PHONY : CMakeFiles/Detection.dir/utilitaires.cpp.o.requires

CMakeFiles/Detection.dir/utilitaires.cpp.o.provides: CMakeFiles/Detection.dir/utilitaires.cpp.o.requires
	$(MAKE) -f CMakeFiles/Detection.dir/build.make CMakeFiles/Detection.dir/utilitaires.cpp.o.provides.build
.PHONY : CMakeFiles/Detection.dir/utilitaires.cpp.o.provides

CMakeFiles/Detection.dir/utilitaires.cpp.o.provides.build: CMakeFiles/Detection.dir/utilitaires.cpp.o

# Object files for target Detection
Detection_OBJECTS = \
"CMakeFiles/Detection.dir/main.cpp.o" \
"CMakeFiles/Detection.dir/detection_etoiles.cpp.o" \
"CMakeFiles/Detection.dir/testRRDM.cpp.o" \
"CMakeFiles/Detection.dir/writeText.cpp.o" \
"CMakeFiles/Detection.dir/star.cpp.o" \
"CMakeFiles/Detection.dir/utilitaires.cpp.o"

# External object files for target Detection
Detection_EXTERNAL_OBJECTS =

Detection: CMakeFiles/Detection.dir/main.cpp.o
Detection: CMakeFiles/Detection.dir/detection_etoiles.cpp.o
Detection: CMakeFiles/Detection.dir/testRRDM.cpp.o
Detection: CMakeFiles/Detection.dir/writeText.cpp.o
Detection: CMakeFiles/Detection.dir/star.cpp.o
Detection: CMakeFiles/Detection.dir/utilitaires.cpp.o
Detection: CMakeFiles/Detection.dir/build.make
Detection: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_nonfree.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_nonfree.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
Detection: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
Detection: CMakeFiles/Detection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Detection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Detection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Detection.dir/build: Detection
.PHONY : CMakeFiles/Detection.dir/build

CMakeFiles/Detection.dir/requires: CMakeFiles/Detection.dir/main.cpp.o.requires
CMakeFiles/Detection.dir/requires: CMakeFiles/Detection.dir/detection_etoiles.cpp.o.requires
CMakeFiles/Detection.dir/requires: CMakeFiles/Detection.dir/testRRDM.cpp.o.requires
CMakeFiles/Detection.dir/requires: CMakeFiles/Detection.dir/writeText.cpp.o.requires
CMakeFiles/Detection.dir/requires: CMakeFiles/Detection.dir/star.cpp.o.requires
CMakeFiles/Detection.dir/requires: CMakeFiles/Detection.dir/utilitaires.cpp.o.requires
.PHONY : CMakeFiles/Detection.dir/requires

CMakeFiles/Detection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Detection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Detection.dir/clean

CMakeFiles/Detection.dir/depend:
	cd /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brunathan/Téléchargements/Planetarium-master/Exemple /home/brunathan/Téléchargements/Planetarium-master/Exemple /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build /home/brunathan/Téléchargements/Planetarium-master/Exemple/Build/CMakeFiles/Detection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Detection.dir/depend

