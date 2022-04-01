C_PROGRAMS += test/window
C_PROGRAMS += test/window-printf

run-tests: run-window-tests
run-window-tests:
	sh run-tests.sh test/window test/window-printf

depend: window-depend
window-depend:
	sh makedepend.sh src/window/window.makefile

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

# DO NOT DELETE

src/window/printf.o: src/range/def.h src/window/def.h src/window/printf.h
src/window/printf.o: src/window/alloc.h src/window/vprintf.h
src/window/vprintf.o: src/range/def.h src/window/def.h src/window/vprintf.h
src/window/vprintf.o: src/window/alloc.h
src/window/printf_append.o: src/range/def.h src/window/def.h
src/window/printf_append.o: src/window/printf.h src/window/alloc.h
src/window/printf_append.o: src/window/vprintf.h
src/window/test/printf.test.o: src/range/def.h src/window/def.h
src/window/test/printf.test.o: src/window/printf.h
src/window/test/window.test.o: src/range/def.h src/range/string.h
src/window/test/window.test.o: src/window/def.h src/window/alloc.h
src/window/test/window.test.o: src/window/string.h src/window/path.h
src/window/test/window.test.o: src/log/log.h
src/window/string.o: src/range/def.h src/window/def.h src/window/alloc.h
src/window/string.o: src/window/string.h
src/window/vprintf_append.o: src/range/def.h src/window/def.h
src/window/vprintf_append.o: src/window/vprintf.h src/window/alloc.h
src/window/path.o: src/range/def.h src/range/string.h src/window/def.h
src/window/path.o: src/window/path.h src/window/string.h src/window/alloc.h
src/window/path.o: src/log/log.h
src/window/alloc.o: src/window/string.h src/range/def.h src/window/def.h
src/window/alloc.o: src/window/alloc.h src/log/log.h
