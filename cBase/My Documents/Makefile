OBJ=main.o add.o minus.o
CHEAD=-I ../include
CFLAG=-wall -O -g -c
CC=gcc
all:exe
		@echo "my second makefile"
		#mv exe ../obj
exe:$(OBJ)
	#	gcc -o exe main.o add.o minus.o
	   #$(CC) -o exe $(OBJ)
	   $(CC) -o $@ $^
		cp exe ../obj
main.o: main.c 
		$(CC) $(CFLAG) $(CHEAD) $<
add.o: add.c
		$(CC) $(CFLAG) $<
minus.o: minus.c
		$(CC) $(CFLAG) $<
PHONY:clean
clean:	
		rm *.o ../obj.exe
