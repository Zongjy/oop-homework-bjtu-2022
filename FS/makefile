fs:fs.o main.o
	g++ main.o fs.o -o fs 
main.o:main.cpp
	g++ main.cpp -c -g -o main.o
fs.o:fs.cpp
	g++ fs.cpp -c -g -o fs.o

clean:
	rm -f *.o