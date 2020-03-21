#include<list>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<thread>        //multithread
#include<unistd.h>      //sleep() and usleep()
#include"airplane.h"    //airplane and bullet
#include"monster.h"     //monster and boss
//#include"tools.h"       //tools
#include"screen.h"      //including ncurses.h implemented and instantiated to be an object
using namespace std;

//global variable
bool endGame = false;
bool dir[2];//0 for keyleft, 1 for keyright
int score=0;
airplane plane;
list<monster*> monsterP_list;
list<bullet> bullet_list;
list<bbullet> bbullet_list;

//multithread functions
void key();
void planeControl();
void planeShoot();
void bulletMove();
void display();
void monsterCreate();
void monsterMove();
void scoreCount();
//void bossShoot();
//void bossCreate();

int main()
{
    srand(time(NULL));
    //parallelly started functions
    thread keyT(key);
    thread planeControlT(planeControl);
    thread planeShootT(planeShoot);
    thread bulletMoveT(bulletMove);
    thread displayT(display);
    thread monsterCreateT(monsterCreate);
    thread monsterMoveT(monsterMove);
    thread scoreCountT(scoreCount); 
  

    if(keyT.joinable()) keyT.join();
    if(planeControlT.joinable()) planeControlT.join();
    if(planeShootT.joinable()) planeShootT.join();
    if(bulletMoveT.joinable()) bulletMoveT.join();
    if(displayT.joinable()) displayT.join();
    if(monsterCreateT.joinable()) monsterCreateT.join();
    if(monsterMoveT.joinable()) monsterMoveT.join();
    if(scoreCountT.joinable()) scoreCountT.join();

    return 0;
}

void key()
{
    int inputChar;
    while(!endGame){
        inputChar = getch(); //the only place to get input
        switch(inputChar){
			case KEY_LEFT:
				dir[0] = true;
				dir[1] = false;
				break;
			case KEY_RIGHT:
				dir[0] = false;
				dir[1] = true;
				break;
            default:
				dir[0] = false;
				dir[1] = false;
				break;
        }
        if(inputChar == 'q') endGame = true;
    }
}

void planeControl()
{
    while(!endGame){
        if(dir[0])//left
            plane.move(-1);
        if(dir[1])//right
            plane.move(1);
        sout.mv(plane.getx(), plane.gety()) << plane.getAp();
        usleep(100000);//move 1 every 0.5 second
    }
}

void planeShoot()
{
    while(!endGame){
        bullet_list.push_front(plane.shoot());
        usleep(plane.getcooldown());
    }
}

void bulletMove()
{
    while(!endGame){
        for(list<bullet>::iterator it=bullet_list.begin();
            it!=bullet_list.end(); it++){
            it->move();
            if(it->outOFrange())
                bullet_list.erase(it--);
        }
        usleep(100000);
    }
}

void monsterCreate()
{
    while(!endGame){
        if(score != 1000){
            monsterP_list.push_front(new monster);
            usleep(2000000);
        }
        else{
            for(list<monster*>::iterator it=monsterP_list.begin();
                it!=monsterP_list.end(); it++)
                delete *it;
            monsterP_list.erase(monsterP_list.begin(), monsterP_list.end());
            monsterP_list.push_front(new boss);
            usleep(10000000);
            monsterP_list.erase(monsterP_list.begin());
        }
    }
}

void monsterMove()
{
    while(!endGame){
        for(list<monster*>::iterator it=monsterP_list.begin();
            it!=monsterP_list.end(); it++){
            (*it)->move();
            if((*it)->outOFrange()){
                delete *it;
                monsterP_list.erase(it--);
            }
        }
        usleep(500000);
    }
}


void display()
{
    char scoreStr[15];
    //score & refresh
    while(!endGame){
        sout << cls;
        sprintf(scoreStr, "score: %d", score);
        sout.mv(0, 0) << scoreStr;
        sout << plane;
        for(list<bullet>::iterator it=bullet_list.begin();
            it!=bullet_list.end(); it++)
            sout << *it;
        for(list<monster*>::iterator it=monsterP_list.begin();
            it!=monsterP_list.end(); it++)
            sout << **it;
        sout << updateScr;
        usleep(5000);
    }
}

void scoreCount()
{
    while(!endGame){
        usleep(2000000);
        score += 100;
    }
} 
