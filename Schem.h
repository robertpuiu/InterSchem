#include "Input.h"
int x[4] = { 7,49,7,27 };
int y[4] = { 140,280,460,620 };
int selectedLeftBlocks = 0, selectedCreatedBlocks = 0;
void atribuireSchem()
{
    //////////////////////////////////
//      Blocuri
//////////////////////////////////
//  Input
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
    CreatedBlocks.CB_array[index].upRight.x = CreatedBlocks.CB_array[index].upLeft.x + 90;
    CreatedBlocks.CB_array[index].upRight.y = CreatedBlocks.CB_array[index].upLeft.y;
    CreatedBlocks.CB_array[index].dwnLeft.x = CreatedBlocks.CB_array[index].upLeft.x + 20;
    CreatedBlocks.CB_array[index].dwnLeft.y = CreatedBlocks.CB_array[index].upLeft.y + 50;
    CreatedBlocks.CB_array[index].dwnRight.x = CreatedBlocks.CB_array[index].upLeft.x + 70;
    CreatedBlocks.CB_array[index].dwnRight.y = CreatedBlocks.CB_array[index].upLeft.y + 50;
    CreatedBlocks.CB_array[index].nrCircles = 2;
    CreatedBlocks.CB_array[index].Circles[0].x = (CreatedBlocks.CB_array[index].upLeft.x + CreatedBlocks.CB_array[index].upRight.x) / 2;
    CreatedBlocks.CB_array[index].Circles[0].y = CreatedBlocks.CB_array[index].upLeft.y - 4;
    CreatedBlocks.CB_array[index].Circles[1].x = CreatedBlocks.CB_array[index].Circles[0].x;
    CreatedBlocks.CB_array[index].Circles[1].y = CreatedBlocks.CB_array[index].dwnLeft.y + 4;

    // INITIALIZARE HITBOX ()
    CreatedBlocks.CB_HitBox[index].upLeft.x = CreatedBlocks.CB_array[index].upLeft.x-5;
    CreatedBlocks.CB_HitBox[index].upLeft.y = CreatedBlocks.CB_array[index].upLeft.y-5;
    CreatedBlocks.CB_HitBox[index].upRight.x = CreatedBlocks.CB_array[index].upRight.x +5;
    CreatedBlocks.CB_HitBox[index].upRight.y = CreatedBlocks.CB_array[index].upRight.y-5;
    CreatedBlocks.CB_HitBox[index].dwnLeft.x = CreatedBlocks.CB_array[index].dwnLeft.x-5;
    CreatedBlocks.CB_HitBox[index].dwnLeft.y = CreatedBlocks.CB_array[index].dwnLeft.y+5;
    CreatedBlocks.CB_HitBox[index].dwnRight.x = CreatedBlocks.CB_array[index].dwnRight.x+5;
    CreatedBlocks.CB_HitBox[index].dwnRight.y = CreatedBlocks.CB_array[index].dwnRight.y+5;
}
void init_cr_IfBlock(int index)
{ // If 1
    CreatedBlocks.CB_array[index].upRight.x = CreatedBlocks.CB_array[index].upLeft.x + 45;
    CreatedBlocks.CB_array[index].upRight.y = CreatedBlocks.CB_array[index].upLeft.y + 35;
    CreatedBlocks.CB_array[index].dwnLeft.x = CreatedBlocks.CB_array[index].upLeft.x - 45;
    CreatedBlocks.CB_array[index].dwnLeft.y = CreatedBlocks.CB_array[index].upLeft.y + 35;
    CreatedBlocks.CB_array[index].dwnRight.x = CreatedBlocks.CB_array[index].upLeft.x;
    CreatedBlocks.CB_array[index].dwnRight.y = CreatedBlocks.CB_array[index].upLeft.y + 70;
    CreatedBlocks.CB_array[index].nrCircles = 3;
    CreatedBlocks.CB_array[index].Circles[0].x = CreatedBlocks.CB_array[index].upLeft.x;
    CreatedBlocks.CB_array[index].Circles[0].y = CreatedBlocks.CB_array[index].upLeft.y;
    CreatedBlocks.CB_array[index].Circles[1].x = CreatedBlocks.CB_array[index].upRight.x;
    CreatedBlocks.CB_array[index].Circles[1].y = CreatedBlocks.CB_array[index].upRight.y;
    CreatedBlocks.CB_array[index].Circles[2].x = CreatedBlocks.CB_array[index].dwnLeft.x;
    CreatedBlocks.CB_array[index].Circles[2].y = CreatedBlocks.CB_array[index].dwnLeft.y;

        // INITIALIZARE HITBOX ()
    CreatedBlocks.CB_HitBox[index].upLeft.x = CreatedBlocks.CB_array[index].upLeft.x;
    CreatedBlocks.CB_HitBox[index].upLeft.y = CreatedBlocks.CB_array[index].upLeft.y-5;
    CreatedBlocks.CB_HitBox[index].upRight.x = CreatedBlocks.CB_array[index].upRight.x +5;
    CreatedBlocks.CB_HitBox[index].upRight.y = CreatedBlocks.CB_array[index].upRight.y;
    CreatedBlocks.CB_HitBox[index].dwnLeft.x = CreatedBlocks.CB_array[index].dwnLeft.x-5;
    CreatedBlocks.CB_HitBox[index].dwnLeft.y = CreatedBlocks.CB_array[index].dwnLeft.y;
    CreatedBlocks.CB_HitBox[index].dwnRight.x = CreatedBlocks.CB_array[index].dwnRight.x;
    CreatedBlocks.CB_HitBox[index].dwnRight.y = CreatedBlocks.CB_array[index].dwnRight.y+5;

}
void init_cr_OperBlock(int index)
{// Operatie 2
    CreatedBlocks.CB_array[index].upRight.x = CreatedBlocks.CB_array[index].upLeft.x + 90;
    CreatedBlocks.CB_array[index].upRight.y = CreatedBlocks.CB_array[index].upLeft.y;
    CreatedBlocks.CB_array[index].dwnLeft.x = CreatedBlocks.CB_array[index].upLeft.x;
    CreatedBlocks.CB_array[index].dwnLeft.y = CreatedBlocks.CB_array[index].upLeft.y + 50;
    CreatedBlocks.CB_array[index].dwnRight.x = CreatedBlocks.CB_array[index].upLeft.x + 90;
    CreatedBlocks.CB_array[index].dwnRight.y = CreatedBlocks.CB_array[index].upLeft.y + 50;
    CreatedBlocks.CB_array[index].nrCircles = 2;
    CreatedBlocks.CB_array[index].Circles[0].x = (CreatedBlocks.CB_array[index].upLeft.x + CreatedBlocks.CB_array[index].upRight.x) / 2;
    CreatedBlocks.CB_array[index].Circles[0].y = CreatedBlocks.CB_array[index].upLeft.y - 4;
    CreatedBlocks.CB_array[index].Circles[1].x = CreatedBlocks.CB_array[index].Circles[0].x;
    CreatedBlocks.CB_array[index].Circles[1].y = CreatedBlocks.CB_array[index].dwnLeft.y + 4;

    // INITIALIZARE HITBOX ()
    CreatedBlocks.CB_HitBox[index].upLeft.x = CreatedBlocks.CB_array[index].upLeft.x-5;
    CreatedBlocks.CB_HitBox[index].upLeft.y = CreatedBlocks.CB_array[index].upLeft.y-5;
    CreatedBlocks.CB_HitBox[index].upRight.x = CreatedBlocks.CB_array[index].upRight.x +5;
    CreatedBlocks.CB_HitBox[index].upRight.y = CreatedBlocks.CB_array[index].upRight.y-5;
    CreatedBlocks.CB_HitBox[index].dwnLeft.x = CreatedBlocks.CB_array[index].dwnLeft.x-5;
    CreatedBlocks.CB_HitBox[index].dwnLeft.y = CreatedBlocks.CB_array[index].dwnLeft.y+5;
    CreatedBlocks.CB_HitBox[index].dwnRight.x = CreatedBlocks.CB_array[index].dwnRight.x+5;
    CreatedBlocks.CB_HitBox[index].dwnRight.y = CreatedBlocks.CB_array[index].dwnRight.y+5;

}
void init_cr_OutputBlock(int index)
{//Output 3
    CreatedBlocks.CB_array[index].upRight.x = CreatedBlocks.CB_array[index].upLeft.x + 50;
    CreatedBlocks.CB_array[index].upRight.y = CreatedBlocks.CB_array[index].upLeft.y;
    CreatedBlocks.CB_array[index].dwnLeft.x = CreatedBlocks.CB_array[index].upLeft.x - 20;
    CreatedBlocks.CB_array[index].dwnLeft.y = CreatedBlocks.CB_array[index].upLeft.y + 50;
    CreatedBlocks.CB_array[index].dwnRight.x = CreatedBlocks.CB_array[index].upLeft.x + 70;
    CreatedBlocks.CB_array[index].dwnRight.y = CreatedBlocks.CB_array[index].upLeft.y + 50;
    CreatedBlocks.CB_array[index].nrCircles = 2;
    CreatedBlocks.CB_array[index].Circles[0].x = (CreatedBlocks.CB_array[index].upLeft.x + CreatedBlocks.CB_array[index].upRight.x) / 2;
    CreatedBlocks.CB_array[index].Circles[0].y = CreatedBlocks.CB_array[index].upLeft.y - 4;
    CreatedBlocks.CB_array[index].Circles[1].x = CreatedBlocks.CB_array[index].Circles[0].x;
    CreatedBlocks.CB_array[index].Circles[1].y = CreatedBlocks.CB_array[index].dwnLeft.y + 4;

        // INITIALIZARE HITBOX ()
    CreatedBlocks.CB_HitBox[index].upLeft.x = CreatedBlocks.CB_array[index].upLeft.x-5;
    CreatedBlocks.CB_HitBox[index].upLeft.y = CreatedBlocks.CB_array[index].upLeft.y-5;
    CreatedBlocks.CB_HitBox[index].upRight.x = CreatedBlocks.CB_array[index].upRight.x +5;
    CreatedBlocks.CB_HitBox[index].upRight.y = CreatedBlocks.CB_array[index].upRight.y-5;
    CreatedBlocks.CB_HitBox[index].dwnLeft.x = CreatedBlocks.CB_array[index].dwnLeft.x-5;
    CreatedBlocks.CB_HitBox[index].dwnLeft.y = CreatedBlocks.CB_array[index].dwnLeft.y+5;
    CreatedBlocks.CB_HitBox[index].dwnRight.x = CreatedBlocks.CB_array[index].dwnRight.x+5;
    CreatedBlocks.CB_HitBox[index].dwnRight.y = CreatedBlocks.CB_array[index].dwnRight.y+5;

}
void initCreatedBlock(int type, int x, int y, int index)
{
    CreatedBlocks.CB_type[index] = type;
    CreatedBlocks.CB_array[index].upLeft.x = x;
    CreatedBlocks.CB_array[index].upLeft.y = y;

    switch (type)
    {
    case 0:
        init_cr_InputBlock(index);
        break;
    case 1:
        init_cr_IfBlock(index);
        break;
    case 2:
        init_cr_OperBlock(index);
        break;
    case 3:
        init_cr_OutputBlock(index);
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

    Zone.upLeft.y=147;
    Zone.dwnRight.x= 930 ;  //1270;
    Zone.dwnRight.y= 660;  //828;

    Zone.upRight.x=Zone.dwnRight.x;
    Zone.upRight.y=Zone.upLeft.y;
    Zone.dwnLeft.x=Zone.upLeft.x;
    Zone.dwnLeft.y=Zone.dwnRight.y;


    /////
    //if((x<Zone.upLeft.x || x> Zone.dwnRight.x) || (y<Zone.upLeft.y || y> Zone.dwnRight.y))
            if(!(overBlock(Zone,CreatedBlocks.CB_HitBox[index].upLeft.x,CreatedBlocks.CB_HitBox[index].upLeft.y) || overBlock(Zone,CreatedBlocks.CB_HitBox[index].dwnLeft.x,CreatedBlocks.CB_HitBox[index].dwnLeft.y)||overBlock(Zone,CreatedBlocks.CB_HitBox[index].upRight.x,CreatedBlocks.CB_HitBox[index].upRight.y) || overBlock(Zone,CreatedBlocks.CB_HitBox[index].dwnRight.x,CreatedBlocks.CB_HitBox[index].dwnRight.y)))
                   return 1;  ////verificare daca colt e in zone (1 --> inafara zonei)

    for(int i=0;i<=nr_CreatedBlock;i++)
        {if(i!=index)
        if(overBlock(CreatedBlocks.CB_HitBox[i],CreatedBlocks.CB_HitBox[index].upLeft.x,CreatedBlocks.CB_HitBox[index].upLeft.y) || overBlock(CreatedBlocks.CB_HitBox[i],CreatedBlocks.CB_HitBox[index].dwnLeft.x,CreatedBlocks.CB_HitBox[index].dwnLeft.y)||overBlock(CreatedBlocks.CB_HitBox[i],CreatedBlocks.CB_HitBox[index].upRight.x,CreatedBlocks.CB_HitBox[index].upRight.y) || overBlock(CreatedBlocks.CB_HitBox[i],CreatedBlocks.CB_HitBox[index].dwnRight.x,CreatedBlocks.CB_HitBox[index].dwnRight.y))
                   return 1;  ////verificare daca fiecare colt al hitboxului blocului[index] este inafara celorlalte hitboxuri (1 --> este peste un alt hitbox)

        }
    return 0;
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

    for (int i = 0; i < 4; i++)
    {
        DrawBlock(Blocks[i],0);
        DrawName(Blocks[i]);
    }


    int mouse_x;// = mousex();
    int mouse_y;// = mousey();
int copie_mouse_x, copie_mouse_y,WasOnFreeSpace; //
    bool ok = 1;
    int i, j;

    /////////////////////////// LOOP PANA CAND SE APASA CLICK DREAPTA
    while (ok)
    {
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
                    break;
                }
            for (j = 0; j <= nr_CreatedBlock && selectedLeftBlocks == 0; j++)
                if (overBlock(CreatedBlocks.CB_array[j], mouse_x, mouse_y))
                {
                    selectedCreatedBlocks = 1;
                    break;
                }
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);

        }
        WasOnFreeSpace=1; //// variabila care tine minte daca la repetarea anterioara blockul nu era peste alt hitbox (verifsandu=1) si invers
        //////drag butoane din meniu
        while (selectedLeftBlocks)
        {
            delay(10);
            if(WasOnFreeSpace)
            DrawBlock(CreatedBlocks.CB_array[nr_CreatedBlock], 15);
            mouse_x = mousex();
            mouse_y = mousey();
            initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);

            if(overAnyHitBox(nr_CreatedBlock,mouse_x,mouse_y)==0) /// daca nu sunt peste un hitbox si nici nu depasesc zona de desenare
            {
                if(WasOnFreeSpace==0)
                {
                    initCreatedBlock(i, copie_mouse_x, copie_mouse_y, nr_CreatedBlock);
                    DrawBlock(CreatedBlocks.CB_array[nr_CreatedBlock], 15);
                }
                initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);
                DrawBlock(CreatedBlocks.CB_array[nr_CreatedBlock], 4);
                copie_mouse_x=mouse_x;
                copie_mouse_y=mouse_y;
                WasOnFreeSpace=1;
            }
            else
                {
                     initCreatedBlock(i, copie_mouse_x, copie_mouse_y, nr_CreatedBlock);
                     DrawBlock(CreatedBlocks.CB_array[nr_CreatedBlock], 4);
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
                selectedLeftBlocks = 0;
                atribuireMainInsertCreatedBlocks();
                nr_CreatedBlock++;
                DrawBlock(Blocks[i], 0);
                MainInsertFNC(i);
            }
        }
        WasOnFreeSpace=1;

        //////////////////// mutare pentru butoane plasate anterier
        while (selectedCreatedBlocks)
        {
             delay(10);
            if(WasOnFreeSpace)
            DrawBlock(CreatedBlocks.CB_array[j], 15);
            mouse_x = mousex();
            mouse_y = mousey();
            initCreatedBlock(CreatedBlocks.CB_type[j], mouse_x, mouse_y, j);

            if(overAnyHitBox(j,mouse_x,mouse_y)==0)
            {
                if(WasOnFreeSpace==0)
                {
                   initCreatedBlock(CreatedBlocks.CB_type[j], copie_mouse_x, copie_mouse_y, j);
                   DrawBlock(CreatedBlocks.CB_array[j], 15);
                }
                initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);
                   DrawBlock(CreatedBlocks.CB_array[j], 4);
                copie_mouse_x=mouse_x;
                copie_mouse_y=mouse_y;
                WasOnFreeSpace=1;
            }
            else
                {
                   initCreatedBlock(CreatedBlocks.CB_type[j], copie_mouse_x, copie_mouse_y, j);
                   DrawBlock(CreatedBlocks.CB_array[j], 4);
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
            }

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
