#pragma once

#include <iostream>


template<typename T>
void normcout(const T& message)
{
    std::cout << "\033[0m" << message << "\033[0m" << std::endl;
}

template<typename T>
void redcout(const T& message)
{
    std::cout << "\033[31m" << message << "\033[0m" << std::endl;
}

template<typename T>
void bluecout(const T& message)
{
    std::cout << "\033[34m" << message << "\033[0m" << std::endl;
}

template<typename T>
void yellowcout(const T& message)
{
    std::cout << "\033[33m" << message << "\033[0m" << std::endl;
}

template<typename T>
void greencout(const T& message)
{
    std::cout << "\033[32m" << message << "\033[0m" << std::endl;
}