FIND_PATH(GFLAGS_INCLUDE_DIR gflags /usr/include /usr/local/include /usr/local/t-midware-expert-common-gflags/include)
MESSAGE(STATUS "GFLAGS_INCLUDE_DIR: " ${GFLAGS_INCLUDE_DIR})

FIND_LIBRARY(GFLAGS_LIBRARY gflags /usr/lib /usr/local/lib /usr/local/t-midware-expert-common-gflags/lib)

IF (GFLAGS_INCLUDE_DIR AND GFLAGS_LIBRARY)
    SET(GFLAGS_FOUND TRUE)
	MESSAGE(STATUS "GFLAGS_LIBRARY: " ${GFLAGS_LIBRARY})
ENDIF(GFLAGS_INCLUDE_DIR AND GFLAGS_LIBRARY)

IF (GFLAGS_FOUND)
    # 若FIND_PACKAGE命令没有指定QUIET参数，那下面的IF语句就为真
    IF (NOT GFLAGS_FIND_QUIETLY)
        MESSAGE(STATUS "Found GFLAGS: ${GFLAGS_LIBRARY}")
    ENDIF (NOT GFLAGS_FIND_QUIETLY)
ELSE (GFLAGS_FOUND)
    # 如果FIND_PACKAGE命令指定了REQUIRED参数，说明这个库是此Project必须的
    # 对应下面的GFLAGS_FIND_REQUIRED变量
    IF (GFLAGS_FIND_REQUIRED)
        MESSAGE(FATAL_ERROR "Could not find GFLAGS library")
    ENDIF (GFLAGS_FIND_REQUIRED)
ENDIF (GFLAGS_FOUND)