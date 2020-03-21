#include<iostream>
//#include"winsize.h"
//#include"readAppearance.h"
#include"screen.h"
#ifndef MONSTER_H
#define MONSTER_H
using namespace std;
class bbullet
{
  friend Screen& operator<<(Screen&, const bbullet&);
    public:
        bbullet(){}
        bbullet(int ,int ,int=1 ,int=5);
        void move();
        bool outOFrange();
        int getx(){return x;}
        int gety(){return y;}
        int getattack(){return attack;}
    protected:
        int speed;
        int attack;
        int x;
        int y;
        std::vector<std::string> bp;
};
class monster
{
        friend Screen& operator<<(Screen&, const monster&);
    public:
        monster();
        //monster(int ,int );
        virtual void move();
        bool outOFrange();
        int getx(){return x;}
        int gety(){return y;}
        int gethp(){return hp;}
        int getattack(){return attack;}
        void sety(int );
        void sethp(int);
    protected:
        int hp;
        int attack;
        int x;
        int y;
        int speed;
        std::vector<std::string> bp;
};
class boss:public monster
{
        friend Screen& operator<<(Screen&, const boss&);
    public:
        boss();
        virtual void move();
        bbullet shoot();
        void HPdown(int);
    protected:
        int bspeed;
};
#endif

