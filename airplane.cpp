//#include<iostream>
//#include<cstring>
//#include<vector>
#include<string>
#include"airplane.h"
#include"winsize.h"
#include"readAppearance.h"
using namespace std;
bullet::bullet(int x,int y,int s,int a)
{
    speed=s;
    attack=a;
    b_x=x;
    b_y=y;
    ap = readFile("bullet.txt");
}
void bullet::move()
{
    b_x-=speed;
}
airplane::airplane()
{
    HP=10;
    x=Xmax;
    y=Ymax/2;
    bspeed=1;
    cooldown=1000000;
    ap = readFile("airplane.txt");
}
void airplane::move(int num)
{
    if(num > 0)
        if(y<Ymax)
            y+=num;
        else
            y = Ymax;
    else // num <= 0
        if(y>0)
            y+=num;
        else
            y = 0;
    /*
     if(y<=Ymax && y>0)
        y+=num;
     else if(num>0)
        y = Ymax;  
     else 
        y = 0;  
    */
}
bullet airplane::shoot()
{
    return bullet(x,y+5,bspeed,attack);
}
void airplane::assignbspeed(int bs)
{
    bspeed+=bs;
}
void airplane::HPup(int h)
{
    HP+=h;
}
void airplane::CDup(int cd)
{
    cooldown+=cd;
}   

Screen& operator<<(Screen& out, const airplane& rval)
{
    out.mv(rval.x, rval.y) << rval.ap;
    return out;
}

Screen& operator<<(Screen& out, const bullet& rval)
{
    int i=0;
    out.mv(rval.b_x, rval.b_y) << rval.ap;
    return out;
}
