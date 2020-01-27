#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void add_echo(int samples[], int size, int rate, double d)
{
   double echoIndex = (size/(double)rate)/size;
   int index = d/echoIndex;
   int temp[size];
   
   for (int i=0; i< size; i++)
   {
      temp[i] = samples[i];
   }
   for (int j=0; j<size; j++) 
   {
      if (j<index)
      {
         temp[j] = samples[j];
      }
      else
      {
         samples[j] = temp[j]+temp[j-index];
      }
   }
}

int main()
{
   int arr[] = {5, 8, 3, 10, 6, 2};
   add_echo (arr , 6, 2, 1.5);
   for(int i =0; i< 6; i++)
   {
      cout << arr[i] << " "; //should print 5 8 3 15 14 5
   }
}