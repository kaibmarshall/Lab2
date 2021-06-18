
#include <iostream>
#include <string>
#include "StreamingService.h"

/*#TODO 5: Implement the Streaming Service.*/

/**
 * HINTS:
 *    Destructor:
 *              Retrieve movies and actors as vectors.
 *              For each movie the vector, remove it form the bag, and delete it.
 *              For each actor in the vector, remove it form the bag and delete it.
 *    addMovie:
 *              should create (new) the new movie.
 *    addActor:
 *              should create the new actor.
 *
 *    addActorToMovie:
 *                      no creation of new objects here. just search.
 *                      make sure you didn't get a nullptr
 *
 *    isMovieAvailable:
 *                      use search
 *
 *    search (either actor or movie):
 *                      get the objects as vectors. compare the data here.
 *
 */


StreamingService::StreamingService() {
    LinkedBag<Movie*> movies;
    LinkedBag<Actor*> actors;
}

StreamingService::~StreamingService() {
    std::vector<Movie*> movieVector = movies.toVector();
    std::vector<Actor*> actorVector = actors.toVector();

    for (Movie* movie : movieVector)
    {
        movies.remove(movie);
    }

    for (Actor* actor : actorVector)
    {
        actors.remove(actor);
    }

}

bool StreamingService::addMovie(const string& title, int year) {
    Movie* movie = new Movie(title, year);
    return movies.add(movie);
}

bool StreamingService::addActor(const string &name) {
    Actor* actor = new Actor(name);
    return actors.add(actor);
}

bool StreamingService::addActorToMovie(const string& title, const string& actorName) {
    Movie* movie = searchMovie(title);
    if (movie != nullptr) {
        Actor* a = new Actor(actorName);
        return movie->addActor(a);
    } else {
        return false;
    }
}

bool StreamingService::isMovieAvailable(const string& title){
    Movie* movie = searchMovie(title);
    bool isAvailable = (movie == nullptr);
    return isAvailable;
}

Movie* StreamingService::searchMovie(const string& title) {
    std::vector<Movie*> movieList = movies.toVector();
    for(Movie* movie : movieList) {
        string movieTitle = movie->getTitle();
        if(movieTitle.compare(title) == 0) { //if title is equal to movieTitle
           return movie;
        }
    }
    return nullptr;
}

Actor* StreamingService::searchActor(const string& actorName){
    std::vector<Actor*> actorList = actors.toVector();
    for (Actor* actor : actorList)
    {
        string actorTitle = actor->getName();
        if (actorTitle.compare(actorName) == 0)
            return actor;
    }

    return nullptr;
}

std::ostream& operator<< (std::ostream& out, const StreamingService& service ) {
    std::vector<Movie*> movieList = service.movies.toVector();
    for(Movie* movie : movieList) {
        out << *movie;
    }
    return out;
}

