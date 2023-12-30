cmake_minimum_required(VERSION 3.3)

set(APPLICATION nohex)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -g -fPIC -fdeclspec -O2")

project(${APPLICATION})

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

set(SOURCES
  "${SRC_DIR}/main.c"
  "${SRC_DIR}/dump.c"
  "${SRC_DIR}/data.c"
  "${SRC_DIR}/stream.c"
  "${SRC_DIR}/args.c")

add_executable(${APPLICATION} ${SOURCES})
