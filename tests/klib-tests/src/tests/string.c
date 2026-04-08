#include <klibtest.h>

void test_string(void) {
  char buf[32];
  char other[32];

  check(strlen("") == 0);
  check(strlen("hello") == 5);

  check(strcmp("abc", "abc") == 0);
  check(strcmp("abc", "abd") < 0);
  check(strcmp("abd", "abc") > 0);
  check(strncmp("abcdef", "abcxyz", 3) == 0);
  check(strncmp("abcdef", "abcxyz", 4) < 0);

  check(strcpy(buf, "hello") == buf);
  check(strcmp(buf, "hello") == 0);

  check(strncpy(other, "abc", 5) == other);
  check(other[0] == 'a' && other[1] == 'b' && other[2] == 'c');
  check(other[3] == '\0' && other[4] == '\0');

  check(strcat(buf, ", world") == buf);
  check(strcmp(buf, "hello, world") == 0);
}
