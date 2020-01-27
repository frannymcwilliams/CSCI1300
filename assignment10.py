# CS1300 Spring 2017
# Author: Franny McWilliams
# Recitation: Harshini
# Assignment 10


class Library:
    #Constructor here
    def __init__(self, books_filename, ratings_filename):
        self.user_dictionary = {} # sets user_dictionary to an empty dictionary
        self.book_list = [] # sets book_list to an empty list
        
    def read_books(self, file_name):
        try:
            f = open(file_name,'r') # opens file f and reads
            for line in f: # goes through the lines of the file
                self.book_list.append(line.strip().lower().split(",")) # strips, splits, and appends line
            print("Data Loaded successfully!") # print if successful
        except:
              print("file did not open properly") # print if unsuccessful

    def read_users(self, file_name):
        try:
            f = open(file_name,'r') # opens file f and reads
            for line in f: # goes through the lines of the file
                key = line.lower().split(",") # divides at comma
                ratings = key[1].lower().strip().split(" ") # strips, splits, and appends line
                for i in range(len(ratings)): # for loop
                    ratings[i] = int(ratings[i]) # convert to int
                self.user_dictionary[key[0]] = ratings # stores the keys in the ratings
        except:
            print ("file did not open properly") # print if load failure
    
    def login(self):
        i = input("Welcome to the Library, What is your name?: \n") # prompts user
        i = i.lower() # covert to lowest
        while (i == ""): # while loop that goes through if not empty
            print ("You provided an empty username, Please provide a valid user name to login or register") # prompt user
            i = input("Enter your name again: \n") # prompts user
            i = i.lower() # covert to lowest
        if (i in self.user_dictionary): # check if username exists
            print("Welcome back,",i) # print
            self.current_user = i # set to i
        else:
            print("Welcome to the Library,",i) # print
            self.current_user = i # set to i
            new_ratings = []
            for j in range(len(self.book_list)):
                new_ratings.append(0) # appends the ratings
            self.user_dictionary[i] = new_ratings 
        
    def view_ratings(self, current_user_name):
        print ("Here are the books that you have rated:") # print
        for i in self.user_dictionary: # for loop
            if current_user_name == i: # if current user is i
                for j in range(len(self.user_dictionary[i])):
                    if self.user_dictionary[i][j] != 0:
                            print("Title :",self.book_list[j][1]) # prints title
                            print("Rating :",self.user_dictionary[i][j]) # prints rating
                            print("------------------------------") # print
                    
    def rate_book(self,current_user_name,book_name,rating):
        for i in range(len(self.book_list)):
            if self.book_list[i][1] == book_name: # check if the book name
                self.user_dictionary[current_user_name][i] = rating # set rating
        print ('Thank-you. The rating for the book titled "' + book_name + '" has been updated to ' + str(rating)) # print
        
    def calc_similarity(self, user1, user2):
        similarity_measure = 0 # simple standard deviation
        for i in range(len(self.book_list)): # for loop
            similarity_measure += (self.user_dictionary[user1][i] - self.user_dictionary[user2][i])**2 # calc simple standard deviation
        return similarity_measure # returns similarity
    
    def get_most_similar_user(self,current_user_name): 
        response = 214748364
        index = -1
        for i in range(len(self.user_dictionary.keys())): # for loop
            if (list(self.user_dictionary.keys())[i] == current_user_name): # if the keys contain name
                continue
            temp_sim = self.calc_similarity(current_user_name,list(self.user_dictionary.keys())[i])
            if (temp_sim < response): # if the temp is less than response
                response = temp_sim # set response to temp
                index = i # set index to i
        return list(self.user_dictionary.keys())[index] # returns keys
                
    def recommend_books(self,current_user_name):
        i = 0
        j = 0
        most_sim = self.get_most_similar_user(current_user_name) # set most_sim to the user
        while i < len(self.book_list) and j < 10: # while loop
            temp = self.user_dictionary[most_sim][i] # temp equals most_sim in dictionary
            if (temp == 3 or temp == 5) and self.user_dictionary[current_user_name][i] == 0: # if temp is 3 or 5 or dicitonary is empty
                if j == 0: # if j is 0
                    print("Here are some of the books that we think you would like")
                print(self.book_list[i][1],"by",self.book_list[i][0]) # print
                j += 1 # increment j
            i += 1 # increment i
        if (j == 0): # if j is 0
            print("There are no recommendations for you at present") # print
            
    def menu(self):
        i = ""
        while (i!='q'): # while loop until quit
            correct = ['v','r','g','q'] # valid inputs
            i = input("Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?: \n") # prompt user
            while (i == "" or i not in correct): # while input isn't in correct or empty
                print ("Please input a valid choice") # prompt user
                i = input("Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?: \n") # prompt user
            if (i == 'v'): # if input is v
                self.view_ratings(self.current_user) # show ratings
            elif (i == 'r'): # if input is r
                new_rating = input("Enter the name of the book that you would like to rate:\n") # prompt user
                new_rating = new_rating.lower() # lowers of new rating
                
                rating= input("Enter your rating of the book:\n") # prompt user
                validRatings = [-5, -3, 1, 3, 5] # valid ratings for the book
                
                exist = False # set to false
                while exist == False: # while loop
                    for subList in self.book_list: # if in book list
                        if exist == subList[1]: 
                            exist = True # set to trye
                            break
                        
                    if exist == False: # if false
                        print("The book you requested does not exist in the database") # print
                        new_rating = new_rating=input("Enter the name of the book that you would like to rate:\n") # prompt user
                        new_rating=new_rating.lower() # lower of rating
                
                        rating= input("Enter your rating of the book:\n") # prompt user
                        validRatings = [-5, -3, 1, 3, 5] # valid ratings for the book
                
                print ("Success!") # print
                self.rate_book(self.current_user,new_rating,int(rating)) # rate book
            elif (i == 'g'): # if input g
                self.recommend_books(self.current_user) # gets recommendations
            elif (i =='q'):
                print("Goodbye!") # print
                
# the lib options and implementations   
lib = Library("books.txt","ratings.txt")
lib.read_books("books.txt")
lib.read_users("ratings.txt")
lib.login()
lib.menu()