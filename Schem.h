#include "varSetup.h"
void atribuireSchem()
{
    //////////////////////////////////
//      Blocuri
//////////////////////////////////
//  Input
Blocks[0].upLeft.x=10;
Blocks[0].upLeft.y=200;
Blocks[0].upRight.x=100;
Blocks[0].upRight.y=200;
Blocks[0].dwnLeft.x=30;
Blocks[0].dwnLeft.y=250;
Blocks[0].dwnRight.x=80;
Blocks[0].dwnRight.y=250;
strcpy(Blocks[0].text,"Input");

// If
Blocks[1].upLeft.x=50;
Blocks[1].upLeft.y=350;
Blocks[1].upRight.x=50;
Blocks[1].upRight.y=350;
Blocks[1].dwnLeft.x=5;
Blocks[1].dwnLeft.y=420;
Blocks[1].dwnRight.x=100;
Blocks[1].dwnRight.y=420;
strcpy(Blocks[1].text,"If");

// Operatie
Blocks[2].upLeft.x=10;
Blocks[2].upLeft.y=550;
Blocks[2].upRight.x=100;
Blocks[2].upRight.y=550;
Blocks[2].dwnLeft.x=10;
Blocks[2].dwnLeft.y=600;
Blocks[2].dwnRight.x=100;
Blocks[2].dwnRight.y=600;
strcpy(Blocks[2].text,"Operatie");

//Output
Blocks[3].upLeft.x=30;
Blocks[3].upLeft.y=720;
Blocks[3].upRight.x=80;
Blocks[3].upRight.y=720;
Blocks[3].dwnLeft.x=10;
Blocks[3].dwnLeft.y=770;
Blocks[3].dwnRight.x=100;
Blocks[3].dwnRight.y=770;
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
void Schem()
{
    atribuireSchem();

    for(int i=0;i<4;i++)
           {
               DrawBlock(Blocks[i],0);
               DrawName(Blocks[i]);
           }
}
