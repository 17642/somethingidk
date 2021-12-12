#include<stdio.h>
#include<stdlib.h>

#define MAP_SIZE_X 100
#define MAP_SIZE_Y 100
#define MOVE_VH 1
#define MOVE_DG 1.4

typedef enum stat{
    NONE=0,
    INM,
    STAT,
    TRAC
}stat;

typedef struct point{
    short x;
    short y;
    stat st;
}point;

int main(void){
    map=stat[MAP_SIZE_X-1][MAP_SIZE_Y-1];
    
}

int huristic(){
    return 0;
}

/*
A* 알고리즘: 
*/