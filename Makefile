CC=gcc
AR=ar
OBJECT_MAIN=main.o
FLAGS= -Wall -g
OBJECT_BANK=myBank.o
all: myBank main 
main:$(OBJECT_MAIN) myBank
	$(CC) $(FLAGS) -o main $(OBJECT_MAIN) myBank
myBank: $(OBJECT_BANK) 
	$(AR) -rcs myBank $(OBJECT_BANK) 
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm myBank main *.o