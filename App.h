#include "Schem.h"
#include <fstream>
using namespace std;
ofstream fout;
ifstream fin;
char typedText[100]="";
void ScrieTextSalvareSchema()
{
    setcolor(0);
    setbkcolor(15);
    settextstyle(3, HORIZ_DIR, 2);
    int x=1200-textwidth(typedText)/2;
    int y=400;
    outtextxy(x, y,typedText );//modificate coordonatele in fuctie de type

}
void AfisareTextSalvareSchema()
{
    setfillstyle(SOLID_FILL, 15);
    bar(1050, 100, 1350, 550);
    setcolor(0);
    setbkcolor(15);
    settextstyle(3 , HORIZ_DIR, 2);
    outtextxy(1120, 300,"Numeste noul fisier" );
    //ScrieTextSalvareSchema()

}
void SalvareSchema()
{
    AfisareTextSalvareSchema();
    int indexTypedText=0;
    char tasta,enter=13,backspace=8;
    bool ok=1;
    while(ok)
    {
        tasta=getch();
        if(tasta==enter)
        {
            AfisareTextSalvareSchema();
        ScrieTextSalvareSchema();
            break;
        }
        if(tasta==backspace&&indexTypedText)
        {
            AfisareTextSalvareSchema();
            typedText[--indexTypedText]=NULL;
        ScrieTextSalvareSchema();
        }
        if(tasta!=backspace)
        {
        typedText[indexTypedText]=tasta;
        indexTypedText++;
        typedText[indexTypedText]=NULL;
        AfisareTextSalvareSchema();
        ScrieTextSalvareSchema();
        }

    }
    setfillstyle(SOLID_FILL, 15);
    bar(1050, 100, 1350, 550);

}
int indexBlockIfBehind[20]={0};
int indexIFBehind=0;
int indentation=0;
void WriteCodeOfBlock(int indexBlock)
{
    CreatedBlocks[indexBlock].ConnectCircle[0].visited++;
    char LineToDisplay[256]="";
    delay(150);
    setcolor(0);
    setbkcolor(15);
    settextstyle(8, HORIZ_DIR, 1);
    if(CreatedBlocks[indexBlock].inputText)
    {if(CreatedBlocks[indexBlock].CB_type==0)
        {strcat(LineToDisplay,"cin>>");strcat(LineToDisplay,CreatedBlocks[indexBlock].inputText);strcat(LineToDisplay,";");outtextxy(1100+indentation, yLineWriten ,LineToDisplay );}
    if(CreatedBlocks[indexBlock].CB_type==1)
        {
            if(CreatedBlocks[indexBlock].ConnectCircle[0].selected==1)
            {
                strcat(LineToDisplay,"if(");strcat(LineToDisplay,CreatedBlocks[indexBlock].inputText);strcat(LineToDisplay,")");
            outtextxy(1100+indentation, yLineWriten ,LineToDisplay );
            yLineWriten+=20;
            indentation+=20;
            outtextxy(1100+indentation, yLineWriten ,"{" );
            indexBlockIfBehind[indexIFBehind]=indexBlock;
            indexIFBehind++;
            }
            else
            {
                strcat(LineToDisplay,"While(");strcat(LineToDisplay,CreatedBlocks[indexBlock].inputText);strcat(LineToDisplay,")");
            outtextxy(1100+indentation, yLineWriten ,LineToDisplay );
            yLineWriten+=20;
            indentation+=20;
            outtextxy(1100+indentation, yLineWriten ,"{" );
            indexBlockIfBehind[indexIFBehind]=indexBlock;
            indexIFBehind++;

            }

            }
    if(CreatedBlocks[indexBlock].CB_type==2)
        {strcat(LineToDisplay,CreatedBlocks[indexBlock].inputText);strcat(LineToDisplay,";");outtextxy(1100+indentation, yLineWriten ,LineToDisplay );}
    if(CreatedBlocks[indexBlock].CB_type==3)
            {strcat(LineToDisplay,"cout>>");strcat(LineToDisplay,CreatedBlocks[indexBlock].inputText);strcat(LineToDisplay,";");outtextxy(1100+indentation, yLineWriten ,LineToDisplay );}

    strcpy(LineToDisplay,"");
    yLineWriten+=20;
    }
}
void GoThroughSchemLeft(int indexCurrentBlock)
{
    while(CreatedBlocks[indexCurrentBlock].ConnectCircle[1].color!=4&&(CreatedBlocks[indexCurrentBlock].ConnectCircle[0].selected==CreatedBlocks[indexCurrentBlock].ConnectCircle[0].visited+1||CreatedBlocks[indexCurrentBlock].CB_type==1))
    {
        if(CreatedBlocks[indexCurrentBlock].ConnectCircle[0].selected>1&&CreatedBlocks[indexCurrentBlock].CB_type!=1)
        {
            for(int i=0;i<CreatedBlocks[indexCurrentBlock].ConnectCircle[0].selected-1;i++)
            {
                outtextxy(1100+indentation, yLineWriten ,"}" );
    indentation-=20;
    yLineWriten+=20;
            }
        }
        if(!(CreatedBlocks[indexCurrentBlock].CB_type==1&&CreatedBlocks[indexCurrentBlock].ConnectCircle[0].visited))
        WriteCodeOfBlock(indexCurrentBlock);
        indexCurrentBlock=CreatedBlocks[indexCurrentBlock].indexBlockConnexionTo[1];
    }
    if(CreatedBlocks[indexCurrentBlock].ConnectCircle[1].color==4)
    {
    WriteCodeOfBlock(indexCurrentBlock);
    setcolor(0);
    setbkcolor(15);
    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(1100+indentation, yLineWriten ,"return 0;" );
    yLineWriten+=20;
    //indentation-=20;
    outtextxy(1100+indentation, yLineWriten ,"}" );
    indentation-=20;
    yLineWriten+=20;
    }
    else //if(CreatedBlocks[indexCurrentBlock].CB_type!=1)
        {
            CreatedBlocks[indexCurrentBlock].ConnectCircle[0].visited++;
            outtextxy(1100+indentation, yLineWriten ,"}end of branch" );
           // cout<<CreatedBlocks[indexCurrentBlock].inputText<<endl;
    indentation-=20;
    yLineWriten+=20;
    }
}
void GoThroughSchem()
{
    int indexCurrentBlock=indexStartBlock;

    GoThroughSchemLeft(indexCurrentBlock);
    while(indexIFBehind>-1)
    {
        if(CreatedBlocks[indexBlockIfBehind[indexIFBehind]].ConnectCircle[2].color==4)
        {
            setcolor(0);
    setbkcolor(15);
    settextstyle(8, HORIZ_DIR, 1);
    //outtextxy(1100+indentation, yLineWriten ,"}" );

    //yLineWriten+=20;
    outtextxy(1100+indentation, yLineWriten ,"else return 0;" );
    indentation-=20;
    yLineWriten+=20;
        }
        else
        {
    if(CreatedBlocks[indexBlockIfBehind[indexIFBehind]].CB_type==1)
            {
                setcolor(0);
    setbkcolor(15);
    settextstyle(8, HORIZ_DIR, 1);
    if(CreatedBlocks[indexBlockIfBehind[indexIFBehind]].ConnectCircle[0].selected==1)
    {
        outtextxy(1100+indentation, yLineWriten ,"else" );
    yLineWriten+=20;
    indentation+=20;
    outtextxy(1100+indentation, yLineWriten ,"{" );
    yLineWriten+=20;
    }
    if(CreatedBlocks[indexBlockIfBehind[indexIFBehind]].ConnectCircle[0].visited+2==CreatedBlocks[indexBlockIfBehind[indexIFBehind]].ConnectCircle[0].selected)
    {
        setcolor(0);
    setbkcolor(15);
    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(1100+indentation, yLineWriten ,"}" );
    yLineWriten+=20;
    }
    GoThroughSchemLeft(CreatedBlocks[indexBlockIfBehind[indexIFBehind]].indexBlockConnexionTo[2]);
            }
        }
        indexIFBehind--;
    }

}
void WriteOnFile();
void ReadFromFile();
void ResetVal()
{
    indexBlockIfBehind[20]={0};
    indexIFBehind=0;
    indentation=0;
    for(int i=0;i<nr_CreatedBlock;i++)
        {
            CreatedBlocks[i].ConnectCircle[0].visited=0;
            CreatedBlocks[i].ConnectCircle[0].selected=0;
        }

}
void App()
{
    readimagefile("bckgnd.jpg", 0, 0, 1360, 765);
    setfillstyle(SOLID_FILL, RGB(0, 155, 155));
    DrawButtons(ButtonsApp, nrOfButtons);
    clearmouseclick(WM_LBUTTONDOWN);
    int mouse_x = mousex();
    int mouse_y = mousey();
    bool ok = 1;
    while (ok)
    {


        mouse_hover_m(mouse_x, mouse_y, ButtonsApp, nrOfButtons); //functioneaza pana la click

        if (ismouseclick(WM_LBUTTONUP))
        {
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);
            mouse_x = mousex();
            mouse_y = mousey();
            if (overBTN(ButtonsApp[0], mouse_x, mouse_y))
            {
                clearmouseclick(WM_LBUTTONUP);
                clearmouseclick(WM_LBUTTONDOWN);
                ok = 0;
            }
            else if (overBTN(ButtonsApp[1], mouse_x, mouse_y))
            {
                setfillstyle(SOLID_FILL, 15);
                bar(0, 61, 1025, 900);
                clearmouseclick(WM_LBUTTONUP);
                clearmouseclick(WM_LBUTTONDOWN);
                DrawButtons(PannelSchem, nrOfButtons + 2);
                CleanRightArea();
                //mouse_hover_m(mouse_x,  mouse_y,PannelSchem,1);
                ResetVal();
                Schem();

            }
            else if(overBTN(ButtonsApp[2], mouse_x, mouse_y))
            {
                strcpy(typedText,"");
                SalvareSchema();
                fin.open(typedText);
                ReadFromFile();
                fout.close();
            }
            else if(overBTN(ButtonsApp[3], mouse_x, mouse_y))
            {
                strcpy(typedText,"");
                SalvareSchema();
                fout.open(typedText);
                WriteOnFile();
                fout.close();
            }
            else if(overBTN(PannelSchem[0],mouse_x,mouse_y))
            {
            yLineWriten=50;
                setcolor(0);
            setbkcolor(15);
            settextstyle(8, HORIZ_DIR, 1);
            outtextxy(1080, yLineWriten ,"#include<iostream>" );
            yLineWriten+=20;
            outtextxy(1080, yLineWriten ,"using namesapace std;" );
            yLineWriten+=20;
            outtextxy(1080, yLineWriten ,"int main()" );
            yLineWriten+=20;
            outtextxy(1080, yLineWriten ,"{" );
            yLineWriten+=20;
                GoThroughSchem();
            }

        }
    }
}
void ReadFromFile()
{
    char s[256]="";
    fin.getline(s,256);
   // cout<<s<<endl;
    strcpy(s,s+18);
    cout<<s<<" "<<strlen(s)<<endl;
    int nrOFBlocksToRead=0;
    int pwr=1;
    for(int i=strlen(s)-1;i>-1;i--)
    {
        nrOFBlocksToRead+=pwr*(s[i]-'0');
        cout<<s[i];
        pwr*=10;
    }
    pwr=1;
    cout<<endl;
    cout<<"nr. blocuri: "<<nrOFBlocksToRead<<endl;
    for(int i=0;i<nrOFBlocksToRead;i++)
    {
        char linie[256]="";
        int Index,Type;
        int indexCircleCurentBlock=-1,indexBlockConnectedTo=-1,indexCircleConnectedTo=-1;
        Spot upLeft,upRight,dwnRight,dwnLeft;
        while(strstr(linie,"Textul blocului:")==0)
        {
            fin.getline(linie,500);
            //cout<<linie<<endl;
            if(strstr(linie,"Index: "))
            {
                strcpy(linie,linie+strlen("Index: "));
                Index=0;
                pwr=1;

                for(int i=strlen(linie)-1;i>-1;i--)
                {
                Index+=pwr*(linie[i]-'0');

                pwr*=10;
                }
                pwr=1;
                cout<<"Index: "<<Index<<endl;
            }
            if(strstr(linie,"Tip bloc: "))
            {
                cout<<linie<<endl;
                Type=-1;
                strcpy(linie,linie+strlen("Tip bloc: "));
                if(strcmp(linie,"Input")==0)
                    Type=0;
                else if(strcmp(linie,"If")==0)
                    Type=1;
                else
                    if(strcmp(linie,"Calcul")==0)
                    Type=2;
                else
                    if(strcmp(linie,"Output")==0)
                    Type=3;
                cout<<"Type: "<<Type<<endl;
            }
            if(strstr(linie,"Tip bloc: "))
            {
                Type=-1;
                strcpy(linie,linie+strlen("Tip bloc: "));
                if(strcmp(linie,"Input")==0)
                    Type=0;
                else if(strcmp(linie,"If")==0)
                    Type=1;
                else
                    if(strcmp(linie,"Calcul")==0)
                    Type=2;
                else
                    if(strcmp(linie,"Output")==0)
                    Type=3;
                cout<<"Type: "<<Type<<endl;
            }
            if(strstr(linie,"Coordonate colt stanga sus: x="))
            {
                int k=strlen(linie)-1;
                int pwr=1;
                upLeft.y=0;
                while(isdigit(linie[k]))
                {
                    upLeft.y+=pwr*(linie[k]-'0');
                    pwr*=10;
                    k--;
                }
                pwr=1;
                while(isdigit(linie[k])==0)
                    k--;
                upLeft.x=0;
                while(isdigit(linie[k]))
                {
                    upLeft.x+=pwr*(linie[k]-'0');
                    pwr*=10;
                    k--;
                }
                pwr=1;
                cout<<"upLeft.x: "<<upLeft.x<<"  upLeft.y:"<<upLeft.y<<endl;
                initCreatedBlock(Type,upLeft.x,upLeft.y,Index);
            }
            if(strstr(linie,"Coordonate colt dreapta sus: x="))
            {
                int k=strlen(linie)-1;
                int pwr=1;
                upRight.y=0;
                while(isdigit(linie[k]))
                {
                    upRight.y+=pwr*(linie[k]-'0');
                    pwr*=10;
                    k--;
                }
                pwr=1;
                while(isdigit(linie[k])==0)
                    k--;
                upRight.x=0;
                while(isdigit(linie[k]))
                {
                    upRight.x+=pwr*(linie[k]-'0');
                    pwr*=10;
                    k--;
                }
                pwr=1;
                cout<<"upRight.x: "<<upRight.x<<"  upRight.y:"<<upRight.y<<endl;
            }
            if(strstr(linie,"Coordonate colt dreapta jos: x="))
            {
                int k=strlen(linie)-1;
                int pwr=1;
                dwnRight.y=0;
                while(isdigit(linie[k]))
                {
                    dwnRight.y+=pwr*(linie[k]-'0');
                    pwr*=10;
                    k--;
                }
                pwr=1;
                while(isdigit(linie[k])==0)
                    k--;
                dwnRight.x=0;
                while(isdigit(linie[k]))
                {
                    dwnRight.x+=pwr*(linie[k]-'0');
                    pwr*=10;
                    k--;
                }
                pwr=1;
                cout<<"dwnRight.x: "<<dwnRight.x<<"  dwnRight.y:"<<dwnRight.y<<endl;
            }
            if(strstr(linie,"Coordonate colt stanga jos: x="))
            {
                int k=strlen(linie)-1;
                int pwr=1;
                dwnLeft.y=0;
                while(isdigit(linie[k]))
                {
                    dwnLeft.y+=pwr*(linie[k]-'0');
                    pwr*=10;
                    k--;
                }
                pwr=1;
                while(isdigit(linie[k])==0)
                    k--;
                dwnLeft.x=0;
                while(isdigit(linie[k]))
                {
                    dwnLeft.x+=pwr*(linie[k]-'0');
                    pwr*=10;
                    k--;
                }
                pwr=1;
                cout<<"dwnLeft.x: "<<dwnLeft.x<<"  dwnLeft.y:"<<dwnLeft.y<<endl;

            }

            if(strstr(linie,"Este conectat la blocurile cu indicii: "))
            {
                fin.getline(linie,500);
                char * paranteza=strtok(linie,"(");
                        while(paranteza)
                        {
                            cout<<paranteza<<endl;
                            int indexCircleCurentBlock=paranteza[0]-'0';
                            strcpy(paranteza,paranteza+2);
                            int indexBlockConnectedTo=paranteza[0]-'0';
                            if(isdigit(paranteza[1]))
                            {
                                indexBlockConnectedTo=indexBlockConnectedTo*10+paranteza[1]-'0';
                            }
                            indexCircleConnectedTo=paranteza[strlen(paranteza)-2]-'0';
                            paranteza=strtok(NULL,"(");

                            CreatedBlocks[Index].isCircleConected[indexCircleCurentBlock]=1;
                                            CreatedBlocks[Index].indexBlockConnexionTo[indexCircleCurentBlock]=indexBlockConnectedTo;
                                            CreatedBlocks[Index].indexCirecleConnexionTo[indexCircleCurentBlock]=indexCircleConnectedTo;
                                            CreatedBlocks[indexBlockConnectedTo].ConnectCircle[indexCircleConnectedTo].selected++;
                            cout<<"int type:  "<<indexCircleCurentBlock<<","<<indexBlockConnectedTo<<"--->>"<<indexCircleConnectedTo<<endl;
                        }

            }

            if(strstr(linie,"Textul blocului: "))
            {
                cout<<linie<<endl;
                char copylinie[500]="";
                strcpy(copylinie,linie);
                strcpy(copylinie,copylinie+strlen("Textul blocului: "));


                CreatedBlocks[Index].upLeft.x=upLeft.x;
                CreatedBlocks[Index].upLeft.y=upLeft.y;

                CreatedBlocks[Index].upRight.x=upRight.x;
                CreatedBlocks[Index].upRight.y=upRight.y;

                CreatedBlocks[Index].dwnLeft.x=dwnLeft.x;
                CreatedBlocks[Index].dwnLeft.y=dwnLeft.y;

                CreatedBlocks[Index].dwnRight.x=dwnRight.x;
                CreatedBlocks[Index].dwnRight.y=dwnRight.y;

                CB_HitBox[Index].upLeft.x=upLeft.x-10;
                CB_HitBox[Index].upLeft.y=upLeft.y-15;

                CB_HitBox[Index].upRight.x=upRight.x+10;
                CB_HitBox[Index].upRight.y=upRight.y-15;

                CB_HitBox[Index].dwnLeft.x=dwnLeft.x-10;
                CB_HitBox[Index].dwnLeft.y=dwnLeft.y+10;

                CB_HitBox[Index].dwnRight.x=dwnRight.x+15;
                CB_HitBox[Index].dwnRight.y=dwnRight.y+10;

                UpdateCirclesPoz(Index);

                strcpy(CreatedBlocks[Index].inputText,copylinie);
                nr_CreatedBlock++;
                cout<<"tegzt:"<<copylinie<<endl;
            }
        }
        cout<<endl<<endl<<endl;
       /* while(strstr(linie,"Textul blocului:")==0)
        {
            fin.getline(linie,500);
            if(strstr(linie,"Indexul:"))
            {
                strcpy(linie,linie+9);
                Index=0;
                pwr=1;
                    for(int i=strlen(s)-1;i>-1;i--)
                {
                Index+=pwr*(s[i]-'0');
                pwr*=10;
                }
                pwr=1;
                cout<<"Indexul: "<<Index<<endl;
            }
            if(strstr(linie,"Tip bloc: "))
            {

                strcpy(linie,linie+10);
                if(strstr(linie,"Input")==0)
                    Type=0;
                if(strstr(linie,"If")==0)
                    Type=1;
                if(strstr(linie,"Calcul")==0)
                    Type=2;
                if(strstr(linie,"Output")==0)
                    Type=3;
                cout<<"Tip bloc: "<<Type<<endl;
            }
            if(strstr(linie,"Coordonate colt stanga sus: x="))
            {
                strcpy(linie,linie+strlen("Coordonate colt stanga sus: x="));
                upLeft.x=0;
                pwr=1;
                    for(int i=strlen(s)-1;i>-1;i--)
                {
                upLeft.x+=pwr*(s[i]-'0');
                pwr*=10;
                }
                pwr=1;
                while(s[0]!='=')
                    strcpy(s,s+1);
                upLeft.y=0;
                pwr=1;
                    for(int i=strlen(s)-1;i>-1;i--)
                {
                upLeft.y+=pwr*(s[i]-'0');
                pwr*=10;
                }
                pwr=1;
                cout<<"Coordonate colt stanga sus: x="<<upLeft.x<<" y="<<upLeft.y<<endl;
            }



            cout<<endl<<endl<<endl;
        }*/
    }
    DrawAllLines();
   // else if(overBTN(ButtonsApp[3], mouse_x, mouse_y))
           // {
           //     strcpy(typedText,"");
            //    SalvareSchema();
             //   fout.open(typedText);
             //   WriteOnFile();
             //   fout.close();
           // }
    ClicksAndBlocks();
}
void WriteOnFile()
{
    fout<<"Numar de blocuri: "<<nr_CreatedBlock<<endl;
    for(int i=0;i<nr_CreatedBlock;i++)
      {
        fout<<"Index: "<<i<<endl;
        fout<<"Tip bloc: ";
        switch(CreatedBlocks[i].CB_type)
        {
            case 0:fout<<"Input"<<endl;break;
            case 1:fout<<"If"<<endl;break;
            case 2:fout<<"Calcul"<<endl;break;
            case 3:fout<<"Output"<<endl;break;
        }
        fout<<"Coordonate colt stanga sus: x="<<CreatedBlocks[i].upLeft.x<<" y="<<CreatedBlocks[i].upLeft.y<<endl;
        fout<<"Coordonate colt dreapta sus: x="<<CreatedBlocks[i].upRight.x<<" y="<<CreatedBlocks[i].upRight.y<<endl;
        fout<<"Coordonate colt dreapta jos: x="<<CreatedBlocks[i].dwnRight.x<<" y="<<CreatedBlocks[i].dwnRight.y<<endl;
        fout<<"Coordonate colt stanga jos: x="<<CreatedBlocks[i].dwnLeft.x<<" y="<<CreatedBlocks[i].dwnLeft.y<<endl;
        bool ok=0;
        for(int j=0;j<CreatedBlocks[i].nrCircles;j++)
            if(CreatedBlocks[i].isCircleConected[j])
                ok=1;
        if(ok)
        {
            fout<<"Este conectat la blocurile cu indicii: (index cerc block curent, indicele blocului la care este conectat -> indicele cercului la care este conectat)"<<endl;
        for(int j=0;j<CreatedBlocks[i].nrCircles;j++)
            if(CreatedBlocks[i].isCircleConected[j])
                    fout<<"("<<j<<","<<CreatedBlocks[i].indexBlockConnexionTo[j]<<"->"<<CreatedBlocks[i].indexCirecleConnexionTo[j]<<")"<<"";
        fout<<endl;}
        if(CreatedBlocks[i].ConnectCircle[0].color==10)
        fout<<"Este blocul de start"<<endl;
        if(CreatedBlocks[i].ConnectCircle[1].color==4||CreatedBlocks[i].ConnectCircle[2].color==4)
        fout<<"Este bloc de stop"<<endl;
        fout<<"Textul blocului: "<<CreatedBlocks[i].inputText<<endl<<endl<<endl;
      }
}
