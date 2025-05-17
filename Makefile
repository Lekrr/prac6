CFLAGS = -m32 -c -std=c99
TARGET = main

all: $(TARGET)

$(TARGET): functions.o main.o root.o integral.o test_integral.o test_root.o
	gcc -no-pie -m32 -o $(TARGET) main.o functions.o root.o integral.o test_root.o test_integral.o -lm

main.o: main.c functions.h root.h integral.h output.h
	gcc $(CFLAGS) -o main.o main.c

functions.o: functions.asm
	nasm -f elf32 -o functions.o functions.asm

root.o: root.c main.h
	gcc $(CFLAGS) -o root.o root.c

integral.o: integral.c main.h
	gcc $(CFLAGS) -o integral.o integral.c

test_integral.o: test_integral.c integral.h
	gcc $(CFLAGS) -o test_integral.o test_integral.c

test_root.o: test_root.c root.h
	gcc $(CFLAGS) -o test_root.o test_root.c

clean:
	rm *.o $(TARGET)
