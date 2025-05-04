CFLAGS = -m32 -c -std=c99
TARGET = main

all: $(TARGET)

$(TARGET): functions.o main.o root.o integral.o test_integral.o test_root.o
	gcc -no-pie -m32 -o $(TARGET) main.o functions.o root.o integral.o test_root.o test_integral.o -lm

main.o: main.c
	gcc $(CFLAGS) -o main.o main.c

main.c: functions.h root.h integral.h output.h
	touch main.c

functions.o: functions.asm
	nasm -f elf32 -o functions.o functions.asm

root.o: root.c
	gcc $(CFLAGS) -o root.o root.c

root.c: main.h
	touch root.c

integral.o: integral.c
	gcc $(CFLAGS) -o integral.o integral.c

integral.c: main.h
	touch integral.c

test_integral.o: test_integral.c
	gcc $(CFLAGS) -o test_integral.o test_integral.c

test_integral.c: integral.h
	touch test_integral.c

test_root.o: test_root.c
	gcc $(CFLAGS) -o test_root.o test_root.c

test_root.c: root.h
	touch test_root.c

debug/debug_main: debug/main_d.o debug/functions_d.o debug/root_d.o debug/integral_d.o
	gcc -no-pie -m32 -o debug/debug_main debug/main_d.o debug/functions_d.o debug/root_d.o debug/integral_d.o

debug/main_d.o: main.c
	gcc $(CFLAGS) -g -o debug/main_d.o main.c

debug/functions_d.o: functions.asm
	nasm -f elf32 -g -o debug/functions_d.o functions.asm

debug/root_d.o: root.c
	gcc $(CFLAGS) -g -o debug/root_d.o root.c

debug/integral_d.o: integral.c
	gcc $(CFLAGS) -g -o debug/integral_d.o integral.c

clean:
	rm *.o $(TARGET)
	rm debug/*.o debug/debug_main
