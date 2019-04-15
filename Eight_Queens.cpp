//
//  Eight_Queens.cpp
//  AI_Project2
//
//  Created by Daniel Vilajeti on 4/10/19.
//  Copyright © 2019 Daniel Vilajeti. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "Eight_Queens.h"
using namespace std;


Eight_Queens::Eight_Queens()
{
	//call rand array
}

Eight_Queens::Eight_Queens(int state[8])
{
	memcpy(this->initial, state, sizeof(this->initial));
}

Eight_Queens :: ~Eight_Queens()
{
	//??
}

void Eight_Queens::solve()
{
	Hill_Climbing_Search(initial);
}

void Eight_Queens::Hill_Climbing_Search(int initial_state[8])
{
	//Do search here
	int current[8];
	int temp[8];
	int min;
	int attacks;

	min = 28; //Max amount of a attacks for any board config.
	copyArray(current, initial_state, 8);

	while (true)
	{

		for (int i = 0; i < 8; i++) // 56 children
		{
			copyArray(temp, current, 8);

			attacks = generateChildren(temp, i);

			if (attacks < min)
			{
				min = attacks;
				copyArray(next, temp, 8);
			}

		}
		if (min >= numAttacks(current))
		{

			printBoard(current);
			return; // current is the peak
		}
		else
		{
			copyArray(current, next, 8);
		}
	}
}
int Eight_Queens::numAttacks(int current[8])
{
	int totalAttacks = 0;

	for (int i = 0; i < 8; i++)
	{
		totalAttacks += (H_Attacks(current, i) + LU_Attacks(current, i) + LD_Attacks(current, i));
	}

	return totalAttacks;
}

int Eight_Queens::H_Attacks(int current[8], int i)
{
	//calculate number attacks for given state
	int numAttacks = 0;

	//horizontal attacks
	for (int j = i + 1; j < 8; j++)
	{
		if (current[i] == current[j])
			numAttacks++;
	}


	return numAttacks;
}

int Eight_Queens::LU_Attacks(int current[8], int i)
{
	//calculate number attacks for given state
	int numAttacks = 0;
	int row = 0;
	int col = 0;

	row = current[i];
	col = i;

	while (row >= 0 && col <= 7)
	{
		if (current[++col] == --row)
		{
			numAttacks++;
		}
	}

	return numAttacks;
}

int Eight_Queens::LD_Attacks(int current[8], int i)
{
	//calculate number attacks for given state
	int numAttacks = 0;
	int row = 0;
	int col = 0;

	row = current[i];
	col = i;

	while (row <= 7 && col <= 7)
	{
		if (current[++col] == ++row)
		{
			numAttacks++;
		}
	}

	return numAttacks;
}

int Eight_Queens::generateChildren(int current[8], int col)
{
	//DETERMINE THE BEST CHILD FOR ALL MOVEMENTS OF A GIVEN QUEEN
	int ignoreChange = current[col];
	int best[8];
	int attacks;
	int min = numAttacks(current);
	
	copyArray(best, current, 8);

	for (int i = 0; i < 8; i++)
	{
		if (i != ignoreChange)
		{
			current[col] = i;

			attacks = numAttacks(current);

			if (attacks < min)
			{
				min = attacks;
				copyArray(best, current, 8);
			}
		}
	}

	copyArray(current, best, 8);
	return min;
}

void Eight_Queens::printBoard(int state[8])
{

	for (int i = 0; i < 8; i++)
	{
		cout << "---------------------------------" << endl;

		for (int j = 0; j < 8; j++)
		{
			if (state[j] == i)
			{
				cout << "| Q ";
			}
			else
				cout << "|   ";
		}
		cout << "|" << endl;
	}

	cout << "---------------------------------" << endl;
}

void Eight_Queens::copyArray(int to_array[8], int from_array[8], int size)
{
	for (int i = 0; i < size; i++)
	{
		to_array[i] = from_array[i];
	}
}
