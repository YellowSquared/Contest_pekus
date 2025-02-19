#include "cstring.cpp"
#include <iostream>
#include <cstring>
#include <cassert>
int main() {
  // const char* f = "abcd";
  // const char* d = "dcba";
  // std::cout << "STRLEN: " << Strlen(f) << '\n';
  // std::cout << "STRCMP: " << Strcmp(f, d) << '\n';
  // std::cout << "STRNCMP: " << Strncmp("abca", "abcabc", 4) << '\n';
  // std::cout << "STRNCMP2: " << std::strncmp("abca", "abcabc", 4) << '\n';

  // char* l = new char[100];
  // Strcpy(l, f);
  // std::cout << "STRCPY: " << l << '\n';

  // Strncpy(l, f, 40);
  // std::cout << "STRNCPY: " << l << '\n';

  // Strcat(l, "lol");
  // std::cout << "STRCAT: " << l << '\n';

  // Strncat(l, "lol", 1);
  // std::cout << "STRNCAT: " << l << '\n';

  // const char *result = Strchr(l, 'e');
  // std::cout << "STRCHR: " << strchr("", 'a') << '\n';

  // result = Strrchr(l, '1');
  // std::cout << "STRCHR: " << result << '\n';

  // size_t res = Strspn("42 — ответ на 128 вопрос.", "1234567890");
  // std::cout << "STRSPN: " << res << '\n';

  // res = Strcspn("hhhhh", "1234567890");
  // std::cout << "STRCSPN: " << res << '\n';

  // const char* res2 = Strpbrk("This is a Simple text.", "S");
  // std::cout << "STRCSPN: " << res2 << '\n';


  const char* res3 = Strstr("name@example.com", "@e");
  std::cout << "STRSTR: " << res3 << '\n';

  // delete[] l;

  // const char* a = "";
  // assert(Strlen(a) == std::strlen(a));


}