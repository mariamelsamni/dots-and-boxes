#include<stdio.h>
#include<stdlib.h>
#define RED "\033[1;31m"
#define BLACK "\033[1;30m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"
void color(char c[7], char text[10]){
   system("");
   printf("%s%s%s",c,text,RESET);
}
void color_int(char c[7], char text[10],int x){
   system("");
   printf("%s%s%d%s",c,text,x,RESET);
}
void color_str(char c[7], char text[10],char x[10]){
   system("");
   printf("%s%s%s%s",c,text,x,RESET);
}
void color_char(char c[7], char text){
   system("");
   printf("%s%c %s",c,text,RESET);
}
int scan_int(char s[])
{  int a;int len;
        gets(s);
        len=strlen(s);
        if(len==1 && isdigit(s[0]))
           {
              a=s[0]-48;
           }
        else
         {
             a=0;
         }
return a;
}

void GetNames (char p1[10],char p2[10])
{

    color(RED,"\n\n\n\n\n\n\t ENTER THE NAME OF THE FIRST PLAYER:");
    printf(RED);gets(p1);printf(RESET);
    color(BLUE,"\n\n\t ENTER THE NAME OF THE SECOND PLAYER:");
    printf(BLUE);gets(p2);printf(RESET);
    system("cls");

}
void getTime (int timeOfBeginning,int timehrsMinSec[])
{
    int timer;
    time_t timenow=time(0);
    timer= timenow-timeOfBeginning;
    int hours=0,minutes=0,seconds=0;
    minutes=timer/60;
    seconds=timer-60*minutes;
    if (minutes>59)
    {
        hours=minutes/60;
        minutes=minutes-60*hours;
    }

     timehrsMinSec[0]=hours;
     timehrsMinSec[1]=minutes;
     timehrsMinSec[2]=seconds;

}
void twoplayersNames(int x)
{char name1[10],name2[10];
 GetNames(name1,name2);
 twoplayers(name1,name2,x);
  /* switch(x)
   {
    case(2):
        twoplayersx3(name1,name2);
    case(3):
        twoplayersx5(name1,name2);
    }*/
}

void negative_one(int A[][2],int m)
{
    for (int i=0;i<m;i++)
    {
        A[i][0]=-1;
        A[i][1]=-1;
    }
}
void zeros(int m ,int A[m])
{
    for (int i=0;i<m;i++)
    {
        A[i]=0;
    }
}

void oneplayerName(int x)
{
    char name[10];
    GetName(name);
    oneplayerx3(name,x);
}
void GetName (char p1[10])
{
    color(RED,"\n\n\n\n\n\n\t ENTER THE NAME OF THE PLAYER:");
    printf(RED);gets(p1);printf(RESET);
    system("cls");
}

void initialize_grid(int m,char A[m][m])
{   int i,j; char k=49;
    A[0][0]=32;
    for (i=1;i<m;i++)
    {
        A[0][i]=k;
        A[i][0]=k++;
    }

    for(i=1;i<m;i++)
    {
        for(j=1;j<m;j++)
        {
             if(i%2==0)
            {
               A[i][j]=32;
            }
            else if(i%2==1)
            {
                if(j%2==0)
                    A[i][j]=32;
                else
                    A[i][j]=254;
            }
        }
    }
    return;
}

int choose_file(char c)
{
    char s[10]; int x;
    color(PURPLE,"\n 1 for file 1 \n 2 for file 2 \n 3 for file 3");
    printf("\nenter the number");x=scan_int(s);
    return x;

}

void save (FILE *file,int m,int player1[m][2],int player2[m][2])
{
    file=fopen("file.txt","w");
    for(int i=0;i<m;i++)
    {
        fprintf(file ,"%d %d ",player1[i][0],player1[i][1]);
    }

    for(int i=0;i<m;i++)
    {
        fprintf(file ,"%d %d ",player2[i][0],player2[i][1]);
    }
    fclose(file);

}
void continue_fn(FILE *file,int m,int player1[m][2],int player2[m][2])
{
    file=fopen("file.txt","r");
    for(int i=0;i<m;i++)
    {
        fscanf(file ,"%d %d ",&player1[i][0],&player1[i][1]);
    }
    for(int i=0;i<m;i++)
    {
        fscanf(file ,"%d %d ",&player2[i][0],&player2[i][1]);
    }
    fclose(file);
}


void check_boxes(int player1[40][2],int player2[40][2],int noOfboxes,int boxes[noOfboxes],int maxi, int indwin[4],int maxturns)
{  int k=0,box=0,colwin=2,rowwin=2,i,j,M,found1=0,found2=0;
    while(k<maxturns && (player1[k][0]!=-1 || player1[k][0]!=-1 || player2[k][0]!=-1 || player2[k][0]!=-1))
    {   rowwin=2; box=0;
        for ( i=0;i<maxi;i+=2)
        {   colwin=2;
            for( j=0;j<maxi;j+=2)
            {
                if(i<player1[k][0] && player1[k][0]<(i+4) && j<player1[k][1] && player1[k][1]<(j+4)  || i<player2[k][0] && player2[k][0]<(i+4) && j<player2[k][1] && player2[k][1]<(j+4) )
                {

                     if( i<player1[k][0] && player1[k][0]<(i+4) && j<player1[k][1] && player1[k][1]<(j+4) && (player1[k][0]%2!=0 || player1[k][1]%2!=0) )
                    {
                        boxes[box]++;
                        if(boxes[box]==4)
                        {   found1=0; M=0;
                            while ( M<maxturns && (player1[k][0]!=-1 || player1[k][0]!=-1) )
                            {
                                if (player1[M][0]==rowwin && player1[M][1]==colwin)
                                {
                                   found1=1;
                                   break;
                                }
                            M++;
                            }
                            if (found1==0)
                            {
                               player1[indwin[0]][0]=rowwin;
                               player1[indwin[0]++][1]=colwin;
                               player2[indwin[1]][0]=-1;
                               player2[indwin[1]++][1]=0;
                            }


                        indwin[2]++;
                        }
                    }
                    else if ( i<player2[k][0] && player2[k][0]<(i+4) && j<player2[k][1] && player2[k][1]<(j+4) && ( player2[k][0]%2!=0 || player2[k][1]%2!=0 ) )
                    {
                        boxes[box]++;
                        if(boxes[box]==4)
                        {   found2=0; M=0;
                            while (M<maxturns && (player2[k][0]!=-1 || player2[k][0]!=-1) )
                            {
                                if (player2[M][0]==rowwin && player2[M][1]==colwin)
                                {
                                    found2=1;
                                    break;
                                }
                            M++;
                            }
                            if (found2==0)
                            {
                                player1[indwin[0]][0]=-1;
                                player1[indwin[0]++][1]=0;
                                player2[indwin[1]][0]=rowwin;
                                player2[indwin[1]++][1]=colwin;
                            }
                        indwin[3]++;
                        }
                    }
                }
            box++;
            colwin+=2;
            }
        rowwin+=2;
        }
     k++;
    }
}


