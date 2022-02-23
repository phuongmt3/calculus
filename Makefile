
all:
	g++ -std=c++17 -c calculus.cpp
	g++ -std=c++17 -c main.cpp
	g++ -std=c++17 calculus.o main.o -o main
run:
	chmod +x main
	./main
test:
	chmod +x mainTest
	./mainTest
clean:
	rm -rf *.o main mainTest