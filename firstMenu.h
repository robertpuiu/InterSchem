#include <graphics.h>
#include "App.h"

void firstMenu(){
    atribuire();
    readimagefile("firstMenu.jpg", 0, 0, 1360, 765);

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

        clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_LBUTTONDOWN); // dela mouse hover


        }
    }
}
