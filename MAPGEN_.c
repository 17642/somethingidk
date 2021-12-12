#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_DIV_CNT 3
#define MAP_SIZE 100
#define URAND(n) (rand()%n) //0-(n-1)

enum type{
    NONE=0,
    GEN0,
    GEN1,
    CONNECTED,
    LINKED
};

typedef struct room{
    unsigned short xpos;
    unsigned short ypos;
    enum type rmtype;
}room;

typedef struct room2{
    unsigned short xpos;
    unsigned short xlen;
    unsigned short ypos;
    unsigned short ylen;
}room2;

void roomdiv(room*,room*,short);
void dataset(room*,room);

int main(void){
    srand(time(NULL));
    room* buffer=void;
    room* buffer2=(room*)malloc(sizeof(room));
    buffer2->xpos=0;
    buffer2->ypos=0;
    buffer2->rmtype=NONE;
    for(i=0;i<MAP_DIV_CNT;i++){
        buffer=(room*)malloc(sizeof(room)*2^i+1);
        roomdiv(buffer,buffer2,i);
        free(buffer2);
        buffer2=(room*)malloc(sizeof(room)*2^i+1);
        for(short a=0;a<2^i;a++){
            dataset(buffer2+a,buffer[a]);
        }
        free(buffer);
    }
    room room[2^MAP_DIV_CNT];
    for(i=0;i<2^MAP_DIV_CNT;i++){
        dataset(room+i,buffer2[i]);
    }
    free(buffer2);
    return 0;
}

void roomdiv(room* room,room* Fdata,short cnt){
    room* buffer=(room*)malloc(sizeof(room)*(2^cnt+1));
    for(short i=0;i<2^cnt;i++){
        buffer[2*i]=Fdata[i];
        buffer[2*i+1]=Fdata[i];
        if(URNAD(2)==0){
            buffer[2*i+1].xpos=((Fdata[i+1].xpos==0)?(MAP_SIZE)|(Fdata[i+1].xpos)-Fdata[i].xpos)/2+Fdata[i].xpos;
        }else{
            buffer[2*i+1].ypos=((Fdata[i+1].ypos==0)?(MAP_SIZE)|(Fdata[i+1].ypos)-Fdata[i].ypos)/2+Fdata[i].ypos;
        }
    }
    for(i=0;i<2^cnt+1<i++){
        dataset(room+i,buffer[i]);
    }
    free(buffer);
    
}

void dataset(room* a,room b){
    a->xpos=b.xpos;
    a->ypos=b.ypos;
    a->type=b.type;
}

/*
 room div ->
[a,n,n,n,n,n,n,n]
[a,n,n,n,b,n,n,n]
[a0,a1,n,n,b0,b1,n,n]
+-20%/

((URAND(40))-20)*MAP_SIZE
(i==2^cnt-1)?(MAP_SIZE)|(Fdata[i+1].xpos)
*/