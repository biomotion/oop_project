#include<iostream>
#include<cstdlib>
#include<vector>
#include"monster.h"
//#include"airplane.h"
#include"winsize.h"
#include"readAppearance.h"
using namespace std;
bbullet::bbullet(int a, int b,int s, int atk)
{
    x=a;
    y=b;
    speed=s;
    attack=atk;
    bp= readFile("bbullet.txt");
}
bool bbullet::outOFrange()
{   return x>=Xmax;}
void bbullet::move()
{
    x-=speed;
}
monster::monster()
{   
    x=0;
    y=rand()%(Ymax-5);
    hp=1;
    attack=2;
    speed=1;    
    bp=readFile("monster.txt");
}
bool monster::outOFrange()
{   return x>Xmax-4;} 
void monster::move()
{
        x+=speed;
}
void monster::sety(int s)
{
    y+=s;
}
void monster::sethp(int att)
{
    hp-=att;
}
boss::boss()
{
    x=0;
    y=rand()%(Ymax-11);
    hp=200;
    speed=1;
    bspeed=1;
    bp=readFile("boss.txt");
}
void boss::move()
{
    if(gety()==0)
        sety(speed);
    else if(gety()==Ymax-10)
        sety(-speed);
    else 
    {
        int a=rand()%2;
            if(a==1)
                sety(speed);
            else
                sety(-speed);
    }
        
}
bbullet boss::shoot()
{
    return bbullet(x,y,bspeed,attack);
}
void boss::HPdown(int att)
{
   sethp(att);
}
Screen& operator<<(Screen& out, const bbullet& rval)
{
    out.mv(rval.x, rval.y) << rval.bp;
    return out;
}
Screen& operator<<(Screen& out, const monster& rval)
{
    out.mv(rval.x, rval.y) << rval.bp;
    return out;
}
Screen& operator<<(Screen& out, const boss& rval)
{
    out.mv(rval.x, rval.y) << rval.bp;
    return out;
}
