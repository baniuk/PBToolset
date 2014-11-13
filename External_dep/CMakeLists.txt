project("External_dep")

# build gtest only if not build on external project
IF (BUILD_GTEST)
	ExternalProject_Add(	googletest
							SVN_REPOSITORY ${GTest_SVN_REPOSITORY}
							# Force separate output paths for debug and release builds to allow easy
							# identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
							CMAKE_ARGS -DCMAKE_CXX_FLAGS='-D_VARIADIC_MAX=10'
								-Dgtest_force_shared_crt=ON
								-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
							# Disable install step
							INSTALL_COMMAND ""
							UPDATE_COMMAND ""
							# Wrap download, configure and build steps in a script to log output
							# LOG_DOWNLOAD ON
						)
ENDIF()
	