cmake_minimum_required(VERSION 3.5)

project(Thesaurus LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (headers
    thesaurusunit.h
	thesaurus.h
)

set (sources
    main.cpp
	thesaurusunit.cpp
	thesaurus.cpp
)

add_executable(Thesaurus
    ${headers}
    ${sources}
)

target_link_libraries(Thesaurus)
