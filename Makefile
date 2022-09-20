all: copy MINILIBMX little_clean

copy:
	mkdir obj
	cp inc/*.h obj
	cp src/*.c obj

MINILIBMX: object.o

object.o:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o part_of_the_matrix obj/*.c

little_clean:
	rm -rf obj

uninstall:
	rm -rf obj
	rm part_of_the_matrix

clean:
	rm -rf obj

reinstall:
	make uninstall
	make
