# CS1300 Spring 2018
# Author: Franny McWilliams
# Recitation: 205 - Harshini Muthukrishnan
# Cloud9 Workspace Editor Link: https://ide.c9.io/frannymcwilliams/csci1300fm
# Homework 9


# Q1
# Algorithm:
#   1. Initialize a dictionary
#   2. For loop that goes through name_list
#       3. Split the names into first and last names
#       4. If the name is empty
#           5. Do nothing
#       6. If the name doesn't match a key
#           7. Set a new key and add that name
#       8. Else
#           9. Add that name to the value at that key
#   10. Return the dictionary
# Parameters: List of names
# Output: None
# Returns: Dictionary with key as first name and value as a list of last names
def countNames(name_list):
    dictionary = {} # dictionary
    for names in name_list: # for loop
        name = names.split() # split the names at that point in name_list
        if len(name) < 2: # if it is empty
            continue # go through the loop and do nothing
        if name[0] not in dictionary.keys(): # if the name doesnt match a key
            dictionary[name[0]] = [name[1]] # set that to a new one
        else: # else
            dictionary[name[0]].append(name[1]) # add that name to the key
    return dictionary # return dictionary

# Q2
# Algorithm:
#   1. Initialize avg and total
#   2. Try
#       3. Open the file
#           4. For loop that goes through the file
#               5. Set list equal to the split of the line
#               6. Initialize grade
#               7. For loop that goes through the list
#                   8. Set grade equal to grade plus the value at that point in the list
#               9. Set grade to float of the grade divided by the length of the list
#               10. Multiply grade by float of the -1 index of list
#               11. Add total to total plus float of the -1 index of list
#               12. Set avg equal to avg plus grade
#           13. Calcluate the average
#   14. Except (if the file didn't open)
#       15. Return "File not found"
#   16. Return avg
# Parameters: A file name
# Output: None
# Returns: Final grade of the class
def compute_grade(file_name):
    avg = 0 # initialize avg
    total = 0 # initialize total
    try:
        with open(file_name, 'r') as f: # open file
            for line in f: # for loop
                list = line.split(',') # split line in file and assign to list
                grade = 0 # initialize grade
                for i in range(0, len(list)-2): # for loop
                    grade = grade + int(list[i]) # add to grade
                grade = float(grade/(len(list)-2)) # set grade equal to float of the grade / length
                grade = grade * float(list[-1]) # multiply to grade
                total = total + float(list[-1]) # add to total
                avg = avg + grade # add to avg
            avg = avg/total # calc avg
    except:
        return "File not found" # return if file doesn't exist
    return avg # return the avg

# Q3
# Algorithm:
# Parameters:
# Output:
# Returns:
def update_dictionary(file_name, dictionary):
    try:
        with open(file_name, 'r') as x:
            print(file_name + ' loaded successfully.')
            for line in  x:
                words = line.strip().split(',')
                dictionary[words[0]] = [words[1]]
    except:
        print(file_name + ' does not exist.')
    print('The dictionary has ' + str(len(dictionary.items())) + ' entries.')
    return dictionary

# Q4
# Algorithm:
#   1. Set slang equal to input string split
#   2. For loop that goes through length of slang
#       3. If the word is in dictionary
#           4. Set the word do the correct value
#   5. Set the correct string to the correct value
#   6. Return deslanged value
# Parameters: Slang string, dictionary
# Output: None
# Returns: Deslanged string
def deslang(slangStr, dictionary):
    slang = slangStr.split() # split input
    for i in range(len(slang)): # for loop
        if(slang[i] in dictionary): # check if it is in dictionary
            slang[i] = dictionary[slang[i]] # set that word to the correct value
    deslangstr = ' '.join(slang) # add to the correct string
    return deslangstr # return correct string

# Q5
# Algorithm:
#   1. Initialize dicitonary
#   2. Set done to false
#   3. While loop that goes while done is false
#       4. Set entry to response
#       5. If a
#           6. Ask to input filename and update dictionary
#       7. If d
#           8. As to enter sentence and deslang
#       9. If q
#           10. Set done to true and break
# Parameters: None
# Output: Prints to console
# Returns: None
def main():
    dictionary = {} # initialize dicitonary
    done = False # initialize done
    while(done == False): # while loop
        entry = input("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ") # prompt user
        if(entry == "a"): # if a
            x = input("Enter a filename: ") # prompt user
            while(len(x) == 0): # if input is empty
                x = input("Enter a filename: ") #prompt user
            update_dictionary(x, dictionary) # update dictionary
        if(entry == "d"): # if d
            x = input("Enter a sentence: ") # prompt user
            while(len(x) == 0): # if input is empty
                z = input("Enter a sentence") # prompt user
            print(deslang(x, dictionary)) # deslang
        if(entry == 'q'): # if q
            done = True # set done to true
            break # break