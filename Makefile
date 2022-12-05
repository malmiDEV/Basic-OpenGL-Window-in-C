render=src/render.c
shader=src/shader.c
window=src/window.c

files=main.c glad.c src/global.c src/game.c $(render) $(shader) $(window)
libs=-L -lopengl32 -lglfw3 -lgdi32

all:
	gcc -c $(files) -g -Wall -m64 -I ../include && gcc *.o -o main $(libs) && .\main.exe