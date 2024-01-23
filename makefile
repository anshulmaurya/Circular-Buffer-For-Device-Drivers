all:
	# /usr/bin/g++ -std=c++20 -o exe  main.cpp 
	/usr/bin/g++ -std=c++20  -c circularBuffer.cpp -I buffer
	/usr/bin/g++ -std=c++20  -c main.cpp
	/usr/bin/g++ -std=c++20 circularBuffer.o main.o -o exe
 

clean:
	rm *.o
	clear

