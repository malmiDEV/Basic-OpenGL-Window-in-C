render=src/render.c src/render_init.c
shader=src/shader.c
window=src/window.c
camera=src/camera.c 

files=main.c glad.c src/global.c src/game.c $(render) $(shader) $(window) $(camera)
libs=-L -lopengl32 -lglfw3 -lgdi32

all:
	gcc -c $(files) -g -Wall -m64 -I ../include && gcc *.o -o main $(libs) && .\main.exe