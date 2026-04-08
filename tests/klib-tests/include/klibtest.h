#ifndef __KLIB_TEST_H__
#define __KLIB_TEST_H__

#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

static inline __attribute__((unused)) void check(bool cond) {
  if (!cond) {
    halt(1);
  }
}

void test_string(void);
void test_memory(void);
void test_stdio(void);
void test_stdlib(void);

#endif
