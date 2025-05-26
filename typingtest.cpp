#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
void loader();
void statistics();
void mainscreen();
void getright(char,char *);
void takeinput(char *);
int askexit();
void paratext(int );
void timertext(int );
int m,area,flag=0,timer_t,loader_flag=0;
int ntime=0,atime=0,etime=0;
int maxx,maxy,midx,midy,status,option,level,length=0,i,tm;
float right=0,attempt=0,word=1;
long double start_t,end_t,total_t;
char choice;
char *p;
void loader()
{
    int x;
void printscr(char *);

    start_t=time(NULL);
    setcolor(YELLOW);
    settextstyle(0,0,4);
    outtextxy(midx-160,0,"WELCOME TO");
    settextstyle(10,0,9);
    setcolor(RED);
    outtextxy(0,40,"TYPING");
    setcolor(GREEN);
    outtextxy(64*6,40,"TEST");
    setcolor(LIGHTBLUE);
    settextstyle(0,0,3);
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    outtextxy(0,150,"Loading:");
    for(x=0;x<=570;x+=5)
    {
        bar(x,190,x+5,220);
        delay(30);
    }
    loader_flag=1;
}
int main()
{
int gd=DETECT,gm;
initwindow(640,480);
maxx=getmaxx();
maxy=getmaxy();
midx=maxx/2;
midy=maxy/2;
if(loader_flag==0)
    loader();
mainscreen();
srand(time(NULL));
if(status==0)
    paratext(level);
if(status==1)
    timertext(level);
return 0;
}
void mainscreen()
{
    cleardevice();
setcolor(RED);
settextstyle(10,0,10);
outtextxy(80,0,"TYPING");
setcolor(GREEN);
outtextxy(160,100,"TEST");
setcolor(MAGENTA);
rectangle(10,240,210,280);
rectangle(220,240,420,280);
rectangle(430,240,630,280);
settextstyle(10,0,3);
outtextxy(12,242,"PARAGRAPH[P]");
outtextxy(242,242,"TIMER[T]");
outtextxy(455,242,"EXIT[E]");
options:
choice=0;
fflush(stdin);
choice=getch();
Beep(1200,300);
while(!(choice=='e' || choice=='E' ||choice=='p' || choice=='P' || choice=='t' || choice=='T'))
{
Beep(1200,300);
    fflush(stdin);
    choice=getch();
}
if(choice=='e' || choice=='E')
{
flag=askexit();
if(flag==1)
    goto options;
}
if(choice=='p' || choice=='P')
{
    status=0;
    setcolor(GREEN);
    settextstyle(10,0,1);
    rectangle(10,281,210,301);
    outtextxy(15,283,"NOVOICE[N]");
        setcolor(YELLOW);
        rectangle(10,304,210,324);
        outtextxy(15,306,"ADVANCED[A]");
        setcolor(RED);
        rectangle(10,327,210,346);
        outtextxy(15,328,"EXPERT[E]");

}
if(choice=='t'||choice=='T')
{
   status=1;
setcolor(GREEN);
settextstyle(10,0,1);
rectangle(220,283,420,303);
outtextxy(225,285,"NOVOICE[N]");
setcolor(YELLOW);
rectangle(220,306,420,326);
outtextxy(225,308,"ADVANCED[A]");
setcolor(RED);
rectangle(220,329,420,349);
outtextxy(225,331,"EXPERT[E]");

}
fflush(stdin);
choice=getch();
Beep(1200,300);
while(!(choice=='e' || choice=='E' || choice=='n' || choice=='N' || choice=='A' || choice=='a'))
{
Beep(1200,300);
    fflush(stdin);
    choice=getch();
}
if(choice=='n' || choice=='N')
    level=1;
if(choice=='a' || choice=='A')
    level=2;
if(choice=='e' || choice=='E')
    level=3;
    cleardevice();
setlinestyle(2,0,2);
setcolor(MAGENTA);
line(0,225,maxx,225);
line(0,maxy-225,maxx,maxy-225);
setcolor(RED);
settextstyle(10,0,3);
outtextxy(midx-96,226,"TYPING");
setcolor(GREEN);
outtextxy(midx,226,"TEST");
setcolor(YELLOW);
settextstyle(10,0,1);
outtextxy(0,226,"<-\" To Surrender...");
setcolor(CYAN);
setlinestyle(0,0,1);
rectangle(maxx-105,228,maxx-20,248);


}
int askexit()
{

char *ptr;
char buff[35];
area=imagesize(midx-161,midy-21,midx+161,midy+21);
ptr=(char *)malloc(area);
getimage(midx-161,midy-21,midx+161,midy+21,ptr);
setviewport(midx-160,midy-20,midx+160,midy+20,1);
clearviewport();
setviewport(0,0,maxx,maxy,1);
setcolor(YELLOW);
settextstyle(10,0,2);
setlinestyle(0,0,3);
rectangle(midx-160,midy-20,midx+160,midy+20);
outtextxy(midx-155,midy-19,"Do You really want to EXIT");
setcolor(GREEN);
outtextxy(midx-100,midy-2,"NO[N]");
setcolor(RED);
outtextxy(midx+20,midy-2,"YES[Y]");
fflush(stdin);
choice=getch();
Beep(1200,300);
while(!(choice=='y'|| choice=='Y' || choice=='n'|| choice=='N'))
{
    Beep(1200,300);
    fflush(stdin);
    choice=getch();
}
if(choice=='y'||choice=='Y')
{
    end_t=time(NULL);
    total_t=end_t-start_t;
    putimage(midx-161,midy-21,ptr,COPY_PUT);
setviewport(midx-285,midy-20,midx+250,midy+20,1);
clearviewport();
setviewport(0,0,maxx,maxy,1);
setcolor(LIGHTBLUE);
setlinestyle(0,0,3);
settextstyle(0,0,2);
rectangle(midx-284,midy-19,midx+249,midy+19);
outtextxy(midx-230,midy-17,"Thanks for using TYPING TEST");
sprintf(buff,"You were here from %2d mins & %2d secs",(int)total_t/60,(int)total_t%60);
outtextxy(midx-260,midy,buff);
delay(5000);
    closegraph();
    restorecrtmode();
    exit(0);
}
if(choice=='n'||choice=='N')
{
    putimage(midx-161,midy-21,ptr,COPY_PUT);
    return 1;
}
}

void takeinput(char *text)
{
    int cx=0,cy=maxy-224;
    length=strlen(text);
    long startime,endtime,tm;
    char buffer[2];
    char timembuff[6];
    char ch;
    word=1;
    right=0;
    attempt=0;
    startime=time(NULL);
    for(i=0;i<length;i++)
    {
        input:
        fflush(stdin);
        ch=getch();
        if(ch==32)
            word++;
        endtime=time(NULL);
        if(status==1)
        {
          if(level==1)
          {
                ntime=length;
            timer_t=ntime-(endtime-startime);
          }
            if(level==2)
            {
                atime=length/2;
                timer_t=atime-(endtime-startime);
            }
         if(level==3)
         {
             etime=length/3;
                timer_t=etime-(endtime-startime);
         }
        }
        else
        timer_t=endtime-startime;

        sprintf(timembuff,"%6ds",timer_t);
        setviewport(maxx-102,229,maxx-23,247,1);
        clearviewport();
        setviewport(0,0,maxx,maxy,1);
        setcolor(CYAN);
        settextstyle(10,0,1);
        outtextxy(maxx-102,229,timembuff);
        if(ch=='\r')
        {
            Beep(1500,300);
        break;
        }
        sprintf(buffer,"%c",ch);
        getright(ch,text);
        settextstyle(10,0,1);
        outtextxy(cx,cy,buffer);
        cx+=16;
        if(cx==640)
        {

            cy=cy+16;
            cx=0;
        }
        setcolor(BLUE);
        setlinestyle(0,0,1);
        rectangle(maxx-177,226,maxx-150,251);
        settextstyle(0,0,3);
        outtextxy(maxx-175,226,buffer);
        if(status==1 && timer_t<=0)
        {
        switch(level)
        {
        case 1:
                area=imagesize(midx-120,midy-30,midx+120,midy+30);
                p=(char *)malloc(area);
                getimage(midx-120,midy-30,midx+120,midy+30,p);
                setcolor(RED);
                setlinestyle(0,0,3);
                settextstyle(10,0,4);
                setviewport(midx-120,midy-30,midx+120,midy+30,1);
                clearviewport();
                setviewport(0,0,maxx,maxy,1);
                rectangle(midx-119,midy-29,midx+119,midy+29);
                outtextxy(midx-70,midy-28,"TIME OUT");
                outtextxy(midx-80,midy-4,"TRY AGAIN");
                Beep(1000,500);
                delay(5000);
                putimage(midx-120,midy-30,p,COPY_PUT);
                goto out;
        case 2:
                area=imagesize(midx-120,midy-30,midx+120,midy+30);
                p=(char *)malloc(area);
                getimage(midx-120,midy-30,midx+120,midy+30,p);
                setcolor(RED);
                setlinestyle(0,0,3);
                settextstyle(10,0,4);
                setviewport(midx-120,midy-30,midx+120,midy+30,1);
                clearviewport();
                setviewport(0,0,maxx,maxy,1);
                rectangle(midx-119,midy-29,midx+119,midy+29);
                outtextxy(midx-70,midy-28,"TIME OUT");
                outtextxy(midx-80,midy-4,"TRY AGAIN");
                Beep(1000,500);
                delay(5000);
                putimage(midx-120,midy-30,p,COPY_PUT);
                goto out;
        case 3:
                area=imagesize(midx-120,midy-30,midx+120,midy+30);
                p=(char *)malloc(area);
                getimage(midx-120,midy-30,midx+120,midy+30,p);
                setcolor(RED);
                setlinestyle(0,0,3);
                settextstyle(10,0,4);
                setviewport(midx-120,midy-30,midx+120,midy+30,1);
                clearviewport();
                setviewport(0,0,maxx,maxy,1);
                rectangle(midx-119,midy-29,midx+119,midy+29);
                outtextxy(midx-70,midy-28,"TIME OUT");
                outtextxy(midx-80,midy-4,"TRY AGAIN");
                Beep(1000,500);
                delay(5000);
                putimage(midx-120,midy-30,p,COPY_PUT);
                goto out;
        }
        }

    }
    out:
    attempt=i;
    if(attempt==0)
        right=0;
    tm=endtime-startime;
    area=imagesize(0,227,maxx,252);
    p=(char *)malloc(area);
    getimage(0,227,maxx,252,p);
    setlinestyle(2,0,2);
    setcolor(MAGENTA);
    setviewport(0,227,maxx,252,1);
    clearviewport();
    setviewport(0,0,maxx,maxy,1);
    line(midx-65,225,midx-65,254);
    line(midx+65,225,midx+65,254);
    settextstyle(10,0,3);
    setcolor(RED);
    outtextxy(midx-47,228,"EXIT[E]");
    setcolor(GREEN);
    outtextxy(midx-220,228,"RESTART[R]");
    setcolor(BLUE);
    outtextxy(midx+75,228,"STATISTICS[S]");
    fflush(stdin);
    choice=getch();
    Beep(1200,300);
    while(!(choice=='e' || choice=='E' || choice=='r' || choice=='R' || choice=='s' || choice=='S'))
    {
        Beep(1200,300);
        fflush(stdin);
        choice=getch();
    }
    if(choice=='r'||choice=='R')
        main();
    if(choice=='s'|| choice=='R')
        statistics();
    if(choice=='e'||choice=='E')
        flag=askexit();
        if(flag==1)
        {
            putimage(0,227,p,COPY_PUT);
            goto input;
        }
}
void printscr(char *str)
{
    int x=0,y=0;
    length=strlen(str);
    char ch,strchar[1];
    setcolor(LIGHTMAGENTA);
    settextstyle(10,0,1);
    for(i=0;i<length;i++)
    {

        ch=str[i];
        sprintf(strchar,"%c",ch);
        outtextxy(x,y,strchar);
            x=x+16;
         if(x==640)
        {
            y=y+16;
            x=0;
        }
    }
}
void getright(char ch,char *text)
{
    if(ch==*(text+i))
    {
        right++;
        setcolor(LIGHTBLUE);
    }
    else
        setcolor(RED);
}
void statistics()
{

    int x=0,y=0;
    float accuracy=0;
    cleardevice();
    char buff[10];
    setcolor(RED);
    settextstyle(10,0,3);
    outtextxy(maxx-160,0,"TYPING");
    setcolor(GREEN);
    outtextxy(maxx-64,0,"TEST");
    setcolor(BLUE);
    settextstyle(10,0,3);
    setlinestyle(0,0,2);
    outtextxy(midx-96,16,"\"STATISTICS\"");
    line(0,40,maxx,40);
    accuracy=right/attempt*100;
    settextstyle(10,0,4);
    setcolor(GREEN);
    outtextxy(0,42,"Accuracy:-");
setcolor(YELLOW);
setlinestyle(0,0,1);
rectangle(0,80,410,110);
setcolor(GREEN);
setlinestyle(0,0,1);
if(accuracy==0)
{
setfillstyle(SOLID_FILL,RED);
    bar(5,85,405,105);
}
else
{
for(x=5,y=85;x<=accuracy*4;x++)
    line(x,y,x,y+20);
}
settextstyle(0,0,3);
sprintf(buff,"%0.1f%%",accuracy);
outtextxy(415,83,buff);
//making boundries
setcolor(YELLOW);
setlinestyle(3,0,3);
line(315,115,315,325);
line(0,325,maxx,325);
setlinestyle(0,0,1);
setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
pieslice(160,200,0,attempt/length*360,75);
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
pieslice(160,200,attempt/length*360,0,75);
setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
pieslice(480,200,0,right/attempt*360,75);
if((attempt-right)!=0){
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
pieslice(480,200,right/attempt*360,0,75);}
setfillstyle(SOLID_FILL,GREEN);
bar(5,290,20,305);
bar(325,290,340,305);
settextstyle(10,0,1);
setcolor(GREEN);
sprintf(buff,"Attempt=%0.0f",attempt);
outtextxy(20,291,buff);
sprintf(buff,"Right=%0.0f",right);
outtextxy(341,290,buff);
setfillstyle(SOLID_FILL,RED);
setcolor(RED);
bar(165,290,180,305);
bar(485,290,500,305);
sprintf(buff,"left=%0.0f",length-attempt);
outtextxy(181,290,buff);
sprintf(buff,"Wrong=%0.0f",attempt-right);
outtextxy(501,290,buff);
sprintf(buff,"Total Length=%d chars",length);
setcolor(MAGENTA);
settextstyle(10,0,4);
outtextxy(0,340,buff);
setcolor(LIGHTMAGENTA);
sprintf(buff,"words Attempted=%0.0f",word);
outtextxy(0,372,buff);
setcolor(BROWN);
sprintf(buff,"Time taken=%d secs",tm);
outtextxy(0,404,buff);
setcolor(GREEN);
if(tm>=60)
{
    sprintf(buff,"Speed=%0.0f words/minute",word/(float)(tm/60));
    outtextxy(0,436,buff);
}
else if(tm<60)
{
    sprintf(buff,"Speed=%0.1f chars/sec",attempt/(float)tm);
    outtextxy(0,436,buff);
}

setcolor(RED);
settextstyle(10,0,2);
outtextxy(0,maxy-16,"Press ENTER to continue...");
statopt:
    fflush(stdin);
choice=getch();
Beep(1200,300);
while(!(choice=='\r'))
{
    fflush(stdin);
    choice=getch();
    Beep(1200,300);
}
area=imagesize(midx-200,midy-15,midx+200,midy+15);
p=(char *)malloc(area);
getimage(midx-200,midy-15,midx+200,midy+15,p);
setviewport(midx-200,midy-15,midx+200,midy+15,1);
clearviewport();
setviewport(0,0,maxx,maxy,1);
setcolor(CYAN);
setlinestyle(0,0,2);
rectangle(midx-199,midy-14,midx+199,midy+14);
settextstyle(10,0,3);
setcolor(GREEN);
outtextxy(midx-160,228,"RESTART[R]");
setcolor(RED);
outtextxy(midx+40,228,"EXIT[E]");
fflush(stdin);
choice=getch();
Beep(1200,300);
while(!(choice=='r'||choice=='R'|| choice=='e' || choice=='E'))
{

    fflush(stdin);
    choice=getch();
    Beep(1200,300);
}

if(choice=='r' || choice=='R')
    main();
if(choice=='e'||choice=='E')
    flag=askexit();
    if(flag==1)
    {
        putimage(midx-200,midy-15,p,COPY_PUT);
        goto statopt;
    }
}
void paratext(int level)
{
    int random;
    switch(level)
    {
    case 1:
        random=rand()%2;
    switch(random)
    {

  case 0:
        char strn0[]="hello my name is typing test.I am developed by Sharique.I am a type of software,basically a utility software to increase your productivity in English typing and practicing you to improve your typing skill.";
printscr(strn0);
                 takeinput(strn0);
       return ;
    }
  case 1:
      random=rand()%1;
      switch(random)
      {

      case 0:
 char stra0[]="hello my name is typing test.I am developed by Sharique.I am a type of software,basically a utility software to increase your productivity in English typing and practicing you to improve your typing skill.";
printscr(stra0);
                 takeinput(stra0);
return;
      }
      case 3:
        random=rand()%1;
        switch(random)
        {
            case 0:
           char stre0[]="hello my name is typing test.I am developed by Sharique.I am a type of software,basically a utility software to increase your productivity in English typing and practicing you to improve your typing skill.";
printscr(stre0);
                 takeinput(stre0);
            return;
        }
    }
}
void timertext(int level)
{
    int random;
    switch(level)
    {
    case 1:
        random=rand()%1;
    switch(random)
    {

  case 0:
        char strn0[]="hello my name is typing test.I am developed by Sharique.I am a type of software,basically a utility software to increase your productivity in English typing and practicing you to improve your typing skill.";
printscr(strn0);
                 takeinput(strn0);
       return;

    }
  case 2:
      random=rand()%1;
      switch(random)
      {

      case 0:
char stra0[]="hello my name is typing test.I am developed by Sharique.I am a type of software,basically a utility software to increase your productivity in English typing and practicing you to improve your typing skill.";
printscr(stra0);
                 takeinput(stra0);
return;
      }
      case 3:
        random=rand()%1;
        switch(random)
        {
            case 0:
             char stre0[]="hello my name is typing test.I am developed by Sharique.I am a type of software,basically a utility software to increase your productivity in English typing and practicing you to improve your typing skill.";
printscr(stre0);
                 takeinput(stre0);
            return;
        }
    }
}

