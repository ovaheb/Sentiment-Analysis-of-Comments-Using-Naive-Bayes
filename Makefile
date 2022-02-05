a.out: main.o model.o word.o
	g++ -std=c++11 main.o model.o word.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
model.o: model.cpp
	g++ -std=c++11 -c model.cpp
word.o: word.cpp
	g++ -std=c++11 -c word.cpp
clean:
	rm -f *.o