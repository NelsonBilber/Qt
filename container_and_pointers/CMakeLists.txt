project(containert_and_pointers)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

set(
MOC_HDRS
#mainwindow.h
#worker.h

)

set(
SRCS
#mainwindow.cpp
main.cpp
#worker.cpp
)


SET( HEADERS_UI )
#mainwindow.ui

# this will run uic on .ui files:
QT4_WRAP_UI( SAMPLE_UI_HDRS ${HEADERS_UI} )
QT4_WRAP_CPP(SAMPLE_HEADERS_MOC ${MOC_HDRS})

INCLUDE_DIRECTORIES( ${CMAKE_BINARY_DIR} )

add_executable(containert_and_pointers
${SRCS}
${SAMPLE_HEADERS_MOC}
${SAMPLE_UI_HDRS})

target_link_libraries(containert_and_pointers
${QT_LIBRARIES}
)

