#pragma once

//
//  Eight_Queens.h
//  AI_Project2
//
//  Created by Daniel Vilajeti on 4/10/19.
//  Copyright © 2019 Daniel Vilajeti. All rights reserved.
//

class Eight_Queens
{
private:

	//current chess board configuration
	int initial[8];

	//child of current chess board configuration
	int next[8];


public:

	Eight_Queens();
	Eight_Queens(int state[8]);
	~Eight_Queens();
	void solve();
	void Hill_Climbing_Search(int initial_state[8]);
	int numAttacks(int current[8]); //COMPLETE
	int H_Attacks(int current[8], int i); //COMPLETE
	int LU_Attacks(int current[8], int i); //COMPLETE
	int LD_Attacks(int current[8], int i); //COMPLETE
	int generateChildren(int current[8], int col);
	void printBoard(int state[8]); //COMPLETE
	void copyArray(int to_array[8], int from_array[8], int size);

};