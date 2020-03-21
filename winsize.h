#ifndef WINSIZE_H
#define WINSIZE_H
/*
#include<sys/ioctl.h>
#include<cstdio>
#include<unistd.h>
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

#define Xmax 30
#define Ymax 50
#endif
