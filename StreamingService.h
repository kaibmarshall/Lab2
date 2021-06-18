
#ifndef INC_2021_SUMMER_CSCI2421_STREAMINGSERVICE_H
#define INC_2021_SUMMER_CSCI2421_STREAMINGSERVICE_H

#include "string"
#include "LinkedBag.h"
#include "Movie.h"
#include "Actor.h"

using namespace std;

class StreamingService {
private:
    LinkedBag<Movie*> movies;
    LinkedBag<Actor*> actors;


public:
    explicit StreamingService();
    virtual ~StreamingService();

    bool addMovie(const string& title, int year);
    bool addActor(const string& name);
    bool addActorToMovie(const string& title, const string& actorName);
    bool isMovieAvailable(const string& title);

    Movie* searchMovie(const string& title);
    Actor* searchActor(const string& actorName);

    friend std::ostream & operator<< (std::ostream& out, const StreamingService& service );
};

#include "StreamingService.cpp"

#endif //INC_2021_SUMMER_CSCI2421_STREAMINGSERVICE_H
