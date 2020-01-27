// CS1300 Spring 2018
// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 7 Part 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>   
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

//part 2 Library class
class Library
{
    public:
    Library(); //constructor
    
    Book getBookAt(int index);
    void setBookAt(int pos, Book b);
    User getUserAt(int index);
    void setUserAt(int pos, User u);
    
    void bookRec(User input);
    void rateBook(User entry);
    void loadBooks();
    void loadUsers();
    void showRatings(User input);
    void saveData();
    void addUser(string name, int ratings[], int numRatings);
    
    private:
    int numUsers = 87; //number of users
    int numBooks = 55; //number of books
    const static int bookSize = 1000;
    const static int userSize = 1000;
    Book books[bookSize]; //book array
    User users[userSize]; //user array
    
};

Library::Library() // default constructor
{
    
}

Book Library::getBookAt(int index)
{
    if(index >= numBooks)
    {
        return Book();
    }
    return books[index]; //return the book at that index if it is in the array
}
void Library::setBookAt(int pos, Book b)
{
    if(pos >= numBooks)
    {
        books[pos] = books[pos];
    }
    books[pos] = b; //replace the book at pos with b if the index is in the array
}
User Library::getUserAt(int index) 
{
    if(index >= numUsers)
    {
        return User();
    }
    return users[index]; //return the user at that index if it is in the array
}
void Library::setUserAt(int pos, User u)
{
    if(pos >= numUsers)
    {
        users[pos] = users[pos];
    }
    users[pos] = u; //replace the user at pos with u if the index is in the array
}

void Library::bookRec(User input)
{
    int count = 0; //counter
    int i = 0; //iterations
    int n = 10000;
    int temp;
    User bestMatch; //best book match
    for(int j=0; j<numUsers; j++)
    {
        temp = 0;
        for(int k=0; k<numBooks; k++)
        {
            temp += pow((input.getRatingAt(k) - users[j].getRatingAt(k)),2); //increment temp
        }
        if(temp<n && temp>=0)
        {
            n = temp; //set n to temp
            bestMatch = users[j];  //set the best book match to that user in the array
        }
    }
            
    for(int l=0; l<numBooks; l++)
    {
        if(count < 10 && i < 100)
        {
            i++; //increment i
            if(bestMatch.getRatingAt(l)>2 && input.getRatingAt(l)==0)
            {
                if(count == 0)
                {
                    cout << "Here are some of the books that we think you would like" << endl;
                }
                string title = books[l].getTitle(); 
                title = title.substr(0, title.length()); 
                cout << title << " by " << books[l].getAuthor() << endl; //print the title and author of the best match
                count++;
             }
        }
    }
    if(count == 0){
    cout << "There are no recommendations for you at present" << endl; //print no options
    }
}

void Library::rateBook(User entry)
{
    int bookIndex; //book array index
    bool rate = false; 
    string bookInput;
    string rateInput;
    
    cout << "Enter the name of the book that you would like to rate:" << endl;
    getline(cin, bookInput); //get the book input
    for(int i=0; i<bookInput.length(); i++)
    {
        bookInput[i] = tolower(bookInput[i]); //convert to lowercase
    }
    for(int j=0; j<numBooks; j++)
    {
        if(books[j].getTitle() == bookInput)
        {
            bookIndex = j; //set the index to j
        }
    }
    cout << "Enter your rating of the book:"<< endl;
    getline(cin, rateInput); //get the rating input
    int finalRating = stoi(rateInput); //convert to an int
    entry.setRatingAt(bookIndex, finalRating);
    cout << "Thank-you. The rating for the book titled " << books[bookIndex].getTitle() << " has been updated to " << rateInput << endl; //print
}
void Library::loadBooks()
{
    int n = 0;
    string temp;
    string author;
    string title;
    
    ifstream myFileStream; 
    myFileStream.open("books.txt"); //open a file stream
    
    if(myFileStream) //if it is open
    {
        while(getline(myFileStream, temp)) //get line 
        {
            if(temp[temp.length()-1] == '\r')
            {
                temp.erase(temp.length() -1, 1); //erase the last character
            }
            
            for(int i=0; i<temp.length(); i++)
            {
                temp[i] = tolower(temp[i]); //convert to lowercase
            }
            for(int j=0; j<temp.length(); j++)
            {
                if(temp[j] == ',') //split at the comma
                {
                    author = temp.substr(0, j);
                    title = temp.substr(j+1);
                    books[n] = Book(title, author);
                    n++;
                }
            }
        }
        myFileStream.close(); //close the file stream
    }
    else
    {
        cout << "Launch unsuccessful" << endl; //print
        cout << "Error! books or ratings file could not be found." << endl; //print
    }
}
void Library::loadUsers()
{
    int n = 0;
    string temp;
    string name;
    string ratingsStore;
    
    ifstream myFileStream; 
    myFileStream.open("ratings.txt"); //open a filestream
    
    if(myFileStream)
    {
        cout << "Data Loaded successfully!" << endl; //print
        while(getline(myFileStream, temp))
        {
            for(int i=0; i<temp.length(); i++)
            {
                temp[i] = tolower(temp[i]); //convert to lowercase
            }
            for(int j=0; j<temp.length(); j++)
            {
                if(temp[j] == ',') //split at the comma
                {
                    name = temp.substr(0, j);
                    ratingsStore = temp.substr(j+1);
                    string arr[numBooks];
                    int arr2[numBooks];
                    int k = 0;
                    stringstream sin(ratingsStore);
                    while (sin.good() && k<numBooks)
                    {
                        sin >> arr[k];
                        k++;
                    }
                    for(int l=0; l<numBooks; l++)
                    {
                        arr2[l] = stoi(arr[l]);
                    }
                    User user1(name,arr2,numBooks);
                    users[n] = user1;
                    n++;
                }
            }
        }
        myFileStream.close(); //close the file
    } 
    else
    {
        cout << "Launch unsuccessful" << endl; //print
        cout << "Error! books or ratings file could not be found." << endl;
    }
}

void Library::showRatings(User input)
{
    int count = 0;
    if(input.getRatingAt(0) == -1000 ||input.getRatingAt(0) == 0 )
    {
        
    } //do nothing if invalid rating
    else
    {
        cout << "Here are the books that you have rated:" << endl;
        for(int i=0; i<numBooks; i++)
        {
            if(input.getRatingAt(i) == 0)
            {
            }
            else
            {
                count ++;
                cout << "Title : " << books[i].getTitle() << '\n';
                cout << "Rating : " << input.getRatingAt(i) << '\n'; //print ratings
                for(int j=0; j<30; j++)
                {
                    cout << '-';
                }
                cout << endl;
            }
        }
    }
    if(count == 0)
    {
        cout << "You have not rated any books as yet:" << endl; //print
    }
}
void Library::saveData()
{
    ofstream myFileStream;
    myFileStream.open("ratings_new.txt"); //open output stream
    if(myFileStream.fail())
    {
        cout << "Error! Could not open file to save data" << endl;
    }
    else
    {
        for(int i=0; i<numUsers; i++)
        {
            myFileStream << users[i].getName() << ','; //write to file
            for(int j=0; j<numBooks; j++)
            {
                myFileStream << users[j].getRatingAt(i); //write to file
            }
            myFileStream << endl;
        }
        myFileStream.close(); //close file
        cout << "Data successfully saved. Goodbye!" << endl; //print
    }
}
void Library::addUser(string name,int ratings[],int numRatings)
{
    numUsers++; //increment numUsers
    users[numUsers] = User(name,ratings,numRatings); //add to user array
}

//main
int main()
{
    char choice;
    User userTest;
    int bookNums = 55;
    int userNums = 87;
    bool exists = false;
    int blank[60];
    Library libtest; //library object
    libtest.loadBooks();
    libtest.loadUsers();
    std::string username;
    
    cout << "Welcome to the Library, What is your name?:" << endl;
    getline(std::cin, username);
    
    if(username.empty())
    {
        //print
        cout << "You provided an empty user name, Please provide a valid user name to login or register:" << endl;
        cout << "Enter your name again:" << endl;
        cin >> username;
    }
    for(int i=0; i<username.length(); i++)
    {
        username[i] = tolower(username[i]); //convert to lowercase
    }
    for(int j=0; j<userNums; j++)
    {
        if(username == libtest.getUserAt(j).getName())
        {
            cout << "Welcome back, " << username << endl; //print
            exists = true; //set exists to true
        }
    }
    if(!exists)
    {
        userNums++; //increment users
        libtest.addUser(username, blank, 0); //add user
        cout << "Welcome to the Library, " << username << endl;
    }
    for(int k=0; k<userNums; k++)
    {
        if(libtest.getUserAt(k).getName() == username)
        {
            userTest = libtest.getUserAt(k); //set user equal to library at that index
        }
    }
    while(choice != 'q') //go through loop until user quits
    {
        cout<< "Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:" << endl;
        cin >> choice;
        cin.ignore();
        if(choice == 'v')
        {
            libtest.showRatings(userTest);
        }
        else if(choice == 'r')
        {
           libtest.rateBook(userTest);
        }
        else if(choice == 'g')
        {
            libtest.bookRec(userTest);
        }
        else if(choice == 'q')
        {
            break;
        }
        else
        {
            cout << "Please input a valid choice" << endl;
        }
     }
     libtest.saveData(); //save the data
}