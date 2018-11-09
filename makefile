output: main.cpp
	g++ -std=c++11 main.cpp Point.cpp Matrix.cpp lsystem.cpp Colour.cpp Turtle.cpp -o test -lglut -lGLU -lGL