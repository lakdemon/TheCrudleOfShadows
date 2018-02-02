install: main.cpp
	 g++ -c main.cpp
	 g++ main.o -o run -lsfml-graphics -lsfml-window -lsfml-system