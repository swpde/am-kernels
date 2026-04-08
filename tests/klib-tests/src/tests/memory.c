#include <klibtest.h>

enum { N = 32 };

static uint8_t data[N];

static void reset_data(void) {
  for (int i = 0; i < N; i ++) {
    data[i] = i + 1;
  }
}

static void check_seq(int l, int r, uint8_t base) {
  for (int i = l; i < r; i ++) {
    check(data[i] == (uint8_t)(base + i - l));
  }
}

static void check_eq(int l, int r, uint8_t val) {
  for (int i = l; i < r; i ++) {
    check(data[i] == val);
  }
}

static void test_memset(void) {
  for (int l = 0; l < N; l ++) {
    for (int r = l + 1; r <= N; r ++) {
      reset_data();
      uint8_t val = (l + r) / 2;
      check(memset(data + l, val, r - l) == data + l);
      check_seq(0, l, 1);
      check_eq(l, r, val);
      check_seq(r, N, r + 1);
    }
  }
}

static void test_memcpy(void) {
  uint8_t src[N];
  uint8_t dst[N];

  for (int i = 0; i < N; i ++) {
    src[i] = (uint8_t)(0xa0 + i);
    dst[i] = 0;
  }

  check(memcpy(dst, src, N) == dst);
  check(memcmp(dst, src, N) == 0);
}

static void test_memmove(void) {
  char buf[16] = "0123456789";

  check(memmove(buf + 2, buf, 8) == buf + 2);
  check(memcmp(buf, "0101234567", 10) == 0);

  check(memmove(buf, buf + 2, 8) == buf);
  check(memcmp(buf, "0123456767", 10) == 0);
}

static void test_memcmp(void) {
  check(memcmp("abc", "abc", 3) == 0);
  check(memcmp("abc", "abd", 3) < 0);
  check(memcmp("abd", "abc", 3) > 0);
}

void test_memory(void) {
  test_memset();
  test_memcpy();
  test_memmove();
  test_memcmp();
}
