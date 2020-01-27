// CS1300 Spring 2018
// Author: Franny McWilliams
// Recitation: 205 – Harshini Muthukrishnan
// Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
// Homework 4

#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm:
 *      1. Declare variables for the similar characters and the similarity score
 *      2. For loop that goes through the length of the sequences
 *          3. If the sequences have the same value at the index
 *              4. Add to the similar characters
 *      5. Calculate the similarity score
 *      6. If the sequences are different lengths
 *          7. Return -1
 *      8. If either of the sequences are empty
 *          9. Return -1
 *      10. Else, return the similarity score
 * Parameters: A string for the first sequence, a string for the second sequence
 * Output: None
 * Returns: Float similarity score
 */
float findSimilarityScore(string seq1, string seq2) //findSimilarityScore function
{
    float similarChars; //variable for how many characters are similar
    float similarity; //variable for the similarity score
    
    for(int i=0; i<seq1.length(); i++) //for loop that goes through the length of the sequences
    {
        if(seq1[i] == seq2[i]) //check if the sequences have the same character at index i
        {
            similarChars++; //add to similarChars
        }
        
    }
    
    similarity = similarChars/seq1.length(); //calculate similarity score
    
    if(seq1.length() != seq2.length()) //check if the sequences are different lengths
    {
        return -1; //return -1
    }
    else if(seq1 == "" || seq2 == "") //check if the sequences are empty strings
    {
        return -1; //return -1
    }
    else
        return similarity; //return the similarity score
}

/**
 * Algorithm:
 *      1. Declare varaibles for the similarity score and the max value
 *      2. For loop that goes through the length of the genome
 *          3. Initialize a variable sub equal to the substring in genome with the length of sequence
 *          4. Initialize similarity and call the findSimilarityScore function to find the value
 *          5. If the similarity score is larger than max value
 *              6. Set max equal to the similarity score
 *      7. If the genome or sequence are empty
 *          8. Return -1
 *      9. If the sequence is longer than the genome
 *          10. Return -2
 *      11. Else, return the max value of the similarity score
 * Parameters: A string for the genome, a string for the sequence
 * Output: None
 * Returns: Float highest similarity score
 */
float findBestMatch(string genome, string sequence) //findBestMatch function
{
    float similarity; //variable for the similarity score
    float max=0; //variable for max value
    
    for(int i=0; i<genome.length(); i++) //for loop that goes through the length of the genome
    {
        string sub = genome.substr(i, sequence.length()); //variable of a string that is the length of sequence within genome
        similarity = findSimilarityScore(sub, sequence); //calculate similarity by calling findSimilarityScore
        
        if (similarity > max) //check if the similarity score is greater than the max
        {
            max = similarity; //set max equal to the new similarity score
        }
    }
    
    if(genome == "" || sequence == "") //check if the genome or sequence are empty strings
    {
        return -1; //return -1
    }
    else if(sequence.length()>genome.length()) //check if the sequence length is longer than the genome
    {
        return -2; //return -2
    }
    else
        return max; //return the max similarity score
}

int main()
{
    //initialize variables for the genomes and sequence
    string genome1 = ""; 
    string genome2 = ""; 
    string genome3 = "";
    string sequence1 = "";
    
    // ask for user input for all 3 genomes
    cout << "Please enter genome 1: \n";
    cin >> genome1;
    cout << "Please enter genome 2: \n";
    cin >> genome2;
    cout << "Please enter genome 3: \n";
    cin >> genome3;
    
    // ask for the sequence
    cout << "Please enter a sequence: \n";
    cin >> sequence1;
    
    // verify sequence length (ask till it meets the length requirement)
    while(sequence1.length()>genome1.length() || sequence1.length()>genome2.length() || sequence1.length()>genome3.length())
    {
        cout << "Sequence cannot be longer than genomes.\n";
        
        // ask for the sequence
        cout << "Please enter a sequence: \n";
        cin >> sequence1;
    }
    
    // find best match with genome1 and sequence
    float x = findBestMatch(genome1, sequence1);
    // find best match with genome2 and sequence
    float y = findBestMatch(genome2, sequence1);
    // find best match with genome3 and sequence
    float z = findBestMatch(genome3, sequence1);
    
    // display result (highest of the 3 values)
    if(genome1=="" || genome2=="" || genome3=="" || sequence1=="")
    {
        cout << "Genome and sequence cannot be empty.";
    }
    else if (x>y && x>z)
    {
        cout << "Genome 1 is the best match.";
    }
    else if (y>z && y>x)
    {
        cout << "Genome 2 is the best match.";
    }
    else if (z>x && z>y)
    {
        cout << "Genome 3 is the best match.";
    }
    else if(x==y && x>z)
    {
        cout << "Genome 1 is the best match.\nGenome 2 is the best match.";
    }
    else if(y==z && y>x)
    {
        cout << "Genome 2 is the best match.\nGenome 3 is the best match.";
    }
    else if(x==z && x>y)
    {
        cout << "Genome 1 is the best match.\nGenome 3 is the best match.";
    }
    else if(x==y && y==z)
    {
        cout << "Genome 1 is the best match.\nGenome 2 is the best match.\nGenome 3 is the best match.";
    }
    
}