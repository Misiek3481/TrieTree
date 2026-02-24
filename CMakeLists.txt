cmake_minimum_required(VERSION 3.10)
project(TrieTreeOptimization)

# Ustawienie standardu C++ na 17 (pokaż, że znasz nowoczesne standardy)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Flagi kompilatora - to zrobi wrażenie na rekruterze Intela
if(MSVC)
    # Dla Visual Studio: najwyższy poziom ostrzeżeń
    add_compile_options(/W4)
else()
    # Dla GCC/Clang (Linux): wszystkie ostrzeżenia i optymalizacja O3
    add_compile_options(-Wall -Wextra -O3)
endif()

# Definicja pliku wykonywalnego i źródeł
add_executable(TrieTree 
    AISD-Project3.cpp 
    Trie.cpp 
    Node.cpp 
    Trie.h 
    Node.h
)