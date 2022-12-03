#include "varSetup.h"
//#include <bits/stdc++.h>
void App()
{
    readimagefile("bckgnd.jpg", 0, 0, 1600, 900);
    setfillstyle( SOLID_FILL, RGB(0,155,155));
        DrawButtons(ButtonsApp,nrOfButtons);

       clearmouseclick(WM_LBUTTONDOWN);

            int mouse_x = mousex();
            int mouse_y = mousey();

    bool ok = 1;
    while (ok)
    {


            mouse_hover_m(mouse_x,  mouse_y,ButtonsApp,nrOfButtons); //functioneaza pana la click

    if(ismouseclick(WM_LBUTTONUP))
        {
          mouse_x = mousex();
          mouse_y = mousey();
        if(overBTN(ButtonsApp[0],mouse_x,mouse_y))
        {
            clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_LBUTTONDOWN);
            ok = 0;
        }
        else if(overBTN(ButtonsApp[1],mouse_x,mouse_y))
        {
            clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_LBUTTONDOWN);
            DrawButtons(PannelSchem,nrOfButtons+2);
            //mouse_hover_m(mouse_x,  mouse_y,PannelSchem,1);

        }
        clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_LBUTTONDOWN);

        }
    }
}
