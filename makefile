main: main.cpp screen.cpp airplane.cpp 
	g++ -o main readAppearance.cpp screen.cpp airplane.cpp monster.cpp main.cpp -std=c++11 -pthread -lncurses
