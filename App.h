#include "varSetup.h"
//#include <bits/stdc++.h>
void App()
{
    readimagefile("bckgnd.jpg", 0, 0, 1600, 900);
    setfillstyle( SOLID_FILL, RGB(0,155,155));
        DrawButtons(ButtonsApp);

       clearmouseclick(WM_LBUTTONDOWN);

            int mouse_x = mousex();
            int mouse_y = mousey();

    bool ok = 1;
    while (ok)
    {


            mouse_hover_m(mouse_x,  mouse_y,ButtonsApp); //functioneaza pana la click

    if(ismouseclick(WM_LBUTTONUP))
        {
          mouse_x = mousex();
          mouse_y = mousey();
        if(overBTN(ButtonsApp[0],mouse_x,mouse_y))
        {
            clearmouseclick(WM_LBUTTONUP);
            ok = 0;
        }
        else if(overBTN(ButtonsApp[3],mouse_x,mouse_y))
        {

        }
        clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_LBUTTONDOWN);

        }
    }
}
