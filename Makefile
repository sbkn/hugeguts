game:
	g++ main.cpp -o play -I include -L lib -l SDL2-2.0.0
opengl:
	g++ opengl-test.cpp game.cpp input.cpp renderer.cpp -o opengltest -I include -L lib -l SDL2-2.0.0 -framework OpenGL