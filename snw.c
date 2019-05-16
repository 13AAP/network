#include <stdio.h>
#include <stdlib.h>

int initpos = 0;

int recieve(char ch,int pos){
    int ac = rand() % 100 + 1;
    int rb = rand() % 100 + 1;
    if(ac < 20) return 0;
    if(pos < initpos){
        printf("Skipping %c\n", ch);
        return 1;
    }
    printf("Recieved %c\n", ch);
    initpos++;
    if(rb < 10) return 0;
    return 1;
} 

int send(char* message, int len){
    initpos = 0;
    for(int i = 0; i < len; ){
        printf("Sent %c\n",message[i]);
        if(recieve(message[i],i))
            i++;
    }
}

int main(){
    send("Hello",5);
    return 0;
}
