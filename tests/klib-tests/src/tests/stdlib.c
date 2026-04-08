#include <klibtest.h>

void test_stdlib(void) {
  check(abs(0) == 0);
  check(abs(7) == 7);
  check(abs(-7) == 7);

  check(atoi("0") == 0);
  check(atoi("12345") == 12345);
  check(atoi("   42xyz") == 42);

  srand(1);
  int r1 = rand();
  int r2 = rand();
  srand(1);
  check(rand() == r1);
  check(rand() == r2);

  unsigned char *p = malloc(16);
  unsigned char *q = malloc(24);
  check(p != NULL);
  check(q != NULL);
  check(p != q);
  check(((uintptr_t)p % sizeof(uintptr_t)) == 0);
  check(((uintptr_t)q % sizeof(uintptr_t)) == 0);

  for (int i = 0; i < 16; i ++) {
    p[i] = (unsigned char)(0xa0 + i);
  }
  for (int i = 0; i < 24; i ++) {
    q[i] = (unsigned char)(0xc0 + i);
  }
  for (int i = 0; i < 16; i ++) {
    check(p[i] == (unsigned char)(0xa0 + i));
  }
  for (int i = 0; i < 24; i ++) {
    check(q[i] == (unsigned char)(0xc0 + i));
  }

  free(p);
  free(q);
}
