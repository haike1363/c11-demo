CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

AUX_SOURCE_DIRECTORY(. SRC_LIST)
SET(TARGET_BIN SeastarDemo)

INCLUDE_DIRECTORIES(/usr/local/include/seastar)
INCLUDE_DIRECTORIES(/usr/local/include)
INCLUDE_DIRECTORIES(/usr/include/)

LINK_DIRECTORIES(/usr/local/lib/c-ares/lib)
LINK_DIRECTORIES(/usr/local/lib)
LINK_DIRECTORIES(/usr/lib)

ADD_EXECUTABLE(${TARGET_BIN} ${SRC_LIST})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

FIND_PACKAGE(Threads)
TARGET_LINK_LIBRARIES(${TARGET_BIN} ${CMAKE_THREAD_LIBS_INIT})

#TARGET_LINK_LIBRARIES(${TARGET_BIN} libseastar.a)
#TARGET_LINK_LIBRARIES(${TARGET_BIN} libcares.a)
#TARGET_LINK_LIBRARIES(${TARGET_BIN} libcares-seastar.a)
#TARGET_LINK_LIBRARIES(${TARGET_BIN} libboost_program_options.a libboost_system.a libboost_filesystem.a libboost_thread.a libboost_chrono.a)
#TARGET_LINK_LIBRARIES(${TARGET_BIN} rt dl)

