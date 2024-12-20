#include <iostream>
#include <cstddef>
#include "cstring.h"

size_t Strlen(const char *str) {
  size_t answ = 0;
  while (str[answ] != '\0') {
    ++answ;
  }
  return answ;
}
int Strcmp(const char* first, const char* second) {
  if (first[0] == '\0' && second[0] != '\0') {
    return -1;
  }
  if (first[0] != '\0' && second[0] == '\0') {
    return 1;
  }
  size_t i = 0;
  for (; first[i] != '\0' && second[i] != '\0'; ++i) {
    if (first[i] != second[i]) {
      if (static_cast<int>(first[i]) > static_cast<int>(second[i])) {
        return 1;
      }
      return -1;
    }
  }
  if (first[i] != second[i]) {
    if (static_cast<int>(first[i]) > static_cast<int>(second[i])) {
      return 1;
    }
    return -1;
  }
  return 0;
}
int Strncmp(const char* first, const char* second, size_t count) {
  if (!count) {
    return 0;
  }
  if (first[0] == '\0' && second[0] != '\0') {
    return -1;
  }
  if (first[0] != '\0' && second[0] == '\0') {
    return 1;
  }
  size_t i = 0;
  for (; i < count && first[i] != '\0' && second[i] != '\0'; ++i) {
    if (first[i] != second[i]) {
      if (static_cast<int>(first[i]) > static_cast<int>(second[i])) {
        return 1;
      }
      return -1;
    }
  }
  return 0;
}
char* Strcpy(char* dest, const char* src) {
  size_t i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    ++i;
  }
  dest[i] = '\0';
  return dest;
}
char* Strncpy(char* dest, const char* src, size_t count) {
  size_t i = 0;
  while (src[i] != '\0' && i < count) {
    dest[i] = src[i];
    ++i;
  }
  while (i < count) {
    dest[i] = '\0';
    ++i;
  }
  return dest;
}
char* Strcat(char* dest, const char* src) {
  size_t dest_end = Strlen(dest);
  size_t src_end = 0;
  for (; src[src_end] != '\0'; ++src_end) {
    dest[dest_end + src_end] = src[src_end];
  }
  dest[dest_end + src_end] = '\0';
  return dest;
}
char* Strncat(char* dest, const char* src, size_t count) {
  size_t dest_end = Strlen(dest);
  size_t src_end = 0;
  for (; src_end < count && src[src_end] != '\0'; ++src_end) {
    dest[dest_end + src_end] = src[src_end];
  }
  dest[dest_end + src_end] = '\0';
  return dest;
}
const char* Strchr(const char* str, char symbol) {
  size_t answ = 0;
  while (str[answ] != '\0') {
    if (str[answ] == symbol) {
      return str + answ;
    }
    ++answ;
  }
  if (str[answ] == symbol) {
    return str + answ;
  }
  return nullptr;
}
const char* Strrchr(const char* str, char symbol) {
  int i = 0;
  int answ = -1;
  while (str[i] != '\0') {
    if (str[i] == symbol) {
      answ = i;
    }
    ++i;
  }
  if (str[i] == symbol) {
    return str + i;
  }
  if (answ != -1) {
    return str + answ;
  }
  return nullptr;
}
size_t Strspn(const char* dest, const char* src) {
  size_t answ = 0;
  size_t idx_1 = 0;
  size_t idx_2 = 0;
  while (dest[idx_1] != '\0') {
    while (src[idx_2] != '\0') {
      if (src[idx_2] == dest[idx_1]) {
        ++answ;
        idx_2 = 0;
        break;
      }
      ++idx_2;
    }
    ++idx_1;
  }
  return answ;
}
size_t Strcspn(const char* dest, const char* src) {
  size_t answ = 0;
  size_t idx_1 = 0;
  size_t idx_2 = 0;
  while (dest[idx_1] != '\0') {
    while (src[idx_2] != '\0') {
      if (src[idx_2] == dest[idx_1]) {
        return answ;
      }
      ++idx_2;
    }
    idx_2 = 0;
    ++idx_1;
    ++answ;
  }
  return answ;
}
char* Strpbrk(const char* dest, const char* breakset) {
  size_t answ = 0;
  while (dest[answ] != '\0') {
    for (size_t i = 0; breakset[i] != '\0'; ++i) {
      if (breakset[i] == dest[answ]) {
        return (char*)dest + answ;
      }
    }
    ++answ;
  }
  return nullptr;
}
char* Strstr(const char* str, const char* pattern) {
  if (pattern[0] == '\0' && str[0] == '\0' || pattern[0] == '\0') {
    return (char*)str;
  }
  if (str[0] == '\0') {
    return nullptr;
  }
  size_t answ = 0;
  size_t i = 1;
  bool is_right = true;
  for (; str[answ] != '\0'; ++answ) {
    is_right = true;
    if (str[answ] == pattern[0]) {
      for (i = 1; pattern[i] != '\0' && str[answ + i] != '\0'; ++i) {
        if (pattern[i] != str[answ + i]) {
          is_right = false;
          break;
        }
      }
      if (is_right && pattern[i] == '\0') {
        return (char*)str + answ;
      }
    }
  }
  return nullptr;
}
