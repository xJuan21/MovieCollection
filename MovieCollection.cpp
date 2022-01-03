#include "Movie.hpp"
#include "MovieCollection.hpp"

#include <iostream>
#include <fstream>

// FILE: MovieCollection.hpp
// AUTHOR: Juan Mota
// DATE: 11/2020
// Definition file for Movie Collection Class

using namespace std;

//Construct a new Movie Collector that takes an ifstream file as its only argument, adding as many movies as there are in the input stream
MovieCollection::MovieCollection(std::istream &iFile) : _head(NULL), _size(0) 
{
	Movie temp;
	if(iFile)
	{
		iFile >> temp; // Read the first Movie of the file (Title, Year, and Rating) and store it into the Movie Collection.
		insertAtHead(temp);// Insert a new Node with the current Movie at the Top of the List.
		while(iFile>>temp) // As long as the input file has movies to read.
			insertAtHead(temp);
	}
}
// 3rd type of constructor: Copy Constructor that takes in as its only parameter an existing MovieCollection and duplicates the existing MovieColection. (SHOULD NOT BE ALLOWED TO CHANGE)
MovieCollection::MovieCollection(const MovieCollection &Collection)
{	
	if(Collection.head() == NULL) // In case that the List that we are trying to copy is empty.
		_head = NULL;
		
	MovieNode* copy = Collection.head();	
	
	while(copy != NULL)
	{
		insertAtHead(copy->movie());
		copy = copy->next();
	}
	
	_size = Collection.size();		
}
//A method that returns the rating of a specific Movie in the Collection. It will be searched according to the title and year that are specified.
int 
MovieCollection::getRating(std::string title, int year)
{
	MovieNode* temp = head();
	Movie Curr;
	while(temp != NULL)
	{
		Curr = temp->movie();//Store the current Movie that is store in this Node.
		if(Curr.title() == title && Curr.year() == year)// If the attributes of this Movie match with the ones from the arguments.
			return Curr.rating();// return the rating of this Movie.
			
		temp = temp -> next();//If Movie not found. Go to the next Node.
	}
	
	return -1;// If the Movie was not found in the List. return rating = -1
}
//Return True if the Movie is already in the Collection or False if it's not.
bool
MovieCollection::findRepeated(MovieNode* Node, Movie NewMovie)
{	
	while(Node != NULL)
	{
		if(Node->movie() == NewMovie) // In case that the Movie is already in the Collection
			return true; // if it's true, do nothing 
			
		Node = Node->next();
	}
	return false;
}
//Insert a new MovieNode with the respective Data (Movie).
void
MovieCollection::insertAtHead(Movie New)
{
	MovieNode* temp = head();
	if(!findRepeated(temp, New)) //Make sure the Movie we are trying to insert is not already in the current Collection.
	{
		MovieNode* newNode = new MovieNode(New);
		newNode->next() = _head;
	  
		_head = newNode;
		_size++;
	}
}
//Remove the respective Movie that the user is looking for when this method is called.
void
MovieCollection::remove(Movie removeMe)
{
	MovieNode* temp = _head;
	MovieNode* _prev = _head;
	
	// In case that the Movie is stored at the head
	if (temp != NULL && temp->movie() == removeMe) 
    	{ 
        	_head = temp->next(); // Update the head of the list... move to the next Node
        	_size--;		//Decrease the amount of Movies in the Collection
        	delete temp;            // free space 
        	return; 
    	}
	
	// Traverse and Search for the Movie that we desire to delete from the list 
	while(temp != NULL && temp->movie() != removeMe)
	{
		_prev = temp; // Store the previous Node before it is updated
		temp = temp->next();// Update the list and move to the next Node until we find the correct location 
	}
	
	// In case that the Movie was not in the List
	if (temp == NULL) 
	        return;
	
	// Unlink the node from linked list 
	_prev->next() = temp->next();
	_size--;
	// Free space 
	delete temp;
}
//Clears out all the current Nodes of the Linked List when this method is called.
void
MovieCollection::clear()
{
	_head = NULL;//_head is now pointing to Nothing (NULL)
	_size = 0;// Now we have 0 Movies.
}

//Prints out the Movie Collection and its current movies stored in it
ostream&
MovieCollection::print(ostream &output) const
{
	MovieNode* temp = _head;
	
	if(temp == NULL)// Let the User know if the Movie Collection that is trying to print is empty or was cleared before
	{
		output << "This Collection is Empty.";
		return output;
	}
	 
	while(temp != NULL)
	{
		output << temp -> movie() << endl;
		temp = temp -> next();
	}
	
  return output;
}
//This method should simply return the 'union' between the two collections. Therefore. each Movie should be returned, but there should be no duplicates
const MovieCollection& 
MovieCollection::operator+(const MovieCollection &SecondCollection) const
{
	MovieCollection *result = new MovieCollection();
	MovieNode* left = head();
	MovieNode* right = SecondCollection.head();
	
	//Traverse the List of the Left operand.
	while(left != NULL)
	{
		*result += left->movie();
		left = left->next();
	}
	//Traverse the List of the Right operand.
	while(right != NULL)
	{
		*result += right->movie();
		right = right->next();
	}
	
	return *result;//Finally return the new Collection with the Union of both Movie Collections.
}
//Using this operator should return the "Intersection" of the two collections
const MovieCollection& 
MovieCollection::operator/(const MovieCollection &SecondCollection) const
{
	MovieCollection *result = new MovieCollection();
	MovieNode* left = head();//Pointer to the Left Hand Side Collection
	MovieNode* right = SecondCollection.head();//Pointer to the Right Hand Side Collection
	
	//Traverse the List from Left operand
	while(left != NULL)
	{
		//Traverse the List from right operand
		while(right != NULL)
		{
			if(left->movie() == right->movie())
				*result += left->movie();
				
			right = right->next();	
		}
		
		left = left->next();// Go to the next Node.
		right = SecondCollection.head(); // We reached to the last Node before, point back to the Head of the List.
	}
	
	return *result;//Finally return the new Collection with the Intersecting Movies.
}
//Using this Operator should cause the operand on the left hand side to change to be a copy of the one on the right hand side.
const MovieCollection& 
MovieCollection::operator=(const MovieCollection &SecondCollection)
{
	clear();//Empty the Current Collection in case it had something.
	MovieNode* temp = SecondCollection.head();
	while(temp != NULL)
	{
		operator+=(temp->movie());
		temp = temp->next();
	}
	_size = SecondCollection.size();
	return *this;
}
//Overloaded with the right-hand side being a single Movie and pass it efficiently (or do nothing if it is already in the collection).
const MovieCollection& 
MovieCollection::operator+=(const Movie &Movie)
{
	MovieNode* temp = head();
	if(!findRepeated(temp, Movie)) // if it is NOT a repeated movie. Store it in the collection on the left hand side. 
	{
		insertAtHead(Movie);
		return *this;
	}
		
	return *this; // Return the updated version of the left hand side Operand.
}
//This method should simply remove the Movie corresponding to the parameter from this selection (or do nothing when the movie is not in the current collection)
const MovieCollection& 
MovieCollection::operator-=(const Movie &Movie)
{
	remove(Movie);
	return *this;
}
//This method should simply add all of the Movies corresponding to the parameter to this collection (right hand side), and add it to a new Collection with non-repeated Movies.
const MovieCollection& 
MovieCollection::operator+=(const MovieCollection &SecondCollection)
{
	MovieNode* temp = SecondCollection.head();
	while(temp != NULL)
	{
		operator+=(temp->movie());
		temp = temp->next();
	}
	
	return *this;
}
//Remove each of the Movies in the collection corresponding to the parameter from this collection
const MovieCollection& 
MovieCollection::operator-=(const MovieCollection &SecondCollection)
{
	MovieNode* temp = SecondCollection.head();
	while(temp != NULL)
	{
		operator-=(temp->movie());
		temp = temp->next();
	}
	
	return *this;
}
//This method is Overloaded to call the method print() (ostream file on the left-hand side << MovieCollection on the right-hand side).			
ostream& operator<<(ostream &output, const MovieCollection &Collection)
{	
	return Collection.print(output);
}

