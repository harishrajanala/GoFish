// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <string>
using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void askCard(Player p, Card card);
void checkForBooks(Player &p1, Player &p2, Card &card1, Card &card2);

#define FAIL 14
#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

int main( )
{
    int numCards = 7;
    
    Player p1("Harish");
    Player p2("Rithvik");
    Card card2;
    Card card1;
    Card drawCard;
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has: " << p1.showHand()<< endl;
    cout << p2.getName() <<" has: " << p2.showHand() << endl;

    // checkForBooks(p1, p2, card1, card2);
    // cout<<p1.showBooks()<<endl;
    // cout<<p2.showBooks()<<endl;

    // Sample Output
    //   Joe asks - Do you have a J?
    //   Jane says - Go Fish
    //   Joe draws 4d

    //   Jane asks - Do you have a 4?
    //   Joe says - Yes. I have a 4.
    //   Jane books the 4..

    //   Jane asks - Do you have a 6?
    //   Joe says - Go Fish
    //   Jane draws Jc

    cout<<"Playing .";
    while(d.size()!=0 && (p1.getBookSize()<14 || p2.getBookSize()<14)){

        cout<<" .";

        checkForBooks(p1, p2, card1, card2);

        cout << p1.getName() <<" has: " << p1.showHand()<< endl;
        cout << p2.getName() <<" has: " << p2.showHand() << endl;

        //putting cards away in books

        //p1 asks for a card
        card1=p1.chooseCardFromHand();
        askCard(p1, card1);

        while(p2.rankInHand(card1)){
            cout<<p2.getName()<<": Yes!"<<endl;
            p1.addCard(p2.removeCardFromHand(card1));
            checkForBooks(p1, p2, card1, card2);
            card1=p1.chooseCardFromHand();
            askCard(p1, card1);
        }

        cout << p1.getName() <<" has: " << p1.showHand()<< endl;
        cout << p2.getName() <<" has: " << p2.showHand() << endl;

        
        cout<<p2.getName()<<": No! Go Fish!"<<endl;
        drawCard=d.dealCard();
        if(drawCard.getRank()!=FAIL){
            p1.addCard(drawCard);
            checkForBooks(p1, p2, card1, card2);
        }
        
        cout << p1.getName() <<" has: " << p1.showHand()<< endl;
        cout << p2.getName() <<" has: " << p2.showHand() << endl;

        // ^^^ for the first player

        checkForBooks(p1, p2, card1, card2);

        if(p1.getHandSize()==0){

            drawCard=d.dealCard();
            if(drawCard.getRank()!=FAIL){
                p1.addCard(drawCard);
                checkForBooks(p1, p2, card1, card2);
            }
            else
                break;
        }

        if(p2.getHandSize()==0){

            drawCard=d.dealCard();
            if(drawCard.getRank()!=FAIL){
                p2.addCard(drawCard);
                checkForBooks(p1, p2, card1, card2);
            }
            else
                break;
        }
        card1=p2.chooseCardFromHand();

        askCard(p2, card1);

        while(p1.rankInHand(card1)){
            cout<<p1.getName()<<": Yes!"<<endl;
            p2.addCard(p1.removeCardFromHand(card1));
            checkForBooks(p1, p2, card1, card2);
            card1=p2.chooseCardFromHand();
            askCard(p2, card1);
        }
        
        cout<<p1.getName()<<": No! Go Fish!"<<endl;
        drawCard=d.dealCard();
        if(drawCard.getRank()!=FAIL){
            p2.addCard(drawCard);
            checkForBooks(p1, p2, card1, card2);
        }
        
        cout << p2.getName() <<" has: " << p2.showHand()<< endl;
        cout << p1.getName() <<" has: " << p1.showHand() << endl;
       
    }
    
    if(p1.getBookSize()==14){
        cout<<endl<<p1.getName()<<": "<<p1.getBookSize()<<" Books: "<<p1.showBooks()<<endl<<p1.getName()<<" Wins!";
    }else{
        cout<<endl<<p2.getName()<<": "<<p2.getBookSize()<<" Books: "<<p2.showBooks()<<endl<<p2.getName()<<" Wins!";
    }
    return EXIT_SUCCESS;  

}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

void askCard(Player p, Card card){ // print: player p asks for card

        switch (card.getRank())
        {
        case ACE:
            cout<<p.getName()<<": do you have an Ace?"<<endl;
            break;
        case JACK:
            cout<<p.getName()<<": do you have a Jack?"<<endl;
            break;
        case QUEEN:
            cout<<p.getName()<<": do you have a Queen?"<<endl;
            break;
        case KING:
            cout<<p.getName()<<": do you have a King?"<<endl;
            break;
        
        default:
            cout<<p.getName()<<": do you have a "<<card.getRank()<<endl;
            break;
        }
        return;
}

void checkForBooks(Player &p1, Player &p2, Card &card1, Card &card2){
        
        while(p1.checkHandForBook(card1, card2)){

            p1.bookCards(card1, card2);
        }
        while(p2.checkHandForBook(card1, card2)){

            p2.bookCards(card1, card2);
        }

        return;
} // check if there is book in any players hand and put them away


 


