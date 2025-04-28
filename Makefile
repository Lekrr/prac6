CFLAGS = -m32 -c -std=c99
TARGET = main

all: $(TARGET)

$(TARGET): functions.o main.o root.o integral.o
	gcc -no-pie -m32 -o $(TARGET) main.o functions.o root.o integral.o

main.o: main.c
	gcc $(CFLAGS) -o main.o main.c

main.c: functions.h root.h integral.h

functions.o: functions.asm
	nasm -f elf32 -o functions.o functions.asm

root.o: root.c
	gcc $(CFLAGS) -o root.o root.c

integral.o: integral.c
	gcc $(CFLAGS) -o integral.o integral.c

test_root:
	gcc $(CFLAGS) -g root.c -o test/root.o
	gcc -m32 -g -o test/test_root test/test_root.c test/root.o -lm

test_integral:
	gcc $(CFLAGS) -g integral.c -o test/integral.o
	gcc -m32 -g -o test/test_integral test/test_integral.c test/integral.o -lm

debug/debug_main: debug/main_d.o debug/functions_d.o debug/root_d.o debug/integral_d.o
	gcc -no-pie -m32 -o debug/debug_main debug/main_d.o debug/functions_d.o

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
	rm test/test_integral test/test_root test/*.o
	rm debug/*.o debug/debug_main
