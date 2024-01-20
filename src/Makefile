CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
TARGET := s21_math.a

CHECKS=$(wildcard ./tests/test_*.check)
TEST_SRC=$(wildcard ./tests/test_*.c)

SRC=$(wildcard s21_*.c)
OBJ=$(patsubst %.c,%.o,$(SRC))

MSG=Minor bug fixes
BRANCH=$(shell git branch --show-current)

OS := $(shell uname -s)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: rebuild test gcov_report

rebuild: clean build

build: ${TARGET}

style:
	-@cp ../materials/linters/.clang-format .clang-format
	-@clang-format -i *.c
	-@clang-format -i *.h
	-@clang-format -i */*.c
	-@clang-format -i */*.h
	-@clang-format -i */*/*.c
	-@clang-format -i */*/*.h
	-@rm -rf .clang-format
	-@echo "Style is finished"

check_style:
	-@cp ../materials/linters/.clang-format .clang-format
	-@clang-format -n *.c
	-@clang-format -n *.h
	-@clang-format -n */*.c
	-@clang-format -n */*.h
	-@clang-format -n */*/*.c
	-@clang-format -n */*/*.h
	-@rm -rf .clang-format
	-@echo "Check style is finished"

clean:
	-@make clean_obj
	-@make clean_test
	-@make clean_gcov
	-@rm -rf *.a *.dSYM ./tests/test_*.c
	-@rm -rf *.out
	-@echo "Clean is finished"

gitgo:
	git add .
	git commit -m "$(BRANCH) $(MSG)"
	git push origin $(BRANCH)

test_s21_math.c: $(CHECKS)
	checkmk clean_mode=1 $(CHECKS) > ./tests//$@

${TARGET}: $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@
	cp $@ lib$@
	make clean_obj

clean_obj:
	-@rm -rf *.o

compile_test_c:
	make test_s21_math.c

compile_test:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) ${TEST_SRC} s21_math.a -o unit_test.out -lcheck -lm
else
	$(CC) $(CFLAGS) ${TEST_SRC} s21_math.a -o unit_test.out -lcheck $(LINUX_FLAGS)
endif


compile_gcov_test:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} -o gcov_test.out -lcheck -lm
else
	$(CC) $(CFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} -o gcov_test.out -lcheck $(LINUX_FLAGS)
endif

test:
	make compile_test_c
	make compile_test
	./unit_test.out

clean_test:
	-@rm -rf unit_test

# If lcov cause errors add "--filter range" after --no-external flag, works only on MAC
gcov_report:
	make compile_test_c
	make compile_gcov_test
	./gcov_test.out
	lcov -t "test" -o s21_test.info --no-external -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

clean_gcov:
	-@rm -rf *.gcda *.gcno *.info report gcov_test
