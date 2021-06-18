/**
 * Laboratory #1 - CSCI2421 - Summer 2021
 * File: main.cpp
 */

#include <iostream> // For cout and cin
#include <string>   // For string objects
#include "Actor.h"
#include "Movie.h"
#include "StreamingService.h"



using namespace std;

int main()
{
    cout << string(80, '*')  << endl;
    cout << string(30, ' ')<< "LABORATORY #2"  << endl;
    cout << string(80, '*')  << endl;

    /**** SOME TESTS  */
    Actor* a1 = new Actor("John");
    cout<<a1->getName()<<endl;
    cout<<*a1<<endl;
    Actor* a2= new Actor("Alice");
    cout<<a2->getName()<<endl;
    cout<<*a2<<endl;


    cout<<endl;cout<<endl;
    Movie* m1 = new Movie("Movie 1",2021);
    cout<<*m1<<endl;
    cout<<"Adding John="<<m1->addActor(a1)<<endl;
    cout<<"Adding Alice="<<m1->addActor(a2)<<endl;
    cout<<"Adding John="<<m1->addActor(a1)<<endl;
    cout<<*m1<<endl;

    cout<<endl;cout<<endl;
    delete a1;
    delete a2;
    delete m1;


    StreamingService* myService = new StreamingService();

    myService->addActor("Daniel Radcliffe");
    myService->addActor("Emma Watson");
    myService->addActor("Rupert Grint");



    myService->addMovie("Harry Potter and the Philosopher's Stone", 2001);



    myService->addActorToMovie("Harry Potter and the Philosopher's Stone", "Daniel Radcliffe");
    myService->addActorToMovie("Harry Potter and the Philosopher's Stone", "Emma Watson");
    myService->addActorToMovie("Harry Potter and the Philosopher's Stone", "Rupert Grint");



    myService->addMovie("Harry Potter and the Chamber of Secrets",  2002);
    myService->addActorToMovie("Harry Potter and the Chamber of Secrets", "Daniel Radcliffe");
    myService->addActorToMovie("Harry Potter and the Chamber of Secrets", "Emma Watson");

    cout << *myService;




    /*********************************************************
     *         IMPLEMENT YOUR MAIN PROGRAM HERE
     *********************************************************/
    /*TODO 6: Finally implement your menu program*/

    char userInput;
    cout << "Choose an option from the menu below: " << endl;
    cout << "a. Display Movies" << endl
    << "b. Check movie availability" << endl
    << "c. Add new movie" << endl
    << "d. Add actor" << endl
    << "e. Add actor to movie" << endl
    << "f. Search for movie by title" << endl
    << "g. Exit";
    cin >> userInput;

    userInput = toupper(userInput);
    if(userInput == 'A')
    {
        cout << *myService;
    } else if (userInput == 'B') {
        string movieTitle;
        cout << "Enter movie name: ";
        cin >> movieTitle;
        cout << "Does movie exist: " << myService->isMovieAvailable(movieTitle);
    } else if(userInput == 'C') {
        cout << "Add a movie, enter title: ";
        string title;
        int year;
        cin >> title;
        cout << endl;
        cout << "Release year? ";
        cin >> year;
        cout << endl;
        myService->addMovie(title, year);
    } else if (userInput == 'D') {
        cout << "Enter actor's name";
        string actorName;
        cin >> actorName;
        myService->addActor(actorName);
    }
    else if (userInput == 'E')
    {
        string movie, actor;
        cout << "Enter title of movie: ";
        cin >> movie;
        cout << endl << "Enter an actor: ";
        cin >> actor;
        myService->addActorToMovie(movie,actor);
    } else if (userInput == 'F')
    {
        string titleToSearch;
        cout << "Enter a movie title to search: ";
        cin >> titleToSearch;
        Movie* aMovie = myService->searchMovie(titleToSearch);
        if (aMovie == nullptr) {
            cout << "Movie not found";
        }else {
            cout << aMovie;
        }
    } else {
        cout << "Program Terminated." <<endl;
    }
};
