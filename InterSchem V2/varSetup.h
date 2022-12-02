#include <cstring>
    struct Spot{
    int x;
    int y;
};
struct Button {
    Spot up_left;
    Spot dwn_right;
    char text[100];
}ButtonsFirstMenu[4],ButtonsApp[4];
//declarare butoane;

void atribuire(){
//Start
ButtonsFirstMenu[0].up_left.x=500;
ButtonsFirstMenu[0].up_left.y=450;
ButtonsFirstMenu[0].dwn_right.x=1100;
ButtonsFirstMenu[0].dwn_right.y=480;
strcpy(ButtonsFirstMenu[0].text,"Start");
//Setari
ButtonsFirstMenu[1].up_left.x=500;
ButtonsFirstMenu[1].up_left.y=500;
ButtonsFirstMenu[1].dwn_right.x=1100;
ButtonsFirstMenu[1].dwn_right.y=530;
strcpy(ButtonsFirstMenu[1].text,"Setari");
//Info?
ButtonsFirstMenu[2].up_left.x=500;
ButtonsFirstMenu[2].up_left.y=550;
ButtonsFirstMenu[2].dwn_right.x=1100;
ButtonsFirstMenu[2].dwn_right.y=580;
strcpy(ButtonsFirstMenu[2].text,"Info");
//Iesire
ButtonsFirstMenu[3].up_left.x=500;
ButtonsFirstMenu[3].up_left.y=600;
ButtonsFirstMenu[3].dwn_right.x=1100;
ButtonsFirstMenu[3].dwn_right.y=630;
strcpy(ButtonsFirstMenu[3].text,"Iesire");
/////////////////////////////////////////////
//       Buttons of App
/////////////////////////////////////////////


//Inapoi
ButtonsApp[0].up_left.x=5;
ButtonsApp[0].up_left.y=5;
ButtonsApp[0].dwn_right.x=100;
ButtonsApp[0].dwn_right.y=60;
strcpy(ButtonsApp[0].text,"Inapoi");
//buton 1
ButtonsApp[1].up_left.x=110;
ButtonsApp[1].up_left.y=5;
ButtonsApp[1].dwn_right.x=469;
ButtonsApp[1].dwn_right.y=60;
strcpy(ButtonsApp[1].text,"Schema noua");
//buton 2
ButtonsApp[2].up_left.x=480;
ButtonsApp[2].up_left.y=5;
ButtonsApp[2].dwn_right.x=838;
ButtonsApp[2].dwn_right.y=60;
strcpy(ButtonsApp[2].text,"Incarcare schema");
//buton test
ButtonsApp[3].up_left.x=850;
ButtonsApp[3].up_left.y=5;
ButtonsApp[3].dwn_right.x=1175;
ButtonsApp[3].dwn_right.y=60;
strcpy(ButtonsApp[3].text,"Salvare schema");

}
bool overBTN(Button BTN,int x,int y)
{
    if(x>=BTN.up_left.x&&x<=BTN.dwn_right.x&&y>=BTN.up_left.y&&y<=BTN.dwn_right.y)
            return true;
    return false;
}
int nrOfButtons=4;
void DrawButtons(Button BTN[4])
{

    for(int i=0;i<nrOfButtons;i++)
    {
        setfillstyle( SOLID_FILL, RGB(0,155,155) );
        bar(BTN[i].up_left.x,BTN[i].up_left.y,BTN[i].dwn_right.x,BTN[i].dwn_right.y);
        setcolor(RGB(255,253,226));
        setbkcolor(RGB(0,155,155));
        settextstyle(10,HORIZ_DIR,3);
        outtextxy( ((BTN[i].dwn_right.x+BTN[i].up_left.x)-textwidth( BTN[i].text))/2, ((BTN[i].dwn_right.y+BTN[i].up_left.y)-textheight( BTN[i].text))/2, BTN[i].text);
    }
}



void mouse_hover_m(int& mouse_x, int& mouse_y,Button BTNType[])
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
        settextstyle(10,HORIZ_DIR,3);
        outtextxy( ((BTNType[i].dwn_right.x+BTNType[i].up_left.x)-textwidth( BTNType[i].text))/2, ((BTNType[i].dwn_right.y+BTNType[i].up_left.y)-textheight( BTNType[i].text))/2, BTNType[i].text);

                while (overBTN(BTNType[i],mouse_x,mouse_y) && noclick)
                {
                    mouse_x = mousex();
                    mouse_y = mousey();
                    if (ismouseclick(WM_LBUTTONDOWN))
                        noclick = 0;
                }
        setcolor(RGB(255,253,226));
        setfillstyle( SOLID_FILL, RGB(0,155,155) );
        bar(BTNType[i].up_left.x,BTNType[i].up_left.y,BTNType[i].dwn_right.x,BTNType[i].dwn_right.y);
        setcolor(RGB(255,253,226));
        setbkcolor(RGB(0,155,155));
        settextstyle(10,HORIZ_DIR,3);
        outtextxy( ((BTNType[i].dwn_right.x+BTNType[i].up_left.x)-textwidth( BTNType[i].text))/2, ((BTNType[i].dwn_right.y+BTNType[i].up_left.y)-textheight( BTNType[i].text))/2, BTNType[i].text);
            }
        }
    }

}



