#include "library.cpp"
#include<iostream>
using namespace std;

int main()
{
    char choice;
    User userTest;
    int bookNums = 55;
    int userNums = 87;
    bool exists = false;
    int blank[60];
    Library libtest;
    libtest.bookLoader();
    libtest.userLoader();
    std::string username;
    
    cout << "Welcome to the Library, What is your name?:" << endl;
    getline(std::cin, username);
    
    if(username.empty())
    {
        cout << "You provided an empty user name, Please provide a valid user name to login or register:" << endl;
        cout << "Enter your name again:" << endl;
        cin >> username;
    }
    for(int i=0; i<username.length(); i++)
    {
        username[i] = tolower(username[i]);
    }
    for(int j=0; j<userNums; j++)
    {
        if(username == libtest.getUser(j).getName())
        {
            cout << "Welcome back, " << username << endl;
            exists = true;
        }
    }
    if(!exists){
        userNums++;
        libtest.addUser(username, blank, 0);
        cout << "Welcome to the Library, " << username << endl;
    }
    for(int k=0; k<userNums; k++)
    {
        if(libtest.getUser(k).getName() == username){
            userTest = libtest.getUser(k);
        }
    }
    while(choice != 'q')
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
     libtest.saveData();
}