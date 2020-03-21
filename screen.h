#ifndef SCREEN_H
#define SCREEN_H
#include<ncurses.h>
#include<vector>

class CLEAR{};
class REFRESH{};

class Screen{
public:
    Screen();
    ~Screen();
    Screen& operator<<(const char);
    Screen& operator<<(const char*);
    Screen& operator<<(const std::vector<std::string>&);
    Screen& operator<<(const CLEAR&);
    Screen& operator<<(const REFRESH&);
    Screen& mv(int x,int y);
    void getcurs(int&, int&);
    //int Ymax() { return ymax; }
    //int Xmax() { return xmax; }
private:
    //int ymax, xmax;
};

static CLEAR cls;
static REFRESH updateScr;
static Screen sout;

#endif
