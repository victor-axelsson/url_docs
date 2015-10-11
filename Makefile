CC=g++
INCLUDES=$(wildcard include/*.h)
SRC=main.cpp $(wildcard src/*.cpp)
FLAGS=-std=c++11 -Wall -g

all: 
	$(CC) $(SRC) -o main -I include $(FLAGS)

clean:
	rm main