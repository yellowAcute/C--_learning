#if !defined(SCREEN_H)
#define SCREEN_H
using namespace std;
#include <iostream>
#include <string>
#include "../inc/Window_mgr.h"


class Window_mgr;

class Screen
{

    typedef string::size_type pos;
    friend void Window_mgr::clear(ScreenIndex);

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    string contents;

    void do_display(ostream &os) const
    {
        os << contents;
    }

public:
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                     contents(ht * wd, c) {}
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, 0) {}

    Screen &set(pos ht, pos wd, char c)
    {
        contents[ht * height + wd] = c;
        return *this;
    }

    Screen &set(char c)
    {
        contents[cursor] = c;
        return *this;
    }

    pos size() const;

    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }

    char get() const
    {
        return contents[cursor];
    }

    char get(pos ht, pos wd) const
    {
        pos row = ht * height;
        return contents[row + wd];
    }

    Screen &move(pos r, pos c)
    {
        pos row = r * height;
        cursor = row + c;
        return *this;
    }
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

Screen::pos Screen::size() const{
    return height * width;
}

#endif // SCREEN_H
