# Define a versão mínima do CMake necessária
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(MeuProjeto VERSION 1.0 LANGUAGES CXX)

# Define o padrão da linguagem C++ (exemplo: C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adicionar os arquivos de código-fonte
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/book.cpp
    src/simulation.cpp
    src/user.cpp
)

# Incluir diretórios para cabeçalhos
target_include_directories(${PROJECT_NAME} PRIVATE include)

