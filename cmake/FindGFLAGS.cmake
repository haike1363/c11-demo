FIND_PATH(GFLAGS_INCLUDE_DIR gflags /usr/include /usr/local/include /usr/local/t-midware-expert-common-gflags/include)
MESSAGE(STATUS "GFLAGS_INCLUDE_DIR: " ${GFLAGS_INCLUDE_DIR})

FIND_LIBRARY(GFLAGS_LIBRARY gflags /usr/lib /usr/local/lib /usr/local/t-midware-expert-common-gflags/lib)

IF (GFLAGS_INCLUDE_DIR AND GFLAGS_LIBRARY)
    SET(GFLAGS_FOUND TRUE)
	MESSAGE(STATUS "GFLAGS_LIBRARY: " ${GFLAGS_LIBRARY})
ENDIF(GFLAGS_INCLUDE_DIR AND GFLAGS_LIBRARY)

IF (GFLAGS_FOUND)
    # ��FIND_PACKAGE����û��ָ��QUIET�������������IF����Ϊ��
    IF (NOT GFLAGS_FIND_QUIETLY)
        MESSAGE(STATUS "Found GFLAGS: ${GFLAGS_LIBRARY}")
    ENDIF (NOT GFLAGS_FIND_QUIETLY)
ELSE (GFLAGS_FOUND)
    # ���FIND_PACKAGE����ָ����REQUIRED������˵��������Ǵ�Project�����
    # ��Ӧ�����GFLAGS_FIND_REQUIRED����
    IF (GFLAGS_FIND_REQUIRED)
        MESSAGE(FATAL_ERROR "Could not find GFLAGS library")
    ENDIF (GFLAGS_FIND_REQUIRED)
ENDIF (GFLAGS_FOUND)