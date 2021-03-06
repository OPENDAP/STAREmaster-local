# This is the cmake file for the src directory of the STAREmaster project.

# Ed Hartnett 7/18/20

# This is the library we create.
add_library(ssc SidecarFile.cpp GeoFile.cpp Modis05L2GeoFile.cpp Modis09L2GeoFile.cpp
  Modis09GAGeoFile.cpp ModisGeoFile.cpp STAREmaster.c)

# This is the executable we create.
add_executable(createSidecarFile createSidecarFile.cpp)

# Add these directories to those searched during linking.
target_link_directories(createSidecarFile PUBLIC ${STARE_LIBRARY_DIR})

# The executable depends on these libraries.
target_link_libraries(createSidecarFile ssc)
target_link_libraries(createSidecarFile ${NETCDF_LIBRARIES_C})
target_link_libraries(createSidecarFile STARE)
target_link_libraries(createSidecarFile ${HDFEOS2})
target_link_libraries(createSidecarFile ${MFHDF4} ${DF} ${JPEG_LIB})
target_link_libraries(createSidecarFile ${HDF5_LIBRARIES} ${HDF5_HL_LIBRARIES})
target_link_libraries(createSidecarFile ${CMD_OUTPUT})

# Install the execuatable in the bin directory.
install(TARGETS createSidecarFile RUNTIME DESTINATION bin)

