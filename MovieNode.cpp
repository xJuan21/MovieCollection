#include "MovieNode.hpp"

// FILE: MovieCollection.hpp
// AUTHOR: Juan Mota
// DATE: 11/2020
// Definition file for Movie Collection Class

using namespace std;

ostream& operator<<(ostream &os, const MovieNode &Node)
{
  os << Node.movie() ;
  return os;
}
