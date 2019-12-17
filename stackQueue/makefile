output: lab9.o Queue.o stringStack.o 
	g++ lab9.o Queue.o stringStack.o -o output

lab9.o: lab9.cpp
	g++ -c lab9.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -c Queue.cpp

stringStack.o: stringStack.cpp stringStack.hpp
	g++ -c stringStack.cpp
clean:
	rm* .o output 
