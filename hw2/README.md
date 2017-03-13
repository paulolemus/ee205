# EE 205 Programming Assignment 2 - Lists

Team   : Sandwich
Date   : 2/24/2017

# what our program does:

the bankwithlist executable begins with a simple interface which
allows the user to add, search for, or delete a BasicAccount.
The user is also given the options to print all bank accounts or close the program.
The user cannot add a bankaccount that has the same ID as an existing one.
The user can search by name OR ID. If an account is found, the user is
prompted if he/she would like to withdraw or deposit.
The user can also delete an account when given a name or ID.
The program expects the user to enter valid entries to each input field.
TLDR: It works pretty well.

# Files:

bankwithlist.cpp
BasicAccount.cpp
BasicAccount.h
singlylinked.h
testdriver.cpp
testdriver2.cpp
testdriver3.cpp
makefile
README.md
evalJessie.md
evalMatt.md
evalPaulo.md

# To make:

type: `make`
This should make the bankwithlist.cpp into a bankwithlist exec.

# Test cases

The outcomes from the three test drivers all met expectations.
The test drivers primarily tested the different functions in the
singlyLinkedList class. The functions all work even with edge cases
where we attempt to append to an empty list, deleting head or tail, 
deleting inside nodes, inserting before a node, inserting before
head or tail, etc.

You can find some examples in the testdrivers.
