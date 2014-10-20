project("External_dep")
# jesli oba google testy sa do tego samego katalogu to jeden daje locka drugiemu przy rebuild - trzeba usunąć
set(SYSTEM_UPDATE_COMMAND svn cleanup ${ROOT_PROJECT_SOURCE_DIR}/External_dep/gtest)
ExternalProject_Add(	googletest
						# wszystko ląduje w Third_party/gtest
						SOURCE_DIR ${ROOT_PROJECT_SOURCE_DIR}/External_dep/gtest
						BINARY_DIR ${ROOT_PROJECT_SOURCE_DIR}/bin/External_dep/gtest
						STAMP_DIR ${ROOT_PROJECT_SOURCE_DIR}/bin/External_dep/gtest/stamp
						SVN_REPOSITORY ${GTest_SVN_REPOSITORY}
						# Force separate output paths for debug and release builds to allow easy
						# identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
						CMAKE_ARGS -DCMAKE_CXX_FLAGS='-D_VARIADIC_MAX=10'
							-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=${ROOT_PROJECT_SOURCE_DIR}/lib
							-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=${ROOT_PROJECT_SOURCE_DIR}/lib
							-Dgtest_force_shared_crt=ON
							-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
						# Disable install step
						INSTALL_COMMAND ""
						UPDATE_COMMAND ${SYSTEM_UPDATE_COMMAND}
						# Wrap download, configure and build steps in a script to log output
						# LOG_DOWNLOAD ON
					)
	