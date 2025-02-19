#include "cstring.h"

size_t Strlen(const char* str) {
  size_t offset = 0;

  while (*(str + offset) != '\0') {
    offset++;
  }
  return offset;
}

int Strcmp(const char* first, const char* second) {
  while (*first == *second && *first != '\0' && *second != '\0') {
    first++;
    second++;
  }

  return *first - *second;
}

int Strncmp(const char* first, const char* second, size_t count) {
  if (count == 0) {
    return 0;
  }
  size_t offset = 0;
  while (*(first + offset) == *(second + offset) && *(first + offset) != '\0' && *(second + offset) != '\0' && offset < count - 1) {
    offset++;
  }

  return *(first + offset) - *(second + offset);
}
char* Strcpy(char* dest, const char* src) {
  size_t offset = 0;
  while (*src != '\0') {
    *(dest + offset) = *src;
    offset++;
    src++;
  }
  *(dest + offset) = '\0';
  return dest;
}

char* Strncpy(char* dest, const char* src, size_t count) {
  if (dest != src) {
    size_t offset = 0;
    while (*(src + offset) != '\0' && offset < count) {
      *(dest + offset) = *(src + offset);
      offset++;
    }

    while (offset < count) {
      *(dest + offset) = 0;
      offset++;
    }
  }
  return dest;
}

char* Strcat(char* dest, const char* src) {
  size_t offset = 0;
  while (*(dest + offset) != '\0') {
    offset++;
  }
  while (*src != '\0') {
    *(dest + offset) = *src;
    offset++;
    src++;
  }
  *(dest + offset) = '\0';
  return dest;
}

char* Strncat(char* dest, const char* src, size_t count) {
  size_t offset = 0;
  while (*(dest + offset) != '\0') {
    offset++;
  }

  size_t s2_offset = 0;
  while (*(src + s2_offset) != '\0' && s2_offset < count) {
    *(dest + offset) = *(src + s2_offset);
    offset++;
    s2_offset++;
  }
  return dest;
}

const char* Strchr(const char* str, char symbol) {
  while (*(str) != '\0') {
    if (*(str) == symbol) {
      return str;
    }
    str++;
  }

  if (*(str) == symbol) {
    return str;
  }
  return nullptr;
}

const char* Strrchr(const char* str, char symbol) {
  const char* last = nullptr;
  while (*str != '\0') {
    if (*str == symbol) {
      last = str;
    }
    str++;
  }

  if (*str == symbol) {
    return str;
  }
  return last;

}

size_t Strspn(const char* dest, const char* src) {
  size_t len = 0;

  for (int i = 0; *(dest + i) != '\0'; i++) {
    bool pass = false;

    for (int j = 0; *(src + j) != '\0'; j++) {
      if (*(dest + i) == *(src + j)) {
        pass = true;
        break;
      }
    }
    if (pass) {
      len++;
    } else {
      break;
    }
  }
  return len;
}

size_t Strcspn(const char* dest, const char* src) {
  size_t len = 0;

  for (int i = 0; *(dest + i) != '\0'; i++) {
    bool pass = true;

    for (int j = 0; *(src + j) != '\0'; j++) {
      if (*(dest + i) == *(src + j)) {
        return len;
      }
    }
    if (pass) {
      len++;
    } else {
      break;
    }
  }
  return len;
}

const char* Strpbrk(const char* dest, const char* breakset) {
  for (int i = 0; *(dest + i) != '\0'; i++) {
    for (int j = 0; *(breakset + j) != '\0'; j++) {
      if (*(dest + i) == *(breakset + j)) {
        return (dest + i);
      }
    }
  }
  return nullptr;
}

const char* Strstr(const char* str, const char* pattern) {
  size_t offset = 0;
  while (*str != '\0') {
    if (*(pattern + offset) == '\0') {
      return str - offset;
    }
    if (*str == *(pattern + offset)) {
      offset++;
    } else {
      str = str - offset;
      offset = 0;
    }
    str++;
  }
  if (*(pattern + offset) == '\0') {
    return str - offset;
  }
  if (*str == *(pattern + offset)) {
    offset++;
  } else {
    offset = 0;
  }
  return nullptr;
}