todo: sort_test	sort_stl 

sort_test.o: sort_test.cpp
	g++ -Wall -c -O2 sort_test.cpp

sort_stl.o: sort_stl.cpp
	g++ -Wall -c -O2 sort_stl.cpp

CountSort.o: CountSort.h CountSort.cpp Value.h
	g++ -Wall -c -O2 CountSort.cpp 

RadixSort.o: RadixSort.h RadixSort.cpp Value.h
	g++ -Wall -c -O2 RadixSort.cpp  

Crono.o: Crono.cpp
	g++ -Wall -c -O2 Crono.cpp

sort_test: sort_test.o CountSort.o RadixSort.o Crono.o
	g++ -Wall sort_test.o CountSort.o RadixSort.o Crono.o -O2 -o bin/sort_test

sort_stl: sort_stl.o
	g++ -Wall sort_stl.o -O2 -o bin/sort_stl

clean:
	rm -rf *.o
	rm bin/sort_test