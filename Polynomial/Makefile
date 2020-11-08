OBJECTS= variable.o subterm.o term.o
HEADERS_ONLY= model/polynomials/monomial.hpp model/polynomials/polynomial.hpp
INCLUDE= -I./model/polynomials

all: polynomial.exe

polynomial.exe: main.o $(OBJECTS) 
	g++ main.o variable.o subterm.o term.o -o polynomial.exe

main.o: main.cpp model/polynomials/monomial.hpp model/polynomials/polynomial.hpp
	g++ -c main.cpp $(INCLUDE) -o main.o

variable.o: model/polynomials/variable.cpp model/polynomials/variable.hpp
	g++ -c model/polynomials/variable.cpp $(INCLUDE) -o variable.o

subterm.o: model/polynomials/subterm.cpp model/polynomials/subterm.hpp model/polynomials/variable.hpp
	g++ -c model/polynomials/subterm.cpp $(INCLUDE) -o subterm.o

term.o: model/polynomials/term.cpp model/polynomials/term.hpp model/polynomials/variable.hpp model/polynomials/subterm.hpp
	g++ -c model/polynomials/term.cpp $(INCLUDE) -o term.o

.PHONY: clean

clean:
	rm -f polynomial.exe *.o