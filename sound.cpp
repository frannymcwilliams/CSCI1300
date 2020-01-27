#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

/*
   This program processes a 16 bit uncompressed mono .WAV file.
   Courtesy of Cay Horstman (Wiley Publisher)
*/

/**
   Processes the sound samples. Modify this function to change
   the way the sound is processed.
   @param samples the sound samples in the sound file
   @param size the number of samples
*/
void process(int samples[], int size)
{
   // Here, we make the sound three times as loud

   for (int i = 0; i < size; i++)
   {
      samples[i] = 3 * samples[i];
   }
}


// your function reverse() goes here
/**
   Processes the sound samples. Reverses the values in the samples array.
   @param samples the sound samples in the sound file
   @param size the number of samples
*/
void reverse(int samples[], int size) //reverse function
{
   int temp; //initialize a temp value
   for(int i=0; i<size/2; i++) //for loop that goes thorugh half the size of the array
   {
      temp = samples[i]; //set the temp equal to the value in the array at index i
      samples[i] = samples[size-i-1]; //set the value in the array at index i equal to the last value in the array
      samples[size-i-1] = temp; //set the last value in the array equal to temp
   }
}


// your function add_echo() goes here
/**
   Processes the sound samples. Adds an echo to the samples array: 
   Take a sample and replace it by the sum of its original value and 
   another value, from "delay" seconds earlier.  
   @param samples the sound samples in the sound file
   @param size the number of samples
   @param sample_rate the number of samples per second
   @param delay the number of seconds echo delay
*/

void add_echo(int samples[], int size, int rate, double d) //add_echo function
{
   double echoIndex = (size/(double)rate)/size; //set index of the echo equal to the size/rate/size
   int index = d/echoIndex; //set the index equal to the delay divided by the index of the echo
   int temp[size]; //declare a temp array of the same size as samples
   
   for (int i=0; i<size; i++) //for loop that goes through the array
   {
      temp[i] = samples[i]; //initialize the values of temp to the same as samples
   }
   for (int j=0; j<size; j++) //for loop that goes through the array
   {
      if (j<index) //if j is less than index
      {
         samples[j] = temp[j]; //then set samples equal to that value in temp
      }
      else
      {
         samples[j] = temp[j]+temp[j-index]; //set samples equal to the temp at j plus the value of temp of at index
      }
   }
}


// your function normalize() goes here
/**
   Processes the sound samples. Normalize the values in the samples array:
   Find the maximum value. Multiply all samples by 36773 and divide by the maximum value.
   @param samples the sound samples in the sound file
   @param size the number of samples
*/
void normalize(int samples[], int size) //normalize function
{
   int max=0; //initialize max equal to 0
   for(int i=0; i<size; i++) //for loop that goes through the array
   {
      if(max < samples[i]) //if max is les than the value of samples at i
      {
         max = samples[i]; //set max equal to that value
      }
   }
   for(int j=0; j<size; j++) //for loop that goes through the array
   {
        samples[j] = samples[j]*36773/max; //set samples equal to that value times 36773 divided by the max value
   }
}


// -------------------------------------------------------------------

/*
  The code below processes a file in the WAV format.
  You can use this program to manipulate sound files without 
  reading or understanding the code below. 

  The code uses C++ features that are introduced in chapters 7 and 8, 
  as well as the internals of the WAV format 
  (https://ccrma.stanford.edu/courses/422/projects/WaveFormat/)
*/

/**
   Gets an unsigned 4-byte integer from a binary stream.
   @param stream the stream
   @return the integer 
*/
int get_unsigned_int4(fstream& stream)
{
   int result = 0;
   int base = 1;
   for (int i = 0; i < 4; i++)
   {
      result = result + stream.get() * base;
      base = base * 256;
   }
   return result;
}

/**
   Gets an unsigned 2-byte integer from a binary stream.
   @param stream the stream
   @return the integer
*/
int get_unsigned_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   return lo + 256 * hi;
}

/**
   Gets a signed 2-byte integer from a binary stream.
   @param stream the stream
   @return the integer
*/
int get_signed_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   int result = lo + 256 * hi;
   if (result >= 32768) { result = result - 65536; }
   return result;
}

/**
   Puts a signed 2-byte integer to a binary stream.
   @param stream the stream
   @param value the integer to put
*/
void put_signed_int2(fstream& stream, int value)
{
   if (value < 0) { value = value + 65536; }
   stream.put(value % 256);
   stream.put(value / 256);
}

int main()
{
   cout << "Please enter the file name: ";
   string filename;
   cin >> filename;

   fstream stream;

   // Open as a binary file
   stream.open(filename.c_str(), ios::in | ios::out | ios::binary);

   // Check that we can handle this file
   stream.seekg(20);
   int format_type = get_unsigned_int2(stream);
   if (format_type != 1)
   {
      cout << "Not an uncompressed sound file." << endl;
      return 1;
   }
   int num_channels = get_unsigned_int2(stream);
   if (num_channels != 1)
   {
      cout << "Not a mono sound file." << endl;
      return 1;
   }

   int sample_rate = get_unsigned_int2(stream);

   stream.seekg(34);
   int bits_per_sample = get_unsigned_int2(stream);
   if (bits_per_sample != 16)
   {
      cout << "Not a 16 bit sound file." << endl;
      return 1;
   }

   // Read data size and allocate data array
   stream.seekg(40);
   int data_size = get_unsigned_int4(stream) / 2; // 2 bytes per data
   int* samples = new int[data_size];

   // Read sound data
   for (int i = 0; i < data_size; i++) 
   {
      samples[i] = get_signed_int2(stream);
   }

   // Process sound data
   //process(samples, data_size);

   // Replace "Process sound data" and the call to the process 
   // function with option A or option B below

   // A. Reverse
   // 1. Call the reverse function
   reverse(samples, data_size);

   // B. Add echo
   // 1. Declare and initialize variable for echo delay
   // 2. Call the add_echo function
   // 3. Call the normalize function

   // Write sound data
   stream.seekp(44);
   for (int i = 0; i < data_size; i++)
   {
      put_signed_int2(stream, samples[i]);
   }

   stream.close();

   delete[] samples;
     
   return 0;
}
