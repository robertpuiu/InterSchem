#include "LinesOfBlocks.h"
/*
struct Button {
    Spot up_left;
    Spot dwn_right;
    char text[100];
    char Litera;
    int textSize;
    int color;
    bool selected=0; */
void CleanInputText(int index)
{
    if(CreatedBlocks[index].CB_type==1)
    {

    }
    else
    {
        setfillstyle(SOLID_FILL, 15);
        bar(CreatedBlocks[index].upLeft.x,CreatedBlocks[index].upLeft.y,CreatedBlocks[index].dwnRight.x,CreatedBlocks[index].dwnRight.y);

    }
}
void    atribuireMainInsertCreatedBlocks()//aici am ramas
{


}
void atribuireMainInsert()
{
    int Y=150;
    char v[]="abcdefgh";
    for(int i=0;i<8;i++)
    {
        ButtonsInputs[i].up_left.x=1100;
        ButtonsInputs[i].up_left.y=Y;
        ButtonsInputs[i].dwn_right.x=1300;
        ButtonsInputs[i].dwn_right.y=Y+40;
        Y=Y+50;
        strncpy(ButtonsInputs[i].text,v+i,1);
        ButtonsInputs[i].Litera=v[i];
        ButtonsInputs[i].textSize=3;
        if(ButtonsInputs[i].selected==0)
        ButtonsInputs[i].color=2;
        else ButtonsInputs[i].color=4;
    }
}
void InserInput(int index)
{
        int mouse_x = mousex();
        int mouse_y = mousey();
        setcolor(0);
        settextstyle(10, HORIZ_DIR, 2);
        outtextxy(1100, 100, "Selecteaza Input");

     //DrawButtons(ButtonsInputs,8);
     for(int i=0;i<8;i++)
        if(ButtonsInputs[i].selected==0)
        DrawButton(ButtonsInputs[i]);
     bool ok=1;
     while(ok)
     {

         if(ismouseclick(WM_LBUTTONDOWN))
         {
             mouse_x = mousex();
             mouse_y = mousey();
             for(int i=0;i<8;i++)
                if(overBTN(ButtonsInputs[i],mouse_x,mouse_y))
             {
                 if(ButtonsInputs[i].selected==0)
                 {
                     strcpy(CreatedBlocks[index].inputText,ButtonsInputs[i].text);
                     ButtonsInputs[i].color=4;
                     ButtonsInputs[i].selected=1;
                     ButtonsInputs[i].disponibilOutput=1;
                     DrawButtons(ButtonsInputs,8);
                     DrawInputText(index,3);
                     ok=0;
                 }
             }
             clearmouseclick(WM_LBUTTONUP);
             clearmouseclick(WM_LBUTTONDOWN);

             delay(700);
             setfillstyle(SOLID_FILL, 15);
                bar(1099, 100, 1300, 550);


         }
     }
     //delete var menu sau functie clean instrc
}
void DrawOutputBtns()
{
    setfillstyle(SOLID_FILL, 15);
    bar(1099, 100, 1300, 550);
        setcolor(0);
        setbkcolor(15);
        settextstyle(10, HORIZ_DIR, 2);
        outtextxy(1100, 100, "Selecteaza Out");
    for(int i=0;i<8;i++)
        {
            if(ButtonsInputs[i].disponibilOutput)
            {
              //  ButtonsInputs[i].disponibilOutput=0;
                DrawButton(ButtonsInputs[i]);
            }
        }
}
void InserOutput(int index)
{
     int mouse_x = mousex();
        int mouse_y = mousey();
        DrawOutputBtns();
        bool ok=1;
        while(ok)
        {
            if(ismouseclick(WM_LBUTTONDOWN))
         {
             mouse_x = mousex();
             mouse_y = mousey();
             for(int i=0;i<8;i++)
                if(overBTN(ButtonsInputs[i],mouse_x,mouse_y)&&ButtonsInputs[i].disponibilOutput)
             {
                 strcpy(CreatedBlocks[index].inputText,ButtonsInputs[i].text);
                 ButtonsInputs[i].disponibilOutput=0;
                 DrawOutputBtns();
                 ok=0;
             }
             clearmouseclick(WM_LBUTTONUP);
             clearmouseclick(WM_LBUTTONDOWN);

             delay(700);
             setfillstyle(SOLID_FILL, 15);
                bar(1099, 100, 1300, 550);


         }
        }


}
void MainInsertFNC(int i,int index)
{
    atribuireMainInsert();
    if(i==0)
       InserInput(index);
    if(i==3)
        InserOutput(index);
}
