
all:
	g++ -std=c++17 -c calculus.cpp
	g++ -std=c++17 -c calculusTest.cpp
	g++ -std=c++17 calculus.o calculusTest.o -lcppunit -o calculusTest
run:
	chmod +x main
	./main
test:
	chmod +x mainTest
	./mainTest
clean:
	rm -rf *.o main mainTest