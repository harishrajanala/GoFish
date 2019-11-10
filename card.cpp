#include "card.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

Card::Card(){

    mySuit=spades;
    myRank=ACE;
}

Card::Card(int rank, Suit s){

    mySuit=s;
    myRank=rank;
}

string Card::toString() const{

    return (rankString(myRank) + suitString(mySuit));
}

bool Card::sameSuitAs(const Card& c) const{

    if(this->mySuit == c.mySuit)
        return true;

    return false;
}

int Card::getRank() const{

    return myRank;
}

string Card::suitString(Suit s) const{

    string suits;

        switch (s){

        case spades:
            suits="s";
            break;
        case hearts:
            suits="h";
            break;
        case diamonds:
            suits="d";
            break;
        case clubs:
            suits="c";
            break;
        }

        return (suits);
    
}

string Card::rankString(int r) const{

    string numbers;

    switch(myRank){

    case ACE:
        numbers="A";
        break;
    case JACK:
        numbers="J";
        break;
    case QUEEN:
        numbers="Q";
        break;
    case KING:
        numbers="K";
        break;
    default:
        numbers = to_string(myRank);
    }
    return numbers;
}

bool Card::operator == (const Card& rhs) const{

    return ((myRank==rhs.myRank) && (mySuit==rhs.mySuit));

}

bool Card::operator != (const Card& rhs) const{

    return !((myRank==rhs.myRank) && (mySuit==rhs.mySuit));
}

ostream& operator << (ostream& out, const Card& c){

    
}
