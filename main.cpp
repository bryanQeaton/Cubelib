#include<iostream>
#include "cube.h"

unsigned long long perft(Cube cube,int depth){
    if (depth<=0){return 1ULL;}
    unsigned long long nodes=0;
    for (int m=0;m<12;m++){
        cube.make_move(m);
        nodes+=perft(cube,depth-1);
        cube.make_move(cube.reverse_moves[m]);
    }
    return nodes;
}

int main(){
    
    Cube cube;

    std::cout<<perft(cube,8);

    cube.ascii();
    
    return 0;
}
