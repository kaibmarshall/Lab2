#include "Actor.h"

/*#TODO 3: Implement Actor*/

Actor::Actor() {
    name = "unknown";
}

Actor::Actor(const string &aName) {
    name = aName;
}

Actor::~Actor() {

}

const string &Actor::getName() const {
    return name;
}

void Actor::setName(const string &aName) {
    name = aName;
}

ostream &operator<<(ostream &out, const Actor &anActor) {
    out << anActor.getName();
    return out;
}
