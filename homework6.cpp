// CS1300 Spring 2018
// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 6

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/** Q1
 * Algorithm:
 *      1. Create an in stream
 *      2. Open the file
 *      3. Initialize a string line
 *      4. Check if the file is open
 *          5. Check if the startIndex is less than the size of the array
 *              6. Declare correctWords array of size size
 *              7. Initialize wordsIndex equal to startIndex
 *              8. While loop that goes through the file and until wordsIndex is equal to the size of the array
 *                  9. Initialize correctWords at wordsIndex to line
 *                  10. Add to wordsIndex
 *          11. Return wordsIndex
 *          12. Else
 *              13. Return -1
 *      14. Else
 *          15. Return -1
 * Parameters: A file, a string array correctWords, the size of correctWords, a startIndex
 * Output: None
 * Returns: Number of words in the array
 * */
int ReadCorrectWords(string filename, string correctWords[], int size, int startIndex) //ReadCorrectWords function
{
    ifstream correctFile; //create instream
    correctFile.open(filename); //open filename
    string line = ""; //initialize line
    if (correctFile.is_open()) //check if the file opened
    {
        if(startIndex<size) //check if startIndex is less than size
        {
            correctWords[size]; //declare correctWords array
            int wordsIndex = startIndex; //initialize wordsIndex to startIndex
            while(getline(correctFile, line) && wordsIndex<size) //while loop
            {
                correctWords[wordsIndex] = line; //initialize correctWords at wordsIndex to line
                wordsIndex++; //increment wordsIndex
            }
            correctFile.close();
            return wordsIndex; //return total number of correct words in array correctWords
        }
        else //else
        {
            correctFile.close();
            return -1; //return -1
        }
    }
    else //else
    {
        correctFile.close();
        return -1; //return -1
    }
}

/** Q2
 * Algorithm:
 *      1. Create an in stream
 *      2. Open the file
 *      3. Initialize a string line
 *      4. Check if the file is open
 *          5. Check if the startIndex is greater than the size of the array
 *              6. Return -1
 *          7. Initialize wordsIndex equal to startIndex
 *          8. While loop that goes through the file and until wordsIndex is equal to the size of the array
 *              9. Getline
 *              10. If the line is not empty
 *                  11. For loop that parses the line length
 *                      12. If statement to see if the character in line is a tab
 *                          13. Set the 0th column of misspelledWords at that index to the string before the tab
 *                          14. Set the 1st column of misspelledWords at that index to the string after the tab
 *                          15. Break the for loop
 *              16. Add to wordsIndex
 *          17. Close the file
 *          18. Return wordsIndex
 *      14. Else
 *          15. Return -1
 * Parameters: A string filename, a 2D string array misspelledWords, rows in the 2D array, the starting index of the array
 * Output: Nothing
 * Returns: How many pairs are in the 2D array
 * */
int ReadMisspelledWords(string filename, string misspelledWords[][2], int rows, int startIndex)
{
    ifstream missedFile; //create instream
    missedFile.open(filename); //open filename
    string line = ""; //initialize line
    if (missedFile.is_open()) //check if the file opened
    {
        if(startIndex>=rows) //check if startIndex is greater than rows
        {
            return -1; //return -1
        }
        int wordsIndex = startIndex; //set wordsIndex equal to startIndex
        while(!missedFile.eof() && wordsIndex<rows) //while loop
        {
            getline(missedFile, line); //getline
	        if(line != "") //if the line is not empty
            {
                for(int i=0; i<line.length(); i++) //for loop that goes through line length
	            {
	                if(line[i] == '\t') //check if the character in line equals tab
                    {
                        misspelledWords[wordsIndex][0] = line.substr(0, i); //set misspelledWords at that index and 0 to the string before the tab
                        misspelledWords[wordsIndex][1] = line.substr(i+1, line.length()-i-1); //set misspelledWords at that index and 1 to the string after the tab
                        break; //break the for loop
                    }
                }
                wordsIndex++; //increment wordsIndex
	        }
	    }
	    missedFile.close(); //close the file
        return wordsIndex; //return total number of word pairs in array misspelledWords
    }
    else //else
    { 
        missedFile.close(); //close the file
        return -1; //return -1
    }
}

/** Q3
 * Algorithm:
 *      1. For loop that parses word
 *          2. Make all the characters in word lowercase
 *      3. For loop that parses the array correctWords
 *          4. If statement that checks if the word is the same as the index at correctWords
 *              5. Return the word
 *          6. Else if statement that checks if the word is the different from the index at correctWords
 *              7. For loop that goes through the rows in misspelledWords
 *                  8. If the index at that row and the 0th column is the word
 *                      9. Return the value of misspelledWords at that row and the 1st column
 *      10. Return "unknown" if the word is not found
 * Parameters: A string word, a string array correctWords, the size of the array correctWords, a string array of misspelledWords, the number of rows in misspelled words
 * Output: Nothing
 * Returns: The word, spelled correctly
 * */
string CheckWord(string word, string correctWords[], int size, string misspelledWords[][2], int rows)
{
    for(int i=0; i<word.length(); i++) //for loop that goes through the word length
    {
        word[i] = tolower(word[i]); //change all the characters to lowercase
    }
	for(int j=0; j<size; j++) //for loop that goes through the array correctWords
	{
	    if(correctWords[j] == word) //check if the index of correctWords is the same as word
	    {
	        return word; //return word
	    }
	    else if(correctWords[j] != word) //check if the index of correctWords is not the same as word
	    {
	        for(int r=0; r<rows; r++) //for loop that goes through the rows of misspelledWords
	        {
	            if(misspelledWords[r][0] == word) //check if the index of misspelledWords in the 0th column is the same as word
	            {
	                return misspelledWords[r][1]; //return the 1st column in misspelled words
	            }
	        }
	    }
	}
	return "unknown"; //return unknown
}

/** Q4
 * Algorithm:
 *      1. If the phrase is empty
 *          2. Print "Phrase is empty. Nothing to write in file."
 *      3. Create an outstream
 *      4. Open the file in append mode
 *      5. If the file fails to open
 *          6. Print "Unable to create/ access output file."
 *      7. Initialize subPos for the temp substring
 *      8. Initialize a string temp
 *      9. For loop that parses phrase
 *          10. If the character in phrase is a space
 *              11. Set temp equal to the substring up to the space
 *              12. Set temp equal to CheckWord on temp
 *              13. Write temp to the file
 *              14. Add to subPos
 *      15. Set temp equal to the substring from space up to the end of phrase
 *      16. Set temp equal to CheckWord on temp
 *      17. Write temp to the file
 *      18. Close the file
 * Parameters: A string phrase, a file to write to, an array of strings correctWords, the size of correctWords, a 2D array of misspelledWords, number of rows in misspelledWords
 * Output: If the phrase is empty or the file cant open outputs that to the console, or writes to the file
 * Returns: Nothing
 * */
void CheckPhrase(string phrase, string outputFile, string correctWords[], int size, string misspelledWords[][2], int rows)
{
    if(phrase == "") //check if phrase is empty
    {
        cout << "Phrase is empty. Nothing to write in file." << endl; //print to the console "Phrase is empty. Nothing to write in file."
    }
        
    ofstream checkStream; //create an out stream
    checkStream.open(outputFile, ios::app ); //open the file in append mode
    
    if(checkStream.fail()) //if the file fails to open
    {
        cout << "Unable to create/ access output file." << endl; //print to the console "Unable to create/ access output file."
    }
    
    int subPos = 0; //initialize subPos
    string temp = ""; //initialize temp string
    for(int i=0; i<phrase.length(); i++) //for loop that goes through the phrase 
    {
        if(phrase[i] == ' ') //if the character in phrase is a space
        {
            temp = phrase.substr(subPos, i-subPos); //set temp equal to the substring up to the space
            temp = CheckWord(temp, correctWords, size, misspelledWords, rows); //CheckWord on temp and set the value to temp 
            checkStream << temp << " "; //write temp to the file
            subPos = i+1; //increase the subPos
        }
    }
    temp = phrase.substr(subPos, phrase.length()-subPos); //set temp equal to the substring from space up to the end of phrase
    temp = CheckWord(temp, correctWords, size, misspelledWords, rows); //CheckWord on temp and set the value to temp 
    checkStream << temp << endl; //write temp to the file
    checkStream.close(); //close the stream
}

/**
 * Algorithm:
 *      1. Create an in stream
 *      2. Open the file
 *      3. Check if the file failed to open
 *          4. Print "invalid"
 *      5. Initialize a string line
 *      6. While loop that goes through the input file
 *          7. If the line is not empty
 *              8. Call the CheckPhrase function
 * Parameters: An input file, an output file, a string array correctWords, the size of correctWords, a 2D array misspelledWords, the number of rows in misspelledWords
 * Output:
 * Returns:
 * */
void CheckFile(string inputFile, string outputFile, string correctWords[], int size, string misspelledWords[][2], int rows)
{
    ifstream inFileStream; //create an in stream
    inFileStream.open(inputFile); //open inputFile
    if(inFileStream.fail()) //if the file doesnt open
    {
        cout << "invalid" << endl; //pring "invalid" to the console
    }
    string line = ""; //initialize string line
    while(getline(inFileStream, line)) //while loop
    {
        if(line != "") //check if the line is not empty
        {
            CheckPhrase(line, outputFile, correctWords, size, misspelledWords, rows); //call CheckPhrase
        }
    }
}

int main()
{
    //ReadCorrectWords test case
    int x = 0;
    string correctWords[3500];
    x = ReadCorrectWords("VALID_WORDS_3000.txt", correctWords, 3500, x);
    cout << x << endl;

    //ReadMisspelledWords test case
    int y = 0;
    string misspelledWords[600][2];
    y =  ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, y);
    cout << y << endl;
    
    //CheckWord test cases
    int a, b, c, d;
    
    a = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, a);
    b = ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, b);
    cout << CheckWord("abilitey", correctWords, a, misspelledWords, b) << endl;

    c = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, c);
    d = ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, d);
    cout << CheckWord("csci1300", correctWords, c, misspelledWords, d) << endl;
    
    //CheckPhrase test cases
    int e, f, g, h;
    e = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, e);
    f = ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, f);
    CheckPhrase("analysis blade birth columne unnaturral uningher","output.txt", correctWords, e, misspelledWords, f);

    f = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, f);
    h = ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, h);
    CheckPhrase("","output.txt", correctWords, g, misspelledWords, h);
    
    //CheckFile test cases
    int i, j, k, l; 
    
    i = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, i);
    j = ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, j);
    CheckFile("test_input3.txt","test_output.txt", correctWords, i, misspelledWords, j);

    k = ReadCorrectWords("VALID_WORDS_3000.txt",correctWords, 3500, k );
    l =  ReadMisspelledWords("MISSPELLED.txt", misspelledWords, 600, l);
    CheckFile("tes1.txt","test_output.txt", correctWords, k, misspelledWords, l);
}