CC=gcc
AR=ar
OBJECT_MAIN=main.o
FLAGS= -Wall -g
OBJECT_BANK=myBank.o
all: libmyBank.a main 
main:$(OBJECT_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o main $(OBJECT_MAIN) libmyBank.a
libmyBank.a: $(OBJECT_BANK) 
	$(AR) -rcs libmyBank.a $(OBJECT_BANK) 
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm libmyBank.a main *.o