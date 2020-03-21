#include<string>
#include"screen.h"
using namespace std;

Screen::Screen()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    clear();
    //getmaxyx(stdscr, ymax, xmax);
}

Screen::~Screen()
{
    endwin();
}

Screen& Screen::operator<<(const char c)
{
    addch(c);
    return *this;
}

Screen& Screen::operator<<(const char* str)
{
    addstr(str);
    return *this;
}

Screen& Screen::operator<<(const vector<string>& svec)
{
    int y, x;
    getcurs(y, x);
    for(vector<string>::const_iterator it=svec.begin();
        it != svec.end(); it++){
        (*this) << it->c_str();
        mv(++y, x);
    } 
    return *this;
}       

Screen& Screen::operator<<(const CLEAR& cls)
{
    clear();
    return *this;
}

Screen& Screen::operator<<(const REFRESH& refs)
{
    refresh();
    return *this;
}

Screen& Screen::mv(int x, int y)
{
    move(x, y);
    return *this;
}
    
void Screen::getcurs(int &y, int &x)
{
    getyx(stdscr, y, x);
    return;
}
