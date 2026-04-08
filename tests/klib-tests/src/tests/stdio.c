#include <klibtest.h>

void test_stdio(void) {
  char buf[64];
  char small[8];
  int ret;

  ret = sprintf(buf, "%s", "hello");
  check(ret == 5);
  check(strcmp(buf, "hello") == 0);

  ret = sprintf(buf, "%d + %d = %d", 2, 10, 12);
  check(ret == 11);
  check(strcmp(buf, "2 + 10 = 12") == 0);

  ret = sprintf(buf, "%c %u %x %%", 'A', 15u, 0x2a);
  check(ret == 9);
  check(strcmp(buf, "A 15 2a %") == 0);

  ret = snprintf(small, sizeof(small), "%s", "truncate");
  check(ret == 8);
  check(strcmp(small, "truncat") == 0);

  small[0] = 'x';
  ret = snprintf(small, 0, "%d", 1234);
  check(ret == 4);
  check(small[0] == 'x');
}
