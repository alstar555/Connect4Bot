#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Drop chips in the columns.
 * Connect at least 4 of your chips in any direction to win.
 **/
 vector<int> avoidIndexVec;   

 int verticalBlock(vector<string> boardVec, char oppId, char myId){
     //check 
     //cerr << boardVec[6] << endl;
     int x=0;
     int y=0;
     int count1 = 0;
     int count2 = 0;
     while(true){
        if(x<0 || y<0 || y>8){
            return -1;
        }
        //cerr << x << ", "<< y<< "... " << count << " id: " << boardVec[x][y] << endl; 
        if(boardVec[x][y] == oppId){
            count1++;
        }
        else{
            count1 = 0;
        }
        if(boardVec[x][y] == myId){
            count2++;
        }
        else{
            count2=0;
        }
        //cerr << count1;
        if(count1==3){
            return y;
        }
        x++;
        if(x>6){
            x=0;
            y++;
        } 
     }    
 }

int horizontalBlock(vector<string> boardVec, char oppId, char myId){
     //check <- y ->  v x ^
     int x=0;
     int y=0;
     int count1 = 0;
     int count2 = 0;
     while(true){
        //cerr << boardVec[x] << endl;
        if(x<0 || y<0 || x>6){
            return -1;
        }
        if(boardVec[x][y] == oppId){
            count1++;
        }
        else{
            count1 = 0;
        }
        if(boardVec[x][y] == myId){
            count2++;
        }
        else{
            count2=0;
        }
        if(count1==3){
            return y;
        }
        y++;
        if(y>8){
            y=0;
            x++;
        } 
     }    
 }



 int findConnectVertical(vector<string> boardVec, char oppId, char myId){
     //check 
     //cerr << boardVec[6] << endl;
     int x=0;
     int y=0;
     int count1 = 0;
     int count2 = 0;
     while(true){
        if(x<0 || y<0 || y>8){
            return -1;
        }
        //cerr << x << ", "<< y<< "... " << count << " id: " << boardVec[x][y] << endl; 
        if(boardVec[x][y] == oppId){
            count1++;
        }
        else{
            count1 = 0;
        }
        if(boardVec[x][y] == myId){
            count2++;
        }
        else{
            count2=0;
        }
        //cerr << count1;
        if(count1==4 || count2==4){
            return y;
        }
        x++;
        if(x>6){
            x=0;
            y++;
        } 
     }    
 }

 int findConnectHorizontal(vector<string> boardVec, char oppId, char myId){
     //check <- y ->  v x ^
     //cerr << boardVec[6] << endl;
     int x=0;
     int y=0;
     int count1 = 0;
     int count2 = 0;
     while(true){
        if(x<0 || y<0 || x>6){
            return -1;
        }
        //cerr << x << ", "<< y<< "... " << count1 << " id: " << boardVec[x][y] << endl; 
        if(boardVec[x][y] == oppId){
            //cerr << count1;
            count1++;
        }
        else{
            count1 = 0;
        }
        if(boardVec[x][y] == myId){
            count2++;
        }
        else{
            count2=0;
        }
        //cerr << count1 << endl;
        if(count1==4 || count2==4){
            if( boardVec[x+1][y] == '.'){
                avoidIndexVec.push_back(y);
            }
            else{
                return y;
            }
        }
        y++;
        if(y>8){
            y=0;
            x++;
        } 
     }    
 }


 int findConnectLeft(vector<string> boardVec, char oppId, char myId){
     //check <- y ->  v x ^
     int x=0;
     int y=0;
     int x2 = 1;
     int y2 = 1;
     int count1 = 0;
     int count2 = 0;
     while(true){
        if(x<0 || y<0 || x>6){
            if(x2 == 1){
                //reverse direction check
                x2 = -1;
                y2= -1;
                x--;
                y--;
            }else{
                return -1;
            }
        }
        //cerr << x << ", "<< y<< "... " << count1 << " id: " << boardVec[x][y] << endl; 
        if(boardVec[x][y] == oppId){
            count1++;
        }
        else{
            count1 = 0;
        }
        if(boardVec[x][y] == myId){
            count2++;
        }
        else{
            count2=0;
        }
        //cerr << count1 << endl;
        if(count1==4 || count2==4){
            cerr << "L pass" << endl;
            return y;
        }
        y+= y2;
        x+= x2;
        if(y>=8){
            y=0;
            x++;
        } 
     }    
 }


  int findConnectRight(vector<string> boardVec, char oppId, char myId){
     //check <- y ->  v x ^
     int x=0;
     int y=0;
     int x2 = 1;
     int y2 = -1;
     int count1 = 0;
     int count2 = 0;
     while(true){
        if(x<0 || y<0 || x>6){
            if(x2 == 1){
                //reverse direction check
                x2 = -1;
                y2= 1;
                y+= y2;
                x-= x2;
            }
            else{
                return -1;
            }
        }
        //cerr << x << ", "<< y<< "... " << count1 << " id: " << boardVec[x][y] << endl; 
        if(boardVec[x][y] == oppId){
            count1++;
        }
        else{
            count1 = 0;
        }
        if(boardVec[x][y] == myId){
            count2++;
        }
        else{
            count2=0;
        }
        //cerr << count1 << endl;
        if(count1==4 || count2==4){
            return y;
        }
        y+= y2;
        x-= x2;
        if(y>=8){
            y=0;
            x++;
        } 
     }    
 }



 //checks al directions
 int findConnect(int x, int y, vector<string> boardVec, char oppId, char myId){
     int index;
     if(boardVec[x][y]!='.'){
         return -1;
     }
     else if(x<5 && boardVec[x+2][y]=='.'){
         return -1;
     }
     else{
         //cerr << "placed good"  << endl;
         //place holder
         boardVec[x][y] = oppId;
     }
     int currentPlayer = boardVec[x][y];
     //cerr << currentPlayer << endl;
  
    while(true){
        //left right
        //cerr << x << ", " << y << endl;
        index = findConnectLeft(boardVec, oppId, myId);
        if(index !=-1){
            cerr << "LEFT" << endl;
            return y;
        }
        //right left
         index = findConnectRight(boardVec, oppId, myId);
         if(index !=-1){
            cerr << "RIGHT" << endl;
            return y;
        }
        //veritcal
        index = findConnectVertical(boardVec, oppId, myId);
        if(index != -1){
            cerr << "VERTICAL" << endl;
            return y;
        }
        //horizontal
        index = findConnectHorizontal(boardVec, oppId, myId);
        if(index !=-1){
            cerr << "HORIZONTAL" << endl;
            return y;
        }
        //block moves 
        index = horizontalBlock(boardVec, oppId, myId);
         if(index !=-1){
             //cerr << "index: " << index << " y: " << y << endl;
            cerr << "H block: " << y << endl;
            return (y-100);
         }
         index = verticalBlock(boardVec, oppId, myId);
         if(index !=-1){
             cerr << "V block: " << y << endl;
             //cerr << "index: " << index << " y: " << y << endl;
            return (y-100);
         }
         //cerr << "return -1" << endl;
         return -1;
    }

 }


int stradegy(int previousIndex, int turnIndex, vector<string> boardVec, int oppId, int myId){
    if(turnIndex > 7){
        return -1;
    }
    if(turnIndex > 5){
        if(previousIndex==2){
            return 3;
        }
        else{
            return 2;
        }
    }
     if(turnIndex == 1){
         return -2;
     }
    vector<int> moveVec = {3, 4, 5};
    for(int move:moveVec){
        if(boardVec[6][move] == '.'){
            cerr << "STRATEGY" << endl;
             return move;
        }
    }
    return -1;
}



int main(){
    // int myId; // 0 or 1 (Player 0 plays first)
    // int oppId; // if your index is 0, this will be 1, and vice versa
    char myId; // 0 or 1 (Player 0 plays first)
    char oppId;
    cin >> myId >> oppId; cin.ignore();
    int moveIndex=4;
    // game loop
    while (1) {
        int turnIndex; // starts from 0; As the game progresses, first player gets [0,2,4,...] and second player gets [1,3,5,...]
        cin >> turnIndex; cin.ignore();
        vector<string> boardRowVec;
        for (int i = 0; i < 7; i++) {
            string boardRow; // one row of the board (from top to bottom)
            cin >> boardRow; cin.ignore();
            boardRowVec.push_back(boardRow);
        }
        int numValidActions; // number of unfilled columns in the board
        cin >> numValidActions; cin.ignore();
        vector<int> actionVec;
        for (int i = 0; i < numValidActions; i++) {
            int action; // a valid column index into which a chip can be dropped
            cin >> action; cin.ignore();
            actionVec.push_back(action);
        }
        int oppPreviousAction; // opponent's previous chosen column index (will be -1 for first player in the first turn)
        cin >> oppPreviousAction; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"


        // Output a column index to drop the chip in. Append message to show in the viewer.
        //check 3 in row down
   
        int block=-1;
        for(int x =0;x!= 7; x++){
            for(int y=0;y!=9;y++){
                moveIndex = findConnect(x, y, boardRowVec, oppId, myId);
                 //cerr << "moveIndex: " << moveIndex << endl;
                 if(moveIndex<-1){
                    block = moveIndex+100;
                    moveIndex = -1;
                }
                else if(moveIndex>-1){
                    break;
                }
                
            }
            if(moveIndex>-1){
                    break;
                }
        }
        
        // moveIndex = findConnectVertical(boardRowVec, oppId, myId);
        // if(moveIndex == -1){
        //     moveIndex = findConnectHorizontal(boardRowVec, oppId, myId);
        if(moveIndex == -1 && block == -1){
                 moveIndex = stradegy(oppPreviousAction, turnIndex, boardRowVec, oppId, myId);
        }
        //cerr << "block: " << block << endl;
        if(moveIndex==-1){
            if(block == -1){
                moveIndex = rand()%3+3;
                cerr << "random: " << moveIndex << endl;
            }else{
                moveIndex = block;
            }
        }
    
       //check to avoid slot 
       if(avoidIndexVec.size() > 0){
            cerr << avoidIndexVec[0] << endl;
       }
        //search for an empty slot
        bool foundSlot = false;
        if(moveIndex==-2){
            foundSlot = true;
        }
        while(foundSlot == false){
            for(int x : actionVec){
                if(x == moveIndex){
                    foundSlot = true;
                    break;
                }
            }
            if(foundSlot==false){
                moveIndex++;
                if(moveIndex>8){
                    moveIndex = 0;
                }
            }
        }
        cout << moveIndex << endl;
    } 
}
