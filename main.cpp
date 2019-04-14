//
//  main.cpp
//  AI_Project2
//
//  Created by Daniel Vilajeti on 4/10/19.
//  Copyright © 2019 Daniel Vilajeti. All rights reserved.
//

#include <iostream>
#include "Eight_Queens.h"
using namespace std;

int main() {
    
    int array[8] = {3,6,2,1,0,5,4,7};
    //int num = 4;
    Eight_Queens test(array);
    test.solve();
    
    cout <<endl << test.numAttacks(array);
    return 0;
}
