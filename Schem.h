#include "Input.h"
int x[4] = { 7,49,7,27 };
int y[4] = { 140,280,460,620 };

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
    CB_HitBox[index].upRight.y = yUp-15;
    CB_HitBox[index].dwnLeft.x = xLeft-10;
    CB_HitBox[index].dwnLeft.y = yDwn+15;
    CB_HitBox[index].dwnRight.x = xRight+10;
    CB_HitBox[index].dwnRight.y = yDwn+15;
    CB_HitBox[index].upLeft.x = xLeft-10;
    CB_HitBox[index].upLeft.y = yUp-15;
//blocuri pt ConnectCircle
//CreatedBlocks.ConnectCircle[index].up_left.x=CreatedBlocks.CB_HitBox[index]
}
void UpdateBlockPozition(int indexBlock,int &mouse_x,int &mouse_y)
{
    int newMousex=mousex();
    int newMousey=mousey();
    if(mouse_x!=newMousex||mouse_y!=newMousey)
            {
                CreatedBlocks[indexBlock].upLeft.x=CreatedBlocks[indexBlock].upLeft.x-mouse_x+newMousex;
                CreatedBlocks[indexBlock].dwnLeft.x=CreatedBlocks[indexBlock].dwnLeft.x-mouse_x+newMousex;
                CreatedBlocks[indexBlock].upRight.x=CreatedBlocks[indexBlock].upRight.x-mouse_x+newMousex;
                CreatedBlocks[indexBlock].dwnRight.x=CreatedBlocks[indexBlock].dwnRight.x-mouse_x+newMousex;
                CreatedBlocks[indexBlock].upLeft.y=CreatedBlocks[indexBlock].upLeft.y-mouse_y+newMousey;
                CreatedBlocks[indexBlock].dwnLeft.y=CreatedBlocks[indexBlock].dwnLeft.y-mouse_y+newMousey;
                CreatedBlocks[indexBlock].upRight.y=CreatedBlocks[indexBlock].upRight.y-mouse_y+newMousey;
                CreatedBlocks[indexBlock].dwnRight.y=CreatedBlocks[indexBlock].dwnRight.y-mouse_y+newMousey;
                UpdateCirclesPoz(indexBlock);
                init_Hitbox(indexBlock);
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
                //CreatedBlocks[i].ConnectCircle[0].selected=1;
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
void InfoUserEsc()
{
    setcolor(8);
        setbkcolor(15);
        settextstyle(3, HORIZ_DIR, 1);
        outtextxy(1200-textwidth("Apasa  Esc  daca ai finalizat schema")/2,20,"Apasa  Esc  daca ai finalizat schema");
}
bool isBlockInValidPoz(int indexBlock)
{
    if(!(CB_HitBox[indexBlock].upLeft.y>60&&CB_HitBox[indexBlock].upLeft.x>110&&CB_HitBox&&CB_HitBox[indexBlock].dwnRight.x<1025&&CB_HitBox[indexBlock].dwnRight.y<750))
        return 0;
    for (int i = 0; i <= nr_CreatedBlock; i++)
    {
        if (i != indexBlock)
            {
                if (overBlock(CB_HitBox[i], CB_HitBox[indexBlock].upLeft.x, CB_HitBox[indexBlock].upLeft.y) || overBlock(CB_HitBox[i], CB_HitBox[indexBlock].dwnLeft.x, CB_HitBox[indexBlock].dwnLeft.y) || overBlock(CB_HitBox[i], CB_HitBox[indexBlock].upRight.x, CB_HitBox[indexBlock].upRight.y) || overBlock(CB_HitBox[i], CB_HitBox[indexBlock].dwnRight.x, CB_HitBox[indexBlock].dwnRight.y))
             return 0;  ////verificare daca fiecare colt al hitboxului blocului[indexBlock] este inafara celorlalte hitboxuri (0 --> este peste un alt hitbox)

             if(CB_HitBox[indexBlock].dwnLeft.x<CB_HitBox[i].dwnLeft.x&&CB_HitBox[indexBlock].upRight.x>CB_HitBox[i].upRight.x&&((CB_HitBox[indexBlock].upLeft.y>CB_HitBox[i].upLeft.y&&CB_HitBox[indexBlock].upLeft.y<CB_HitBox[i].dwnRight.y)||(CB_HitBox[indexBlock].dwnRight.y>CB_HitBox[i].upLeft.y&&CB_HitBox[indexBlock].dwnRight.y<CB_HitBox[i].dwnRight.y)||(CB_HitBox[indexBlock].dwnRight.y>=CB_HitBox[i].dwnRight.y&&CB_HitBox[indexBlock].upLeft.y<=CB_HitBox[i].upLeft.y)))
                return 0;
             if(CB_HitBox[indexBlock].upLeft.y<CB_HitBox[i].upLeft.y&&CB_HitBox[indexBlock].dwnRight.y>CB_HitBox[i].dwnRight.y&&((CB_HitBox[indexBlock].dwnLeft.x<=CB_HitBox[i].upRight.x&&CB_HitBox[indexBlock].dwnLeft.x>=CB_HitBox[i].dwnLeft.x)||(CB_HitBox[indexBlock].upRight.x>=CB_HitBox[i].dwnLeft.x&&CB_HitBox[indexBlock].upRight.x<=CB_HitBox[i].upRight.x)))
                return 0;
            }
    }
    return 1;
}
void HoverRightBlocks()
{
    int mouse_x = mousex();
    int mouse_y = mousey();
    for (int i = 0; i < 4; i++)
                if (overBlock(Blocks[i], mouse_x, mouse_y))
                {
                    CleanRightArea();
                    while(ismouseclick(WM_LBUTTONDOWN)==0&&overBlock(Blocks[i], mouse_x, mouse_y))
                    {
                        mouse_x = mousex();
                        mouse_y = mousey();
                        DrawBlock(Blocks[i], 3);
                        DrawName(Blocks[i],3);
                        setcolor(8);
                        setbkcolor(15);
                        settextstyle(3, HORIZ_DIR, 1);
                        outtextxy(1200-textwidth("Click Stanga  pentru a crea un bloc")/2,70,"Click Stanga  pentru a crea un bloc");
                    }
                    CleanRightArea();
                    InfoUserEsc();
                    DrawBlock(Blocks[i], 0);
                    DrawName(Blocks[i],0);
                }
}
void ClicksAndBlocks()
{
    DrawButtons(PannelSchem, nrOfButtons+3);
    DrawAllLines();
    CleanRightArea();
    InfoUserEsc();
    atribuireSchem();
    for (int i = 0; i < 4; i++)
    {
        DrawBlock(Blocks[i], 0);
        DrawName(Blocks[i],0);
    }
    int mouse_x = mousex();
    int mouse_y = mousey();
    bool ok = 1, selectedLeftBlocks = 0, selectedCreatedBlocks = 0;
    int i, j;
    /////////////////////////// LOOP PANA CAND SE APASA CLICK DREAPTA
    while (ok)
    {

        CheckOverBlockCircle();
        HoverRightBlocks();
        if (ismouseclick(WM_LBUTTONDOWN) && selectedLeftBlocks == 0 && selectedCreatedBlocks == 0)
        {
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);

            mouse_x = mousex();
            mouse_y = mousey();
            for (i = 0; i < 4; i++)
                if (overBlock(Blocks[i], mouse_x, mouse_y))
                {
                    selectedLeftBlocks = 1;
                    CleanRightArea();
                    initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);
                    break;
                }
            for (j = 0; j < nr_CreatedBlock && selectedLeftBlocks == 0; j++)
                if (overBlock(CreatedBlocks[j], mouse_x, mouse_y))
                {
                    selectedCreatedBlocks = 1;
                    CleanRightArea();
                    CleanInputText(j);
                    DrawLineOffBlock(j,15);
                    CleanLinesOff(j);
                    break;
                }
                InfoUserWhileMovingBlock(selectedLeftBlocks,selectedCreatedBlocks);
        }
        //////drag butoane din meniu
        while (selectedLeftBlocks)
        {
            UpdateBlockPozition(nr_CreatedBlock,mouse_x,mouse_y);
            if(isBlockInValidPoz(nr_CreatedBlock))
            {
                DrawBlock(CreatedBlocks[nr_CreatedBlock],0);
                delay(1);
                DrawBlock(CreatedBlocks[nr_CreatedBlock],15);
                setfillstyle(SOLID_FILL, 15);
                bar(1100, 150, 1300, 170);
                if (ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    clearmouseclick(WM_LBUTTONUP);
                    CleanRightArea();
                    selectedLeftBlocks = 0;
                    DrawBlock(CreatedBlocks[nr_CreatedBlock],0);
                    while(kbhit()) getch();
                    MainInsertFNC(i, nr_CreatedBlock);
                    nr_CreatedBlock++;
                    DrawAllLines();
                    InfoUserEsc();

                }
            }
            else
            {
                setcolor(4);
                setbkcolor(15);
                outtextxy(1200-textwidth("Pozitie Invalida")/2,150,"Pozitie Invalida");
            }
            if (ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    clearmouseclick(WM_LBUTTONUP);
                }
                if (ismouseclick(WM_RBUTTONDOWN))
            {
                selectedLeftBlocks = 0;
                CleanRightArea();
                InfoUserEsc();
                clearmouseclick(WM_RBUTTONDOWN);
                clearmouseclick(WM_RBUTTONUP);
                DrawBlock(CreatedBlocks[nr_CreatedBlock], 15);
                initCreatedBlock(0, 1360, 765, nr_CreatedBlock);
            }
        }
        bool editBlock=0;
        if(selectedCreatedBlocks)
        {
            DrawBlock(CreatedBlocks[j],15);
        }
        while(selectedCreatedBlocks)
        {
            if(kbhit())
            {
                if(101==getch())
                {
                    editBlock=1;
                    setfillstyle(SOLID_FILL, 15);
                    bar(1080,90,1350,150);
                }
            }
            UpdateBlockPozition(j,mouse_x,mouse_y);
            if(isBlockInValidPoz(j))
            {
                DrawBlock(CreatedBlocks[j],0);
                delay(1);
                DrawBlock(CreatedBlocks[j],15);
                setfillstyle(SOLID_FILL, 15);
                bar(1100, 150, 1300, 170);
                if (ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    clearmouseclick(WM_LBUTTONUP);
                    CleanRightArea();
                    DrawBlock(CreatedBlocks[j],0);
                    DrawAllLines();
                    selectedCreatedBlocks = 0;
                    if(editBlock)
                        {
                            CleanInputText(j);
                            DrawBlock(CreatedBlocks[j],4);
                            DrawInputText(j,2);
                            while(kbhit()) getch();
                            MainInsertFNC(CreatedBlocks[j].CB_type,j);
                        }
                        InfoUserEsc();
                }
                if (ismouseclick(WM_RBUTTONDOWN))
            {

                selectedCreatedBlocks = 0;
                clearmouseclick(WM_RBUTTONDOWN);
                clearmouseclick(WM_RBUTTONUP);
                CleanRightArea();
                InfoUserEsc();
                DrawBlock(CreatedBlocks[j], 15);


                for (int indice = j; indice <= nr_CreatedBlock - 1; indice++)
                {
                    CreatedBlocks[indice] = CreatedBlocks[indice + 1];
                    CB_HitBox[indice] = CB_HitBox[indice + 1];

                }

////////////////////// singura depandeta de initCreatedBlock in while u asta
                initCreatedBlock(0, 1360, 760, --nr_CreatedBlock);
                refacereLegaturi(j);

            }

            }
            else
            {
                setcolor(4);
                setbkcolor(15);
                outtextxy(1200-textwidth("Pozitie Invalida")/2,150,"Pozitie Invalida");
            }
            if (ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    clearmouseclick(WM_LBUTTONUP);
                }


        }
        if (ismouseclick(WM_RBUTTONDOWN))
        {
            clearmouseclick(WM_RBUTTONDOWN);
            clearmouseclick(WM_RBUTTONUP);
        }
        if (kbhit())
        {

        setcolor(8);
        setbkcolor(15);
        settextstyle(3, HORIZ_DIR, 1);
        outtextxy(1200-textwidth("Apasa  Esc  daca ai finalizat schema")/2,20,"Apasa  Esc  daca ai finalizat schema");
            if(27==getch())
            {ok = 0;
            DrawButtons(ButtonsApp, nrOfButtons);
            MarkStartStopBlocks();
            CleanRightArea();
            setcolor(8);
        setbkcolor(15);
        settextstyle(3, HORIZ_DIR, 1);
        outtextxy(1200-textwidth("Apasa  Enter  pentru a modifica schema")/2,20,"Apasa  Enter  pentru a modifica schema");
            }
        }
    }
    clearmouseclick(WM_LBUTTONUP);
    clearmouseclick(WM_LBUTTONDOWN);

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


    initParametriCB();

    ClicksAndBlocks();

}
