OBJS = main.cpp

OBJ_NAME = main.exe

all : $(OBJS)
	g++ -g $(OBJS) -IC:\Development\SL2_MinGW_32bit\include -LC:\Development\SL2_MinGW_32bit\lib -w -lmingw32 -lSDL2main -lSDL2 -o $(OBJ_NAME)