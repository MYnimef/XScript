include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/headers
)

add_library(
        dsl_functions STATIC

        ${CMAKE_CURRENT_LIST_DIR}/sources/FuncPrint.cpp
        ${CMAKE_CURRENT_LIST_DIR}/sources/FuncPrintln.cpp
)