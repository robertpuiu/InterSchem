#include "Input.h"
int x[4] = { 7,49,7,27 };
int y[4] = { 140,280,460,620 };

//CreatedBlocks
bool freeSpaceOfGrid(Block Block)
{
    if(schemGrid[Block.upLeft.y][Block.upLeft.x]||schemGrid[Block.dwnLeft.y][Block.dwnLeft.x]||schemGrid[Block.upRight.y][Block.upRight.x]||schemGrid[Block.dwnRight.y][Block.dwnRight.x])
        return 0;
    return 1;
}
void CleanSchemGrid()
{
    for(int i=86;i<720;i++)
    for(int j=111;j<1024;j++)
    schemGrid[i][j]=0;
}
void MarkOnSchemGrid(int index,int type,int x,int y, int mark)
{
    //cutia block-ului
    setcolor(15);
            if(type==3)
            x=x-20;
            if(type==1)
            {
                x=x-45;
                y=y+5;
            }
            for(int i=x-6;i<x+97;i++)
                {
                    schemGrid[y-14][i]=mark;
                    schemGrid[y+65][i]=mark;
                    line(i,y-14,i-1,y-14);
                    line(i,y+65,i-1,y+65);
                }
            for(int i=y-14;i<y+66;i++)
            {
                schemGrid[i][x-6]=mark;
                    schemGrid[i][x+96]=mark;
                    line(x-6,i,x-7,i);
                    line(x+96,i,x+95,i);
            }
        // ConnectCircle
        //if(mark)

    CreatedBlocks[index].ConnectCircle[0].up_left.x=(x-6+x+96)/2-5;
    CreatedBlocks[index].ConnectCircle[0].dwn_right.x=(x-6+x+96)/2+5;
    CreatedBlocks[index].ConnectCircle[0].up_left.y=y-11;
    CreatedBlocks[index].ConnectCircle[0].dwn_right.y=y-1;
    if(type==1)
    {
        CreatedBlocks[index].nrCircles=3;
    CreatedBlocks[index].ConnectCircle[1].up_left.x=x-6;
    CreatedBlocks[index].ConnectCircle[1].dwn_right.x=x+4;
    CreatedBlocks[index].ConnectCircle[1].up_left.y=y+25;
    CreatedBlocks[index].ConnectCircle[1].dwn_right.y=y+35;

    CreatedBlocks[index].ConnectCircle[2].up_left.x=x+85;
    CreatedBlocks[index].ConnectCircle[2].dwn_right.x=x+95;
    CreatedBlocks[index].ConnectCircle[2].up_left.y=y+25;
    CreatedBlocks[index].ConnectCircle[2].dwn_right.y=y+35;
    }
    else
    {CreatedBlocks[index].nrCircles=2;
    CreatedBlocks[index].ConnectCircle[1].up_left.x=(x-6+x+96)/2-5;
    CreatedBlocks[index].ConnectCircle[1].dwn_right.x=(x-6+x+96)/2+5;
    CreatedBlocks[index].ConnectCircle[1].up_left.y=y+50;
    CreatedBlocks[index].ConnectCircle[1].dwn_right.y=y+60;

    }

}
void DrawSchemGrid(int color)
{
    setcolor(color);
    for(int i=1;i<725;i++)
        for(int j=0;j<1025;j++)
        if(schemGrid[i][j])
        line(j,i,j-1,i);

}
void atribuireSchem()
{
    //////////////////////////////////
//      Blocuri
//////////////////////////////////
//  Input
    Blocks[0].type=0;
    Blocks[0].upLeft.x = x[0];
    Blocks[0].upLeft.y = y[0];
    Blocks[0].upRight.x = Blocks[0].upLeft.x + 90;
    Blocks[0].upRight.y = Blocks[0].upLeft.y;
    Blocks[0].dwnLeft.x = Blocks[0].upLeft.x + 20;
    Blocks[0].dwnLeft.y = Blocks[0].upLeft.y + 50;
    Blocks[0].dwnRight.x = Blocks[0].upLeft.x + 70;
    Blocks[0].dwnRight.y = Blocks[0].upLeft.y + 50;

    Blocks[0].nrCircles = 2;
    Blocks[0].Circles[0].x = (Blocks[0].upLeft.x + Blocks[0].upRight.x) / 2;
    Blocks[0].Circles[0].y = Blocks[0].upLeft.y - 4;
    Blocks[0].Circles[1].x = Blocks[0].Circles[0].x;
    Blocks[0].Circles[1].y = Blocks[0].dwnLeft.y + 4;
    strcpy(Blocks[0].headText, "Input");
    // If
    Blocks[1].type=1;
    Blocks[1].upLeft.x = x[1];
    Blocks[1].upLeft.y = y[1];
    Blocks[1].upRight.x = Blocks[1].upLeft.x + 45;
    Blocks[1].upRight.y = Blocks[1].upLeft.y + 35;
    Blocks[1].dwnLeft.x = Blocks[1].upLeft.x - 45;
    Blocks[1].dwnLeft.y = Blocks[1].upLeft.y + 35;
    Blocks[1].dwnRight.x = Blocks[1].upLeft.x;
    Blocks[1].dwnRight.y = Blocks[1].upLeft.y + 70;
    Blocks[1].nrCircles = 3;
    Blocks[1].Circles[0].x = Blocks[1].upLeft.x;
    Blocks[1].Circles[0].y = Blocks[1].upLeft.y;
    Blocks[1].Circles[1].x = Blocks[1].upRight.x;
    Blocks[1].Circles[1].y = Blocks[1].upRight.y;
    Blocks[1].Circles[2].x = Blocks[1].dwnLeft.x;
    Blocks[1].Circles[2].y = Blocks[1].dwnLeft.y;
    strcpy(Blocks[1].headText, "If");

    // Operatie
    Blocks[2].type=2;
    Blocks[2].upLeft.x = x[2];
    Blocks[2].upLeft.y = y[2];
    Blocks[2].upRight.x = Blocks[2].upLeft.x + 90;
    Blocks[2].upRight.y = Blocks[2].upLeft.y;
    Blocks[2].dwnLeft.x = Blocks[2].upLeft.x;
    Blocks[2].dwnLeft.y = Blocks[2].upLeft.y + 50;
    Blocks[2].dwnRight.x = Blocks[2].upLeft.x + 90;
    Blocks[2].dwnRight.y = Blocks[2].upLeft.y + 50;

    Blocks[2].nrCircles = 2;
    Blocks[2].Circles[0].x = (Blocks[2].upLeft.x + Blocks[2].upRight.x) / 2;
    Blocks[2].Circles[0].y = Blocks[2].upLeft.y - 4;
    Blocks[2].Circles[1].x = Blocks[2].Circles[0].x;
    Blocks[2].Circles[1].y = Blocks[2].dwnLeft.y + 4;
    strcpy(Blocks[2].headText, "Operatie");

    //Output
    Blocks[3].type=3;
    Blocks[3].upLeft.x = x[3];
    Blocks[3].upLeft.y = y[3];
    Blocks[3].upRight.x = Blocks[3].upLeft.x + 50;
    Blocks[3].upRight.y = Blocks[3].upLeft.y;
    Blocks[3].dwnLeft.x = Blocks[3].upLeft.x - 20;
    Blocks[3].dwnLeft.y = Blocks[3].upLeft.y + 50;
    Blocks[3].dwnRight.x = Blocks[3].upLeft.x + 70;
    Blocks[3].dwnRight.y = Blocks[3].upLeft.y + 50;

    Blocks[3].nrCircles = 2;
    Blocks[3].Circles[0].x = (Blocks[3].upLeft.x + Blocks[3].upRight.x) / 2;
    Blocks[3].Circles[0].y = Blocks[3].upLeft.y - 4;
    Blocks[3].Circles[1].x = Blocks[3].Circles[0].x;
    Blocks[3].Circles[1].y = Blocks[3].dwnLeft.y + 4;
    strcpy(Blocks[3].headText, "Output");
    // schemGrid
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<100;j++)
            schemGrid[Blocks[i].dwnRight.y+20][j]=1;
    }
    for(int i=85;i<721;i++)
        {
            schemGrid[i][1024]=1;
        }
    for(int i=110;i<1024;i++)
    {
        schemGrid[85][i]=1;
        schemGrid[720][i]=1;
    }

}
void init_cr_InputBlock(int index)
{    //  Input 0
    CreatedBlocks[index].upRight.x = CreatedBlocks[index].upLeft.x + 90;
    CreatedBlocks[index].upRight.y = CreatedBlocks[index].upLeft.y;
    CreatedBlocks[index].dwnLeft.x = CreatedBlocks[index].upLeft.x + 20;
    CreatedBlocks[index].dwnLeft.y = CreatedBlocks[index].upLeft.y + 50;
    CreatedBlocks[index].dwnRight.x = CreatedBlocks[index].upLeft.x + 70;
    CreatedBlocks[index].dwnRight.y = CreatedBlocks[index].upLeft.y + 50;
    CreatedBlocks[index].nrCircles = 2;
    CreatedBlocks[index].Circles[0].x = (CreatedBlocks[index].upLeft.x + CreatedBlocks[index].upRight.x) / 2;
    CreatedBlocks[index].Circles[0].y = CreatedBlocks[index].upLeft.y - 4;
    CreatedBlocks[index].Circles[1].x = CreatedBlocks[index].Circles[0].x;
    CreatedBlocks[index].Circles[1].y = CreatedBlocks[index].dwnLeft.y + 4;

}
void init_cr_IfBlock(int index)
{ // If 1
    CreatedBlocks[index].upRight.x = CreatedBlocks[index].upLeft.x + 45;
    CreatedBlocks[index].upRight.y = CreatedBlocks[index].upLeft.y + 35;
    CreatedBlocks[index].dwnLeft.x = CreatedBlocks[index].upLeft.x - 45;
    CreatedBlocks[index].dwnLeft.y = CreatedBlocks[index].upLeft.y + 35;
    CreatedBlocks[index].dwnRight.x = CreatedBlocks[index].upLeft.x;
    CreatedBlocks[index].dwnRight.y = CreatedBlocks[index].upLeft.y + 70;
    CreatedBlocks[index].nrCircles = 3;
    CreatedBlocks[index].Circles[0].x = CreatedBlocks[index].upLeft.x;
    CreatedBlocks[index].Circles[0].y = CreatedBlocks[index].upLeft.y;
    CreatedBlocks[index].Circles[1].x = CreatedBlocks[index].upRight.x;
    CreatedBlocks[index].Circles[1].y = CreatedBlocks[index].upRight.y;
    CreatedBlocks[index].Circles[2].x = CreatedBlocks[index].dwnLeft.x;
    CreatedBlocks[index].Circles[2].y = CreatedBlocks[index].dwnLeft.y;

}
void init_cr_OperBlock(int index)
{// Operatie 2
    CreatedBlocks[index].upRight.x = CreatedBlocks[index].upLeft.x + 90;
    CreatedBlocks[index].upRight.y = CreatedBlocks[index].upLeft.y;
    CreatedBlocks[index].dwnLeft.x = CreatedBlocks[index].upLeft.x;
    CreatedBlocks[index].dwnLeft.y = CreatedBlocks[index].upLeft.y + 50;
    CreatedBlocks[index].dwnRight.x = CreatedBlocks[index].upLeft.x + 90;
    CreatedBlocks[index].dwnRight.y = CreatedBlocks[index].upLeft.y + 50;
    CreatedBlocks[index].nrCircles = 2;
    CreatedBlocks[index].Circles[0].x = (CreatedBlocks[index].upLeft.x + CreatedBlocks[index].upRight.x) / 2;
    CreatedBlocks[index].Circles[0].y = CreatedBlocks[index].upLeft.y - 4;
    CreatedBlocks[index].Circles[1].x = CreatedBlocks[index].Circles[0].x;
    CreatedBlocks[index].Circles[1].y = CreatedBlocks[index].dwnLeft.y + 4;
}
void init_cr_OutputBlock(int index)
{//Output 3
    CreatedBlocks[index].upRight.x = CreatedBlocks[index].upLeft.x + 50;
    CreatedBlocks[index].upRight.y = CreatedBlocks[index].upLeft.y;
    CreatedBlocks[index].dwnLeft.x = CreatedBlocks[index].upLeft.x - 20;
    CreatedBlocks[index].dwnLeft.y = CreatedBlocks[index].upLeft.y + 50;
    CreatedBlocks[index].dwnRight.x = CreatedBlocks[index].upLeft.x + 70;
    CreatedBlocks[index].dwnRight.y = CreatedBlocks[index].upLeft.y + 50;
    CreatedBlocks[index].nrCircles = 2;
    CreatedBlocks[index].Circles[0].x = (CreatedBlocks[index].upLeft.x + CreatedBlocks[index].upRight.x) / 2;
    CreatedBlocks[index].Circles[0].y = CreatedBlocks[index].upLeft.y - 4;
    CreatedBlocks[index].Circles[1].x = CreatedBlocks[index].Circles[0].x;
    CreatedBlocks[index].Circles[1].y = CreatedBlocks[index].dwnLeft.y + 4;
}
void init_Hitbox(int index)
{
    int x,y;
    x=CreatedBlocks[index].upLeft.x;
    y=CreatedBlocks[index].upLeft.y;


    if(CreatedBlocks[index].CB_type==3)
            x=x-20;

    if(CreatedBlocks[index].CB_type==1)
            {
                x=x-45;
                y=y+5;
            }

                    CB_HitBox[index].upRight.x=x+96;
                    CB_HitBox[index].upRight.y=y-14;
                    CB_HitBox[index].dwnLeft.x=x-6;
                    CB_HitBox[index].dwnLeft.y=y+65;
                    CB_HitBox[index].dwnRight.x=x+96;
                    CB_HitBox[index].dwnRight.y=y+65;
                   CB_HitBox[index].upLeft.x=x-6;
                   CB_HitBox[index].upLeft.y=y-14;


                   //blocuri pt ConnectCircle
    //CreatedBlocks.ConnectCircle[index].up_left.x=CreatedBlocks.CB_HitBox[index]



}
void initCreatedBlock(int type, int x, int y, int index)
{
    CreatedBlocks[index].CB_type = type;
    CreatedBlocks[index].upLeft.x = x;
    CreatedBlocks[index].upLeft.y = y;


    switch (type)
    {
    case 0:
        init_cr_InputBlock(index);
        init_Hitbox(index);
        break;
    case 1:
        init_cr_IfBlock(index);
        init_Hitbox(index);
        break;
    case 2:
        init_cr_OperBlock(index);
        init_Hitbox(index);
        break;
    case 3:
        init_cr_OutputBlock(index);
        init_Hitbox(index);
        break;
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
    /*
    circle((Block.upLeft.x+Block.upRight.x)/2,Block.upLeft.y-4,6);
    if(Block.upLeft.x==Block.dwnRight.x)//daca e if
    {
        circle(Block.dwnLeft.x+4,Block.dwnLeft.y+4,6);
        circle(Block.dwnRight.x-4,Block.dwnRight.y+4,6);
    }
    else
        circle((Block.dwnRight.x+Block.dwnLeft.x)/2,Block.dwnLeft.y+4,6);
        */

}
bool overBlock(Block Block, int x, int y)
{
    //if(x>=BTN.up_left.x&&x<=BTN.dwn_right.x&&y>=BTN.up_left.y&&y<=BTN.dwn_right.y)


    if ((x >= Block.dwnLeft.x || x >= Block.upLeft.x) && (x <= Block.dwnRight.x || x <= Block.upRight.x) && y >= Block.upLeft.y && (y <= Block.dwnLeft.y || y <= Block.dwnRight.y))
        return true;
    return false;
}


bool overAnyHitBox(int index, int x, int y) // x , y input mouse
{
    ////declarari pentru a pune blockuri doar unde trebuie
// 1280 143
   // if(selectedLeftBlocks)
       // Zone.upLeft.x=5;
    //else if(selectedCreatedBlocks)
        Block Zone;


    Zone.upLeft.x=200;

    Zone.upLeft.y=162;
    Zone.dwnRight.x= 922 ;  //1270;
    Zone.dwnRight.y= 640;  //828;

    Zone.upRight.x=Zone.dwnRight.x;
    Zone.upRight.y=Zone.upLeft.y;
    Zone.dwnLeft.x=Zone.upLeft.x;
    Zone.dwnLeft.y=Zone.dwnRight.y;


    /////
    //if((x<Zone.upLeft.x || x> Zone.dwnRight.x) || (y<Zone.upLeft.y || y> Zone.dwnRight.y))
            if(!(overBlock(Zone,CB_HitBox[index].upLeft.x,CB_HitBox[index].upLeft.y) || overBlock(Zone,CB_HitBox[index].dwnLeft.x,CB_HitBox[index].dwnLeft.y)||overBlock(Zone,CB_HitBox[index].upRight.x,CB_HitBox[index].upRight.y) || overBlock(Zone,CB_HitBox[index].dwnRight.x,CB_HitBox[index].dwnRight.y)))
                   return 1;  ////verificare daca colt e in zone (1 --> inafara zonei)

    for(int i=0;i<=nr_CreatedBlock;i++)
        {if(i!=index)
        if(overBlock(CB_HitBox[i],CB_HitBox[index].upLeft.x,CB_HitBox[index].upLeft.y) || overBlock(CB_HitBox[i],CB_HitBox[index].dwnLeft.x,CB_HitBox[index].dwnLeft.y)||overBlock(CB_HitBox[i],CB_HitBox[index].upRight.x,CB_HitBox[index].upRight.y) || overBlock(CB_HitBox[i],CB_HitBox[index].dwnRight.x,CB_HitBox[index].dwnRight.y))
                   return 1;  ////verificare daca fiecare colt al hitboxului blocului[index] este inafara celorlalte hitboxuri (1 --> este peste un alt hitbox)

        }
    return 0;
}


void initParametriCB()
{
    for(int i=0;i<nr_CreatedBlock;i++)
    {
        initCreatedBlock(0, 1360, 765, i);
    }
    nr_CreatedBlock=0;
}
void Schem()
{
    ////////// DESENARE SI ATRIBUIRE
    setfillstyle(SOLID_FILL, RGB(0, 0, 155));
    bar(ButtonsApp[1].up_left.x, ButtonsApp[1].up_left.y, ButtonsApp[1].dwn_right.x, ButtonsApp[1].dwn_right.y);
    setcolor(RGB(255, 253, 226));
    setbkcolor(RGB(0, 0, 155));
    settextstyle(10, HORIZ_DIR, ButtonsApp[1].textSize);
    outtextxy(((ButtonsApp[1].up_left.x + ButtonsApp[1].dwn_right.x) - textwidth(ButtonsApp[1].text)) / 2, ((ButtonsApp[1].dwn_right.y + ButtonsApp[1].up_left.y) - textheight(ButtonsApp[1].text)) / 2, ButtonsApp[1].text);

    atribuireSchem();
    CleanSchemGrid();
    initParametriCB();
    for (int i = 0; i < 4; i++)
    {
        DrawBlock(Blocks[i],0);
        DrawName(Blocks[i]);
    }


    int mouse_x = mousex();
    int mouse_y = mousey();

int copie_mouse_x, copie_mouse_y,WasOnFreeSpace;
    bool ok = 1, selectedLeftBlocks = 0, selectedCreatedBlocks = 0;
    int i, j;
    int pozitiesafex,pozitiesafey;
    /////////////////////////// LOOP PANA CAND SE APASA CLICK DREAPTA
    while (ok)
    {
        CheckOverBlockCircle();
         /*

                for(int k=0;k<nr_CreatedBlock;k++)
            for(int h=0;h<CreatedBlocks[k].nrCircles;h++)//test desenare pe cerc
            if(overBTN(CreatedBlocks[k].ConnectCircle[h],mousex(),mousey()))
        {

            setfillstyle(SOLID_FILL, RGB(0, 100, 155));
                bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
        }
        */

        if (ismouseclick(WM_LBUTTONDOWN) && selectedLeftBlocks == 0 && selectedCreatedBlocks == 0)
        {
            mouse_x = mousex();
            mouse_y = mousey();
            copie_mouse_x=mouse_x;
                copie_mouse_y=mouse_y;
            for (i = 0; i < 4; i++)
                if (overBlock(Blocks[i], mouse_x, mouse_y))
                {
                    selectedLeftBlocks = 1;
                    initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);
                    DrawSchemGrid(0);
                    break;
                }
            for (j = 0; j <= nr_CreatedBlock && selectedLeftBlocks == 0; j++)
                if (overBlock(CreatedBlocks[j], mouse_x, mouse_y))
                {
                    selectedCreatedBlocks = 1;
                    pozitiesafex=CreatedBlocks[j].upLeft.x;
                    pozitiesafey=CreatedBlocks[j].upLeft.y;
                    DrawSchemGrid(0);
                    MarkOnSchemGrid(j,CreatedBlocks[j].CB_type,CreatedBlocks[j].upLeft.x,CreatedBlocks[j].upLeft.y,0);/////////HEEEELPPP Sandu VICTORIEEEEEEEEEEEEEEEEEEEE BAAAAAAAAAAAAAA
                    //CleanSchemGrid();

                    break;
                }
               /*
                for(int k=0;k<nr_CreatedBlock;k++)
            for(int h=0;h<CreatedBlocks[k].nrCircles;h++)//test desenare pe cerc
            if(overBTN(CreatedBlocks[k].ConnectCircle[h],mouse_x,mouse_y))
        {
            setfillstyle(SOLID_FILL, RGB(0, 100, 155));
                bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
        } */
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);

        }
         WasOnFreeSpace=1; //// variabila care tine minte daca la repetarea anterioara blockul nu era peste alt hitbox (verifsandu=1) si invers
        //////drag butoane din meniu
        while (selectedLeftBlocks)
        {
            delay(5);
            if(WasOnFreeSpace)
            DrawBlock(CreatedBlocks[nr_CreatedBlock], 15);
            mouse_x = mousex();
            mouse_y = mousey();
            initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);

            if(overAnyHitBox(nr_CreatedBlock,mouse_x,mouse_y)==0) // daca nu sunt peste un hitbox si nici nu depasesc zona de desenare deci loc ok
            {
                if(WasOnFreeSpace==0)
                {
                    initCreatedBlock(i, copie_mouse_x, copie_mouse_y, nr_CreatedBlock);
                    DrawBlock(CreatedBlocks[nr_CreatedBlock], 15);
                }
                initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);
                DrawBlock(CreatedBlocks[nr_CreatedBlock], 4);
                copie_mouse_x=mouse_x;
                copie_mouse_y=mouse_y;
                WasOnFreeSpace=1;
            }
            else
                {
                     initCreatedBlock(i, copie_mouse_x, copie_mouse_y, nr_CreatedBlock);
                     DrawBlock(CreatedBlocks[nr_CreatedBlock], 4);
                     WasOnFreeSpace=0;
                }

                for(int contor=0;contor<4;contor++)
                {
                    DrawBlock(Blocks[contor], 0);
                    DrawName(Blocks[contor]);
                }

            if (ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);

                DrawBlock(Blocks[i], 0);
                if(overAnyHitBox(nr_CreatedBlock,CreatedBlocks[nr_CreatedBlock].upLeft.x,CreatedBlocks[nr_CreatedBlock].upLeft.y))
                {
                    DrawBlock(CreatedBlocks[nr_CreatedBlock], 15);
                    initCreatedBlock(0, 1360, 765, nr_CreatedBlock);



                }
                else
                {
		selectedLeftBlocks = 0;
		MarkOnSchemGrid(j,i,copie_mouse_x,copie_mouse_y,1);
                DrawSchemGrid(15);
                atribuireMainInsertCreatedBlocks();
                MainInsertFNC(i);
                nr_CreatedBlock++;

                }
            }
        }
            WasOnFreeSpace=1;// pt while-ul de mai jos
        //////////////////// mutare pentru butoane plasate anterier
        while (selectedCreatedBlocks)
        {
             delay(5);
            if(WasOnFreeSpace)
            DrawBlock(CreatedBlocks[j], 15);
            mouse_x = mousex();
            mouse_y = mousey();
           initCreatedBlock(CreatedBlocks[j].CB_type, mouse_x, mouse_y, j);

            if(overAnyHitBox(j,mouse_x,mouse_y)==0)
            {
                if(WasOnFreeSpace==0)
                {
                   initCreatedBlock(CreatedBlocks[j].CB_type, copie_mouse_x, copie_mouse_y, j);
                   DrawBlock(CreatedBlocks[j], 15);
                }

                initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);
                   DrawBlock(CreatedBlocks[j], 4);
                copie_mouse_x=mouse_x;
                copie_mouse_y=mouse_y;
                WasOnFreeSpace=1;
            }
            else
                {
                   initCreatedBlock(CreatedBlocks[j].CB_type, copie_mouse_x, copie_mouse_y, j);
                   DrawBlock(CreatedBlocks[j], 4);
                     WasOnFreeSpace=0;
                }


            //////// partea veche
          /*  delay(10);
            DrawBlock(CreatedBlocks.CB_array[j], 15);
            mouse_x = mousex();
            mouse_y = mousey();
            initCreatedBlock(CreatedBlocks.CB_type[j], mouse_x, mouse_y, j);
            DrawBlock(CreatedBlocks.CB_array[j], 4);
            */
            ///////////



            if (ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                selectedCreatedBlocks = 0;
                if(overAnyHitBox(j,CreatedBlocks[j].upLeft.x,CreatedBlocks[j].upLeft.y))
                {
                   DrawBlock(CreatedBlocks[j], 15);
                   initCreatedBlock(CreatedBlocks[j].CB_type, pozitiesafex, pozitiesafey, j);
                   DrawBlock(CreatedBlocks[j], 4);
                   MarkOnSchemGrid(j,CreatedBlocks[j].CB_type,pozitiesafex,pozitiesafey,1);
                   DrawSchemGrid(15);
                }
                else
                {
                    MarkOnSchemGrid(j,CreatedBlocks[j].CB_type,copie_mouse_x,copie_mouse_y,1);
                   DrawSchemGrid(15);
                }
            }
            /* Stergere block cand click dreapta
            if (ismouseclick(WM_RBUTTONDOWN))
        {
            for(int k=j;k<nr_CreatedBlock;k++)
            initCreatedBlock(CreatedBlocks[k+1].CB_type, CreatedBlocks[k+1].upLeft.x, CreatedBlocks[k+1].upLeft.y, k);
            clearmouseclick(WM_RBUTTONDOWN);
            clearmouseclick(WM_RBUTTONUP);
            nr_CreatedBlock--;
        }*/

        }
        if (ismouseclick(WM_RBUTTONDOWN))
        {
            ok = 0;
            clearmouseclick(WM_RBUTTONDOWN);
            clearmouseclick(WM_RBUTTONUP);
            DrawButtons(ButtonsApp, nrOfButtons);
        }
    }
    clearmouseclick(WM_LBUTTONUP);
    clearmouseclick(WM_LBUTTONDOWN);

}
