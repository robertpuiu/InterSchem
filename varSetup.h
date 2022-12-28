#include <cstring>
#include <graphics.h>
#include <iostream>
bool schemGrid[725][1025]={0};
int nrOfButtons = 4;
int indexStartBlock;
int yLineWriten;
bool CloseMenu = 0;
bool startBlockExists=0;
struct Spot {
    int x;
    int y;
};
struct Button {
    Spot up_left;
    Spot dwn_right;
    char text[100];
    char Litera;
    int textSize;
    int color;
    int selected = 0;
    int visited=0;
    bool disponibilOutput=0;
}ButtonsFirstMenu[4], ButtonsApp[4], PannelSchem[6], ButtonsInputs[8];
//declarare butoane;
struct Block {
    int type;
    int CB_type;
    Spot upLeft;
    Spot upRight;
    Spot dwnLeft;
    Spot dwnRight;
    int nrCircles;
    Button ConnectCircle[3];
    bool isCircleConected[3]={0};
    int indexBlockConnexionTo[3];
    int indexCirecleConnexionTo[3];
    Spot lineEndSpot[3];
    Spot Circles[3];//centru
    int color;//negru
    char headText[100];
    char inputText[100];

}Blocks[4],CreatedBlocks[20],CB_HitBox[20];//Blocks [0]  = input Blocks[1]=if Blocks[2]=operatie/calcul Blocks[3]=output;
struct CB // created blocks
{
    Block CB_array[20];
    int CB_type[20];
    Block CB_HitBox[20];
    Button ConnectCircle[20][3];
};
int nr_CreatedBlock = 0;

void atribuire() {
    //Start
    ButtonsFirstMenu[0].up_left.x = 380;
    ButtonsFirstMenu[0].up_left.y = 450;
    ButtonsFirstMenu[0].dwn_right.x = 980;
    ButtonsFirstMenu[0].dwn_right.y = 480;
    strcpy(ButtonsFirstMenu[0].text, "Start");
    ButtonsFirstMenu[0].textSize = 3;
    ButtonsFirstMenu[0].color = 3;
    //Setari
    ButtonsFirstMenu[1].up_left.x = 380;
    ButtonsFirstMenu[1].up_left.y = 500;
    ButtonsFirstMenu[1].dwn_right.x = 980;
    ButtonsFirstMenu[1].dwn_right.y = 530;
    strcpy(ButtonsFirstMenu[1].text, "Setari");
    ButtonsFirstMenu[1].textSize = 3;
    ButtonsFirstMenu[1].color = 3;
    //Info?
    ButtonsFirstMenu[2].up_left.x = 380;
    ButtonsFirstMenu[2].up_left.y = 550;
    ButtonsFirstMenu[2].dwn_right.x = 980;
    ButtonsFirstMenu[2].dwn_right.y = 580;
    strcpy(ButtonsFirstMenu[2].text, "Info");
    ButtonsFirstMenu[2].textSize = 3;
    ButtonsFirstMenu[2].color = 3;
    //Iesire
    ButtonsFirstMenu[3].up_left.x = 380;
    ButtonsFirstMenu[3].up_left.y = 600;
    ButtonsFirstMenu[3].dwn_right.x = 980;
    ButtonsFirstMenu[3].dwn_right.y = 630;
    strcpy(ButtonsFirstMenu[3].text, "Iesire");
    ButtonsFirstMenu[3].textSize = 3;
    ButtonsFirstMenu[3].color = 3;
    /////////////////////////////////////////////
    //       Buttons of App
    /////////////////////////////////////////////


    //Inapoi
    ButtonsApp[0].up_left.x = 5;
    ButtonsApp[0].up_left.y = 5;
    ButtonsApp[0].dwn_right.x = 100;
    ButtonsApp[0].dwn_right.y = 40;
    strcpy(ButtonsApp[0].text, "Inapoi");
    ButtonsApp[0].textSize = 2;
    ButtonsApp[0].color = 3;
    //Schema noua
    ButtonsApp[1].up_left.x = 110;
    ButtonsApp[1].up_left.y = 5;
    ButtonsApp[1].dwn_right.x = 310;
    ButtonsApp[1].dwn_right.y = 40;
    strcpy(ButtonsApp[1].text, "Schema noua");
    ButtonsApp[1].textSize = 2;
    ButtonsApp[1].color = 3;
    //Incarcare schema
    ButtonsApp[2].up_left.x = 320;
    ButtonsApp[2].up_left.y = 5;
    ButtonsApp[2].dwn_right.x = 570;
    ButtonsApp[2].dwn_right.y = 40;
    strcpy(ButtonsApp[2].text, "Incarcare schema");
    ButtonsApp[2].textSize = 2;
    ButtonsApp[2].color = 3;
    //Salvare schema
    ButtonsApp[3].up_left.x = 580;
    ButtonsApp[3].up_left.y = 5;
    ButtonsApp[3].dwn_right.x = 830;
    ButtonsApp[3].dwn_right.y = 40;
    strcpy(ButtonsApp[3].text, "Salvare schema");
    ButtonsApp[3].textSize = 2;
    ButtonsApp[3].color = 3;
    ///////////////////////////////////////////
    // Panou stanga
    ///////////////////////////////////////////

    // Cod - stage 1 | Executa stage 2
    PannelSchem[0].up_left.x = 840;
    PannelSchem[0].up_left.y = 2;
    PannelSchem[0].dwn_right.x = 1025;
    PannelSchem[0].dwn_right.y = 43;
    strcpy(PannelSchem[0].text, "Cod");
    PannelSchem[0].textSize = 2;
    PannelSchem[0].color = 2;
    // Pranteza sus [
    PannelSchem[1].up_left.x = 5;
    PannelSchem[1].up_left.y = 45;
    PannelSchem[1].dwn_right.x = 100;
    PannelSchem[1].dwn_right.y = 80;
    PannelSchem[1].color = 3;
    // Fundal
    PannelSchem[3].up_left.x = 15;
    PannelSchem[3].up_left.y = 63;
    PannelSchem[3].dwn_right.x = 90;
    PannelSchem[3].dwn_right.y = 745;
    PannelSchem[3].color = 15;
    //   Pranteza jos ]
    PannelSchem[2].up_left.x = 5;
    PannelSchem[2].up_left.y = 725;
    PannelSchem[2].dwn_right.x = 100;
    PannelSchem[2].dwn_right.y = 763;
    PannelSchem[2].color = 3;
    //  Block Start
    PannelSchem[4].up_left.x = 110;
    PannelSchem[4].up_left.y = 45;
    PannelSchem[4].dwn_right.x = 1025;
    PannelSchem[4].dwn_right.y = 80;
    PannelSchem[4].color = 3;
    strcpy(PannelSchem[4].text, "START");
    PannelSchem[4].textSize = 4;
    // Block Stop
    PannelSchem[5].up_left.x = 110;
    PannelSchem[5].up_left.y = 725;
    PannelSchem[5].dwn_right.x = 1025;
    PannelSchem[5].dwn_right.y = 763;
    PannelSchem[5].color = 3;
    strcpy(PannelSchem[5].text, "STOP");
    PannelSchem[5].textSize = 4;
}
bool overBTN(Button BTN, int x, int y)
{
    if (x >= BTN.up_left.x && x <= BTN.dwn_right.x && y >= BTN.up_left.y && y <= BTN.dwn_right.y)
        return true;
    return false;
}

void DrawButtons(Button BTN[], int nrOfButtons)
{

    for (int i = 0; i < nrOfButtons; i++)
    {
        setfillstyle(SOLID_FILL, BTN[i].color);
        bar(BTN[i].up_left.x, BTN[i].up_left.y, BTN[i].dwn_right.x, BTN[i].dwn_right.y);
        setcolor(RGB(255, 253, 226));
        setbkcolor(BTN[i].color);
        settextstyle(10, HORIZ_DIR, BTN[i].textSize);
        outtextxy(((BTN[i].dwn_right.x + BTN[i].up_left.x) - textwidth(BTN[i].text)) / 2, ((BTN[i].dwn_right.y + BTN[i].up_left.y) - textheight(BTN[i].text)) / 2, BTN[i].text);
    }
}
void DrawButton(Button BTN)
{
    setfillstyle(SOLID_FILL, BTN.color);
        bar(BTN.up_left.x, BTN.up_left.y, BTN.dwn_right.x, BTN.dwn_right.y);
        setcolor(RGB(255, 253, 226));
        setbkcolor(BTN.color);
        settextstyle(10, HORIZ_DIR, BTN.textSize);
        outtextxy(((BTN.dwn_right.x + BTN.up_left.x) - textwidth(BTN.text)) / 2, ((BTN.dwn_right.y + BTN.up_left.y) - textheight(BTN.text)) / 2, BTN.text);

}


void mouse_hover_m(int& mouse_x, int& mouse_y, Button BTNType[], int nrOfButtons)
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
            if (overBTN(BTNType[i], mouse_x, mouse_y))
            {
                setfillstyle(SOLID_FILL, RGB(0, 0, 155));
                bar(BTNType[i].up_left.x, BTNType[i].up_left.y, BTNType[i].dwn_right.x, BTNType[i].dwn_right.y);
                setcolor(RGB(255, 253, 226));
                setbkcolor(RGB(0, 0, 155));
                settextstyle(10, HORIZ_DIR, BTNType[i].textSize);
                outtextxy(((BTNType[i].dwn_right.x + BTNType[i].up_left.x) - textwidth(BTNType[i].text)) / 2, ((BTNType[i].dwn_right.y + BTNType[i].up_left.y) - textheight(BTNType[i].text)) / 2, BTNType[i].text);

                while (overBTN(BTNType[i], mouse_x, mouse_y) && noclick)
                {
                    mouse_x = mousex();
                    mouse_y = mousey();
                    if (ismouseclick(WM_LBUTTONDOWN))
                        noclick = 0;
                }
                setcolor(RGB(255, 253, 226));
                setfillstyle(SOLID_FILL, BTNType[i].color);
                bar(BTNType[i].up_left.x, BTNType[i].up_left.y, BTNType[i].dwn_right.x, BTNType[i].dwn_right.y);
                setcolor(RGB(255, 253, 226));
                setbkcolor(BTNType[i].color);
                settextstyle(10, HORIZ_DIR, BTNType[i].textSize);
                outtextxy(((BTNType[i].dwn_right.x + BTNType[i].up_left.x) - textwidth(BTNType[i].text)) / 2, ((BTNType[i].dwn_right.y + BTNType[i].up_left.y) - textheight(BTNType[i].text)) / 2, BTNType[i].text);
            }
        }
    }

}
void DrawName(Block Block)
{
    setbkcolor(15);
    settextstyle(10, HORIZ_DIR, 2);

    if (strcmp(Block.headText, "If"))
        outtextxy(((Block.upLeft.x + Block.upRight.x) - textwidth(Block.headText)) / 2, Block.upLeft.y - 40, Block.headText);
    else outtextxy(((Block.upLeft.x * 2) - textwidth(Block.headText)) / 2, Block.upLeft.y - 40, Block.headText);
}
void DrawBlock(Block Block, int color)
{
    setcolor(color);
    line(Block.upLeft.x, Block.upLeft.y, Block.upRight.x, Block.upRight.y);//sus
    line(Block.upRight.x, Block.upRight.y, Block.dwnRight.x, Block.dwnRight.y);//dreapta
    line(Block.upLeft.x, Block.upLeft.y, Block.dwnLeft.x, Block.dwnLeft.y);//stanga
    line(Block.dwnLeft.x, Block.dwnLeft.y, Block.dwnRight.x, Block.dwnRight.y);//jos
    for (int i = 0; i < Block.nrCircles; i++)
    {
        circle(Block.Circles[i].x, Block.Circles[i].y, 6);
    }
}
bool overBlock(Block Block, int x, int y)
{
    //if(x>=BTN.up_left.x&&x<=BTN.dwn_right.x&&y>=BTN.up_left.y&&y<=BTN.dwn_right.y)


    if ((x >= Block.dwnLeft.x || x >= Block.upLeft.x) && (x <= Block.dwnRight.x || x <= Block.upRight.x) && y >= Block.upLeft.y && (y <= Block.dwnLeft.y || y <= Block.dwnRight.y))
        return true;
    return false;
}
void CleanSpace()
{
     setfillstyle(SOLID_FILL, 15);
                bar( 110 , 85 , 1025 ,720 );
}
void DrawInputText(int index,int syze)// delete syze | CreatedBlocks[index].CB_type=>text syze
{
    if(CreatedBlocks[index].CB_type==1||CreatedBlocks[index].CB_type==2)
        syze=1;
    setcolor(0);
    setbkcolor(15);
    settextstyle(3, HORIZ_DIR, syze);
    int x=(CreatedBlocks[index].upLeft.x+CreatedBlocks[index].upRight.x+CreatedBlocks[index].dwnLeft.x+CreatedBlocks[index].dwnRight.x)/4;
    int y=(CreatedBlocks[index].upLeft.y+CreatedBlocks[index].upRight.y+CreatedBlocks[index].dwnLeft.y+CreatedBlocks[index].dwnRight.y)/4;
    outtextxy(x-textwidth(CreatedBlocks[index].inputText)/2, y-textheight(CreatedBlocks[index].inputText)/2,CreatedBlocks[index].inputText );//modificate coordonatele in fuctie de type

}
  /* // dont`t delete pls
void DrawDynamicLine(int xStart, int yStart)
{
    clearmouseclick(WM_LBUTTONUP);
    clearmouseclick(WM_LBUTTONDOWN);
    bool ok=1;
    int actualX=mousex();
    int actualY=mousey();
    while(ok){
            if(actualX!=mousex()||actualY!=mousey())
            {
                setcolor(15);
                line(xStart,yStart,actualX,actualY);
                actualX=mousex();
                actualY=mousey();
                setcolor(0);
                line(xStart,yStart,actualX,actualY);
                delay(10);
            }
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            ok=0;
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);
            setcolor(15);
            line(xStart,yStart,actualX,actualY);
        }

    }
}*/
void CleanRightArea()
{
    setfillstyle(SOLID_FILL, 15);
    bar(1050, 0, 1350, 765);
}
void WriteOnRightArea(char text[])
{
    setcolor(0);
    setbkcolor(15);
    settextstyle(3, HORIZ_DIR, 2);
    int x=1200-textwidth(text)/2;
    int y=400;
    outtextxy(x, y,text );//modificate coordonatele in fuctie de type
}
int IndexOfBlockClicked()
{
    bool ok=1;
    while(ok)
    {
        if (ismouseclick(WM_LBUTTONDOWN) ) {
        clearmouseclick(WM_LBUTTONUP);
        clearmouseclick(WM_LBUTTONDOWN);
        for(int i=0;i<nr_CreatedBlock;i++)
            if(overBlock(CreatedBlocks[i],mousex(),mousey()))
            {
                ok=0;
                return i;
            }

    }
}
}
