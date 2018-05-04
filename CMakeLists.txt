cmake_minimum_required(VERSION 3.5)
project( HashTable VERSION 0.1.0 )

add_library(HashTable STATIC src/HashTable.c)

target_include_directories( HashTable PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_sources( HashTable PRIVATE ${PROJECT_SOURCE_DIR}/src/HashTable )
target_sources( HashTable PUBLIC ${PROJECT_SOURCE_DIR}/include/HashTable )

set_target_properties(HashTable
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)
