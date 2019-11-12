#include "player.h"
#include "card.h"
#include "deck.h"
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

void Player::addCard(Card c){

    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){

    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2){

    for(int i=0; i<getHandSize(); i++){

        for(int j=i+1; j<getHandSize();j++){

            if(myHand[i].getRank() == myHand[j].getRank()){
                c1=myHand[i];
                c2=myHand[j];
                myHand.erase(myHand.begin()+i);
                myHand.erase(myHand.begin()+(j-1));
                return true;
            }
        }
    }
    return false;
} // make sure you loop until false

bool Player::rankInHand(Card c) const{

    for(int i=0; i<myHand.size(); i++){

        if(myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;

}

Card Player::chooseCardFromHand() const{

    int randNum;
    int sizeOfHand=myHand.size();
    if(sizeOfHand==0){
        sizeOfHand++;
    }
    randNum=(rand()%sizeOfHand);
    return myHand[randNum]; // get around mod 0
}

bool Player::cardInHand(Card c) const{

    for(int i=0; i<myHand.size(); i++){

        if(myHand.back().getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c){

    Card temp;
    for(int a=0; a<getHandSize();a++){

        if(myHand[a].getRank()==c.getRank()){

            temp=myHand[a];
            myHand.erase(myHand.begin()+a);
        }
    }
    return temp;
}

string Player::showHand() const{

    string ret;
    for(int r=0; r<myHand.size(); r++){

        ret+=myHand[r].toString()+" ";
    }
    return ret;
}
string Player::showBooks() const{

    string ret;
    for(int r=0; r<myBook.size(); r++){

        ret+=myBook[r].toString()+" ";
    }
    return ret;
}

int Player::getHandSize() const{

    return myHand.size();
}

int Player::getBookSize() const{

    return (myBook.size()/2);
}