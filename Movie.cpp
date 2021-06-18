#include <iostream>
#include "Movie.h"

/*#TODO 4: implement Movie*/
/**
* Hints:
*  Destructor:
*      Get the vector of actors. Then for each actor remove it from the bag
*
*  addActor:
*       if the actor is in the bag return false, else return what the bag add method r
 *
 **/
 Movie::Movie() {
     title = "NA";
     releaseYear = 0;
     LinkedBag<Actor*> actors;
 }

 Movie::Movie(const string &aTitle, int year) {
     title = aTitle;
     releaseYear = year;
     LinkedBag<Actor*> actors;
 }
Movie::~Movie(){

 }

string Movie::getTitle() const {
     return title;
 }
void Movie::setTitle(const string &aTitle) {
     title = aTitle;
 }

int Movie::getReleaseYear() const {
     return releaseYear;
 }
void Movie::setReleaseYear(int year) {
     releaseYear = year;
 }

 std::ostream &operator <<(std::ostream& out, const Movie& aMovie ) {
     out << aMovie.getTitle() << std::endl;
     std::vector<Actor*> actorsList = aMovie.getActors();
     for(Actor* actor : actorsList) {
         out << "-" << actor->getName() << std::endl;
     }
     out << aMovie.getReleaseYear() << std::endl;
     return out;
 }


bool Movie::addActor(Actor* &anActor) {
    return actors.add(anActor);
}

bool Movie::removeActor(Actor* &anActor) {
    return actors.remove(anActor);
 }
vector<Actor*> Movie::getActors() const {
    return actors.toVector();
 }


