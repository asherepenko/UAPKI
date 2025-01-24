cmake_minimum_required(VERSION 3.17)

project(cm-pkcs12 LANGUAGES C CXX)

message(STATUS "Project: cm-pkcs12")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message(STATUS "Build type not specified: Use Release by default")
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
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
set(PATH_UAPKIC ${PATH_PRJ}/../uapkic)
set(PATH_UAPKIF ${PATH_PRJ}/../uapkif)
set(PATH_COMMON_CMAPI ${PATH_PRJ}/../common/cm-api)
set(PATH_COMMON_JSON ${PATH_PRJ}/../common/json)
set(PATH_COMMON_MACROS ${PATH_PRJ}/../common/macros)
set(PATH_COMMON_PKIX ${PATH_PRJ}/../common/pkix)

include_directories(
    ${PATH_UAPKIC}/include
    ${PATH_UAPKIF}/include
    ${PATH_COMMON_CMAPI}
    ${PATH_COMMON_JSON}
    ${PATH_COMMON_MACROS}
    ${PATH_COMMON_PKIX}
    ${PATH_PRJ}/src
    ${PATH_PRJ}/src/crypto
    ${PATH_PRJ}/src/storage
)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../build)

if(${ANDROID})
    # include_directories(${PATH_PRJ}/../libs/iconv/include)
    add_library(iconv STATIC IMPORTED)
    set_target_properties(iconv PROPERTIES 
        IMPORTED_LOCATION ${PATH_PRJ}/../libs/iconv/android_${ANDROID_ABI}/lib/libiconv.a
        INTERFACE_INCLUDE_DIRECTORIES ${PATH_PRJ}/../libs/iconv/include
    )
endif()

aux_source_directory(${PATH_PRJ}/src CMP12_SRC_SOURCES)
aux_source_directory(${PATH_PRJ}/src/crypto CMP12_CRYPTO_SOURCES)
aux_source_directory(${PATH_PRJ}/src/storage CMP12_STORAGE_SOURCES)
aux_source_directory(${PATH_COMMON_JSON} JSON_SOURCES)
set(COMMON_SOURCES
    ${PATH_COMMON_PKIX}/aid.c
    ${PATH_COMMON_PKIX}/ba-utils.c
    ${PATH_COMMON_PKIX}/dstu4145-params.c
    ${PATH_COMMON_PKIX}/iconv-utils.c
    ${PATH_COMMON_PKIX}/iso15946.c
    ${PATH_COMMON_PKIX}/key-wrap.c
    ${PATH_COMMON_PKIX}/oids.c
    ${PATH_COMMON_PKIX}/oid-utils.c
    ${PATH_COMMON_PKIX}/private-key.c
    ${PATH_COMMON_PKIX}/uapki-ns-util.cpp
)

add_library(cm-pkcs12 SHARED
    ${CMP12_CRYPTO_SOURCES}
    ${CMP12_SRC_SOURCES}
    ${CMP12_STORAGE_SOURCES}
    ${COMMON_SOURCES}
    ${JSON_SOURCES}
)

set_target_properties(cm-pkcs12 PROPERTIES LINK_FLAGS_RELEASE -s)

target_compile_definitions(cm-pkcs12 PRIVATE CM_LIBRARY)
if(${WIN32})
    target_compile_definitions(cm-pkcs12 PRIVATE NOCRYPT)
    target_compile_definitions(cm-pkcs12 PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

target_link_libraries(cm-pkcs12 PRIVATE uapkic uapkif)

if(${ANDROID})
    target_link_libraries(cm-pkcs12 PRIVATE iconv)
endif()
if(${APPLE})
    target_link_libraries(cm-pkcs12 PRIVATE iconv)
endif()

if(NOT ${ANDROID})
    add_custom_command(TARGET cm-pkcs12 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:cm-pkcs12> ../out/
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:cm-pkcs12> ../../${OUT_DIR}/
    )
endif()
