CC=gcc
CFLAGS=-Wall -Wextra -Werror
GCOV=-fprofile-arcs -ftest-coverage
OS=$(shell uname)
ifeq ($(OS), Linux)
	LIBS=-lcheck -lpthread -lrt -lm -lsubunit
	LEAKS=CK_FORK=no valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test.out
	OPEN=xdg-open
	testS=$(CC) -g test.c s21_math.a $(LIBS) -o test.out
else
	LIBS=-lcheck -lpthread -lm -lgcov
	LEAKS=CK_FORK=no leaks --atExit -- ./test.out
	OPEN=open
	testS=$(CC) -g test.c s21_math.a $(LIBS) -o test.out
endif

all: clean s21_math.a test

test: clean s21_math.a
	$(testS)
	./test.out

# eval "$(~/goinfre/homebrew/bin/brew shellenv)"
gcov_report:
	$(CC) --coverage -c s21_math.c
	ar rc s21_math.a *.o
	$(CC) test.c -L. s21_math.a $(LIBS) -o test_cov
	rm -rf *.o
	./test_cov
	gcov *.gcda
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	mkdir -p ./report
	genhtml -o report gcov_report.info
	$(OPEN) ./report/index.html

s21_math.a:
	$(CC) -c s21_math.c -o s21_math.o
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a

clean:
	rm -rf *.0 *.a *.gcno *.gcda *.info *.out report *.dSYM *.gch *.o test2.out .vscode .DS_Store s21_math.c.gcov test_cov CPPLINT.cfg s21_math ../.DS_Store ../.vscode a.out .clang-format

leaks: clean test
	$(LEAKS)

codestyle:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h
	rm -rf .clang-format

CPPcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

CH: clean leaks codestyle CPPcheck
	rm -rf *.0 *.a *.gcno *.gcda *.info *.out report *.dSYM test2.out *.gch *.o .vscode .DS_Store a.out s21_math.c.gcov test_cov CPPLINT.cfg s21_math ../.DS_Store ../.vscode 
