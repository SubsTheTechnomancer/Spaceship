OBJS = main.cpp

OBJ_NAME = main.exe

all : $(OBJS)
	g++ -g $(OBJS) -IC:\Development\SL2_MinGW_32bit\include -IC:\Development\SDL_Tff_MinGW_32bit\include -IC:\Development\SDL_Image_MinGW_32bit\include -LC:\Development\SL2_MinGW_32bit\lib -LC:\Development\SDL_Image_MinGW_32bit\lib -LC:\Development\SDL_Tff_MinGW_32bit\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -o $(OBJ_NAME)