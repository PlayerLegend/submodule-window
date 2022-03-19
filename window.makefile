C_PROGRAMS += test/window
C_PROGRAMS += test/window-printf

RUN_TESTS += test/window
RUN_TESTS += test/window-printf

test/window: src/window/test/window.test.o
test/window: src/window/alloc.o
test/window: src/window/string.o
test/window: src/window/path.o
test/window: src/range/strdup.o
test/window: src/range/streq_string.o
test/window: src/range/string_tokenize.o
test/window: src/range/streq.o
test/window: src/range/strchr.o
test/window: src/range/strdup.o
test/window: src/range/string_init.o
test/window: src/log/log.o

test/window-printf: src/window/test/printf.test.o
test/window-printf: src/window/printf.o
test/window-printf: src/window/printf_append.o
test/window-printf: src/window/vprintf.o
test/window-printf: src/window/vprintf_append.o
test/window-printf: src/window/alloc.o

window-tests: test/window
window-tests: test/window-printf
tests: window-tests
