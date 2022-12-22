#include "Schem.h"
#include <fstream>
char typedText[100]="";
void ScrieTextSalvareSchema(char typedText[])
{
    setcolor(0);
    setbkcolor(15);
    settextstyle(3, HORIZ_DIR, 2);
    int x=1200-textwidth(typedText)/2;
    int y=400;
    outtextxy(x, y,typedText );//modificate coordonatele in fuctie de type

}
void AfisareTextSalvareSchema(char typedText[])
{
    setfillstyle(SOLID_FILL, 15);
    bar(1050, 100, 1350, 550);
    setcolor(0);
    setbkcolor(15);
    settextstyle(3 , HORIZ_DIR, 2);
    outtextxy(1100, 200,"Numeste noul fisier" );
    //ScrieTextSalvareSchema()

}
void SalvareSchema()
{
    char typedText[100]="";
    int indexTypedText=0;
    char tasta,enter=13,backspace=8;
    bool ok=1;
    while(ok)
    {
        tasta=getch();
        if(tasta==enter)
        {
            AfisareTextSalvareSchema(typedText);
        ScrieTextSalvareSchema(typedText);
            break;
        }
        if(tasta==backspace)
        {
            AfisareTextSalvareSchema(typedText);
            typedText[--indexTypedText]=NULL;
        ScrieTextSalvareSchema(typedText);
        }
        if(tasta!=backspace)
        {
        typedText[indexTypedText]=tasta;
        indexTypedText++;
        AfisareTextSalvareSchema(typedText);
        ScrieTextSalvareSchema(typedText);
        }

    }
    setfillstyle(SOLID_FILL, 15);
    bar(1050, 100, 1350, 550);

}
void App()
{
    readimagefile("bckgnd.jpg", 0, 0, 1360, 765);
    setfillstyle(SOLID_FILL, RGB(0, 155, 155));
    DrawButtons(ButtonsApp, nrOfButtons);

    clearmouseclick(WM_LBUTTONDOWN);
    int mouse_x = mousex();
    int mouse_y = mousey();
    bool ok = 1;
    while (ok)
    {


        mouse_hover_m(mouse_x, mouse_y, ButtonsApp, nrOfButtons); //functioneaza pana la click

        if (ismouseclick(WM_LBUTTONUP))
        {
            mouse_x = mousex();
            mouse_y = mousey();
            if (overBTN(ButtonsApp[0], mouse_x, mouse_y))
            {
                clearmouseclick(WM_LBUTTONUP);
                clearmouseclick(WM_LBUTTONDOWN);
                ok = 0;
            }
            else if (overBTN(ButtonsApp[1], mouse_x, mouse_y))
            {
                setfillstyle(SOLID_FILL, 15);
                bar(0, 61, 1025, 900);
                clearmouseclick(WM_LBUTTONUP);
                clearmouseclick(WM_LBUTTONDOWN);
                DrawButtons(PannelSchem, nrOfButtons + 2);
                //mouse_hover_m(mouse_x,  mouse_y,PannelSchem,1);
                Schem();

            }
            else if(overBTN(ButtonsApp[3], mouse_x, mouse_y))
            {
                SalvareSchema();
            }
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);

        }
    }
}
