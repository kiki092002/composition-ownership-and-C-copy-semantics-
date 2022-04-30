/**
 * @file P2.cpp
 * @author Nga Hoang 
 * @version 1
 * @date 2022-04-14
 * PURPOSE: 
 * - This file is meant to test move() , minQ(), maxQ(), copy constructor, assignment operator, copy semantic, move semantic. 
 * PROCESSING:
 * - Using rng and array to generate data for test move() , minQ(), maxQ(), copy constructor, assignment operator, copy semantic, move semantic. 
 * OUTPUT:
 * - test move semantic -> print out the address of each object to check 
 * - test copy constructor and overloaded assignment operator - > print out min() max() values. 
 */

#include <iostream>
#include "inFest.h"
#include  <math.h>
using namespace  std;
inFest inFestSemantic();
int main(int argc, char** argv){
    const int SIZE = 5;
    int Xarr[SIZE] = {3,7,38,34,98};
    int Yarr[SIZE] = {27,90,59,63,26};
    inFest Obj(Xarr,Yarr,SIZE);
    // Test move() , minQ(), maxQ()
    for ( int i = 0 ; i <=100 ;i++){    
        Obj.move(i);    
    }
    cout << "The minimum : " << Obj.minQ() << endl;
    cout << "The maximum : "  << Obj.maxQ() << endl;
    cout << endl;

    //Test Copy Constructor
    inFest Obj1 = Obj;
    cout << "The minimum of: " << Obj1.minQ() << endl; 
    cout << "The maximum of : "  << Obj1.maxQ() << endl;
    cout << endl;

    // Test Assignment 

    const int NUM= 6; 
    int X2Arr[NUM];
    for ( int i = 0 ; i <=NUM;i++){
        X2Arr[i] = rand() % 2;
    }
    int Y2Arr[NUM];
    for ( int i = 0 ; i <=NUM;i++){
        Y2Arr[i] = rand()%2 + 1;
    }
    inFest Obj2(X2Arr,Y2Arr,NUM); 
    
    cout << "The minimum of Obj2: " << Obj2.minQ() << endl; 
    cout << "The maximum of Obj2: "  << Obj2.maxQ() << endl;

    Obj = Obj2;
    cout << "The minimum of Obj: " << Obj.minQ() << endl; 
    cout << "The maximum of Obj: "  << Obj.maxQ() << endl;
        
    // test Copy Semantic 
    Obj2 = inFestSemantic();
    cout << "Address of Obj2: " << &Obj2 << endl;
    

    inFest Obj3  = inFestSemantic();
     cout << "Address of Obj3: " << &Obj2 << endl;
    return 0;

  
}
inFest inFestSemantic(){
    const int SIZE = 7;
    int Xtest[SIZE];
    for ( int i = 0 ; i <=SIZE;i++){

        Xtest[i] = rand()/20;
    }
    int Ytest[SIZE];
    for ( int i = 0 ; i <=SIZE;i++){
        Ytest[i] = rand()/30;
    }
    inFest testObj(Xtest,Ytest,SIZE);
    cout << "Address of testObj: " << &testObj << endl;

    return testObj;
}