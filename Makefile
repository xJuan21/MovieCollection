CC=g++ -c -g -Wall -ansi -pedantic 

runMe: test.o Movie.o MovieCollection.o 
	g++ -o runMe test.o Movie.o MovieCollection.o
	
test.o: test.cpp Movie.hpp MovieCollection.hpp 
	$(CC)  test.cpp
	
Movie.o: Movie.cpp Movie.hpp
	$(CC) Movie.cpp

MovieCollection.o: MovieCollection.cpp MovieCollection.hpp
	$(CC) MovieCollection.cpp
