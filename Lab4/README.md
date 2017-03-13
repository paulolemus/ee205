# EE 205 LAB 4 - CLASSES

Name: Paulo Lemus

Hello. Here you will find three working cpp files,
SavingsAccount.cpp, BasicAccount.cpp, bank.cpp

The Account .cpp files have main()'s that are used for individual testing.
The bank.cpp is the main driver that tests the functionality for both classes.


## To compile bank:

`make`

The make file will compile bank.cpp along with the other classes.
If you have any errors, then ensure that the main()'s for the two
class .cpp files are commented out. I assure you, they all work.

## To compile SavingsAccount:

First you must uncomment the SavingsAccount main(), and check that
the BasicAccount main() IS commented. Then type:

`make savings`

## To compile BasicAccount:

Same as above, check that the correct main is uncommented.
Then type:

`make basic`

## Notes:

So There is no dedicated "Prettyprint" function, as it is EXACTLY the same as
the << overload for both functions. I assume that prettyprint means to have a 
way to print all class fields, and that is what << does.

Cheers
