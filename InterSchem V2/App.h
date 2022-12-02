#include <varSetup.h>
//#include <bits/stdc++.h>
void App()
{
    readimagefile("bckgnd.jpg", 0, 0, 1600, 900);
    setfillstyle( SOLID_FILL, RGB(0,155,155));
        DrawButtons(ButtonsApp);

       clearmouseclick(WM_LBUTTONDOWN);

    bool ok = 1;
    while (ok)
    {
    if(ismouseclick(WM_LBUTTONUP))
        {
            int mouse_x = mousex();
            int mouse_y = mousey();
            if(overBTN(ButtonsApp[0],mouse_x,mouse_y))
        {
            clearmouseclick(WM_LBUTTONUP);
            ok = 0;
        }
        clearmouseclick(WM_LBUTTONUP);
        }
    }
}
