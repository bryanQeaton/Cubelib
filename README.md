# Rubiks
A fairly performant Rubik's Cube representation written in C++

todo:
-180 turns (U2)
-center turns (M)
-double layer turns (r)
-orientation changes (x)
-solver
-pattern database
-transposition table

What is implemented:
-cube 
-zobrist hashing


move history will likely not be added due to performance issues, you are welcome to devise a system of your own though :)

____Getting Started____:
```c++
#include<iostream>
#include "cube.h"

unsigned long long perft(Cube cube,int depth){
    if (depth<=0){return 1ULL;}
    unsigned long long nodes=0;
    for (int m=0;m<12;m++){ 
        cube.make_move(m);
        nodes+=perft(cube,depth-1);
        cube.make_move(cube.reverse_moves[m]);   //undo_move  - cheap fix, double the speed over a move_history implementation :D
    }
    return nodes;
}

int main(){
    Cube cube;
    std::cout<<perft(cube,8);
    cube.ascii();
    return 0;
}
```







# Build & Run
## Windows
1. `cd src`
2. `build` or `g++ rubiks.cpp -o rubiks.exe -O3`

7431ms | 429981696nodes | 57855nodes per ms


## MacOS/Linux
```shell
make all
./rubiks
```
