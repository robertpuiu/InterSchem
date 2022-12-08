#include "varSetup.h"

int x[4]={10,50,10,30};
int y[4]={200,350,550,720};
int cx[4]={10,50,10,30};
int cy[4]={200,350,550,720};
void atribuireSchem()
{
    //////////////////////////////////
//      Blocuri
//////////////////////////////////
//  Input
Blocks[0].upLeft.x=x[0];
Blocks[0].upLeft.y=y[0];
Blocks[0].upRight.x=Blocks[0].upLeft.x+90;
Blocks[0].upRight.y=Blocks[0].upLeft.y;
Blocks[0].dwnLeft.x=Blocks[0].upLeft.x+20;
Blocks[0].dwnLeft.y=Blocks[0].upLeft.y+50;
Blocks[0].dwnRight.x=Blocks[0].upLeft.x+70;
Blocks[0].dwnRight.y=Blocks[0].upLeft.y+50;
strcpy(Blocks[0].text,"Input");
// If
Blocks[1].upLeft.x=x[1];
Blocks[1].upLeft.y=y[1];
Blocks[1].upRight.x=Blocks[1].upLeft.x;
Blocks[1].upRight.y=Blocks[1].upLeft.y;
Blocks[1].dwnLeft.x=Blocks[1].upLeft.x-45;
Blocks[1].dwnLeft.y=Blocks[1].upLeft.y+70;
Blocks[1].dwnRight.x=Blocks[1].upLeft.x+50;
Blocks[1].dwnRight.y=Blocks[1].upLeft.y+70;
strcpy(Blocks[1].text,"If");

// Operatie
Blocks[2].upLeft.x=x[2];
Blocks[2].upLeft.y=y[2];
Blocks[2].upRight.x=Blocks[2].upLeft.x+90;
Blocks[2].upRight.y=Blocks[2].upLeft.y;
Blocks[2].dwnLeft.x=Blocks[2].upLeft.x;
Blocks[2].dwnLeft.y=Blocks[2].upLeft.y+50;
Blocks[2].dwnRight.x=Blocks[2].upLeft.x+90;
Blocks[2].dwnRight.y=Blocks[2].upLeft.y+50;
strcpy(Blocks[2].text,"Operatie");

//Output
Blocks[3].upLeft.x=x[3];
Blocks[3].upLeft.y=y[3];
Blocks[3].upRight.x=Blocks[3].upLeft.x+50;
Blocks[3].upRight.y=Blocks[3].upLeft.y;
Blocks[3].dwnLeft.x=Blocks[3].upLeft.x-20;
Blocks[3].dwnLeft.y=Blocks[3].upLeft.y+50;
Blocks[3].dwnRight.x=Blocks[3].upLeft.x+70;
Blocks[3].dwnRight.y=Blocks[3].upLeft.y+50;
strcpy(Blocks[3].text,"Output");

}
void DrawName(Block Block)
{
    setbkcolor(15);
    settextstyle(10,HORIZ_DIR,2);
    outtextxy( ((Block.upLeft.x+Block.upRight.x)-textwidth( Block.text))/2, Block.upLeft.y-40,Block.text);
}
void DrawBlock(Block Block,int color)
{
    setcolor(color);
        line(Block.upLeft.x,Block.upLeft.y,Block.upRight.x,Block.upRight.y);//sus
        line(Block.upRight.x,Block.upRight.y,Block.dwnRight.x,Block.dwnRight.y);//dreapta
        line(Block.upLeft.x,Block.upLeft.y,Block.dwnLeft.x,Block.dwnLeft.y);//stanga
        line(Block.dwnLeft.x,Block.dwnLeft.y,Block.dwnRight.x,Block.dwnRight.y);//jos
        circle((Block.upLeft.x+Block.upRight.x)/2,Block.upLeft.y-4,6);
        if(Block.upLeft.x==Block.upRight.x)//daca e if
        {
            circle(Block.dwnLeft.x+4,Block.dwnLeft.y+4,6);
            circle(Block.dwnRight.x-4,Block.dwnRight.y+4,6);
        }
        else
            circle((Block.dwnRight.x+Block.dwnLeft.x)/2,Block.dwnLeft.y+4,6);

}
bool overBlock(Block Block, int x,int y)
{
    //if(x>=BTN.up_left.x&&x<=BTN.dwn_right.x&&y>=BTN.up_left.y&&y<=BTN.dwn_right.y)

    if(x>=Block.dwnLeft.x&&x<=Block.dwnRight.x&&y>=Block.upLeft.y&&y<=Block.dwnLeft.y)
            return true;
    return false;
}



/*
void rand_coord(int &xblock,int &yblock)
{
int coord_x=0, coord_y=0;
    srand(time(0));
    coord_x = rand() % 900 + 150;
   srand(time(0));
    coord_y = rand() % 650 + 150;
    xblock = coord_x;
    yblock = coord_y;
}
*/


int ff=1;
void Schem()
{
setfillstyle( SOLID_FILL, RGB(0,0,155) );
        bar(ButtonsApp[1].up_left.x,ButtonsApp[1].up_left.y,ButtonsApp[1].dwn_right.x,ButtonsApp[1].dwn_right.y);
        setcolor(RGB(255,253,226));
        setbkcolor(RGB(0,0,155));
        settextstyle(10,HORIZ_DIR,ButtonsApp[1].textSize);
        outtextxy( ((ButtonsApp[1].up_left.x+ButtonsApp[1].dwn_right.x)-textwidth( ButtonsApp[1].text))/2, ((ButtonsApp[1].dwn_right.y+ButtonsApp[1].up_left.y)-textheight( ButtonsApp[1].text))/2, ButtonsApp[1].text);
    for(int i=0;i<4;i++)
    {
        x[i]=cx[i];
        y[i]=cy[i];
    }
    atribuireSchem();

    for(int i=0;i<4;i++)
           {
               DrawBlock(Blocks[i],0);
               DrawName(Blocks[i]);
           }

        int mouse_x = mousex();
        int mouse_y = mousey();

    bool ok=1,selected=0;
    int i;
    while(ok)
    {
        if(ismouseclick(WM_LBUTTONDOWN)&&selected==0)
        {
          mouse_x = mousex();
          mouse_y = mousey();
          for(i=0;i<4;i++)
        if(overBlock(Blocks[i],mouse_x,mouse_y))
        {
            selected=1;
            ff=1;
            break;
        }

        clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_LBUTTONDOWN);

        }
        while(selected)
        {
            DrawBlock(Blocks[i],15);

            x[i]=mouse_x;
            y[i]=mouse_y;
            atribuireSchem();
          mouse_x = mousex();
          mouse_y = mousey();
        DrawBlock(Blocks[i],4);
            if(ismouseclick(WM_LBUTTONDOWN))
               {
        clearmouseclick(WM_LBUTTONDOWN);
                  selected=0;
                  x[i]=cx[i];
                  y[i]=cy[i];
                  atribuireSchem();
                  DrawBlock(Blocks[i],0);
                  selected=0;
               }

        }
if(ismouseclick(WM_RBUTTONDOWN))
               {
                   ok=0;
                   clearmouseclick(WM_RBUTTONDOWN);
        clearmouseclick(WM_RBUTTONUP);
               }
}
        clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_LBUTTONDOWN);

     }


