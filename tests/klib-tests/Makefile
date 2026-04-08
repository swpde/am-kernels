NAME = klib-test
SRCS = $(shell find src/ -name "*.c")

ifeq ($(KLIBTEST_INNER),1)
include $(AM_HOME)/Makefile
else

.PHONY: run gdb image clean

COLOR_RED   = \033[1;31m
COLOR_GREEN = \033[1;32m
COLOR_NONE  = \033[0m

run:
	@if $(MAKE) -s KLIBTEST_INNER=1 ARCH=$(ARCH) run; then \
		printf "[%14s] $(COLOR_GREEN)PASS$(COLOR_NONE)\n" $(NAME); \
	else \
		printf "[%14s] $(COLOR_RED)***FAIL***$(COLOR_NONE)\n" $(NAME); \
		exit 1; \
	fi

gdb image clean:
	@$(MAKE) KLIBTEST_INNER=1 ARCH=$(ARCH) $@

endif
