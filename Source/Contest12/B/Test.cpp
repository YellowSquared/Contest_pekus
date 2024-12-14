#include <cassert>
#include <cstring>

#include "cstring.cpp"

bool SameSign(int x, int y) {
  return (x >= 0) ^ (y < 0);
}

void TestStrlen() {
  const char* a = "";
  const char* b = "a";
  const char* c = "a#b$c\n0\t";

  assert(Strlen(a) == std::strlen(a));
  assert(Strlen(b) == std::strlen(b));
  assert(Strlen(c) == std::strlen(c));
}

void TestStrcmp() {
  const char a[] = "";
  const char aa[] = "";
  const char b[] = "abca";
  const char bb[] = "abca";
  const char* c = "abcabc";
  const char* d = "cbac";
  const char* e = "cbacba";

  assert(SameSign(Strcmp(a, a), std::strcmp(a, a)));
  assert(SameSign(Strcmp(a, aa), std::strcmp(a, aa)));
  assert(SameSign(Strcmp(b, b), std::strcmp(b, b)));
  assert(SameSign(Strcmp(b, bb), std::strcmp(b, bb)));
  assert(SameSign(Strcmp(a, b), std::strcmp(a, b)));
  assert(SameSign(Strcmp(b, a), std::strcmp(b, a)));
  assert(SameSign(Strcmp(b, c), std::strcmp(b, c)));
  assert(SameSign(Strcmp(c, b), std::strcmp(c, b)));
  assert(SameSign(Strcmp(b, d), std::strcmp(b, d)));
  assert(SameSign(Strcmp(d, b), std::strcmp(d, b)));
  assert(SameSign(Strcmp(b, e), std::strcmp(b, e)));
  assert(SameSign(Strcmp(e, b), std::strcmp(e, b)));
  assert(SameSign(Strcmp(c, d), std::strcmp(c, d)));
  assert(SameSign(Strcmp(d, c), std::strcmp(d, c)));
}

void TestStrncmp() {
  const char a[] = "";
  const char aa[] = "";
  const char b[] = "abca";
  const char bb[] = "abca";
  const char* c = "abcabc";
  const char* d = "cbac";
  const char* e = "cbacba";

  assert(SameSign(Strncmp(a, a, 0), std::strncmp(a, a, 0)));
  assert(SameSign(Strncmp(a, aa, 100), std::strncmp(a, aa, 100)));
  assert(SameSign(Strncmp(b, b, 100), std::strncmp(b, b, 100)));
  assert(SameSign(Strncmp(b, bb, 0), std::strncmp(b, bb, 0)));
  assert(SameSign(Strncmp(b, bb, 2), std::strncmp(b, bb, 2)));
  assert(SameSign(Strncmp(a, b, 0), std::strncmp(a, b, 0)));
  assert(SameSign(Strncmp(b, a, 1), std::strncmp(b, a, 1)));
  assert(SameSign(Strncmp(b, c, 4), std::strncmp(b, c, 4)));
  assert(SameSign(Strncmp(c, b, 0), std::strncmp(c, b, 0)));
  assert(SameSign(Strncmp(b, d, 3), std::strncmp(b, d, 3)));
  assert(SameSign(Strncmp(d, b, 100), std::strncmp(d, b, 100)));
  assert(SameSign(Strncmp(b, e, 3), std::strncmp(b, e, 3)));
  assert(SameSign(Strncmp(e, b, 100), std::strncmp(e, b, 100)));
}

void TestStrchr() {
  const char* a = "";
  const char* b = "k#ba$ca\nb\t0e";

  assert(Strchr(a, 'a') == std::strchr(a, 'a'));
  assert(Strchr(a, '\0') == std::strchr(a, '\0'));
  assert(Strchr(b, 'd') == std::strchr(b, 'd'));
  assert(Strchr(b, '\0') == std::strchr(b, '\0'));
  assert(Strchr(b, 'a') == std::strchr(b, 'a'));
  assert(Strchr(b, '\n') == std::strchr(b, '\n'));
  assert(Strchr(b, '0') == std::strchr(b, '0'));
  assert(Strchr(b, 'e') == std::strchr(b, 'e'));
  assert(Strchr(b, 'k') == std::strchr(b, 'k'));
}

void TestStrrchr() {
  const char* a = "";
  const char* b = "k#ba$ca\nb\t0e";

  assert(Strrchr(a, 'a') == std::strrchr(a, 'a'));
  assert(Strrchr(a, '\0') == std::strrchr(a, '\0'));
  assert(Strrchr(b, 'd') == std::strrchr(b, 'd'));
  assert(Strrchr(b, '\0') == std::strrchr(b, '\0'));
  assert(Strrchr(b, 'a') == std::strrchr(b, 'a'));
  assert(Strrchr(b, '\n') == std::strrchr(b, '\n'));
  assert(Strrchr(b, '0') == std::strrchr(b, '0'));
  assert(Strrchr(b, 'e') == std::strrchr(b, 'e'));
  assert(Strrchr(b, 'k') == std::strrchr(b, 'k'));
}

void TestStrspn() {
  const char* a = "";
  const char* b = "abc";
  const char* c = "ababab";
  const char* d = "#0\nfg";

  assert(Strspn(a, a) == std::strspn(a, a));
  assert(Strspn(b, b) == std::strspn(b, b));
  assert(Strspn(b, a) == std::strspn(b, a));
  assert(Strspn(a, b) == std::strspn(a, b));
  assert(Strspn(b, c) == std::strspn(b, c));
  assert(Strspn(c, b) == std::strspn(c, b));
  assert(Strspn(c, d) == std::strspn(c, d));
  assert(Strspn(d, c) == std::strspn(d, c));
}

void TestStrcspn() {
  const char* a = "";
  const char* b = "abc";
  const char* c = "ababab";
  const char* d = "#0\nfg";

  assert(Strcspn(a, a) == std::strcspn(a, a));
  assert(Strcspn(b, b) == std::strcspn(b, b));
  assert(Strcspn(b, a) == std::strcspn(b, a));
  assert(Strcspn(a, b) == std::strcspn(a, b));
  assert(Strcspn(b, c) == std::strcspn(b, c));
  assert(Strcspn(c, b) == std::strcspn(c, b));
  assert(Strcspn(c, d) == std::strcspn(c, d));
  assert(Strcspn(d, c) == std::strcspn(d, c));
}

void TestStrpbrk() {
  const char* a = "";
  const char* b = "abc";
  const char* c = "ababab";
  const char* d = "#0\nfg";

  assert(Strpbrk(a, a) == std::strpbrk(a, a));
  assert(Strpbrk(b, b) == std::strpbrk(b, b));
  assert(Strpbrk(b, a) == std::strpbrk(b, a));
  assert(Strpbrk(a, b) == std::strpbrk(a, b));
  assert(Strpbrk(b, c) == std::strpbrk(b, c));
  assert(Strpbrk(c, b) == std::strpbrk(c, b));
  assert(Strpbrk(c, d) == std::strpbrk(c, d));
  assert(Strpbrk(d, c) == std::strpbrk(d, c));
}

void TestStrstr() {
  const char* a = "";
  const char* b = "aabc";
  const char* c = "dddaabdddabcaabcd";
  const char* d = "zxcbav";
  const char* e = "aab";
  const char* f = "aaab";
  const char* g = "abcabcabcd";
  const char* h = "abcabcd";
  assert(Strstr(a, a) == std::strstr(a, a));
  assert(Strstr(b, b) == std::strstr(b, b));
  assert(Strstr(b, a) == std::strstr(b, a));
  assert(Strstr(a, b) == std::strstr(a, b));
  assert(Strstr(b, b) == std::strstr(b, b));
  assert(Strstr(c, b) == std::strstr(c, b));
  assert(Strstr(d, b) == std::strstr(d, b));
  assert(Strstr(f, e) == std::strstr(f, e));
  assert(Strstr(g, h) == std::strstr(g, h));
}

void TestStrcpy() {
  const char* a = "";
  const char* b = "abc";
  char c[10] = "defg";

  assert(std::strcmp("fg", Strcpy(c, c + 2)) == 0);
  assert(std::strcmp("f", Strcpy(c + 1, a) - 1) == 0);
  assert(std::strcmp("fabc", Strcpy(c + 1, b) - 1) == 0);
  assert(std::strcmp("fababc", Strcpy(c + 3, b) - 3) == 0);
  assert(std::strcmp("abc", Strcpy(c, b)) == 0);
  assert(std::strcmp("", Strcpy(c, a)) == 0);
}

void TestStrncpy() {
  const char* a = "";
  const char* b = "abc";
  char c[10] = "defg";

  assert(std::strcmp("fg", Strncpy(c, c + 2, 5)) == 0);
  assert(std::strcmp("f", Strncpy(c + 1, a, 5) - 1) == 0);
  assert(std::strcmp("fab", Strncpy(c + 1, b, 2) - 1) == 0);
  assert(std::strcmp("abb", Strncpy(c, b, 2)) == 0);
  assert(std::strcmp("abc", Strncpy(c, b, 5)) == 0);
  assert(std::strcmp("abc", Strncpy(c, b, 0)) == 0);
  assert(std::strcmp("", Strncpy(c, a, 1)) == 0);
}

void TestStrcat() {
  const char* a = "";
  const char* b = "abc";
  char c[10]{};

  assert(std::strcmp("", Strcat(c, a)) == 0);
  assert(std::strcmp("abc", Strcat(c, b)) == 0);
  assert(std::strcmp("abc", Strcat(c, a)) == 0);
  assert(std::strcmp("abcbc", Strcat(c, b + 1)) == 0);
}

void TestStrncat() {
  const char* a = "";
  const char* b = "abc";
  char c[10]{};

  assert(std::strcmp("", Strncat(c, a, 5)) == 0);
  assert(std::strcmp("ab", Strncat(c, b, 2)) == 0);
  assert(std::strcmp("ababc", Strncat(c, b, 4)) == 0);
  assert(std::strcmp("ababcb", Strncat(c, b + 1, 1)) == 0);
}

int main() {
  TestStrlen();
  TestStrcmp();
  TestStrncmp();
  TestStrchr();
  TestStrrchr();
  TestStrspn();
  TestStrcspn();
  TestStrpbrk();
  TestStrstr();
  TestStrcpy();
  TestStrncpy();
  TestStrcat();
  TestStrncat();
  return 0;
}