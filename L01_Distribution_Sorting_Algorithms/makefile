todo: sort_test

sort_test.o: sort_test.cpp
	g++ -Wall -c sort_test.cpp

CountSort.o: CountSort.h CountSort.cpp Value.h
	g++ -Wall -c CountSort.cpp 

RadixSort.o: RadixSort.h RadixSort.cpp Value.h
	g++ -Wall -c RadixSort.cpp  

sort_test: sort_test.o CountSort.o RadixSort.o 
	g++ -Wall sort_test.o CountSort.o RadixSort.o -o bin/sort_test

clean:
	rm -rf *.o
	rm bin/sort_test