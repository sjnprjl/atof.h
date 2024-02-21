all: atof.h
	gcc main.c -o main

clean:
	rm -rvf ./main
