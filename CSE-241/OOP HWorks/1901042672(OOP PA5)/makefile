OBJS	= and.o circuit.o component.o decoder.o flipflop.o gate.o main.o not.o or.o token.o
SOURCE	= and.cpp circuit.cpp component.cpp decoder.cpp flipflop.cpp gate.cpp main.cpp not.cpp or.cpp token.cpp
HEADER	= and.h circuit.h component.h decoder.h flipflop.h gate.h not.h or.h token.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

and.o: and.cpp
	$(CC) $(FLAGS) and.cpp -std=c++11

circuit.o: circuit.cpp
	$(CC) $(FLAGS) circuit.cpp -std=c++11

component.o: component.cpp
	$(CC) $(FLAGS) component.cpp -std=c++11

decoder.o: decoder.cpp
	$(CC) $(FLAGS) decoder.cpp -std=c++11

flipflop.o: flipflop.cpp
	$(CC) $(FLAGS) flipflop.cpp -std=c++11

gate.o: gate.cpp
	$(CC) $(FLAGS) gate.cpp -std=c++11

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

not.o: not.cpp
	$(CC) $(FLAGS) not.cpp -std=c++11

or.o: or.cpp
	$(CC) $(FLAGS) or.cpp -std=c++11

token.o: token.cpp
	$(CC) $(FLAGS) token.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)

