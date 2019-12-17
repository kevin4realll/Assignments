main: recursionMain.o recursiveFunctions.o
	g++ recursionMain.o recursiveFunctions.o -o main

recursiveMain.o: recursionMain.cpp
	g++ -c recursionMain.cpp

recursiveFunctions.o: recursiveFunctions.cpp
	g++ -c recursiveFunctions.cpp

clean:
	rm* .o 
