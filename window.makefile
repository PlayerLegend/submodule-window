C_PROGRAMS += test/window
C_PROGRAMS += test/window-printf

run-tests: run-window-tests
run-window-tests:
	sh run-tests.sh test/window test/window-printf

depend: window-depend
window-depend:
	cdeps src/window > src/window/depends.makefile

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
