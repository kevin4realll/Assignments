output: linkList.o Node.o main.o Menu.o 
	g++ linkList.o Node.o main.o Menu.o -o output 

main.o: main.cpp
	g++ -c main.cpp

linkList.o: linkList.cpp linkList.hpp
	g++ -c linkList.cpp

Node.o: Node.cpp Node.hpp
	g++ -c Node.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

clean:
	rem* .o output
