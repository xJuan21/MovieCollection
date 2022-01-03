#ifndef _MOVIE_NODE_HPP_
#define _MOVIE_NODE_HPP_

// FILE: MovieCollection.hpp
// AUTHOR: Juan Mota
// DATE: 11/2020
//    Definition file for Movie Node Class 

#include <iostream>
#include "Movie.hpp"

class MovieNode
{
private:
  Movie _movie;//The desired data that we want to store.
  MovieNode* _next;//Pointer linking to other Nodes, or in case it is the last one, to NULL
public:
  //Default Constructor
  MovieNode(): _movie(), _next(NULL) {}
  //Constructor with a Movie as an argument
  MovieNode(Movie val): _movie(val), _next(NULL) {}

  Movie movie() const {return _movie;}
  Movie& movie() {return _movie;}

  MovieNode* next() const {return _next;}
  MovieNode*& next() {return _next;}
  
  friend std::ostream& operator<< (std::ostream &os, const MovieNode &Node);
};
#endif
