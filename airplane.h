#ifndef AIRPLANE_H
#define AIRPLANE_H
//#include"winsize.h"
#include"screen.h"
#include<string>
#include<vector>
class bullet
{
    friend Screen& operator<<(Screen& out, const bullet& rval);
public:
    bullet(int,int,int=1,int=1);
    void move();
    bool outOFrange(){return b_x<=0;} 
    int getattack(){return attack;}
    int getspeed(){ return speed;}
    int getx(){return b_x;}
    int gety(){return b_y;}
    std::vector<std::string> getAp() const {return ap;} 
protected:
    int speed;
    int attack;
    int b_x;
    int b_y;
    std::vector<std::string> ap;
};
class airplane
{
    friend Screen& operator<<(Screen& out, const airplane& rval);
public:
    airplane();
    void move(int);
    bullet shoot();
    void assignbspeed(int);
    void HPup(int);
    void CDup(int);
    int getcooldown(){return cooldown;}
    int gethp(){return HP;}
    int getx(){return x;}
    int gety(){return y;}
    std::vector<std::string> getAp() const {return ap;}
protected:
    std::vector<std::string> ap;
    int HP;
    int x;
    int y;
    int bspeed;
    int attack;
    int cooldown;//in micro second
};
#endif

