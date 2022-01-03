#ifndef _MOVIECOLLECTION_HPP_
#define _MOVIECOLLECTION_HPP_

// FILE: MovieCollection.hpp
// AUTHOR: Juan Mota
// DATE: 11/2020
// Definition file for Movie Collection Class 

#include <iostream>
#include <fstream>

#include "Movie.hpp"
#include "MovieNode.hpp"

class MovieCollection
{
private:
  MovieNode *_head = NULL;
  int _size; //Current amount of movies in the Collection
  
public:
  //Default constructor
  MovieCollection() : _head(NULL), _size(0){}
  
  // A constructor that is built from an input stream
  MovieCollection(std::istream &iFile);

  // A copy constructor that takes in as its only parameter an existing MovieCollection duplicates the existing MovieCollection.
  MovieCollection(const MovieCollection &Collection);
  
  MovieNode* head() const {	return _head;	}
  
  //Accessor to the current amount of Movies in the Collection.
  const int size() const { 	return _size;	}
  
  // Method that looks for the rating of a specific Movie in the Collection.
  int getRating(std::string title, int year);
  
  //Function that will return true if if finds a repeated movie in the Collection.
  bool findRepeated(MovieNode* Node, Movie NewMovie);
  
  //Function that will store New Movies to the Collection.
  void insertAtHead(Movie New);
  
  //Function that removes specific Movies from the current Collection.
  void remove(Movie removeMe);

 //Function to print out Movie Collections via a stream 
  std::ostream& print(std::ostream &output) const;
  
  //A method that simply empties out the current collection. After calling this, it should appear as if there are no Movies in the current collection.
  void clear();
 
 // Overloading + operator with a MovieCollection as a parameter for the right-hand side.
  const MovieCollection& operator+(const MovieCollection &SecondCollection)const;
  
  // Overloading / operator with a MovieCollection as a parameter for the right-hand side.
  const MovieCollection& operator/(const MovieCollection &SecondCollection)const;
  
  // Overloading = operator with a MovieCollection as a parameter for the right-hand side.
  const MovieCollection& operator=(const MovieCollection &SecondCollection);
  
  //Overloading += operator with a Movie as a parameter for the right-hand side.
  const MovieCollection& operator+=(const Movie &Movie);
  
  // Overloading -= operator with a Movie as a parameter for the right-hand side.. 
  const MovieCollection& operator-=(const Movie &Movie);

  // Overloading += operator with a MovieCollection as a parameter for the right-hand side. 
  const MovieCollection& operator+=(const MovieCollection &SecondCollection);
 
  // Overloading -= operator with a MovieCollection as a parameter for the right-hand side. 
  const MovieCollection& operator-=(const MovieCollection &SecondCollection);
  
  // Overloading << operator. 
  friend std::ostream& operator<< (std::ostream &output, const MovieCollection &Collection);

};
#endif
