cmake_minimum_required(VERSION 3.10)
# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

# Название проекта
project(FE)

# Установить стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавить исходные файлы
add_executable(FE src/main.cpp)

# Добавить тесты
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(FE tests/test.cpp)
target_link_libraries(FE ${GTEST_LIBRARIES} pthread)

add_test(NAME FE COMMAND FacadePatternTest)
