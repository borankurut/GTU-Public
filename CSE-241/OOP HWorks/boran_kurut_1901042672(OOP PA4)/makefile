OBJS	= Robot.o Bulldozer.o Roomba.o Humanic.o Optimusprime.o Robocop.o main.o
SOURCE	= Robot.cpp Bulldozer.cpp Roomba.cpp Humanic.cpp Optimusprime.cpp Robocop.cpp main.cpp
HEADER	= Robot.h Bulldozer.h Roomba.h Humanic.h Optimusprime.h Robocop.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Robot.o: Robot.cpp
	$(CC) $(FLAGS) Robot.cpp -std=c++11

Bulldozer.o: Bulldozer.cpp
	$(CC) $(FLAGS) Bulldozer.cpp -std=c++11

Roomba.o: Roomba.cpp
	$(CC) $(FLAGS) Roomba.cpp -std=c++11

Humanic.o: Humanic.cpp
	$(CC) $(FLAGS) Humanic.cpp -std=c++11

Optimusprime.o: Optimusprime.cpp
	$(CC) $(FLAGS) Optimusprime.cpp -std=c++11

Robocop.o: Robocop.cpp
	$(CC) $(FLAGS) Robocop.cpp -std=c++11

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)
