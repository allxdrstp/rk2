cmake_minimum_required(VERSION 3.10)

# Проектное имя
project(FactoryPatternExample)

# Установка переменной C++ стандарта
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление директории с заголовочными файлами
include_directories(include)

# Список исходных файлов
set(SOURCES
    src/main.cpp
    src/IProduct.h
    src/IFactory.h
    src/ConcreteFactory.h
    src/ConcreteProductA.h
    src/ConcreteProductB.h
)

# Создание исполняемого файла
add_executable(FactoryPatternExample ${SOURCES})
