# MovieCollection
Author: Juan Mota
11/16/2020.
Platform used: Linux.

Description: This program utilizes a Linked List inside of a "MovieCollection" object that will serve to store "Movie" Objects and print them if necessary. The purpose of this project was to enhance the knowledge about Data Structures and overloading operators with methods to interact with other objects in the program. the MovieCollection object has the capacity of executing the following actions with its assigned operators:

 -Adding more movies to the collection (+=)
 -Merging two movie collections together (NewCollection = Collection1 + Collection2) 
 -Deleting movie(s) from the collection (-=) 
 -Remove all the movies that match with another collection (Collection1 - Collection2) 
 -Duplicating on MovieCollection (NewCollection = OldCollection) 
 -Clearing out an entire Collection Object (Collection.Clear())  
 -Creating a new Collection by extracting Movies from a .txt file 
 -Find all the movies that intersect/match between to Collections (Collection1/Collection2)
 -Print the amount of movies found in the collection (.size())  
 -Printing the rating from one specific movie in a MovieCollection 

In order to compile the following Project, it was need to complete the following sequence of steps:

1.- Initialize:

	1.a A class called <MovieNode> that allows to Link multiple Nodes that store a single Movie for each Node.
  	This class contains 2 attributes/variables : One Movie that is used to store the data, and a pointer that is used
 	to link with other Nodes or point to NULL if it's the last one in the List.

	1.b A class called <MovieCollection> that primarily works with a Movie Node (head) and links with other Movies if necessary.
	Therefore, anytime a new Movie Node is added it'll resize its List and the amount of movies stored in the Collection.

	1.c A variable of type integer that allows to count/add the amount of movies that are stored in the Collection/List.
	It was used to work as a reference to the amount of Movies or Nodes that are currently in the Collection.

	1.d 3 Different types of constructors that would permit the user to choose how to create a MovieCollection Object.
	The situations were: 

	a) A default constructor that takes no arguments and stores Movies at their default value (No title, default year and default rating).
	b) A Contructor that takes a single parameter of ifstream to store movies from a .txt file
	c) A copy Constructor that is called whenever a copy of another MovieCollection was needed. Also, C++ takes this as a parameter if it needs to invoke values by reference.

	1.e Finally, multiple operators that are overloaded along the MovieCollection that allow the user to Add, Remove, Fusion, or Intersect Movies in a specific Collection.

2.- Special/Additional Steps:

	2.a A good understanding of Pointers and its use. Also, the difference between passing by reference or sending a copy of variables.

	2.b The correct use of the 3 constructors and their definition given since they were essential to avoid bugs or compile errors at the time of creating methods/operators

	2.c Acknowledment of Linked Lists and their structure. It was important the use of tracing their values with either diagrams or using Nemiver (Debugger)
	to complete multiple tasks that were required in the prcocess. 

	2.d The implementation of the Movie class provided and created by Dr.Blythe that were essential to define methods or use attributes during the proccess. 

	2.e Using the keyword const relative to parameters, methods and return values. This allowed to avoid changing the original values when it was not needed, 
	and create accessors that refer to variables without changing its content.

3.- Bugs:

<< No bugs have been found at this point. >>

In order to approach to the solution/creation of this project, it was essential to understand and review the use of pointers and how are related to the concept of Linked Lists and Nodes. Not to mention, using the debugger(Nemiver) allowed to track the value/data that was being stored in specific nodes, and also to find the origin of segmentation faults when they ocurred in the program.  

The operator<< and the method print() were the first things to be completed since those functions allow to start testing the program along the way and find any bugs/segmentation fault errors that might along the way. Consequently, a function to insert new movies was an essential step that allowed me to use it in most of the class functions to overload multiple operators, same as remove() function to overload operator -=Movie and -=MovieCollection.

It was very important to learn how to define methods and functions depending on the type of file (hpp or cpp) in order to refer correctly one to the another. The use of the correct keywords such as 'const' that were needed to define or execute variables without alterating their original values. Finally, it was important to understand the use of operators and how C++ uses them to execute functions according to what it is defined inside of them.
