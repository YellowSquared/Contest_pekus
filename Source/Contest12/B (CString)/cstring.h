/*    ____        __      __   ____________  __       __    __      __    ________     __
     /    \       \  \   /  /  |____  ____|  \  \    /  /  |  |    |  |  |   ____ |   |  |
    /  /\  \       \   \/  /       |  |       \  \  /  /   |  |____|  |  |  |         |  |
   /  /__\  \       \     /        |  |        \  \/  /    |   ____   |  |  |         |  |
  /  _____   \      /  /\  \       |  |         \    /     |  |    |  |  |  |         |__|
 /  /      \  \    /  /   \  \     |  |          |  /      |  |    |  |  |  |          __
/__/        \__\  /__/     \__\    |__|         /__/       |__|    |__|  |__|         |__|

ЗА РЕШЕНИЕ НЕ ВЫСТАВЛЕН ОКОНЧАТЕЛЬНЫЙ БАЛЛ!!!
Т.е., его приняла система, но не проверил ассистент
*/

//
// Created by altea_dev on 12/10/2024.
//

#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>
#include <cstddef>

size_t Strlen(const char* str);
int Strcmp(const char* first, const char* second);
int Strncmp(const char* first, const char* second, size_t count);
char* Strcpy(char* dest, const char* src);
char* Strncpy(char* dest, const char* src, size_t count);
char* Strcat(char* dest, const char* src);
char* Strncat(char* dest, const char* src, size_t count);
const char* Strchr(const char* str, char symbol);
const char* Strrchr(const char* str, char symbol);
size_t Strspn(const char* dest, const char* src);
size_t Strcspn(const char* dest, const char* src);
char* Strpbrk(const char* dest, const char* breakset);
char* Strstr(const char* str, const char* pattern);

#endif //CSTRING_H
