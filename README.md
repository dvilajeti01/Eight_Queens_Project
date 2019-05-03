# EIGHT QUEENS PROJECT

AI Project #3 : Solving the Eight Queens problem using Hill Climbing Search ( steepest-ascent version ).
Project Members: Daniel Vilajeti

# Explanation of the ``` Eight_Queens ``` class and its respective member function:

The ``` Eight_Queens ``` class has two constructors a default constructor which generates a random Eight Queens puzzle 
board everytime a new instance of the class is created. And an overloaded constructor which accepts a board configuration as a
parameter.

The most important function of the class are the:

``` c++

void Hill_Climbing_Search(int initial_state[8]);
int numAttacks(int current[8]);
int generateChildren(int current[8], int col);

```

The ```Hill_Climbing_Search is the implementation of the hillclimbing search algorithm. This function is called by the 
```solve``` function.

The ``` numAttacks ``` function calls three seperate functions, each dealing with a certain attack such as horizontal attacks,
lateral down attacks and lateral up attacks. It returns the sum of all three seperate attack functions. 

And finally the ```generateChildren``` function which will produce all 7 possible children for a given column. The function will only change the 
board to the child with the fewest number of attacks.

# OUTPUT

