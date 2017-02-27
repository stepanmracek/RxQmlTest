cmake_minimum_required(VERSION 3.0)
project(RxQmlTest)

find_package(Qt5 COMPONENTS Quick Gui Widgets Core Network)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB_RECURSE ${PROJECT_NAME}.Sources "src/*.cpp")
file(GLOB_RECURSE ${PROJECT_NAME}.Resources "src/*.qrc")

add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}.Sources}
    ${${PROJECT_NAME}.Resources}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE rxcpp
)

target_link_libraries(${PROJECT_NAME}
    pthread
)

qt5_use_modules(${PROJECT_NAME} Quick Gui Widgets Core Network)
