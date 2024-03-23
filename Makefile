main : 
	gcc -o build/main main.c `sdl2-config --cflags --libs`
	./build/main
