#ifdef __APPLE__
#else
#endif
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<bits/stdc++.h>
#include <time.h>
#include<stdlib.h>
using namespace std;
//physical and logical widths and heights
int phyWidth = 700;
int phyHeight = 700;
int logWidth = 100;
int logHeight = 100;
//storing mouse location
int mouseXX;
int mouseYY;
//squares in main menu
int sqwidth=20;
int sqhight=5;
//squares in the game
int sqwidth_=10;
int sqhight_=30;
//centers of the boxes in the main menu
int centerXplay=50;
int centerYplay=75;
int centerXHS=50;
int centerYHS=50;
int centerXQ=50;
int centerYQ=25;
//bool sqUp=true;//square direction
int sqDelta=0;
//int maxY=22;
//saving value entered by user
char str[10000];
char Newstr[2];
int number1,number2;//the two numbers in the equation
char operatorr;
char equ[50];//array of 50 equations
int check_answer=0;
int step=0;
int score=0;
int status=0;
int flag=0;
bool fileFlag = 1;
bool fflag=true;
char str_score[50];
int scoresize = 5;
int array_scores[5];
int Rank = 0;
char ra[50];
char strr[20];
char H_SCO[10];
typedef struct Square{
    int cx;
    int cy;
    int sqhight;
    int sqwidth;
    char arithmetic_op[50];
}Square;
typedef struct ans{
    int ans;
    bool state_ans;
}ans;
ans result_mo3dlat[50];
Square sq[50];
void init2D(float r, float g, float b)
{
    glClearColor(r,g,b,0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, logWidth, 0.0, logHeight);
}
void printSome(char *str,int x,int y)
{
    glRasterPos2d(x,y);//get logical location
    int len = strlen(str);
    for (int i=0;i<len;i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str[i]);//draw a char
    glFlush();
}
void Timer(int value)
{
    glutTimerFunc(200, Timer, value);
    glutPostRedisplay();
}
void Timer2(int value)
{
            status=4;
}
void Timer3(int value)
{
    glutTimerFunc(60000, Timer2, value);

}
void Keyboard(unsigned char key, int x, int y)
{
     if(key == (char)13)
     {
        check_answer=atoi(str);
        strcpy(str,"");
     }
     else
     {
         Newstr[0]=key;
        strcat(str,Newstr);
     }
}
void speacial_keyboard(int key,int x,int y)
{
    if(key == GLUT_KEY_F1)
    {
        flag=0;
        status=1;
    }
    else if(key == GLUT_KEY_F2)
        status=0;
}
void mouseClick(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
     //physical location to logical location
     mouseXX = x;
     mouseXX=0.5+1.0*mouseXX*logWidth/phyWidth;
     //y is reversed
     mouseYY = phyHeight- y;
     mouseYY=0.5+1.0*mouseYY*logHeight/phyHeight;
     if( mouseXX>=(centerXplay-sqhight/2) && mouseXX<=(centerXplay+sqhight/2) && mouseYY >=(centerYplay-sqwidth/2) && mouseYY <=(centerYplay+sqwidth/2))
     {
        status=1;
     }
     if( mouseXX>=(centerXHS-sqhight/2) && mouseXX<=(centerXHS+sqhight/2) && mouseYY >=(centerYHS-sqwidth/2) && mouseYY <=(centerYHS+sqwidth/2))
     {
        status=2;
     }
     if( mouseXX>=(centerXQ-sqhight/2) && mouseXX<=(centerXQ+sqhight/2) && mouseYY >=(centerYQ-sqwidth/2) && mouseYY <=(centerYQ+sqwidth/2))
     {
        status=3;
     }
    }
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
     status=0;
    }
     glutPostRedisplay();
    }
void check()
{
    if(check_answer == result_mo3dlat[step].ans && result_mo3dlat[step].state_ans==0)
    {
        result_mo3dlat[step].state_ans=1;
        score++;
    }
    /*else if(check_answer == result_mo3dlat[step+1].ans && result_mo3dlat[step+1].state_ans==0)
    {
        result_mo3dlat[step+1].state_ans=1;
        score++;
    }
    else if(check_answer == result_mo3dlat[step+2].ans && result_mo3dlat[step+2].state_ans==0)
    {
        result_mo3dlat[step+2].state_ans=1;
        score++;
    }*/
    check_answer = 10000;
}
void BG()
{
    glColor3f(1.0, 1.0, 1.0);
    for(int j = 0; j<5 ; j++){
        for(int i = 0; i<10 ; i++){
    glBegin(GL_POLYGON);
    glVertex2i(10+j*20+10,100-i*10);
    glVertex2i(0+j*20+10,90-i*10);
    glVertex2i(10+j*20+10,90-i*10);
    glEnd();
    }
    }
}
void drawSquares()
   {
glColor3f(1.0,0.0,0.0);
    printSome("MATH HERO",45,98);
     glEnd();
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex2f(centerXplay-sqwidth/2, centerYplay-sqhight/2);
glVertex2f(centerXplay+sqwidth/2, centerYplay-sqhight/2);
glVertex2f(centerXplay+sqwidth/2, centerYplay+sqhight/2);
glVertex2f(centerXplay-sqwidth/2, centerYplay+sqhight/2);
glEnd();
glColor3f(1.0,1.0,1.0);
    printSome("PLAY",47.5,75);
     glEnd();
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex2f(centerXHS-sqwidth/2, centerYHS-sqhight/2);
glVertex2f(centerXHS+sqwidth/2, centerYHS-sqhight/2);
glVertex2f(centerXHS+sqwidth/2, centerYHS+sqhight/2);
glVertex2f(centerXHS-sqwidth/2, centerYHS+sqhight/2);
glEnd();
glColor3f(1.0,1.0,1.0);
    printSome("HIGH SCORE",44,50);
     glEnd();
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex2f(centerXQ-sqwidth/2, centerYQ-sqhight/2);
glVertex2f(centerXQ+sqwidth/2, centerYQ-sqhight/2);
glVertex2f(centerXQ+sqwidth/2, centerYQ+sqhight/2);
glVertex2f(centerXQ-sqwidth/2, centerYQ+sqhight/2);
glEnd();
glColor3f(1.0,1.0,1.0);
    printSome("QUIT",48,25);
     glEnd();
}
void drawSquares_2(Square sq,int cx,int cy)
{
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(cx-sqhight_/2, cy-sqwidth_/2+sqDelta);
    glVertex2f(cx+sqhight_/2, cy-sqwidth_/2+sqDelta);
    glVertex2f(cx+sqhight_/2, cy+sqwidth_/2+sqDelta);
    glVertex2f(cx-sqhight_/2, cy+sqwidth_/2+sqDelta);
    glEnd();

    int len=strlen(sq.arithmetic_op);
    glColor3f(1,1,1);
    printSome(sq.arithmetic_op,cx-len+2,(cy-1)+sqDelta);
    glEnd();
}
void desc_sort(int a[10], int n)
{
 int i, j, temp;
 for(i=0;i< n-1;i++)
 {
  for(j=i+1;j< n;j++)
  {
   if(a[i]< a[j])
   {
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
   }
  }
 }
}
void mo3dlat(int index,char *equ,int number1,int number2,char operatorr){

    result_mo3dlat[index].state_ans=0;

    if(operatorr == '+')
    {
        result_mo3dlat[index].ans=number1+number2;
    }
    else if(operatorr == '-')
    {
        result_mo3dlat[index].ans=number1-number2;
    }
    else if(operatorr == '*')
    {
        result_mo3dlat[index].ans=number1*number2;
    }
    sprintf(equ,"%d %c %d",number1,operatorr,number2);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //drawSquares();
    glClear(GL_COLOR_BUFFER_BIT);

                if(status==0)
                {

                        score=0;
                        glClearColor(0,0,0,0);
                        BG();
                        drawSquares();
                }
                else if(status==1)

            {
                if(flag==0)
                {
                    Timer3(0);
                    step=0;
                    int s=0;//spacing between each box
                    char arr[3]={'+','-','*'};//array of possible operators
                    for(int i=0;i<50;i++)
                    {
                        sq[i].cx=50;
                        sq[i].cy=80-s;
                        sq[i].sqhight=sqhight;
                        sq[i].sqwidth=sqwidth;
                        number1=rand()%4;
                        number2=rand()%4;
                        operatorr=arr[rand()%3];
                        mo3dlat(i,equ,number1,number2,operatorr);
                        strcpy(sq[i].arithmetic_op,equ);
                        s=s+40;
                    }
                    flag=1;
                    sqDelta=0;
                    score=0;
                    check_answer = 100000;
                }
    BG();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(50,60);
    glVertex2i(60,60);
    glVertex2i(60,70);
    glEnd();
                for(int i=0;i<50;i++)
                {
                    drawSquares_2(sq[i],sq[i].cx,sq[i].cy);
                }

                sqDelta++;

                if(sq[step].cy+sqDelta >100)
                {
                    step++;
                }

                check();

                glColor3f(1,0,0); //
                sprintf(str_score,"Score : %d",score);
                printSome(str_score,5,85);
                glEnd();
                //if (abs(sqDelta)>maxY) sqUp=!sqUp ;
                //if (sqUp) sqDelta+=1; //else sqDelta-=1;}
            }


            else if(status==2)
            {
                glColor3f(1.0,1.0,1.0);
                printSome("HIGHSCORES",40,90);
                glEnd();


                if(fileFlag)
                {
                    int i = 0;
                    FILE *scores = fopen("C:\\Users\\Sebaiexx\\Desktop\\scores.txt","r");
                    while(~fscanf(scores,"%d",&array_scores[i])){i++;}
                    fclose(scores);

                    scoresize = i;

                    desc_sort(array_scores,i);

                    fileFlag = 0;
                }

                glColor3f(1.0,1.0,1.0);
                sprintf(H_SCO,"  %d",array_scores[0]);
                glColor3f(1,1,1);
                printSome("1 -",5,70);
                printSome(H_SCO,10,70);
                sprintf(H_SCO,"  %d",array_scores[1]);
                printSome("2 -",5,60);
                printSome(H_SCO,10,60);
                sprintf(H_SCO,"  %d",array_scores[2]);
                printSome("3 -",5,50);
                printSome(H_SCO,10,50);
                sprintf(H_SCO,"  %d",array_scores[3]);
                printSome("4 -",5,40);
                printSome(H_SCO,10,40);
                sprintf(H_SCO,"  %d",array_scores[4]);
                printSome("5 -",5,30);
                printSome(H_SCO,10,30);
            }

            else if(status==3)
            {
                exit(1);
            }

            else if(status==4)
            {
                int i=0;
                FILE *scores = fopen("C:\\Users\\Sebaiexx\\Desktop\\scores.txt","r");
                    while(~fscanf(scores,"%d",&array_scores[i])){i++;}
                    fclose(scores);

                    scoresize = i;


                    desc_sort(array_scores,i);
                    //sort(array_scores, array_scores+scoresize);

                     Rank = upper_bound(array_scores, array_scores+scoresize, score) - array_scores;
                     Rank = scoresize - Rank +1;

                 glClearColor(0,0,0,0);
                 glColor3f(1,1,1);
                 sprintf(strr,"Your Score : %d",score);
                 printSome(strr,30,65);
                 sprintf(ra,"Your Rank is : %d",Rank);
                 printSome(ra,30,35);

                 glEnd();


                if(fflag)
                {
                     FILE *file = fopen("C:\\Users\\Sebaiexx\\Desktop\\scores.txt","a");
                     fprintf(file,"%d\n",score);
                     fclose(file);

                    int i = 0;

                    file = fopen("C:\\Users\\Sebaiexx\\Desktop\\scores.txt","r");
                     while(~fscanf(file,"%d",&array_scores[i])){i++;}
                     fclose(file);
                     fflag=false;
                }
            }
        glEnd();
        glutSwapBuffers();
        glFlush();
    }
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition (logWidth, logHeight);
    glutInitWindowSize (phyWidth , phyHeight);
    glutCreateWindow ("Math Hero");
    init2D(0.0,0.0,0.0);
    glutDisplayFunc(display);
    Timer(0);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(speacial_keyboard);
    glutMouseFunc(mouseClick);
    glutMainLoop();
}
