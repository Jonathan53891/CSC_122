#include <iostream>
#include <string>
#include <locale>

using namespace std;

//enumeration type card suit
enum CardSuit
{
   hearts,
   spades,
   club,
   diamonds,
   other
};

//read the suit from user using the readSuit function
CardSuit readSuit(string cs)
{
   //object for locale
   locale l;
   //create the object for suit and
   //initialize the other
   CardSuit st = other;
   //initializes the string for spades, diamond, clubs and hearts
   string sp = "spades", d = "diamonds",
       c = "clubs", h = "hearts";
   //for find the string length
   int sl = cs.length();
   //to convert string for lower case letter
   for (int i = 0; i<sl; ++i)
       cs[i] = tolower(cs[i], l);
   //to find the substring for diamonds
   if (cs == d.substr(0 , sl))
       st = diamonds;
   //to find the substring for spades
   else if (cs == sp.substr(0, sl))
       st = spades;
   //to find the substring for hearts
   else if (cs == h.substr(0, sl))
       st = hearts;
   //to find the substring for club
   else if (cs == c.substr(0, sl))
       st = club;
   //return the suit
   return st;
}

//function definition for display the message
//based on the card type
void displayMessage(CardSuit st)
{
   //check the card type using switch case
   switch (st)
   {
      //display message for hearts card
       case hearts:
           cout << "You have a heart! Don't wear it on your sleeve..!" << endl;
           break;
       //display message for spades card
       case spades:
           cout << "So, you have a spade! Dig me a hole out back, won't you?" << endl;
           break;
       //display message for club card
       case club:
           cout << "Ah, a club! Don't beat me up!!" << endl;
           break;
      //display message for diamond card
       case diamonds:
           cout << "Ooo...diamonds. Don't cut my monitor with those!" << endl;
           break;
       //display message for other
       case other:
           cout << "I'm sorry, I don't recognize that suit...please try again." << endl;
           break;
   }
}

//main function
int main()
{
//initializes the option for another card continues
   char ch = 'y';
   //declare the variable cs for CardSuit
   string cs;
   //for enum type
   CardSuit suit;
//display the given message
   cout << "Welcome to the Card Suit Entering Program!!!\n" << endl ;
   //check option is y using while loop
   while (ch == 'y' || ch == 'Y')
   {
       //get the card suit form user
       cout << "What is the suit of your card?   ";
       cin >> cs;
       //call the readSuit function
       suit = readSuit(cs);
       //call the displayMessage function
       displayMessage(suit);
       //get the input for another card
       cout << "Another card? ";
       cin >> ch;
   }

   //print the given message if ch is n
   cout << "Thank you for using the CSEP!!" << endl << "Endeavor to have a stimulating day!";
   return 0;
}
