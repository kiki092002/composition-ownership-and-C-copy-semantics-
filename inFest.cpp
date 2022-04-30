/* Nga Hoang - April 14 2022
    Implementation Invariants:
  - The inFest will encapsulated a fixed number of gridFlea objects.
  - An array of provided distinct gridFlea objects are given to a inFest object.
  - Each gridFlea object stay in diferent (X,Y) positions.
  - gridFlea subobject makes movement when inFest is in active mode. 

  
*/

#include "inFest.h"
#include <iostream>
using namespace std;
inFest::inFest(int startX[], int startY[], int numObjs): numGridFleas(numObjs)
{
    gridFleaObjs = new gridFlea[numGridFleas];
    for( int i = 0 ; i < numGridFleas; i++){
        gridFleaObjs[i].initial(startX[i],startY[i]);
        
        
    }
    active = true;

}
inFest::inFest(const inFest& orig){
    copy(orig);
}

/* PreCondition: The inFest must be "active" for moving
   PostCondition: The inFest may become  inactive
*/
int inFest::move(int p){
    
    int count = 0 ; 
    if(active){
        for(int  i = 0 ; i < numGridFleas; i++){
          if(gridFleaObjs[i].activeStatus()){
              gridFleaObjs[i].move(p);
              count++;
        
           }
        
        }
    }
    else{
        throw "the inFest is not active";
    }
    return count;
    

}
/* PreCondition: The inFest must be "active" for selecting min value
*/
int inFest::minQ(){
    if(!active){
        throw " The inFest is not active ";
    }
    
    int min = gridFleaObjs[0].value();
    for( int i = 0 ; i < numGridFleas;i++){

        if(gridFleaObjs[i].value() < min){
            min = gridFleaObjs[i].value();
            
        }
    }
    
    
    return min; 

}
/* PreCondition: The gridFlea must be "active" for selecting max value
*/
int inFest::maxQ(){
    if(!active){
        throw " The inFest is not active ";
    }
    int max = 0;
    for ( int i = 0 ; i < numGridFleas;i++){

        if(gridFleaObjs[i].value() > max){
            max = gridFleaObjs[i].value();
            
        }
    }
    return max;
    
}



inFest::inFest(inFest&& orig) noexcept{
    gridFleaObjs      = orig.gridFleaObjs;
    numGridFleas      = orig.numGridFleas;
    active             = orig.active;

    orig.gridFleaObjs = nullptr;
    orig.active       = false;
    orig.numGridFleas = 0;
}
inFest& inFest::operator=(const inFest& orig){
    if(this == &orig){
        return *this;
    }
    delete[] gridFleaObjs;
    copy(orig);
    return *this;

}

inFest& inFest::operator=(inFest&& orig) noexcept{
    if (this == &orig) return *this;

    swap(numGridFleas, orig.numGridFleas);
    swap(active, orig.active);
    swap(gridFleaObjs, orig.gridFleaObjs);

    return *this;
}

inFest::~inFest(){
    delete [] gridFleaObjs;
}
void inFest::copy(const inFest& orig){
    
    gridFleaObjs = new gridFlea[orig.numGridFleas];
    for( int i = 0 ; i < orig.numGridFleas; i++){
        gridFleaObjs[i] = orig.gridFleaObjs[i];
    }
    numGridFleas = orig.numGridFleas;
    active = orig.active;

}

bool inFest::isActive(){
    return active;
}
