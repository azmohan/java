OBJ=main.o
BUILT=ar -cr ../lib/libmylib.a
LIB=add.o minus.o
LIBAR=-L ../lib -l mylib
CHEAD=-I ../include
CFLAG=-Wall -O -g -c
CC=gcc
all:exe
		@echo "my second makefile"
		#mv exe ../obj
exe:$(OBJ) mylib
	#	gcc -o exe main.o add.o minus.o
	   #$(CC) -o exe $(OBJ)
	   $(CC) -o $@ $(OBJ) $(LIBAR)
		cp exe ../obj
main.o: main.c
		$(CC) $(CFLAG) $(CHEAD) $<
mylib:$(LIB)
		$(BUILT) $(LIB)
	#	cp libmylib.a ../lib
add.o: add.c
		$(CC) $(CFLAG) $<
minus.o: minus.c
		$(CC) $(CFLAG) $<
PHONY:clean
clean:
		rm *.o ../obj/exe ../lib/libmylib.a
