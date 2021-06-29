
cmake_minimum_required(VERSION 3.20)
project(IceKnife)

set(CMAKE_CXX_STANDARD 14)

find_package(glm REQUIRED)
find_package(sdl2 REQUIRED)
find_package(sdl2-ttf REQUIRED)
find_package(sdl2-mixer REQUIRED)
find_package(sdl2-image REQUIRED)
find_package(sdl2-net REQUIRED)

set(VCPKG_LIBS 
    glm::glm
    SDL2::SDL2
    SDL2::SDL2_ttf
    SDL2::SDL2_mixer
    SDL2::SDL2_image
    SDL2::SDL2_net
)

set(SRC_FILES 
    src/game.cpp
)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE  ${VCPKG_LIBS})
set(TEST_APP_NAME ${PROJECT_NAME}_test)

set(TEST_SRC
    test/src/game.test.cpp
)

list(REMOVE_ITEM SRC_FILES src/main.cpp)
add_executable(${TEST_APP_NAME} ${TEST_SRC} ${SRC_FILES} test/src/test_main.cpp)
target_include_directories(${TEST_APP_NAME} PUBLIC test/include)
target_include_directories(${TEST_APP_NAME} PUBLIC include)
target_link_libraries(${TEST_APP_NAME} PRIVATE ${VCPKG_LIBS})

enable_testing()

add_test(
  NAME ${TEST_APP_NAME}
  COMMAND ${TEST_APP_NAME} -o report.xml -r junit)

