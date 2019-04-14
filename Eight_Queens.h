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
    Eight_Queens(int *state);
    ~Eight_Queens();
    void solve();
    int * Hill_Climbing_Search(int *initial_state);
    int numAttacks(int *current); //COMPLETE
    int H_Attacks(int *current, int i); //COMPLETE
    int LU_Attacks(int *current, int i); //COMPLETE
    int LD_Attacks(int *current, int i); //COMPLETE
    int generateChildren(int *current, int col);
    void printBoard(int *state); //COMPLETE
    
};
