#include "deck.h"
#include "card.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FAIL 14
#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

Deck::Deck(){

    myIndex=52;
    for(int i=0; i<4; i++){

        for(int j=ACE; j<=KING;j++){

            if(i==0){
                Card thisCard(j,Card::spades);
                myCards.push_back(thisCard);
            }
            if(i==1){
                Card thisCard(j,Card::hearts);
                myCards.push_back(thisCard);
            }
            if(i==2){
                Card thisCard(j,Card::diamonds);
                myCards.push_back(thisCard);
            }
            if(i==3){
                Card thisCard(j,Card::clubs);
                myCards.push_back(thisCard);
            }

        }
    }

    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);

}

void Deck::shuffle(){

    if(size()<=1){
        return;
    }
    for(int i=0; i<size()*2; i++){

        int randF=(rand()%size());
        Card first= myCards[randF];
        int randS=(rand()%size());
        Card second=myCards[randS];

        myCards[randF]=second;
        myCards[randS]=first;
    }
}

Card Deck::dealCard(){

    Card fail(FAIL, Card::spades);
    if(myIndex==0){
        return fail;
    }
    Card temp=myCards.back();
    myCards.pop_back();
    myIndex--;
    return temp;

}

int Deck::size() const{

    return myCards.size();
}