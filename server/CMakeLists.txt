cmake_minimum_required(VERSION 3.20)


if(NOT NAME)
    message(FATAL_ERROR "NAME is required")
endif()

if(NOT SRC)
    message(FATAL_ERROR "SRC is required")
endif()


project(${NAME}
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(NOT DEFINED PACKAGES)
    set(PACKAGES "")
endif()

if(NOT DEFINED TARGETS)
    set(TARGETS "")
endif()

if(NOT DEFINED COMMON)
    set(COMMON "")
endif()


if(ENV)
    set(
        CMAKE_INSTALL_PREFIX
        "${ENV}"
        CACHE PATH "Install prefix"
        FORCE
    )

    list(APPEND CMAKE_PREFIX_PATH "${ENV}")
endif()


set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}/../bin"
)


separate_arguments(PACKAGES)
separate_arguments(TARGETS)
separate_arguments(SRC)
separate_arguments(COMMON)


list(TRANSFORM SRC REPLACE "^(.+)$" "src/\\1.cpp")
list(TRANSFORM COMMON REPLACE "^(.+)$" "../common/src/\\1.cpp")

add_executable(${NAME}
    ${SRC}
    ${COMMON}
)


target_include_directories(${NAME}
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../common/include>
        $<INSTALL_INTERFACE:include>
)

if (ENV)

    target_include_directories(${NAME}
        PRIVATE
            "${ENV}/include"
    )

endif()


target_compile_options(${NAME}
    PRIVATE
        -Wall
        -Werror
        -Wextra
)


foreach(PACKAGE ${PACKAGES})
    find_package(${PACKAGE} REQUIRED)
endforeach()

target_link_libraries(${NAME}
    PRIVATE
        ${TARGETS}
)
