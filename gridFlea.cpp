
/* Nga Hoang -April 14 -2022
    Implementation Invariants: 
    - GridFlea moves inside of the grid's size.
    - A gridFlea starts at (0,0)
    - The active state of a gridFlea will be evaluated to false if the number of
    moves exceeds the size of the grid.
    - The active status will change back to true if the gridFlea is revive or reset.
    - Reviving an active gridFlea will permanently deactivate it. The gridFlea can not
    be revived or reset after permanent deactivation.
    - SwitchMode() will turn active gridFlea into permanetly deactivated. 
    - while moving, if in energetic mode the gridFlea object will move p squares, otherwise moves 1 square 
    (must smaller than size of grid.)
    - gridFlea object will not in object mode after some number of moves smaller than SIZE /2

  
*/
#include "gridFlea.h"
gridFlea::gridFlea(){
    x = initialX;
    y = initialY;
    energetic = true;
    change = 0;
    moveCount = 0;
    isActive = true;
    permanentlyDeactivated = false;

}
void gridFlea::initial(int startX, int startY){
    x = startX;
    y = startY;
    energetic = true;
    change = 0;
    moveCount = 0;
    isActive = true;
    permanentlyDeactivated = false;
    initialX = startX;
    initialY = startY;
}
bool gridFlea::activeStatus(){
    return isActive;
}
/* PreCondition: the gridFlea must be "active"
   PostCondition: the gridFlea is inactive 

*/
bool gridFlea::move(int p){
    if (!isActive)
    {
        return false;
    }
    
    if (energetic)
    {
        if (x - p >= 0 )
        {
            x -= p;
        }
        else if ( y -p >=0){
              y -=p;
        }
        else if (x + p< SIZE)
        {
            if( x + p > SIZE /2){
                energetic = false;
            }
             x +=p;
        }
        else if (y + p < SIZE){
            if ( y + p > SIZE / 2){
                energetic = false;
            }
            y +=p;
        }
        else
        {
            isActive = false;
            return false;
        }
                
        moveCount += p;
        checkMoveCount();
        change +=p;
        reward -=p;
        energetic = false;
                
    }
    else
    {   
        if (x - 1 >= 0)
        {
            x--;
        }
        else if (y - 1 >= 0)
        {
            y--;
        }
        else if (x + 1 < SIZE)
         {
            x++;
            
         }
         else if (y + 1 < SIZE)
         {
             y++;
             
         }
         else
         {
             isActive = false;
             return false;
        }
        
        moveCount++;
        checkMoveCount();
        change++;
        reward--;
        
        
        
    }
    return true;

}
int gridFlea::value(){
    change = (initialX - this->x) + (initialY - this->y);
        return reward * SIZE * change;
    
}
void gridFlea::checkMoveCount(){
    
    isActive  = moveCount <= SIZE;
}       
bool gridFlea::isEnergetic(){
    return energetic;
}
/*PreCondition: The gridFlea is active
  PostCondition: The gridFlea is  deactivated
 */
bool gridFlea::revive(){
    if(isActive){
        
        isActive = false;
    }
    return isActive = !isActive && !permanentlyDeactivated;
}
/* PreCondition: The gridFlea may be inactive
   PostCondition: Set gridFlea to its original position.
*/
bool gridFlea::reset(int startX, int startY){
    if(permanentlyDeactivated){
        return false;
    }
    initial(startX,startY);
    return true;

}
/* PreCondition: The gridFlea is active
   PostCondition: The gridFlea is permanently deactivated
*/
bool gridFlea::switchMode(){
    if(isActive){
        permanentlyDeactivated = true;
        isActive = false;
        return true;
    }
    
    return isActive = !isActive;
}