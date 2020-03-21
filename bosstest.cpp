#include<iostream>
#include<unistd.h>
#include"screen.h"
#include"monster.h"
using namespace std;

int main()
{
    boss b1;
    while(!b1.outOFrange()){
        sout << b1 << updateScr;
        b1.move();
        usleep(250000);
        sout << cls;
    }
    return 0;
}

