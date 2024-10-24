file(GLOB_RECURSE ELFReaderSources
	"${CMAKE_CURRENT_SOURCE_DIR}/ELFReader.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/ELFReader.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
)

add_executable(${ELFREADER_TARGET_NAME} ${ELFReaderSources})
target_include_directories(${ELFREADER_TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../")
target_link_libraries(${ELFREADER_TARGET_NAME} PRIVATE ${LIBELF_TARGET_NAME})
