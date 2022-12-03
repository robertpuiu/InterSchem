#include <graphics.h>
#include "App.h"

void firstMenu(){
    atribuire();
    readimagefile("firstMenu.jpg", 0, 0, 1600, 900);

    DrawButtons(ButtonsFirstMenu,nrOfButtons);

            int mouse_x = mousex();
            int mouse_y = mousey();


    clearmouseclick(WM_LBUTTONDOWN);
    bool ok = 1;
    while (ok)
    {
       mouse_hover_m(mouse_x,  mouse_y,ButtonsFirstMenu,nrOfButtons); //functioneaza pana la click

    if(ismouseclick(WM_LBUTTONUP))
        {
            mouse_x = mousex();

             mouse_y = mousey();
            if(overBTN(ButtonsFirstMenu[0],mouse_x,mouse_y))
        {
            App();
            clearmouseclick(WM_LBUTTONUP);
            firstMenu();
            ok = 0;

        }
        if(overBTN(ButtonsFirstMenu[3],mouse_x,mouse_y))
        {
            clearmouseclick(WM_LBUTTONUP);
            ok=0;
            CloseMenu=1;
        }
       /*  else if (mouse_x >= x_Settings1 && mouse_x <= x_Settings2 && mouse_y >= y_Settings1 && mouse_y <= y_Settings2)
        {
            //setting();
            firstMenu();
            ok = 0;
        }
       else if (mouse_x >= x_semnint1 && mouse_x <= x_semnint2 && mouse_y >= y_semnint1 && mouse_y <= y_semnint2)
        {
            //info();
            firstMenu();
            ok = 0;
        }
        else
        {
            firstMenu();
            ok = 0;
        }*/

        clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_LBUTTONDOWN); // dela mouse hover


        }
    }
}
