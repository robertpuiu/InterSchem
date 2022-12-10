#include "Input.h"
int x[4] = { 7,49,7,27 };
int y[4] = { 140,280,460,620 };
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
        DrawBlock(Blocks[i], 0);
        DrawName(Blocks[i]);
    }


    int mouse_x;// = mousex();
    int mouse_y;// = mousey();

    bool ok = 1, selectedLeftBlocks = 0, selectedCreatedBlocks = 0;
    int i, j;

    /////////////////////////// LOOP PANA CAND SE APASA CLICK DREAPTA
    while (ok)
    {
        if (ismouseclick(WM_LBUTTONDOWN) && selectedLeftBlocks == 0 && selectedCreatedBlocks == 0)
        {
            mouse_x = mousex();
            mouse_y = mousey();
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
        //////drag butoane din meniu
        while (selectedLeftBlocks)
        {
            delay(10);
            DrawBlock(CreatedBlocks.CB_array[nr_CreatedBlock], 15);
            mouse_x = mousex();
            mouse_y = mousey();
            initCreatedBlock(i, mouse_x, mouse_y, nr_CreatedBlock);
            DrawBlock(CreatedBlocks.CB_array[nr_CreatedBlock], 4);
                            DrawBlock(Blocks[i], 0);

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

        //////////////////// mutare pentru butoane plasate anterier
        while (selectedCreatedBlocks)
        {
            delay(10);
            DrawBlock(CreatedBlocks.CB_array[j], 15);
            mouse_x = mousex();
            mouse_y = mousey();
            initCreatedBlock(CreatedBlocks.CB_type[j], mouse_x, mouse_y, j);
            DrawBlock(CreatedBlocks.CB_array[j], 4);
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
