todo: memcost memcost2

Utils.o: Utils.cpp
	g++ -Wall -c Utils.cpp -O2

memcost.o: memcost.cpp
	g++ -Wall -c memcost.cpp -O2

memcost2.o: memcost2.cpp
	g++ -Wall -c memcost2.cpp -O2

memcost: memcost.o Utils.o
	g++ -Wall memcost.o -o memcost -O2

memcost2: memcost2.o Utils.o
	g++ -Wall memcost2.o -o memcost2 -O2

.PHONE: clean
clean:
	rm -rf *.o
	rm memcost
	rm memcost2