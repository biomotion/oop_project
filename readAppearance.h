#ifndef READF_H
#define READF_H
#include<vector>
#include<fstream>
#include<sys/ioctl.h>
#include<cstdio>
#include<unistd.h>
using namespace std;

vector<string> readFile(string fileName);
/*
int getmaxX()
{
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
}

int getmaxY()
{
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

const int Xmax = getmaxX();
const int Ymax = getmaxY();
*/
#endif    
