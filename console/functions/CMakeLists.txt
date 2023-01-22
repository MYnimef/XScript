include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/headers
)

add_library(
        dsl_console_functions STATIC

        ${CMAKE_CURRENT_LIST_DIR}/sources/FuncClearConsole.cpp
        ${CMAKE_CURRENT_LIST_DIR}/sources/FuncInput.cpp
        ${CMAKE_CURRENT_LIST_DIR}/sources/FuncList.cpp
        ${CMAKE_CURRENT_LIST_DIR}/sources/FuncPrint.cpp
        ${CMAKE_CURRENT_LIST_DIR}/sources/FuncPrintln.cpp
)