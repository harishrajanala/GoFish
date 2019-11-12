// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <string>
#include <fstream>
using namespace std;


#define NO false
#define YES true;
#define FAIL 14
#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void askCard(Player p, Card card);
bool checkForBooks(Player &p1, Player &p2, Card &card1, Card &card2);

bool keepPlaying(int deckSize, int pOneHand, int pTwoHand, int pOneBook, int pTwoBook){

    if( (deckSize==0 && pOneHand==0 && pTwoHand==0) || ( (pOneBook+pTwoBook) >=26 ) ){
        
        return NO;
    }
    return YES;
}

ofstream myFile("game.txt");
Deck d; 

int main( )
{
    
    
    int numCards = 7;
    
    Player p1("Harish");
    Player p2("Rithvik");
    Card card2;
    Card card1;
    Card drawCard;
    d.shuffle();

    if(myFile.is_open()){

        myFile<<"Start of Game\n"<<p1.getName()<<" V.S. "<<p2.getName()<<endl<<endl;
    }
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    myFile << p1.getName() <<" has: " << p1.showHand()<< endl;
    myFile << p2.getName() <<" has: " << p2.showHand() << endl;

    checkForBooks(p1, p2, card1, card2);

    myFile << p1.getName() <<" has: " << p1.showHand()<< endl;
    myFile << p2.getName() <<" has: " << p2.showHand() << endl;

    cout<<"Playing .";

    while( keepPlaying(d.size(),p1.getHandSize(),p2.getHandSize(),p1.getBookSize(),p2.getBookSize()) ){

        cout<<" .";
        myFile<<endl;

        card1=p1.chooseCardFromHand();
        askCard(p1, card1);

        while(p2.rankInHand(card1)){
            myFile<<p2.getName()<<": Yes!"<<endl;
            p1.addCard(p2.removeCardFromHand(card1));
            if(! checkForBooks(p1, p2, card1, card2) ){
                break;
            }
            myFile << p1.getName() <<" has: " << p1.showHand()<< endl;
            myFile << p2.getName() <<" has: " << p2.showHand() << endl;
            card1=p1.chooseCardFromHand();
            askCard(p1, card1);
        }
        
        if(! checkForBooks(p1, p2, card1, card2) ){
                break;
        }

        myFile<<p2.getName()<<": No! Go Fish!"<<endl;
        drawCard=d.dealCard();

        if(drawCard.getRank()!=FAIL){
            myFile<<p1.getName()<<" drew: "<<drawCard.toString()<<endl;
            p1.addCard(drawCard);
            myFile << p1.getName() <<" has: " << p1.showHand()<< endl;
            myFile << p2.getName() <<" has: " << p2.showHand() << endl;
            if(! checkForBooks(p1, p2, card1, card2) ){
                break;
            }
        }
        else if(!(keepPlaying(d.size(),p1.getHandSize(),p2.getHandSize(),p1.getBookSize(),p2.getBookSize())))
                    break;
        
        myFile << p1.getName() <<" has: " << p1.showHand()<< endl;
        myFile << p2.getName() <<" has: " << p2.showHand() << endl;

        myFile<<endl; // ^^^ for the first player

        if(! checkForBooks(p1, p2, card1, card2) ){
                break;
        }

        if(p1.getHandSize()==0){

            drawCard=d.dealCard();
            if(drawCard.getRank()!=FAIL){
                myFile<<p1.getName()<<" drew: "<<drawCard.toString()<<endl;
                p1.addCard(drawCard);
                myFile << p1.getName() <<" has: " << p1.showHand()<< endl;
                myFile << p2.getName() <<" has: " << p2.showHand() << endl;
                if(! checkForBooks(p1, p2, card1, card2) ){
                    break;
                }
            }
            else if(!(keepPlaying(d.size(),p1.getHandSize(),p2.getHandSize(),p1.getBookSize(),p2.getBookSize())))
                    break;
        }

        if(p2.getHandSize()==0){

            drawCard=d.dealCard();
            if(drawCard.getRank()!=FAIL){
                myFile<<p2.getName()<<" drew: "<<drawCard.toString()<<endl;
                p2.addCard(drawCard);
                myFile << p1.getName() <<" has: " << p1.showHand()<< endl;
                myFile << p2.getName() <<" has: " << p2.showHand() << endl;
                if(! checkForBooks(p1, p2, card1, card2) ){
                    break;
                }
            }
            else if(!(keepPlaying(d.size(),p1.getHandSize(),p2.getHandSize(),p1.getBookSize(),p2.getBookSize())))
                    break;
        }

        card1=p2.chooseCardFromHand();
        askCard(p2, card1);

        while(p1.rankInHand(card1)){
            myFile<<p1.getName()<<": Yes!"<<endl;
            p2.addCard(p1.removeCardFromHand(card1));
            if(! checkForBooks(p1, p2, card1, card2) ){
                break;
            }
            myFile << p1.getName() <<" has: " << p1.showHand()<< endl;
            myFile << p2.getName() <<" has: " << p2.showHand() << endl;
            card1=p2.chooseCardFromHand();
            askCard(p2, card1);
        }
        if(! checkForBooks(p1, p2, card1, card2) ){
                break;
        }
        myFile<<p1.getName()<<": No! Go Fish!"<<endl;
        drawCard=d.dealCard();

        if(drawCard.getRank()!=FAIL){
            myFile<<p2.getName()<<" drew: "<<drawCard.toString()<<endl;
            p2.addCard(drawCard);
            myFile << p1.getName() <<" has: " << p1.showHand()<< endl;
            myFile << p2.getName() <<" has: " << p2.showHand() << endl;
            if(! checkForBooks(p1, p2, card1, card2) ){
                break;
            }
        }
        else if(!(keepPlaying(d.size(),p1.getHandSize(),p2.getHandSize(),p1.getBookSize(),p2.getBookSize())))
                    break;
        
        myFile << p1.getName() <<" has: " << p1.showHand()<< endl;
        myFile << p2.getName() <<" has: " << p2.showHand() << endl;
       
    }
    
    cout<<endl;
    
    if(p1.getBookSize()>=14){

        myFile<<p1.getName()<<" Wins!"<<endl;
    }else if(p2.getBookSize()>=14){

        myFile<<p2.getName()<<" Wins!"<<endl;
    }else{

        myFile<<"Tie!!"<<endl;
    }

    myFile<<endl<<p1.getName()<<": "<<p1.getBookSize()<<" Books: "<<p1.showBooks()<<endl;
    myFile<<endl<<p2.getName()<<": "<<p2.getBookSize()<<" Books: "<<p2.showBooks()<<endl;

    myFile.close();
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
            myFile<<p.getName()<<": do you have an Ace?"<<endl;
            break;
        case JACK:
            myFile<<p.getName()<<": do you have a Jack?"<<endl;
            break;
        case QUEEN:
            myFile<<p.getName()<<": do you have a Queen?"<<endl;
            break;
        case KING:
            myFile<<p.getName()<<": do you have a King?"<<endl;
            break;
        case 8:
            myFile<<p.getName()<<": do you have an 8?"<<endl;
        default:
            myFile<<p.getName()<<": do you have a "<<card.getRank()<<"?"<<endl;
            break;
        }
        return;
}

bool checkForBooks(Player &p1, Player &p2, Card &card1, Card &card2){
        
        while(p1.checkHandForBook(card1, card2)){
            myFile<<p1.getName()<<" booked: "<<card1.toString()<<" and "<<card2.toString()<<endl;
            p1.bookCards(card1, card2);
        }
        while(p2.checkHandForBook(card1, card2)){
            myFile<<p2.getName()<<" booked: "<<card1.toString()<<" and "<<card2.toString()<<endl;
            p2.bookCards(card1, card2);
        }
        myFile<<endl;

        if( keepPlaying(d.size(),p1.getHandSize(),p2.getHandSize(),p1.getBookSize(),p2.getBookSize()) )
            return YES;

        return NO;
} // check if there is book in any players hand and put them away


 


