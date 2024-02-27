#if !defined(WINDOW_MGR_H)
#define WINDOW_MGR_H
using namespace std;
#include "../inc/Screen.h"
#include <vector>
#include <string>

class Screen;

class Window_mgr
{

private:
    vector<Screen> screens{Screen(24, 80, ' ')};

public:
    using ScreenIndex = vector<Screen>::size_type;
    Window_mgr(/* args */);
    ~Window_mgr();
    void clear(ScreenIndex);
};

Window_mgr::Window_mgr(/* args */)
{
}

Window_mgr::~Window_mgr()
{
}

#endif // WINDOW_MGR_H
