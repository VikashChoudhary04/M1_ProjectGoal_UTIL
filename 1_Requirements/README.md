# Research

This program focuses on how to create a bank account system using C language and File handling in C.
Concepts of file handling will be used to store the data of the users, and then read all data from that particular file, store structures in a file.

# HIGH LEVEL REQUIREMENTS
* account()- This function is used to create new accounts.
* transfermoney()- This function is used to transfer money to the accounts
* checkbalances()- This function is used to check the balance in the accounts.
* login()- This function is used to login into the account.

# LOW LEVEL REQUIREMENTS
* Create a Bank Account
  account() -
  Take all the input from the user and make a structure for it to store the data in a file.
* Transfer Money
  transfermoney()- 
  Take the username of another user to whom we want to transfer the money and open his record in the file and write the amount to the file.
* Check Balances
  checkbalances()-
  Opening a file in which all the transfer records are written and read them one by one and match the username passed in the function to fetch the correct transfer records.
* Login Functionality
  login() -
  To add Login functionality, we are opening the file and matching the username provided by the user at the time of registration, and logging in to him if the username is correct and matches with the record present in our file.  

-> Create a Menu in the main function and create different functions for the Menu, which will be called using switch case statements. There are four different functions-
   account()
   transfermoney()
   checkbalances()
   login()

-> First, create an account of user by calling the account() function after the creation of an account, store all the data into a file using file handling functions.

-> Then the user is able to transfer the amount to other users, for that transfermoney() function is called, and for checking the current balance in the account call checkbalances() function.


# 4W1H

# Why

* Why do we need this system?

To store thw data of the public or users having account in the bank

To efficiently manage all the huge data and have a digital record of all the users.

# Who

* Who can accsess?

The banking staff and the employees of the bank can access the system.

#  What

* What could be implemented?

Features include checking the balance money in account, transfer money from one account to another, display the balance amount, loggin in and out of the user profile to see their data and balance, creating new account.

# Where
* Where the system could be used?
 This system is helpful for small banking management solutions.

# How
* How the system runs?

The main menu window appears on each execution

Once the required option is selected, the terminal shows the desired results

If not required, then exit from the system
