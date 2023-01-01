#include "Input.h"
int x[4] = { 7,49,7,27 };
int y[4] = { 140,280,460,620 };

void CleanSchemGrid()
{
    for (int i = 86; i < 720; i++)
        for (int j = 111; j < 1024; j++)
            schemGrid[i][j] = 0;
}

void DrawSchemGrid(int color)
{
    setcolor(color);
    for (int i = 1; i < 725; i++)
        for (int j = 0; j < 1025; j++)
            if (schemGrid[i][j])
                line(j, i, j - 1, i);

}
void atribuireSchem()
{
    //////////////////////////////////
//      Blocuri
//////////////////////////////////
//  Input
    Blocks[0].type = 0;
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
    Blocks[1].type = 1;
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
    Blocks[2].type = 2;
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
    Blocks[3].type = 3;
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
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 100; j++)
            schemGrid[Blocks[i].dwnRight.y + 20][j] = 1;
    }
    for (int i = 85; i < 721; i++)
    {
        schemGrid[i][1024] = 1;
    }
    for (int i = 110; i < 1024; i++)
    {
        schemGrid[85][i] = 1;
        schemGrid[720][i] = 1;
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
    /*
    int x, y;
    x = CreatedBlocks[index].upLeft.x;
    y = CreatedBlocks[index].upLeft.y;


    if (CreatedBlocks[index].CB_type == 3)
        x = x - 20;

    if (CreatedBlocks[index].CB_type == 1)
    {
        x = x - 45;
        y = y + 5;
    }
    */
    int xLeft;
    if(CreatedBlocks[index].dwnLeft.x<CreatedBlocks[index].upLeft.x)
    xLeft=CreatedBlocks[index].dwnLeft.x;
    else
    xLeft=CreatedBlocks[index].upLeft.x;
    int xRight;
    if(CreatedBlocks[index].upRight.x>CreatedBlocks[index].dwnRight.x)
        xRight=CreatedBlocks[index].upRight.x;
    else
        xRight=CreatedBlocks[index].dwnRight.x;
    int yUp=CreatedBlocks[index].upLeft.y;
    int yDwn=CreatedBlocks[index].dwnRight.y;

    CB_HitBox[index].upRight.x = xRight+10;
    CB_HitBox[index].upRight.y = yUp-10;
    CB_HitBox[index].dwnLeft.x = xLeft-10;
    CB_HitBox[index].dwnLeft.y = yDwn+10;
    CB_HitBox[index].dwnRight.x = xRight+10;
    CB_HitBox[index].dwnRight.y = yDwn+10;
    CB_HitBox[index].upLeft.x = xLeft-10;
    CB_HitBox[index].upLeft.y = yUp-10;


    //blocuri pt ConnectCircle
//CreatedBlocks.ConnectCircle[index].up_left.x=CreatedBlocks.CB_HitBox[index]



}
void UpdateBlockPozition(int indexBlock,int &mouse_x,int &mouse_y)
{
    int newMousex=mousex();
    int newMousey=mousey();
    if(mouse_x!=newMousex||mouse_y!=newMousey)
            {


                //DrawBlock(CreatedBlocks[indexBlock],15);
                //MarkOnSchemGrid(indexBlock,0);
                CreatedBlocks[indexBlock].upLeft.x=CreatedBlocks[indexBlock].upLeft.x-mouse_x+newMousex;
                CreatedBlocks[indexBlock].dwnLeft.x=CreatedBlocks[indexBlock].dwnLeft.x-mouse_x+newMousex;
                CreatedBlocks[indexBlock].upRight.x=CreatedBlocks[indexBlock].upRight.x-mouse_x+newMousex;
                CreatedBlocks[indexBlock].dwnRight.x=CreatedBlocks[indexBlock].dwnRight.x-mouse_x+newMousex;
                CreatedBlocks[indexBlock].upLeft.y=CreatedBlocks[indexBlock].upLeft.y-mouse_y+newMousey;
                CreatedBlocks[indexBlock].dwnLeft.y=CreatedBlocks[indexBlock].dwnLeft.y-mouse_y+newMousey;
                CreatedBlocks[indexBlock].upRight.y=CreatedBlocks[indexBlock].upRight.y-mouse_y+newMousey;
                CreatedBlocks[indexBlock].dwnRight.y=CreatedBlocks[indexBlock].dwnRight.y-mouse_y+newMousey;
                UpdateCirclesPoz(indexBlock);
                //DrawBlock(CreatedBlocks[indexBlock],0);
                init_Hitbox(indexBlock);
               // MarkOnSchemGrid(indexBlock,1);
                mouse_x=newMousex;
                mouse_y=newMousey;



            }
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
    UpdateCirclesPoz(index);
}



bool overAnyHitBox(int index, int x, int y) // x , y input mouse
{
    ////declarari pentru a pune blockuri doar unde trebuie
// 1280 143
   // if(selectedLeftBlocks)
       // Zone.upLeft.x=5;
    //else if(selectedCreatedBlocks)
    Block Zone;


    Zone.upLeft.x = 200;

    Zone.upLeft.y = 162;
    Zone.dwnRight.x = 922;  //1270;
    Zone.dwnRight.y = 640;  //828;

    Zone.upRight.x = Zone.dwnRight.x;
    Zone.upRight.y = Zone.upLeft.y;
    Zone.dwnLeft.x = Zone.upLeft.x;
    Zone.dwnLeft.y = Zone.dwnRight.y;


    /////
    //if((x<Zone.upLeft.x || x> Zone.dwnRight.x) || (y<Zone.upLeft.y || y> Zone.dwnRight.y))
    if (!(overBlock(Zone, CB_HitBox[index].upLeft.x, CB_HitBox[index].upLeft.y) || overBlock(Zone, CB_HitBox[index].dwnLeft.x, CB_HitBox[index].dwnLeft.y) || overBlock(Zone, CB_HitBox[index].upRight.x, CB_HitBox[index].upRight.y) || overBlock(Zone, CB_HitBox[index].dwnRight.x, CB_HitBox[index].dwnRight.y)))
        return 1;  ////verificare daca colt e in zone (1 --> inafara zonei)

    for (int i = 0; i <= nr_CreatedBlock; i++)
    {
        if (i != index)
            if (overBlock(CB_HitBox[i], CB_HitBox[index].upLeft.x, CB_HitBox[index].upLeft.y) || overBlock(CB_HitBox[i], CB_HitBox[index].dwnLeft.x, CB_HitBox[index].dwnLeft.y) || overBlock(CB_HitBox[i], CB_HitBox[index].upRight.x, CB_HitBox[index].upRight.y) || overBlock(CB_HitBox[i], CB_HitBox[index].dwnRight.x, CB_HitBox[index].dwnRight.y))
                return 1;  ////verificare daca fiecare colt al hitboxului blocului[index] este inafara celorlalte hitboxuri (1 --> este peste un alt hitbox)

    }
    return 0;
}


void initParametriCB()
{
    for (int i = 0; i < nr_CreatedBlock; i++)
    {
        initCreatedBlock(0, 1360, 765, i);
        for(int j=0;j<CreatedBlocks[i].nrCircles;j++)
        CreatedBlocks[i].isCircleConected[j]=0;

    }
    nr_CreatedBlock = 0;
}
void CleanLinesOff(int index)
{
    for (int i=0;i<nr_CreatedBlock;i++)
        for(int indiceCerc=0;indiceCerc<3;indiceCerc++)
                if(CreatedBlocks[i].indexBlockConnexionTo[indiceCerc]==index && CreatedBlocks[i].isCircleConected[indiceCerc]==1)
                    DrawLineOffBlock(i,15);
}
void refacereLegaturi(int index) // dupa stergere block creat si dupa decrementare nr_createdblock
{
    for (int i=0;i<nr_CreatedBlock;i++)
        for(int indiceCerc=0;indiceCerc<3;indiceCerc++)
                {
                if(CreatedBlocks[i].indexBlockConnexionTo[indiceCerc]==index && CreatedBlocks[i].isCircleConected[indiceCerc]==1)
                    CreatedBlocks[i].isCircleConected[indiceCerc]=0;
                if(CreatedBlocks[i].indexBlockConnexionTo[indiceCerc]>index && CreatedBlocks[i].isCircleConected[indiceCerc]==1)
                   CreatedBlocks[i].indexBlockConnexionTo[indiceCerc]--;

                }

}
void MarkStartStopBlocks()
{
    for(int i=0;i<nr_CreatedBlock;i++)
    {

            if(CreatedBlocks[i].ConnectCircle[0].selected==0)
            {
                indexStartBlock=i;
                CreatedBlocks[i].ConnectCircle[0].color=10;
                DrawButton(CreatedBlocks[i].ConnectCircle[0]);
                CreatedBlocks[i].ConnectCircle[0].selected=1;
            }
            if(CreatedBlocks[i].isCircleConected[1]==0)
            {
                CreatedBlocks[i].ConnectCircle[1].color=4;
                DrawButton(CreatedBlocks[i].ConnectCircle[1]);
            }
            if(CreatedBlocks[i].CB_type==1)
            if(CreatedBlocks[i].isCircleConected[2]==0)
            {
                CreatedBlocks[i].ConnectCircle[2].color=4;
                DrawButton(CreatedBlocks[i].ConnectCircle[2]);
            }

    }
}
bool isBlockInValidPoz(int indexBlock)
{
    if(!(CB_HitBox[indexBlock].upLeft.y>90&&CB_HitBox[indexBlock].upLeft.x>110&&CB_HitBox&&CB_HitBox[indexBlock].dwnRight.x<1025&&CB_HitBox[indexBlock].dwnRight.y<715))
        return 0;
    for (int i = 0; i <= nr_CreatedBlock; i++)
    {
        if (i != indexBlock)
            {
                if (overBlock(CB_HitBox[i], CB_HitBox[indexBlock].upLeft.x, CB_HitBox[indexBlock].upLeft.y) || overBlock(CB_HitBox[i], CB_HitBox[indexBlock].dwnLeft.x, CB_HitBox[indexBlock].dwnLeft.y) || overBlock(CB_HitBox[i], CB_HitBox[indexBlock].upRight.x, CB_HitBox[indexBlock].upRight.y) || overBlock(CB_HitBox[i], CB_HitBox[indexBlock].dwnRight.x, CB_HitBox[indexBlock].dwnRight.y))
             return 0;  ////verificare daca fiecare colt al hitboxului blocului[indexBlock] este inafara celorlalte hitboxuri (0 --> este peste un alt hitbox)
             if(CB_HitBox[indexBlock].dwnLeft.x<=CB_HitBox[i].dwnLeft.x&&CB_HitBox[indexBlock].upRight.x>=CB_HitBox[i].upRight.x&&((CB_HitBox[indexBlock].upLeft.y>=CB_HitBox[i].upLeft.y&&CB_HitBox[indexBlock].upLeft.y<=CB_HitBox[i].dwnRight.y)||(CB_HitBox[indexBlock].dwnRight.y>=CB_HitBox[i].upLeft.y&&CB_HitBox[indexBlock].dwnRight.y<=CB_HitBox[i].dwnRight.y)))
                return 0;
            }
    }
    return 1;
}
void Schem()
{
    ////////// DESENARE SI ATRIBUIRE
        for(int i=0;i<8;i++)
        {
            ButtonsInputs[i].color=2;
            //ButtonsInputs[i].selected=0;
            ButtonsInputs[i].disponibilOutput=0;
        }

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
        DrawBlock(Blocks[i], 0);
        DrawName(Blocks[i]);
    }


    int mouse_x = mousex();
    int mouse_y = mousey();

    int copie_mouse_x, copie_mouse_y, WasOnFreeSpace;
    bool ok = 1, selectedLeftBlocks = 0, selectedCreatedBlocks = 0;
    int i, j;
    int pozitiesafex, pozitiesafey;
    /////////////////////////// LOOP PANA CAND SE APASA CLICK DREAPTA
    while (ok)
    {

        CheckOverBlockCircle();

        if (ismouseclick(WM_LBUTTONDOWN) && selectedLeftBlocks == 0 && selectedCreatedBlocks == 0)
        {
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);

            mouse_x = mousex();
            mouse_y = mousey();
            copie_mouse_x = mouse_x;
            copie_mouse_y = mouse_y;
            for (i = 0; i < 4; i++)
                if (overBlock(Blocks[i], mouse_x, mouse_y))
                {
                    selectedLeftBlocks = 1;
                    initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);
                    DrawSchemGrid(0);
                    break;
                }
            for (j = 0; j < nr_CreatedBlock && selectedLeftBlocks == 0; j++)
                if (overBlock(CreatedBlocks[j], mouse_x, mouse_y))
                {
                    selectedCreatedBlocks = 1;
                    pozitiesafex = CreatedBlocks[j].upLeft.x;
                    pozitiesafey = CreatedBlocks[j].upLeft.y;
                    DrawSchemGrid(0);
                    MarkOnSchemGrid(j, 0);
                    InfoUserWhileMovingBlock();
                    //CleanSchemGrid();
                    CleanInputText(j);
                    DrawLineOffBlock(j,15);
                    CleanLinesOff(j);
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


        }
        //WasOnFreeSpace = 1; //// variabila care tine minte daca la repetarea anterioara blockul nu era peste alt hitbox (verifsandu=1) si invers
        //////drag butoane din meniu
        mouse_x=mousex();
        mouse_y=mousey();
        while (selectedLeftBlocks)
        {
           // delay(5);
           // if (WasOnFreeSpace)
            //    DrawBlock(CreatedBlocks[nr_CreatedBlock], 15);
           // mouse_x = mousex();
           // mouse_y = mousey();
           // initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);
            UpdateBlockPozition(nr_CreatedBlock,mouse_x,mouse_y);
            if(isBlockInValidPoz(nr_CreatedBlock))
            {
                DrawBlock(CreatedBlocks[nr_CreatedBlock],0);
                delay(1);
                DrawBlock(CreatedBlocks[nr_CreatedBlock],15);
                if (ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    clearmouseclick(WM_LBUTTONUP);
                    CleanRightArea();
                    DrawAllLines();
                    selectedLeftBlocks = 0;
                    MarkOnSchemGrid(nr_CreatedBlock, 1);
                    DrawSchemGrid(15);
                    DrawBlock(CreatedBlocks[nr_CreatedBlock],0);
                    MainInsertFNC(i, nr_CreatedBlock);
                    nr_CreatedBlock++;

                }
            }
            if (ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    clearmouseclick(WM_LBUTTONUP);
                }
                if (ismouseclick(WM_RBUTTONDOWN))
            {
                selectedLeftBlocks = 0;
                clearmouseclick(WM_RBUTTONDOWN);
                clearmouseclick(WM_RBUTTONUP);
                DrawBlock(CreatedBlocks[nr_CreatedBlock], 15);
                initCreatedBlock(0, 1360, 765, nr_CreatedBlock);
                DrawSchemGrid(15);
            }
            /*
            if (overAnyHitBox(nr_CreatedBlock, mouse_x, mouse_y) == 0) // daca nu sunt peste un hitbox si nici nu depasesc zona de desenare deci loc ok
            {
                if (WasOnFreeSpace == 0)
                {
                    initCreatedBlock(i, copie_mouse_x, copie_mouse_y, nr_CreatedBlock);
                    DrawBlock(CreatedBlocks[nr_CreatedBlock], 15);
                }
                initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);
                DrawBlock(CreatedBlocks[nr_CreatedBlock], 4);
                copie_mouse_x = mouse_x;
                copie_mouse_y = mouse_y;
                WasOnFreeSpace = 1;
            }
            else
            {
                initCreatedBlock(i, copie_mouse_x, copie_mouse_y, nr_CreatedBlock);
                DrawBlock(CreatedBlocks[nr_CreatedBlock], 4);
                WasOnFreeSpace = 0;
            }

            for (int contor = 0; contor < 4; contor++)
            {
                DrawBlock(Blocks[contor], 0);
                DrawName(Blocks[contor]);
            }
            if (ismouseclick(WM_RBUTTONDOWN))
            {
                selectedLeftBlocks = 0;
                clearmouseclick(WM_RBUTTONDOWN);
                clearmouseclick(WM_RBUTTONUP);
                DrawBlock(CreatedBlocks[nr_CreatedBlock], 15);
                initCreatedBlock(0, 1360, 765, nr_CreatedBlock);


                DrawSchemGrid(15);


            }

            else if (ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);

                DrawBlock(Blocks[i], 0);
                if (overAnyHitBox(nr_CreatedBlock, CreatedBlocks[nr_CreatedBlock].upLeft.x, CreatedBlocks[nr_CreatedBlock].upLeft.y))
                {
                    DrawBlock(CreatedBlocks[nr_CreatedBlock], 15);
                    initCreatedBlock(0, 1360, 765, nr_CreatedBlock);



                }
                else
                {

                    selectedLeftBlocks = 0;
                    MarkOnSchemGrid(nr_CreatedBlock, 1);
                    DrawSchemGrid(15);
                    MainInsertFNC(i, nr_CreatedBlock);
                    nr_CreatedBlock++;

                }
            }
            */
        }
        bool editBlock=0;
        mouse_x=mousex();
        mouse_y=mousey();
        if(selectedCreatedBlocks)
        {
            DrawBlock(CreatedBlocks[j],15);
            MarkOnSchemGrid(j,0);
            DrawSchemGrid(0);
        }
        while(selectedCreatedBlocks)
        {
            if(kbhit())
            {
                if(101==getch())
                {
                    editBlock=1;
                    setfillstyle(SOLID_FILL, 15);
                    bar(1080,80,1350,120);
                }
            }
            UpdateBlockPozition(j,mouse_x,mouse_y);
            if(isBlockInValidPoz(j))
            {
                DrawBlock(CreatedBlocks[j],0);
                delay(1);
                DrawBlock(CreatedBlocks[j],15);
                if (ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    clearmouseclick(WM_LBUTTONUP);
                    CleanRightArea();
                    DrawBlock(CreatedBlocks[j],0);
                    MarkOnSchemGrid(j,1);
                    DrawSchemGrid(15);
                    DrawAllLines();
                    selectedCreatedBlocks = 0;
                    if(editBlock)
                        {
                            CleanInputText(j);
                            DrawBlock(CreatedBlocks[j],4);
                            MainInsertFNC(CreatedBlocks[j].CB_type,j);
                        }
                }
                if (ismouseclick(WM_RBUTTONDOWN))
            {

                selectedCreatedBlocks = 0;
                clearmouseclick(WM_RBUTTONDOWN);
                clearmouseclick(WM_RBUTTONUP);
                DrawBlock(CreatedBlocks[j], 15);


                for (int indice = j; indice <= nr_CreatedBlock - 1; indice++)
                {
                    CreatedBlocks[indice] = CreatedBlocks[indice + 1];
                    CB_HitBox[indice] = CB_HitBox[indice + 1];

                }

////////////////////// singura depandeta de initCreatedBlock in while u asta
                initCreatedBlock(0, 1360, 760, --nr_CreatedBlock);
                refacereLegaturi(j);
                DrawSchemGrid(15);

            }

            }
            if (ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    clearmouseclick(WM_LBUTTONUP);
                }


        }

        if (ismouseclick(WM_RBUTTONDOWN))
        {
            ok = 0;
            clearmouseclick(WM_RBUTTONDOWN);
            clearmouseclick(WM_RBUTTONUP);
            DrawButtons(ButtonsApp, nrOfButtons);
            MarkStartStopBlocks();
        }
    }
    clearmouseclick(WM_LBUTTONUP);
    clearmouseclick(WM_LBUTTONDOWN);

}
