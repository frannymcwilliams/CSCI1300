// CS1300 Spring 2018
// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 7 Part 1

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Q1 Book class
class Book
{
    public:
    string getTitle();
    void setTitle(string bookTitle);
    string getAuthor();
    void setAuthor(string authorName);
    
    Book(string bookTitle, string authorName);
    Book();
    
    private:
    string title;
    string author;
};

string Book::getTitle()
{
    return title;
}
void Book::setTitle(string bookTitle)
{
    title = bookTitle;
}
string Book::getAuthor()
{
    return author;
}
void Book::setAuthor(string authorName)
{
    author = authorName;
}
    
Book::Book(string bookTitle, string authorName)
{
    title = bookTitle;
    author = authorName;
}
Book::Book()
{
    title = "NONE";
    author = "NONE";
}

//Q2 User class
class User
{
    public:
    User(string userName, int userRatings[], int numberRatings);
    User();
    
    string getName();
    void setName(string userName);
    int getNumRatings();
    void setNumRatings(int numberRatings);
    int getRatingAt(int index);
    int setRatingAt(int pos, int rate);
    
    private:
    string name;
    int ratings[100];
    int numRatings;
    
};

User::User(string userName, int userRatings[], int numberRatings)
{
    name = userName;
    for(int i=0; i<100; i++)
    {
        ratings[i] = userRatings[i];
    }
    numRatings = numberRatings;
}

User::User()
{
    name = "NONE";
    for(int i=0; i<100; i++)
    {
        ratings[i] = 0;
    }
    numRatings = 0;
}

string User::getName()
{
    return name;
}
void User::setName(string userName)
{
    name = userName;
}
int User::getNumRatings()
{
    return numRatings;
}
void User::setNumRatings(int numberRatings)
{
    numRatings = numberRatings;
}
int User::getRatingAt(int index)
{
    if(index >= numRatings)
    {
        return -1000;
    }
    return ratings[index];
}
int User::setRatingAt(int pos, int rate)
{
    if(pos >= numRatings)
    {
        ratings[pos] = ratings[pos];
        return -1000;
    }

    if(rate==-5 ||rate==-3 ||rate==0 ||rate==1 ||rate==3 ||rate==5)
    {
        ratings[pos] = rate;
        cout << "Success!" << endl;
        return 0;
    }
    
    cout << "Invalid Input!" << endl;
    return -1;
}

//main
int main()
{
    
}