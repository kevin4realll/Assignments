binarySearchExe: binarySearch.o inputVal.o
	g++ binarySearch.o inputVal.o -o binarySearchExe 

binarySearch.o: binarySearch.cpp
	g++ -c  binarySearch.cpp

selectionSortExe: selectionSort.o inputVal.o
	g++ selectionSort.o inputVal.o -o selectionSortExe

selectionSort.o: selectionSort.cpp
	g++ -c selectionSort.cpp

simpleSearchExe: simpleSearch.o inputVal.o
	g++ simpleSearch.o inputVal.o -o simpleSearchExe
 
simpleSearch.o: simpleSearch.cpp
	g++ -c simpleSearch.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ inputVal.cpp

clean:
	rm* .o binarySearchExe simpleSearchExe selectionSortExe 
