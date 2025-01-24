cmake_minimum_required(VERSION 3.17)

project(uapkic LANGUAGES C)
set(UAPKIC_VERSION 2.0.8)
message(STATUS "Project: uapkic, version: " ${UAPKIC_VERSION})

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message(STATUS "Build type not specified: Use Release by default")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")
set(CMAKE_SKIP_RPATH ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(${WIN32})
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

set(PATH_PRJ ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
    ${PATH_PRJ}
    ${PATH_PRJ}/include
)

if(${ANDROID})
    add_library(iconv STATIC IMPORTED)
    set_target_properties(iconv PROPERTIES 
        IMPORTED_LOCATION ${PATH_PRJ}/../libs/iconv/android_${ANDROID_ABI}/lib/libiconv.a
        INTERFACE_INCLUDE_DIRECTORIES ${PATH_PRJ}/../libs/iconv/include
    )
endif()

aux_source_directory(${PATH_PRJ}/src UAPKIC_SOURCES)

add_library(uapkic SHARED
    ${UAPKIC_SOURCES}
)

set_target_properties(uapkic PROPERTIES LINK_FLAGS_RELEASE -s)
set_target_properties(uapkic PROPERTIES VERSION ${UAPKIC_VERSION})

target_compile_definitions(uapkic PRIVATE UAPKIC_LIBRARY)
target_compile_definitions(uapkic PRIVATE UAPKIC_SELF_TEST)
if(${WIN32})
    target_compile_definitions(uapkic PRIVATE NOCRYPT)
    target_compile_definitions(uapkic PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

if(${ANDROID})
    target_link_libraries(uapkic PRIVATE iconv)
else()
    target_link_libraries(uapkic PRIVATE pthread)
endif()
if(${APPLE})
    target_link_libraries(uapkic PRIVATE iconv)
endif()

if(NOT ${ANDROID})
    add_custom_command(TARGET uapkic POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:uapkic> ../out/
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:uapkic> ../../${OUT_DIR}/
    )
endif()
