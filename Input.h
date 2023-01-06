#include "LinesOfBlocks.h"
#include <conio.h>
void CleanInputText(int index)
{
    setfillstyle(SOLID_FILL, 15);
    if(CreatedBlocks[index].CB_type==1)
    {
         int x=(CreatedBlocks[index].upLeft.x+CreatedBlocks[index].upRight.x+CreatedBlocks[index].dwnLeft.x+CreatedBlocks[index].dwnRight.x)/4;
         int y=(CreatedBlocks[index].upLeft.y+CreatedBlocks[index].upRight.y+CreatedBlocks[index].dwnLeft.y+CreatedBlocks[index].dwnRight.y)/4;
        bar(x-textwidth(CreatedBlocks[index].inputText),y-textheight(CreatedBlocks[index].inputText),x+textwidth(CreatedBlocks[index].inputText),y+textheight(CreatedBlocks[index].inputText));
    }
    else
    {
        bar(CreatedBlocks[index].upLeft.x,CreatedBlocks[index].upLeft.y,CreatedBlocks[index].dwnRight.x,CreatedBlocks[index].dwnRight.y);

    }
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
        //if(ButtonsInputs[i].selected==0)
        ButtonsInputs[i].color=2;
        //else ButtonsInputs[i].color=4;
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
                     strcpy(CreatedBlocks[index].inputText,ButtonsInputs[i].text);
                     ButtonsInputs[i].color=4;
                     ButtonsInputs[i].selected=1;
                     ButtonsInputs[i].disponibilOutput=1;
                     DrawButton(ButtonsInputs[i]);
                     ButtonsInputs[i].color=2;
                     DrawInputText(index,3);
                     ok=0;
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
                 //ButtonsInputs[i].disponibilOutput=0;
                 DrawOutputBtns();
                 ok=0;
             }
             clearmouseclick(WM_LBUTTONUP);
             clearmouseclick(WM_LBUTTONDOWN);
             DrawInputText(index,3);
             delay(300);
             setfillstyle(SOLID_FILL, 15);
                bar(1099, 100, 1300, 550);


         }
        }


}
void UpdateText(int index)
{
    int x=(CreatedBlocks[index].upLeft.x+CreatedBlocks[index].upRight.x+CreatedBlocks[index].dwnLeft.x+CreatedBlocks[index].dwnRight.x)/4;
    int y=(CreatedBlocks[index].upLeft.y+CreatedBlocks[index].upRight.y+CreatedBlocks[index].dwnLeft.y+CreatedBlocks[index].dwnRight.y)/4;

    setcolor(15);
    setfillstyle(SOLID_FILL, 15);
    bar(x-textwidth(CreatedBlocks[index].inputText)/2 , y-textheight(CreatedBlocks[index].inputText)/2, x+textwidth(CreatedBlocks[index].inputText)/2, y+textheight(CreatedBlocks[index].inputText)/2);

}
void InfoUserTypeTextOfBlock(int typeOFBlock)
{
        setcolor(8);
        setbkcolor(15);
        settextstyle(3, HORIZ_DIR, 1);
    if(typeOFBlock==1)
    {
        outtextxy(1200-textwidth("Tasteaza Conditia")/2,50,"Tasteaza Conditia");
    }
    else
    {
        outtextxy(1200-textwidth("Tasteaza Operatia")/2,50,"Tasteaza Operatia");
    }
    outtextxy(1200-textwidth("Backspace = stergere caracter")/2,70,"backspace = stergere caracter");
    outtextxy(1200-textwidth("Enter = confirmare")/2,90,"Enter = confirmare");


}
void InserTyping(int index)
{
    MarkOnSchemGrid(index,0);
    char typedText[100]="";
    strcpy(typedText,CreatedBlocks[index].inputText);
    int indexTypedText=strlen(typedText);
    char tasta,enter=13,backspace=8;
    bool ok=1;
    int padding=25;
    InfoUserTypeTextOfBlock(CreatedBlocks[index].CB_type);
    while(ok)
    {
        tasta=getch();
        if(tasta==enter)
        {
            typedText[indexTypedText]=NULL;
            strcpy(CreatedBlocks[index].inputText,typedText);
            DrawBlock(CreatedBlocks[index],0);
            MarkOnSchemGrid(index,1);
            DrawAllLines();
            break;
        }
        else{
                DrawBlock(CreatedBlocks[index],15);
        if(tasta==backspace&&indexTypedText)
        {
            UpdateText(index);
            typedText[--indexTypedText]=NULL;
            if(typedText&&CreatedBlocks[index].upRight.x-CreatedBlocks[index].dwnLeft.x>100)
            {
        if(CreatedBlocks[index].CB_type==1)
        {
            CreatedBlocks[index].dwnLeft.x+=6;
            CreatedBlocks[index].upRight.x-=6;

            CB_HitBox[index].dwnLeft.x+=6;
            CB_HitBox[index].upRight.x-=6;
            //padding-=10;
        }
        else
        {
            CreatedBlocks[index].upLeft.x-=-4;
            CreatedBlocks[index].dwnLeft.x-=-4;
            CreatedBlocks[index].upRight.x+=-4;
            CreatedBlocks[index].dwnRight.x+=-4;

            CB_HitBox[index].upLeft.x-=-4;
            CB_HitBox[index].dwnLeft.x-=-4;
            CB_HitBox[index].upRight.x+=-4;
            CB_HitBox[index].dwnRight.x+=-4;
        }
        UpdateCirclesPoz(index);
        }
        strcpy(CreatedBlocks[index].inputText,typedText);
        DrawInputText(index,2);
        }
        if(tasta!=backspace)
        {
        typedText[indexTypedText]=tasta;
        strcpy(CreatedBlocks[index].inputText,typedText);
        indexTypedText++;
        if(textwidth(typedText)+padding>CreatedBlocks[index].upRight.x-CreatedBlocks[index].dwnLeft.x)
        {

        if(CreatedBlocks[index].CB_type==1)
        {
            CreatedBlocks[index].dwnLeft.x-=6;
            CreatedBlocks[index].upRight.x+=6;

            CB_HitBox[index].dwnLeft.x-=6;
            CB_HitBox[index].upRight.x+=6;
            padding+=10;
        }
        else
        {
            CreatedBlocks[index].upLeft.x-=6;
            CreatedBlocks[index].dwnLeft.x-=6;
            CreatedBlocks[index].upRight.x+=6;
            CreatedBlocks[index].dwnRight.x+=6;

            CB_HitBox[index].upLeft.x-=6;
            CB_HitBox[index].dwnLeft.x-=6;
            CB_HitBox[index].upRight.x+=6;
            CB_HitBox[index].dwnRight.x+=6;
        }
        UpdateCirclesPoz(index);
        }
        UpdateText(index);
        DrawInputText(index,2);
        }
        DrawAllLines();
        DrawInputText(index,2);
        DrawBlock(CreatedBlocks[index],2);
        }
    }
    CleanRightArea();

}
void MainInsertFNC(int i,int index)
{
    atribuireMainInsert();
    if(i==0)
       InserInput(index);
    if(i==3)
        InserOutput(index);
    if(i==1||i==2)
    {
        InserTyping(index);
    }
}
