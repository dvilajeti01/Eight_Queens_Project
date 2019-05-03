//
//  main.cpp
//  AI_Project2
//
//  Created by Daniel Vilajeti on 4/10/19.
//  Copyright © 2019 Daniel Vilajeti. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Eight_Queens.h"

using namespace std;



int main() {
    
    int solved = 0;
    int numGenerated = 0;
    srand((unsigned)time(0));
    while(solved < 20)
    {
        Eight_Queens test;
        solved += test.solve();
        numGenerated++;
    }
   
    const long double percentage = (20/numGenerated) * 100;
    
    cout << setprecision(6) << "Number of generated boards: "<< numGenerated << endl << "Number of solved states: "<< solved << endl << "Percentage of successfully solved boards: " << percentage << endl;
    return 0;
}
