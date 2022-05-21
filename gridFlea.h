/* Nga Hoang - April 14 2022
    Class Invariants:
    - Calling move() will return True if the gridFlea object successfully moves, otherwise return false
    - Calling revive() will return True if the gridFlea object successfull revives, otherwise return false
    - Calling reset() will return True if the gridFlea object successfull revives, otherwise return false
    -gridFlea must be initialized with x, y, size (x, y is position)
    - if object is out of bound( Size/2 ) -> the object will not in energetic mode 
    
   Interface Invariants: 
    - A gridFlea object is not usable when inactive. The object becomes
    inactive when the number of moves exceeds the size of the grid.
    - A gridFlea object can be reactivated if and only if it is inactive but
      not permanently inactive.
    - gridFlea stay in the previous position if the current position it need to move is out of bound
    - when x, y, size become encapsulated in a gridflea, the initial state of the gridflea 
    is set to active. The number of move is set to 0

*/

#ifndef GRIDFLEA_H
#define GRIDFLEA_H

class gridFlea{
    private:
        int x;
        int y;
        int initialX = 0 ;
        int initialY = 0;
        bool isActive;
         int change;
        const static int SIZE = 200; // size of grid - bound
        int reward = 5;
        int moveCount;
        bool energetic;
        bool permanentlyDeactivated;
        void checkMoveCount();
        
        
        
    public:
        void initial(int startX, int startY);
        gridFlea();
        /* PreCondition: The gridFlea may be inactive
        PostCondition: Set gridFlea to its original position.
        */
        bool reset(int startX, int startY);
        /*PreCondition: The gridFlea is active
        PostCondition: The gridFlea is  deactivated
        */
        bool revive();
        /* PreCondition: the gridFlea must be "active"
           PostCondition: the gridFlea is inactive 

        */
        bool move(int p);
        bool activeStatus();
        bool isEnergetic();
        /* PreCondition: The gridFlea is active
           PostCondition: The gridFlea is permanently deactivated
        */
        bool switchMode();
        int value();
        



};
#endif

