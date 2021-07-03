cmake_minimum_required(VERSION 3.5)
project(kenobet)

### [1] Application target
# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.hpp"
include_directories( include )

# Cria um executável com nome "kenobet", adiciona neste executável os arquivos os seus .cpp
add_executable(kenobet ../src/main.cpp ../src/kenobet.cpp)

# define C++11 standard
set_property(TARGET kenobet PROPERTY CXX_STANDARD 11)

# The end
