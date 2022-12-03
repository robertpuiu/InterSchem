#include <cstring>
bool CloseMenu=0;
    struct Spot{
    int x;
    int y;
};
struct Button {
    Spot up_left;
    Spot dwn_right;
    char text[100];
    int textSize;
    int color;
}ButtonsFirstMenu[4],ButtonsApp[4],PannelSchem[4];
//declarare butoane;

void atribuire(){
//Start
ButtonsFirstMenu[0].up_left.x=500;
ButtonsFirstMenu[0].up_left.y=450;
ButtonsFirstMenu[0].dwn_right.x=1100;
ButtonsFirstMenu[0].dwn_right.y=480;
strcpy(ButtonsFirstMenu[0].text,"Start");
ButtonsFirstMenu[0].textSize=3;
ButtonsFirstMenu[0].color=3;
//Setari
ButtonsFirstMenu[1].up_left.x=500;
ButtonsFirstMenu[1].up_left.y=500;
ButtonsFirstMenu[1].dwn_right.x=1100;
ButtonsFirstMenu[1].dwn_right.y=530;
strcpy(ButtonsFirstMenu[1].text,"Setari");
ButtonsFirstMenu[1].textSize=3;
ButtonsFirstMenu[1].color=3;
//Info?
ButtonsFirstMenu[2].up_left.x=500;
ButtonsFirstMenu[2].up_left.y=550;
ButtonsFirstMenu[2].dwn_right.x=1100;
ButtonsFirstMenu[2].dwn_right.y=580;
strcpy(ButtonsFirstMenu[2].text,"Info");
ButtonsFirstMenu[2].textSize=3;
ButtonsFirstMenu[2].color=3;
//Iesire
ButtonsFirstMenu[3].up_left.x=500;
ButtonsFirstMenu[3].up_left.y=600;
ButtonsFirstMenu[3].dwn_right.x=1100;
ButtonsFirstMenu[3].dwn_right.y=630;
strcpy(ButtonsFirstMenu[3].text,"Iesire");
ButtonsFirstMenu[3].textSize=3;
ButtonsFirstMenu[3].color=3;
/////////////////////////////////////////////
//       Buttons of App
/////////////////////////////////////////////


//Inapoi
ButtonsApp[0].up_left.x=5;
ButtonsApp[0].up_left.y=5;
ButtonsApp[0].dwn_right.x=100;
ButtonsApp[0].dwn_right.y=60;
strcpy(ButtonsApp[0].text,"Inapoi");
ButtonsApp[0].textSize=3;
ButtonsApp[0].color=3;
//Schema noua
ButtonsApp[1].up_left.x=110;
ButtonsApp[1].up_left.y=5;
ButtonsApp[1].dwn_right.x=469;
ButtonsApp[1].dwn_right.y=60;
strcpy(ButtonsApp[1].text,"Schema noua");
ButtonsApp[1].textSize=3;
ButtonsApp[1].color=3;
//Incarcare schema
ButtonsApp[2].up_left.x=480;
ButtonsApp[2].up_left.y=5;
ButtonsApp[2].dwn_right.x=838;
ButtonsApp[2].dwn_right.y=60;
strcpy(ButtonsApp[2].text,"Incarcare schema");
ButtonsApp[2].textSize=3;
ButtonsApp[2].color=3;
//Salvare schema
ButtonsApp[3].up_left.x=850;
ButtonsApp[3].up_left.y=5;
ButtonsApp[3].dwn_right.x=1175;
ButtonsApp[3].dwn_right.y=60;
strcpy(ButtonsApp[3].text,"Salvare schema");
ButtonsApp[3].textSize=3;
ButtonsApp[3].color=3;
///////////////////////////////////////////
// Panou stanga
///////////////////////////////////////////

// Executa
PannelSchem[0].up_left.x=5;
PannelSchem[0].up_left.y=70;
PannelSchem[0].dwn_right.x=100;
PannelSchem[0].dwn_right.y=130;
strcpy(PannelSchem[0].text,"Executa");
PannelSchem[0].textSize=2;
PannelSchem[0].color=3;
// Pranteza sus [
PannelSchem[1].up_left.x=5;
PannelSchem[1].up_left.y=135;
PannelSchem[1].dwn_right.x=100;
PannelSchem[1].dwn_right.y=180;
PannelSchem[1].color=3;
// Fundal
PannelSchem[3].up_left.x=15;
PannelSchem[3].up_left.y=150;
PannelSchem[3].dwn_right.x=90;
PannelSchem[3].dwn_right.y=880;
PannelSchem[3].color=15;
//   Pranteza jos ]
PannelSchem[2].up_left.x=5;
PannelSchem[2].up_left.y=850;
PannelSchem[2].dwn_right.x=100;
PannelSchem[2].dwn_right.y=895;
PannelSchem[2].color=3;
}
bool overBTN(Button BTN,int x,int y)
{
    if(x>=BTN.up_left.x&&x<=BTN.dwn_right.x&&y>=BTN.up_left.y&&y<=BTN.dwn_right.y)
            return true;
    return false;
}
int nrOfButtons=4;
void DrawButtons(Button BTN[],int nrOfButtons)
{

    for(int i=0;i<nrOfButtons;i++)
    {
        setfillstyle( SOLID_FILL, BTN[i].color );
        bar(BTN[i].up_left.x,BTN[i].up_left.y,BTN[i].dwn_right.x,BTN[i].dwn_right.y);
        setcolor(RGB(255,253,226));
        setbkcolor(BTN[i].color);
        settextstyle(10,HORIZ_DIR,BTN[i].textSize);
        outtextxy( ((BTN[i].dwn_right.x+BTN[i].up_left.x)-textwidth( BTN[i].text))/2, ((BTN[i].dwn_right.y+BTN[i].up_left.y)-textheight( BTN[i].text))/2, BTN[i].text);
    }
}



void mouse_hover_m(int& mouse_x, int& mouse_y,Button BTNType[],int nrOfButtons)
{
   // setfillstyle(0, culbk); // idk yet

    bool noclick = 1; //nu avem click
    while (noclick)
    {
        mouse_x = mousex();
        mouse_y = mousey();
        if (ismouseclick(WM_LBUTTONDOWN))
            noclick = 0;
        for (int i = 0; i < nrOfButtons && noclick; i++)
        {
          //  if (B[i].up_left.x<mouse_x && B[i].up_left.y < mouse_y && B[i].dwn_right.x > mouse_x && B[i].dwn_right.y > mouse_y)
          if(overBTN(BTNType[i],mouse_x,mouse_y))
            {
        setfillstyle( SOLID_FILL, RGB(0,0,155) );
        bar(BTNType[i].up_left.x,BTNType[i].up_left.y,BTNType[i].dwn_right.x,BTNType[i].dwn_right.y);
        setcolor(RGB(255,253,226));
        setbkcolor(RGB(0,0,155));
        settextstyle(10,HORIZ_DIR,BTNType[i].textSize);
        outtextxy( ((BTNType[i].dwn_right.x+BTNType[i].up_left.x)-textwidth( BTNType[i].text))/2, ((BTNType[i].dwn_right.y+BTNType[i].up_left.y)-textheight( BTNType[i].text))/2, BTNType[i].text);

                while (overBTN(BTNType[i],mouse_x,mouse_y) && noclick)
                {
                    mouse_x = mousex();
                    mouse_y = mousey();
                    if (ismouseclick(WM_LBUTTONDOWN))
                        noclick = 0;
                }
        setcolor(RGB(255,253,226));
        setfillstyle( SOLID_FILL, BTNType[i].color );
        bar(BTNType[i].up_left.x,BTNType[i].up_left.y,BTNType[i].dwn_right.x,BTNType[i].dwn_right.y);
        setcolor(RGB(255,253,226));
        setbkcolor(BTNType[i].color);
        settextstyle(10,HORIZ_DIR,BTNType[i].textSize);
        outtextxy( ((BTNType[i].dwn_right.x+BTNType[i].up_left.x)-textwidth( BTNType[i].text))/2, ((BTNType[i].dwn_right.y+BTNType[i].up_left.y)-textheight( BTNType[i].text))/2, BTNType[i].text);
            }
        }
    }

}



