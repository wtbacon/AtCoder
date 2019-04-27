cmake_minimum_required(VERSION 3.13)

project(ABC)

MACRO(ADD_ALL_SUBDIR result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${child})
            IF(EXISTS ${curdir}/${child}/CMakeLists.txt)
                add_subdirectory(${child})
            ELSE()
                aux_source_directory(${child} SOURCE)
            ENDIF()
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()

ADD_ALL_SUBDIR(SUBDIRS ${ABC_SOURCE_DIR})

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)

IF(SOURCE)
    add_executable(ABC ${SOURCE})
ENDIF()