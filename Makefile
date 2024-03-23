main : 
	g++ -o build/main src/main.cpp src/Window.cpp `sdl2-config --cflags --libs`
	./build/main
