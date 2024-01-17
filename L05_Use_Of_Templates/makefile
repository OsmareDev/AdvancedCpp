todo: test

alumno.o: alumno.cpp alumno.h
	g++ -Wall -c alumno.cpp

tabla_t.o: tabla_t.cpp tabla_t.h
	g++ -Wall -c tabla_t.cpp

test_tabla.o: test_tabla.cpp
	g++ -Wall -c test_tabla.cpp

test: test_tabla.o alumno.o tabla_t.o
	g++ -Wall test_tabla.o alumno.o tabla_t.o -o test

.PHONE: clean
clean:
	rm -rf *.o
	rm test