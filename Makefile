all: main

main: functions.o main.o root.o integral.o
	gcc -m32 -o main main.o functions.o

main.o: main.c
	gcc -m32 -o main.o -c -std=c99 main.c

functions.o: functions.asm
	nasm -f elf32 -o functions.o functions.asm

root.o: root.c
	gcc -m32 -o main -c -std=c99 root.c

integral.o: integral.c
	gcc -m32 -o main -c -std=c99 integral.c

clean:
	rm *.o
	rm main
