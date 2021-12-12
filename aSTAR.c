#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAP_SIZE_X 100
#define MAP_SIZE_Y 100
#define MOVE_VH 1
#define MOVE_DG 1.4

#define PNTEST(n) ((n<0)?-1:(n>0)?1:0)
#define XMOD(count) (((count<6)?1:-1)*(count-1%4))
#define YMOD(count) ((count-3)%4)



typedef enum stat{
    NONE=0,
    INM,
    STAT,
    TRAC
}stat;

typedef struct point{
    short x;
    short y;
}point;

int main(void){
    map=stat[MAP_SIZE_X-1][MAP_SIZE_Y-1];
    map={0,};

}

int astar(point status,point end,stat* map){
    float weight[8]; // 0->NW, 
    int k=0;
    for(int i=0;i<8,i++){
        weight[i]=(i%2==0)?MOVE_DG:MOVE_VH;
        weight[i]+=huristic_test({status.x+PNTEST(XMOD(count)),status.y+PNTEST(YMOD(count)},end)
        weight[i]*=avtest(map,i,status);
    }
    for(i=1;i<8,i++){
        if(weight[i]<weight[k]){
            if(weight[i]!=0||weight[k]==0){
                k=i;
            }
        }
    }
    if(k==8&&weight[k]==0)return -1;
    if(status==end){return 0;
    }else{
        map[status.x][status.y]=TRAC;
        status.x+=PNTEST(XMOD(k));
        status.y+=PNTEST(YMOD(k));
        astar(point status,point end,stat* map);
    }
}

int avtest(stat map[MAP_SIZE_X-1][MAP_SIZE_Y],int count,point status){
    if(status.x+PNTEST(XMOD(count))<0||status.x+PNTEST(XMOD(count))=>MAP_SIZE_X||status.y+PNTEST(YMOD(count))<0||status.y+PNTEST(YMOD(count))=>MAP_SIZE_Y){
        return 0;
    }
    if(map[status.x+PNTEST(XMOD(count))][status.y+PNTEST(YMOD(count))]!=0){
        return 0;
    }
    return 1;
}

int huristic(){
    return 0;
}

float huristic_test(point status,point end){
    return sqrt(pow(status.x-end.x,2)+pow(status.y-end.y,2));
}

/*
count       count-3%4   ((count<6)?1:-1)*(count-1%4)    xmod    ymod
0 -> -1+1   -3          -1                              -1      -1
1 -> -0+1   -2          0                               0       -1
2 -> +1+1   -1          1                               1       -1
3 -> +1-0   0           2                               1       0
4 -> +1-1   1           3                               1       1
5 -> -0-1   2           0                               0       1
6 -> -1-1   3           -1                              -1      1
7 -> -1-0   0           -2                              -1      0
*/
