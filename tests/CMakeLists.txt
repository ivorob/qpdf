CMAKE_MINIMUM_REQUIRED (VERSION 3.0)
PROJECT (tests)

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET (MAIN_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../src)
SET (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../include)
SET (SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/StringTest.cpp
        ${SRC_DIR}/ContentLoaderTest.cpp
        # main sources
        ${MAIN_SRC_DIR}/string.cpp
        ${MAIN_SRC_DIR}/ContentLoader.cpp
    )

SET (HEADERS
        ${INCLUDE_DIR}/qpdf/string.h
        ${INCLUDE_DIR}/qpdf/ContentLoader.h
    )

ADD_EXECUTABLE (tests ${SOURCES} ${HEADERS})
TARGET_INCLUDE_DIRECTORIES (tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
TARGET_LINK_LIBRARIES (tests gtest)

ADD_CUSTOM_COMMAND(TARGET tests
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/data/pdf-sample.pdf ${CMAKE_CURRENT_BINARY_DIR}/pdf-sample.pdf
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/data/minimal.pdf ${CMAKE_CURRENT_BINARY_DIR}/minimal.pdf
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/data/minimal_crlf.pdf ${CMAKE_CURRENT_BINARY_DIR}/minimal_crlf.pdf
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/data/minimal_crlf_l.pdf ${CMAKE_CURRENT_BINARY_DIR}/minimal_crlf_l.pdf
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/data/minimal_l.pdf ${CMAKE_CURRENT_BINARY_DIR}/minimal_l.pdf
    )
