all: polynomial.exe

polynomial.exe: main.o  variable.o subterm.o term.o
	g++ main.o  variable.o subterm.o term.o -o polynomial.exe

main.o: main.cpp model/monomial.hpp
	g++ -c main.cpp -o main.o

variable.o: model/variable.cpp model/variable.hpp
	g++ -c model/variable.cpp -o variable.o

subterm.o: model/subterm.cpp model/subterm.hpp
	g++ -c model/subterm.cpp -o subterm.o

term.o: model/term.cpp model/term.hpp
	g++ -c model/term.cpp -o term.o

.PHONY: clean

clean:
	rm -f polynomial.exe *.o