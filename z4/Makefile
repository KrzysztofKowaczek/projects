#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: system_of_equations
	./system_of_equations < data.dat

system_of_equations: obj/main.o obj/SystemOfLinearEquations.o obj/Complex.o
	g++ -Wall -pedantic -o system_of_equations obj/main.o obj/Complex.o\
                                    obj/SystemOfLinearEquations.o

obj/main.o: src/main.cpp inc/SystemOfLinearEquations.hh inc/Matrix.hh inc/Vector.hh inc/Size.hh inc/Complex.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/SystemOfLinearEquations.o: src/SystemOfLinearEquations.cpp inc/SystemOfLinearEquations.hh inc/Complex.hh
	g++ ${CPPFLAGS} -o obj/SystemOfLinearEquations.o src/SystemOfLinearEquations.cpp

obj/Complex.o: src/Complex.cpp inc/Complex.hh
	g++ ${CPPFLAGS} -o obj/Complex.o src/Complex.cpp

clean:
	rm -f obj/*.o system_of_equations