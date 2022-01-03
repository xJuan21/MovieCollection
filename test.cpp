/* Author: Juan Mota
 *
 * Description: Use of a Movie Collector object that will serve to 
 * store "Movie" Objects and print them if necessary, the MovieCollection
 * object has the capacity of:
 *
 * -Adding more movies to the collection (+=) 
 * -Merging two movie collections together (NewCollection = Collection1 + Collection2)
 * -Deleting movie(s) from the collection (-=)
 * -Remove all the movies that match with another collection (Collection1 - Collection2)
 * -Duplicating on MovieCollection (NewCollection = OldCollection)
 * -Clearing out an entire Collection Object (Collection.Clear())
 * -Creating a new Collection by extracting Movies from a .txt file
 * -Find all the movies that intersect/match between to Collections (Collection1/Collection2)
 * -Print the amount of movies found in the collection (.size())
 * -Printing the rating from one specific movie in a MovieCollection 
 * 
 */
 
#include <iostream>
#include <fstream>
#include <string>
#include "Movie.hpp"
#include "MovieCollection.hpp"
using namespace std;

int main(int argc, char *arv[])
{  

	MovieCollection def; //A default constructor that will store 0 movies for now
	
	cout <<"\n\n--------|Default Collection (EMPTY)|-----------" << endl;
	cout << def << endl;
	cout << "\nI have: " << def.size() << " Movies" << endl;
	cout <<"-----------------------------------------------" << endl;
	
	Movie ToyStory("ToyStory", 2010, 8);//single movie created
	Movie marvel("Endgame", 2019, 10); 
	Movie Nemo("Nemo", 2000, 7); 
	
	def += marvel;// Add this movie, Now the collection has 1 current movie
	def += ToyStory;// Add this movie, Now the collection has 2 current movies
	def += ToyStory;// Try this to see if it duplicates the movie
	def += ToyStory;// Try this to see if it duplicates the movie
	def += Nemo;// Add this movie, Now the collection has 3 current movies
	
	cout <<"\n\n--------|Default+=Movie|----------------" << endl;
	cout << "Add 3 different types of Movies \nto the Empty Collection\n" << endl;
	cout << def << endl;
	cout << "I have: " << def.size() << " Movies" << endl;
	cout <<"----------------------------------------" << endl;
	
	cout <<"\n\n--------------DUPLICATE--------------" << endl;
	cout << "Makes a copy of the previous Collection\n" << endl;
	MovieCollection duplicate(def);
	cout << duplicate << endl;
	cout << "I have: " << duplicate.size() << " Movies" << endl;
	cout <<"-------------------------------------" << endl;
	
	cout <<"\n\n-------|Default-=Movie|-----------" << endl;
	def-=marvel;
	cout << "Delete: EndGame from the \noriginal Collection\n" << endl;
	cout << def << endl;
	cout << "I have: " << def.size() << " Movies" << endl;
	cout <<"----------------------------------" << endl;
	
	cout <<"\n\n-----------DUPLICATE(Again)-----------" << endl;
	cout << "Nothing should have changed this\n" << endl;
	cout << duplicate << endl;
	cout << "I have: " << duplicate.size() << " Movies" << endl;
	cout <<"--------------------------------------" << endl;
	
	def.clear();
	cout <<"\n\n--------CLEAR()----------" << endl;
	cout << def << endl;
	cout << "\nI have: " << def.size() << " Movies" << endl;
	cout <<"-------------------------" << endl;

	ifstream Netflix("Netflix.txt");
	MovieCollection fromFile(Netflix);  
	Netflix.close();
	
	cout <<"\n\n------------CollectionFromFile------------" << endl;
	//Movie Zorro("Mark of Zorro, The", 1940, 8); //Head of the List
	//Movie mag("Magnificent Seven, The", 1960, 7); // Middle of the List
	//fromFile-=mag;
	cout << fromFile << endl;
	cout << "I have: " << fromFile.size() << " Movies" << endl;
	cout <<"---------------------------------------" << endl;
	
	cout <<"\n\n------------|CopyFile=fromFile|------------" << endl;
	Movie Zorro("Mark of Zorro, The", 1940, 8); //Head of the List
	MovieCollection Z;
	Z += Zorro;
	//Movie mag("Magnificent Seven, The", 1960, 7); // Middle of the List
	//fromFile-=mag;
	cout << "By using operator=, create a new collection \nwith the same movies.\n"<<endl;
	MovieCollection CopyFile = fromFile;
	cout << CopyFile << endl;
	cout << "I have: " << CopyFile.size() << " Movies" << endl;
	cout <<"--------------------------------------------" << endl;
	
	cout <<"\n\n------------GetRating()--------------" << endl;
	cout << "(Mark of Zorro, The) Should give 8.\nIf not found, return -1.\n" << endl;
	cout << " ---Answer--->  " << fromFile.getRating("Mark of Zorro, The", 1940) << endl;
	cout <<"-------------------------------------" << endl;
	 
	cout <<"\n\n------------|Duplicate+=fromFile|------------" << endl;
	cout << "By using operator+=MovieCollection,\npass all the movies to the corresponding \nCollection on the left.\n"<<endl;
	duplicate += fromFile;
	cout << duplicate << endl;
	cout << "I have: " << duplicate.size() << " Movies" << endl;
	cout <<"--------------------------------------------" << endl;
	
	Movie stw1("Star Wars I", 1999, 4);
	Movie stw2("Star Wars II", 2002, 2);
	MovieCollection StarWars;
	StarWars += stw1;
	StarWars += stw2;
	
	cout <<"\n\n-------------|Duplicate-=StarWars|------------" << endl;
	cout << "By using operator-=MovieCollection,\nremove all the movies from the corresponding \nCollection on the left that match with the \nCollection on the right .\n"<<endl;
	duplicate -= StarWars;
	cout << duplicate << endl;
	cout << "I have: " << duplicate.size() << " Movies" << endl;
	cout <<"---------------------------------------------" << endl;
	
	cout <<"\n\n--------------|Duplicate/fromFile|------------" << endl;
	cout << "By using operator/MovieCollection, return a new \nCollection of Movies that 'intersect/match' \nbetween the left/right operand.\n"<<endl;
	MovieCollection intersection = duplicate/fromFile;
	cout << intersection << endl;
	cout << "I have: " << intersection.size() << " Movies" << endl;
	cout <<"--------------------------------------------" << endl;
	
	cout <<"\n\n--------------|Duplicate+CopyFile|------------" << endl;
	MovieCollection Sum = duplicate + CopyFile;
	cout << Sum << endl;
	cout << "I have: " << Sum.size() << " Movies" << endl;
	cout <<"----------------------------------------------" << endl;	
}
