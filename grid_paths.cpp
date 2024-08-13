#include <iostream>

int dr[4] = {-1, 0, 1, 0}; //helps transitions
int dc[4] = {0, 1, 0, -1};
int p[48]; //path
bool onPath[9][9]; //whether cell is on path, 9 because we want to set borders
int tryPath(int pathIdx, int curR, int curC);

int main() {
    std::string line;
    std::getline(std::cin, line);
    //convert path to ints
    for(int i=0; i < 48; i++) {
        char cur = line[i];
        if (cur == 'U') p[i]=0;
        else if(cur=='R') p[i]=1;
        else if(cur=='D') p[i]=2;
        else if(cur=='L') p[i]=3;
        else p[i]=4;
    }
    //set borders of grid, these are boundaries
    for (int i=0; i<9;i++) {
        onPath[0][i]=true;
        onPath[8][i]=true;
        onPath[i][0]=true;
        onPath[i][8]=true;
    }
    for(int i=1; i<=7; i++) { // clean slate where every cell is false
        for (int j=1; j<=7; j++) {
            onPath[i][j]=false;
        }
    }

    int startIdx=0;
    int startR=1;
    int startC=1;
    int ans=tryPath(startIdx, startR, startC);
    std::cout << ans << std::endl;
    return 0;
}

int tryPath(int pathIdx, int curR, int curC) {
    //splits grid
    if((onPath[curR][curC-1] && onPath[curR][curC+1]) 
        && (!onPath[curR-1][curC] && !onPath[curR+1][curC])) return 0;
    //up down blocked, right left not
    if((onPath[curR-1][curC] && onPath[curR+1][curC])
        && (!onPath[curR][curC-1] && !onPath[curR][curC+1])) return 0;
    
    if(curR==7 && curC==1) { //reached endpoint before visiting all
        if (pathIdx == 48) {
            return 1;
        }
        return 0;
    }

    if(pathIdx==48) return 0;

    int ret = 0;
    onPath[curR][curC]=true; //mark current pos as on path
    //turn already determined
    if(p[pathIdx] < 4) {
        int nxtR = curR + dr[p[pathIdx]];
        int nxtC = curC + dc[p[pathIdx]];
        if(!onPath[nxtR][nxtC]) {
            ret += tryPath(pathIdx+1, nxtR, nxtC);
        }
    }
    else { //iterate through all four possible turns
        for(int i=0; i<4; i++) {
            int nxtR = curR + dr[i];
            int nxtC = curC + dc[i];
            if (onPath[nxtR][nxtC]) continue;
            ret += tryPath(pathIdx+1, nxtR, nxtC);
        }
    }
    //reset and return
    onPath[curR][curC] = false;
    return ret;
}
