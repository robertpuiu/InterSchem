#include <graphics.h>
#include "firstMenu.h"
using namespace std;

int main()
{
    initwindow(1360, 765, "Interschem Puiu Robert si Sirbu Sandu");
    firstMenu();
    while(!CloseMenu)
    getch();
    return 0;
}
