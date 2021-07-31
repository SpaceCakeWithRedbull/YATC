start_point:
	g++ -c main.cpp
	g++ -c block.cpp
	g++ -c piece.cpp
	g++ -c board.cpp
	g++ main.o board.o block.o piece.o -lsfml-graphics -lsfml-window -lsfml-system
	./a.out