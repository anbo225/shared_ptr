all:app
CFLAGS=-W -g
CC=g++
OBJ=main.o

app:$(OBJ)
$(CC) $(CFLAGS) -o app $(OBJ)

main.o:main.cpp SharedPtr.hpp
$(CC) $(CFLAGS) -c main.cpp

.PHONY:clean

clean:
-rm -f $(OBJ) app
