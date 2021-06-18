//
// Created by Javier Pastorino on 6/10/21.
//

#ifndef INC_2021_SUMMER_CSCI2421_MOVIE_H
#define INC_2021_SUMMER_CSCI2421_MOVIE_H

#include <string>
#include "LinkedBag.h"
#include "Actor.h"

using namespace std;

class Movie {
private:
    string title;
    int releaseYear;
    LinkedBag<Actor*> actors;

public:
    explicit Movie();
    explicit Movie(const string &aTitle, int year);
    ~Movie();

    string getTitle() const;
    void setTitle(const string &aTitle);

    int getReleaseYear() const;
    void setReleaseYear(int year);

    friend std::ostream &operator <<(std::ostream& out, const Movie& aMovie );


    bool addActor(Actor* &anActor);

    bool removeActor(Actor* &anActor);
    vector<Actor*> getActors() const;



};

#include "Movie.cpp"


#endif //INC_2021_SUMMER_CSCI2421_MOVIE_H
