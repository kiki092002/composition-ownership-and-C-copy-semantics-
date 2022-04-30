/* Nga Hoang 
  * Date April 14 -2022 
  Class Invariants:
   - Each inFest must contain a number of gridFlea objects, each of
   which is distinct, having their own uniquely privided encapsulated (X,Y).
   - The number of gridFlea can vary between inFest objects, as the cardinality is not constant.
   -  Throw exception if minQ() and maxQ() is not active
   - Calling min() and max() will respectively return the minimum and maximum acquired fron a value() call across all gridFlea subobjects.
   - Size of X and Y is same and equal to number of gridFlea subobjects that a inFest current holds

  Interface Invariants:
   - The a inFest must be active to ensure max and min are selected; otherwise,
   return throw message " the inFest is not active"
   - move() will return number of gridFlea objects currently moving, otherwise it will throw message indicating that
    the inFest is not in active mode.
   -Client must construct the Cluster with an interger array of X axis, Y axis, and number of gridFLea objects
  
   - Since all objects moving at the same time, at inital they have the same min max and gradually have a 
   diffenrent values depends on the given bound ( SIZE /2)
   -


*/
#include "gridFlea.h"
#ifndef INFEST_H
#define INFEST_H
class inFest{
    private:
        gridFlea* gridFleaObjs;
        int numGridFleas;
        void copy(const inFest& orig);
        bool active;
        
    public:
        
        inFest(int StartX[], int startY[], int numObjs);
        inFest(const inFest& orig);
        inFest(inFest&& orig) noexcept;
        inFest& operator=(const inFest& orig);
        inFest& operator=(inFest&& orig) noexcept;
        /* PreCondition: The inFest must be "active" for moving
           PostCondition: The inFest may become  inactive
        */
        int move(int p);
        /* PreCondition: The inFest must be "active" for selecting min value
        */
        int minQ();
        /* PreCondition: The gridFlea must be "active" for selecting max value
        */
        int maxQ();
        ~inFest();
        bool isActive();


};

#endif


