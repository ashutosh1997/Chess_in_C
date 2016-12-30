/* GAME OF CHESS USING COMPUTER GRAPHICS AND DATA STRUCTURES IN C
   MADE BY :
   ASHUTOSH KUMAR
   ROLL NO: 02720902714
   C.S.E.- 3RD SEMESTER */

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#define R(a) (int)(a+0.5)

int A[10][10]={0};
union REGS in,out;
/*int initmouse()
{
   in.x.ax=0;
   int86(0X33,&in,&out);
   return (out.x.ax );
}*/

/*To show mouse pointer */
void showmouseptr()
{
   in.x.ax=1;
   int86(0X33,&in,&out);
}

/*To hide mouse pointer */
void mousehide()
{
   in.x.ax=2;
   int86(0X33,&in,&out);
}

/*To get current mouse position*/
void getmousepos(int *button, int *x, int *y)
{
   in.x.ax=3;
   int86(0X33,&in,&out);
   *button=out.x.bx;
   *x=out.x.cx;
   *y=out.x.dx;
}

/*Function to clear the Array */
void cleararray(int A[10][10])
{
	int i,j;
	for(i=1;i<=8;i++)
	for(j=1;j<=8;j++)
	A[i][j]=0;
}

/*Function to Draw Line using DDL Algorithm */
void line1(int xa,int ya,int xb,int yb,int c)
{
	int dx,dy,x,y,i,steps,xi,yi;
	dx=xb-xa;
	dy=yb-ya;
	x=xa;
	y=ya;
	if(abs(dx)>abs(dy))
	{
		steps=abs(dx);
	}
	else
	{
		steps=abs(dy);
	}
	xi=dx/(float)steps;
	yi=dy/(float)steps;
	putpixel (R(x),R(y),c);
	for(i=0;i<steps;i++)
	{
		x=x+xi;
		y=y+yi;
		putpixel (R(x),R(y),c);
	}
}

/*Function to draw circle using Bresenham Circle algorithm */
void circle1(int xc,int yc,int r,int c)
{
	int x,y,dx,dy,d;
	putpixel(xc,yc+r,c);
	putpixel(xc,yc-r,c);
	putpixel(xc+r,yc,c);
	putpixel(xc-r,yc,c);
	x=0;
	y=r;
	d=3-2*r;
	while(x<y)
	{
		x++;
		if(d<0)
		{
			d=d+4*x+6;
		}
		else if(d>0)
		{
			y--;
			d=d+4*x-4*y+10;
		}
		putpixel(xc+x,yc+y,c);
		putpixel(xc+y,yc+x,c);
		putpixel(xc+y,yc-x,c);
		putpixel(xc+x,yc-y,c);
		putpixel(xc-x,yc-y,c);
		putpixel(xc-y,yc-x,c);
		putpixel(xc-y,yc+x,c);
		putpixel(xc-x,yc+y,c);
	}
}

/*Function to draw Chess Board */
void createboard(int x,int y)
{
	int i;
	for(i=0;i<=8;i++)
	{
		line1(x,50,x,450,8);
		line1(50,y,450,y,8);
		x=x+50;
		y=y+50;
	}
}

/*Function to color Chess Board */
void colorboard(int x1,int y1)
{
	int x,y,i,j;
	x=x1;
	for(i=1;i<=8;i++)
	{
	y=y1;
	for(j=1;j<=8;j++)
	{
		if(i%2!=0)
		{
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(x,y,8);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(x,y+50,8);
		}
		else if(i%2==0)
		{
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(x,y,8);
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(x,y+50,8);
		}
		y=y+100;
	}
	x=x+50;
   }

}

/*Function to create ROOK */
void rook(int x,int y)
{
	setcolor(8);
	line1(x-15,y-20,x-10,y-20,8);
	line1(x-10,y-20,x-10,y-15,8);
	line1(x-10,y-15,x-5,y-15,8);
	line1(x-5,y-15,x-5,y-20,8);
	line1(x-5,y-20,x+5,y-20,8);
	line1(x+5,y-20,x+5,y-15,8);
	line1(x+5,y-15,x+10,y-15,8);
	line1(x+10,y-15,x+10,y-20,8);
	line1(x+10,y-20,x+15,y-20,8);
	line1(x+15,y-20,x+15,y-10,8);
	line1(x+15,y-10,x+10,y-10,8);
	line1(x+10,y-10,x+10,y+10,8);
	line1(x+10,y+10,x+15,y+10,8);
	line1(x+15,y+10,x+15,y+20,8);
	line1(x+15,y+20,x-15,y+20,8);
	line1(x-15,y+20,x-15,y+10,8);
	line1(x-15,y+10,x-10,y+10,8);
	line1(x-10,y+10,x-10,y-10,8);
	line1(x-10,y-10,x-15,y-10,8);
	line1(x-15,y-10,x-15,y-20,8);
}

/*Function to create KNIGHT */
void knight(int x,int y)
{
	setcolor(8);
	line1(x-5,y-5,x-15,y-5,8);
	line1(x-15,y-5,x-15,y-10,8);
	line(x-15,y-10,x,y-20);
	line1(x,y-20,x+10,y-20,8);
	line(x+10,y-20,x+15,y+20);
	line1(x+15,y+20,x-10,y+20,8);
	line(x-10,y+20,x-5,y-5);
}

/*Function to create BISHOP */
void bishop(int x,int y)
{
	setcolor(8);
	line1(x-10,y-5,x-15,y-5,8);
	line1(x-15,y-5,x-15,y-10,8);
	line(x-15,y-10,x,y-20);
	line(x,y-20,x+15,y-10);
	line1(x+15,y-10,x+15,y-5,8);
	line1(x+15,y-5,x+10,y-5,8);
	line1(x+10,y-5,x+10,y+15,8);
	line1(x+10,y+15,x+15,y+15,8);
	line1(x+15,y+15,x+15,y+20,8);
	line1(x+15,y+20,x-15,y+20,8);
	line1(x-15,y+20,x-15,y+15,8);
	line1(x-15,y+15,x-10,y+15,8);
	line1(x-10,y+15,x-10,y-5,8);
}

/*Function to create PAWN */
void pawn(int x,int y)
{
	setcolor(8);
	line1(x-5,y-5,x-10,y-5,8);
	line1(x+10,y-5,x+5,y-5,8);
	line(x-5,y-5,x-5,y+10);
	line(x-5,y+10,x-10,y+10);
	line1(x-10,y+10,x-10,y+15,8);
	line1(x-10,y+15,x+10,y+15,8);
	line1(x+10,y+15,x+10,y+10,8);
	line1(x+10,y+10,x+5,y+10,8);
	line1(x+5,y+10,x+5,y-5,8);
	arc(x,y-5,0,180,10);
}

/*Function to create KING */
void king(int x,int y)
{
	setcolor(8);
	line1(x-10,y-5,x-15,y-5,8);
	line1(x-15,y-5,x-15,y-10,8);
	line1(x-15,y-10,x-5,y-10,8);
	line1(x-5,y-10,x-5,y-15,8);
	line1(x-5,y-15,x+5,y-15,8);
	line1(x+5,y-15,x+5,y-10,8);
	line1(x+5,y-10,x+15,y-10,8);
	line1(x+15,y-10,x+15,y-5,8);
	line1(x+15,y-5,x+10,y-5,8);
	line1(x+10,y-5,x+10,y+10,8);
	line(x+10,y+10,x+15,y+15);
	line1(x+15,y+15,x+15,y+20,8);
	line1(x+15,y+20,x-15,y+20,8);
	line1(x-15,y+20,x-15,y+15,8);
	line(x-15,y+15,x-10,y+10);
	line1(x-10,y+10,x-10,y-5,8);
	circle1(x,y-18,3,8);
}

/*Function to create QUEEN */
void queen(int x,int y)
{
	setcolor(8);
	line1(x-10,y-5,x-15,y-5,8);
	line1(x-15,y-5,x-15,y-15,8);
	line(x-15,y-15,x-5,y-10);
	line(x-5,y-10,x,y-15);
	line(x,y-15,x+5,y-10);
	line(x+5,y-10,x+15,y-15);
	line1(x+15,y-15,x+15,y-5,8);
	line1(x+15,y-5,x+10,y-5,8);
	line1(x+10,y-5,x+10,y+10,8);
	line(x+10,y+10,x+15,y+15);
	line1(x+15,y+15,x+15,y+20,8);
	line1(x+15,y+20,x-15,y+20,8);
	line1(x-15,y+20,x-15,y+15,8);
	line(x-15,y+15,x-10,y+10);
	line1(x-10,y+10,x-10,y-5,8);
	circle1(x,y-18,2,8);
	circle1(x-15,y-18,2,8);
	circle1(x+15,y-18,2,8);

}

/*Function to put Rooks on chess board */
void putrooks(int x1,int y1)
{
   int i,x,y;
   for(i=0;i<4;i++)
   {
	x=x1;y=y1;
	if(i==0)
	{
		x=x-175;
		y=y-175;
	}
	else if(i==1)
	{
		x=x-175;
		y=y+175;
	}
	else if(i==2)
	{
		x=x+175;
		y=y-175;
	}
	else if(i==3)
	{
		x=x+175;
		y=y+175;
	}
	rook(x,y);
	if(i%2==0)
	{
		setfillstyle(SOLID_FILL,8);
		floodfill(x,y,8);
		A[x/50][y/50]=50;
	}
	else
	{
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x,y,8);
		A[x/50][y/50]=51;
	}
   }
}

/*Function to put Knights on chess board */
void putknights(int x1,int y1)
{
   int i,x,y;
   for(i=0;i<4;i++)
   {
	x=x1;y=y1;
	if(i==0)
	{
		x=x-125;
		y=y-175;
	}
	else if(i==1)
	{
		x=x-125;
		y=y+175;
	}
	else if(i==2)
	{
		x=x+125;
		y=y-175;
	}
	else if(i==3)
	{
		x=x+125;
		y=y+175;
	}
	knight(x,y);
	if(i%2==0)
	{
		setfillstyle(SOLID_FILL,8);
		floodfill(x,y,8);
		A[x/50][y/50]=40;
	}
	else
	{
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x,y,8);
		A[x/50][y/50]=41;
	}
   }
}

/*Function to put Bishops on chess board */
void putbishops(int x1,int y1)
{
   int i,x,y;
   for(i=0;i<4;i++)
   {
	x=x1;y=y1;
	if(i==0)
	{
		x=x-75;
		y=y-175;
	}
	else if(i==1)
	{
		x=x-75;
		y=y+175;
	}
	else if(i==2)
	{
		x=x+75;
		y=y-175;
	}
	else if(i==3)
	{
		x=x+75;
		y=y+175;
	}
	bishop(x,y);
	if(i%2==0)
	{
		setfillstyle(SOLID_FILL,8);
		floodfill(x,y,8);
		A[x/50][y/50]=30;
	}
	else
	{
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x,y,8);
		A[x/50][y/50]=31;
	}
   }
}

/*Function to put Pawns on chess board */
void putpawns(int x1,int y1)
{
	int i,j,x,y;
	x=x1;y=y1;
	for(i=0;i<2;i++)
	{
		x=x1;
		for(j=0;j<8;j++)
		{
			pawn(x,y);
			if(i==0)
			{
				setfillstyle(SOLID_FILL,8);
				floodfill(x,y,8);
				A[x/50][y/50]=60;
			}
			else
			{
				setfillstyle(SOLID_FILL,WHITE);
				floodfill(x,y,8);
				A[x/50][y/50]=61;
			}
			x=x+50;
		}
		y=y+250;
	}
}

/*Function to put Kings on chess board */
void putkings(int x1,int y1)
{
   int i,x,y;
   for(i=0;i<2;i++)
   {
	x=x1;y=y1;
	if(i==0)
	{
		x=x+25;
		y=y-175;
	}
	else if(i==1)
	{
		x=x+25;
		y=y+175;
	}
	king(x,y);
	if(i==0)
	{
		setfillstyle(SOLID_FILL,8);
		floodfill(x,y,8);
		floodfill(x,y-18,8);
		A[x/50][y/50]=10;
	}
	else
	{
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x,y,8);
		floodfill(x,y-18,8);
		A[x/50][y/50]=11;
	}
   }
}

/*Function to put Queens on chess board */
void putqueens(int x1,int y1)
{
   int i,x,y;
   for(i=0;i<2;i++)
   {
	x=x1;y=y1;
	if(i==0)
	{
		x=x-25;
		y=y-175;
	}
	else if(i==1)
	{
		x=x-25;
		y=y+175;
	}
	queen(x,y);
	if(i==0)
	{
		setfillstyle(SOLID_FILL,8);
		floodfill(x,y,8);
		floodfill(x,y-18,8);
		floodfill(x-15,y-18,8);
		floodfill(x+15,y-18,8);
		A[x/50][y/50]=20;
	}
	else
	{
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(x,y,8);
		floodfill(x,y-18,8);
		floodfill(x-15,y-18,8);
		floodfill(x+15,y-18,8);
		A[x/50][y/50]=21;
	}
   }
}

/*Functions to return mid-point of any box for any
  entered coordinate inside the box */
int midx(int x)
{
	int i,minx,x2;
	minx=x;
	for(i=50;i<=400;i=i+50)
	{
		if((x-i)<minx && (x-i)>=0)
		{
			minx=x-i;
			x2=(x-minx+25);
		}
	}
	return x2;
}

int midy(int y)
{
	int i,miny,y2;
	miny=y;
	for(i=50;i<=400;i=i+50)
	{
		if((y-i)<miny && (y-i)>=0)
		{
			miny=y-i;
			y2=(y-miny+25);
		}
	}
	return y2;
}

/*Function to fill a box with its background color */
int fillbox(int x,int y,int color)
{
	int i,j;
	setfillstyle(SOLID_FILL,color);
	for(i=x-23;i<x+24;i++)
	{
		for(j=y-23;j<y+24;j++)
		{
			floodfill(i,j,color);
		}
	}
	return 0;
}

/*Function to highlight the selected piece
  box and its valid positions */
int colorbox(int x,int y,int c)
{
	line1(x-23,y-23,x-23,y+23,c);
	line1(x-21,y+23,x+21,y+23,c);
	line1(x+23,y+23,x+23,y-23,c);
	line1(x+21,y-23,x-21,y-23,c);
	return 0;
}

/*Function to create RESTART and EXIT Buttons on GAME OVER */
void gameoverbuttons()
{
	setcolor(15);
	line1(210,250,270,250,8);
	line1(270,250,270,280,8);
	line1(270,280,210,280,8);
	line1(210,280,210,250,8);
   setfillstyle(SOLID_FILL,3);
	floodfill(215,255,8);
	outtextxy(213,265,"RESTART");
	line1(290,250,350,250,8);
	line1(350,250,350,280,8);
	line1(350,280,290,280,8);
	line1(290,280,290,250,8);
  setfillstyle(SOLID_FILL,4);
	floodfill(295,255,8);
   outtextxy(305,265,"EXIT");
}

/*Function to check whether the king is CHECKMATED or not */
int win(int x1,int y1,int x2,int y2)
{
	int a=A[x1/50][y1/50];
	int b=A[x2/50][y2/50];
	if((a%2!=0 && b==10)||(a%2==0 && b==11))
	{
		return 1;
	}
	else return 0;
}

void instructions()
{
	clearviewport();
	setfillstyle(SOLID_FILL,3);
	floodfill(10,10,8);
	settextstyle(DEFAULT_FONT,0,2);
	outtextxy(100,40,"-------------");
	outtextxy(100,60," HOW TO PLAY");
	outtextxy(100,80,"-------------");
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(50,120,"1. Right Click on any piece to select it.");
	outtextxy(50,140,"2. Left Click on any valid position to move the selected piece there.");
	outtextxy(50,160,"3. Left Click on CLEAR SELECTION button to clear the selected piece.");
	outtextxy(50,180,"4. TURN box shows who's turn, currently is.");
	outtextxy(50,200,"5. Left click on INSTRUCTIONS button to see how to play the game.");
	outtextxy(50,220,"6. Left Click on RESTART button to restart or reset the game.");
	outtextxy(50,240,"7. Left Click on EXIT button to exit the game.");
	outtextxy(180,280," *** BEST OF LUCK ***");
	outtextxy(150,300,"...Press any key to continue...");
	getch();
}

/*Function to exit the game */
void exitgame()
{
	    int i;
	    cleardevice();
	    setfillstyle(SOLID_FILL,15);
	    floodfill(10,10,7);
	    setbkcolor(CYAN);
	    setcolor(RED);
	    outtextxy(200,200,"...Exiting...Please Wait...");
	    line1(110,223,512,223,8);
	    line1(512,223,512,240,8);
	    line1(512,240,110,240,8);
	    line1(110,240,110,223,8);
	    gotoxy(15,15);
	    for(i=0;i<50;i++)
	    {
			setcolor(CYAN);
			printf(" ");
			outtextxy(50,350,"SUBMITTED TO :");
			outtextxy(50,365,"MS. RINKLE ASWANI");
			outtextxy(50,380,"&");
			outtextxy(50,395,"MS. PRIYANKA");
			outtextxy(50,410,"ASST. PROFESSORS");
			outtextxy(50,425,"CSE DEPARTMENT");
			outtextxy(450,350,"MADE BY :");
			outtextxy(450,365,"ASHUTOSH KUMAR");
			outtextxy(450,380,"ROLL NO : 02720902714");
			outtextxy(450,395,"DHEERENDRA SINGH");
			outtextxy(450,410,"ROLL NO : 06920902714");
			outtextxy(450,425,"C.S.E.- 3RD SEMESTER");
			delay(40);
	    }
	    closegraph();
	    exit(0);
}

/*Function to decide valid positions for ROOK */
void rookpos(int x,int y,int i)
{
	int x1,y1,c,a,a1;
	a1=A[x/50][y/50];
	x1=x;y1=y;
	a=A[(x1+50)/50][y1/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1);
		if(i==1)
		colorbox(x1+50,y1,12);
		else if(i==0)
		colorbox(x1+50,y1,c);
	}
	while(A[(x1+50)/50][y1/50]==0 && x1+50<450)
	{
		c=getpixel(x1+50,y1);
		if(i==1)
		colorbox(x1+50,y1,10);
		else if(i==0)
		colorbox(x1+50,y1,c);
		x1=x1+50;
		a=A[(x1+50)/50][y1/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1);
			if(i==1)
			colorbox(x1+50,y1,12);
			else if(i==0)
			colorbox(x1+50,y1,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][y1/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1);
		if(i==1)
		colorbox(x1-50,y1,12);
		else if(i==0)
		colorbox(x1-50,y1,c);
	}
	while(A[(x1-50)/50][y1/50]==0 && x1-50>50)
	{
		c=getpixel(x1-50,y1);
		if(i==1)
		colorbox(x1-50,y1,10);
		else if(i==0)
		colorbox(x1-50,y1,c);
		x1=x1-50;
		a=A[(x1-50)/50][y1/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1);
			if(i==1)
			colorbox(x1-50,y1,12);
			else if(i==0)
			colorbox(x1-50,y1,c);
		}
	}
	x1=x;y1=y;
	a=A[x1/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-18,y1+50);
		if(i==1)
		colorbox(x1,y1+50,12);
		else if(i==0)
		colorbox(x1,y1+50,c);
	}
	while(A[x1/50][(y1+50)/50]==0 && y1+50<450)
	{
		c=getpixel(x1-18,y1+50);
		if(i==1)
		colorbox(x1,y1+50,10);
		else if(i==0)
		colorbox(x1,y1+50,c);
		y1=y1+50;
		a=A[x1/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-18,y1+50);
			if(i==1)
			colorbox(x1,y1+50,12);
			else if(i==0)
			colorbox(x1,y1+50,c);
		}
	}
	x1=x;y1=y;
	a=A[x1/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-18,y1-50);
		if(i==1)
		colorbox(x1,y1-50,12);
		else if(i==0)
		colorbox(x1,y1-50,c);
	}
	while(A[x1/50][(y1-50)/50]==0 && y1-50>50)
	{
		c=getpixel(x1,y1-50);
		if(i==1)
		colorbox(x1,y1-50,10);
		else if(i==0)
		colorbox(x1,y1-50,c);
		y1=y1-50;
		a=A[x1/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-18,y1-50);
			if(i==1)
			colorbox(x1,y1-50,12);
			else if(i==0)
			colorbox(x1,y1-50,c);
		}
	}
}

/*Function to decide valid positions for KNIGHT */
void knightpos(int x,int y,int i)
{
	int a1,a,c,j,x1,y1;
	a1=A[x/50][y/50];
	for(j=8;j>=1;j--)
	{
		x1=x;
		y1=y;
		if(j==8)
		{
			x1=x1+50;
			y1=y1-100;
		}
		else if(j==7)
		{
			x1=x1+100;
			y1=y1-50;
		}
		else if(j==6)
		{
			x1=x1+100;
			y1=y1+50;
		}
		else if(j==5)
		{
			x1=x1+50;
			y1=y1+100;
		}
		else if(j==4)
		{
			x1=x1-50;
			y1=y1+100;
		}
		else if(j==3)
		{
			x1=x1-100;
			y1=y1+50;
		}
		else if(j==2)
		{
			x1=x1-100;
			y1=y1-50;
		}
		else if(j==1)
		{
			x1=x1-50;
			y1=y1-100;
		}
		a=A[x1/50][y1/50];
		if(x1>50 && x1<450 && y1>50 && y1<450)
		{
			if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
			{
				c=getpixel(x1-18,y1);
				if(i==1)
				colorbox(x1,y1,12);
				else if(i==0)
				colorbox(x1,y1,c);
			}
			else if(a==0)
			{
				c=getpixel(x1-18,y1);
				if(i==1)
				colorbox(x1,y1,10);
				else if(i==0)
				colorbox(x1,y1,c);
			}
		}
	}
}

/*Function to decide valid positions for BISHOP */
void bishoppos(int x,int y,int i)
{
	int x1,y1,c,a1,a;
	a1=A[x/50][y/50];
	x1=x;y1=y;
	a=A[(x1+50)/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1-50);
		if(i==1)
		colorbox(x1+50,y1-50,12);
		else if(i==0)
		colorbox(x1+50,y1-50,c);
	}
	while(A[(x1+50)/50][(y1-50)/50]==0 && x1+50<450 && y1-50>50)
	{
		c=getpixel(x1+50,y1-50);
		if(i==1)
		colorbox(x1+50,y1-50,10);
		else if(i==0)
		colorbox(x1+50,y1-50,c);
		x1=x1+50;
		y1=y1-50;
		a=A[(x1+50)/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1-50);
			if(i==1)
			colorbox(x1+50,y1-50,12);
			else if(i==0)
			colorbox(x1+50,y1-50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1-50);
		if(i==1)
		colorbox(x1-50,y1-50,12);
		else if(i==0)
		colorbox(x1-50,y1-50,c);
	}
	while(A[(x1-50)/50][(y1-50)/50]==0 && x1-50>50 && y1-50>50)
	{
		c=getpixel(x1-50-18,y1-50);
		if(i==1)
		colorbox(x1-50,y1-50,10);
		else if(i==0)
		colorbox(x1-50,y1-50,c);
		x1=x1-50;
		y1=y1-50;
		a=A[(x1-50)/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1-50);
			if(i==1)
			colorbox(x1-50,y1-50,12);
			else if(i==0)
			colorbox(x1-50,y1-50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1+50)/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1+50);
		if(i==1)
		colorbox(x1+50,y1+50,12);
		else if(i==0)
		colorbox(x1+50,y1+50,c);
	}
	while(A[(x1+50)/50][(y1+50)/50]==0 && x1+50<450 && y1+50<450)
	{
		c=getpixel(x1+50,y1+50);
		if(i==1)
		colorbox(x1+50,y1+50,10);
		else if(i==0)
		colorbox(x1+50,y1+50,c);
		x1=x1+50;
		y1=y1+50;
		a=A[(x1+50)/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1+50);
			if(i==1)
			colorbox(x1+50,y1+50,12);
			else if(i==0)
			colorbox(x1+50,y1+50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1+50);
		if(i==1)
		colorbox(x1-50,y1+50,12);
		else if(i==0)
		colorbox(x1-50,y1+50,c);
	}
	while(A[(x1-50)/50][(y1+50)/50]==0 && x1-50>50 && y1+50<450)
	{
		c=getpixel(x1-50,y1+50);
		if(i==1)
		colorbox(x1-50,y1+50,10);
		else if(i==0)
		colorbox(x1-50,y1+50,c);
		x1=x1-50;
		y1=y1+50;
		a=A[(x1-50)/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1+50);
			if(i==1)
			colorbox(x1-50,y1+50,12);
			else if(i==0)
			colorbox(x1-50,y1+50,c);
		}
	}
}

/*Function to decide valid positions for QUEEN */
void queenpos(int x,int y,int i)
{
	int x1,y1,c,a1,a;
	a1=A[x/50][y/50];
	x1=x;y1=y;
	a=A[(x1+50)/50][y1/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1);
		if(i==1)
		colorbox(x1+50,y1,12);
		else if(i==0)
		colorbox(x1+50,y1,c);
	}
	while(A[(x1+50)/50][y1/50]==0 && x1+50<450)
	{
		c=getpixel(x1+50-18,y1);
		if(i==1)
		colorbox(x1+50,y1,10);
		else if(i==0)
		colorbox(x1+50,y1,c);
		x1=x1+50;
		a=A[(x1+50)/50][y1/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1);
			if(i==1)
			colorbox(x1+50,y1,12);
			else if(i==0)
			colorbox(x1+50,y1,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][y1/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1);
		if(i==1)
		colorbox(x1-50,y1,12);
		else if(i==0)
		colorbox(x1-50,y1,c);
	}
	while(A[(x1-50)/50][y1/50]==0 && x1-50>50)
	{
		c=getpixel(x1-50-18,y1);
		if(i==1)
		colorbox(x1-50,y1,10);
		else if(i==0)
		colorbox(x1-50,y1,c);
		x1=x1-50;
		a=A[(x1-50)/50][y1/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1);
			if(i==1)
			colorbox(x1-50,y1,12);
			else if(i==0)
			colorbox(x1-50,y1,c);
		}
	}
	x1=x;y1=y;
	a=A[x1/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-18,y1+50);
		if(i==1)
		colorbox(x1,y1+50,12);
		else if(i==0)
		colorbox(x1,y1+50,c);
	}
	while(A[x1/50][(y1+50)/50]==0 && y1+50<450)
	{
		c=getpixel(x1-18,y1+50);
		if(i==1)
		colorbox(x1,y1+50,10);
		else if(i==0)
		colorbox(x1,y1+50,c);
		y1=y1+50;
		a=A[x1/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-18,y1+50);
			if(i==1)
			colorbox(x1,y1+50,12);
			else if(i==0)
			colorbox(x1,y1+50,c);
		}
	}
	x1=x;y1=y;
	a=A[x1/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-18,y1-50);
		if(i==1)
		colorbox(x1,y1-50,12);
		else if(i==0)
		colorbox(x1,y1-50,c);
	}
	while(A[x1/50][(y1-50)/50]==0 && y1-50>50)
	{
		c=getpixel(x1,y1-50);
		if(i==1)
		colorbox(x1,y1-50,10);
		else if(i==0)
		colorbox(x1,y1-50,c);
		y1=y1-50;
		a=A[x1/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-18,y1-50);
			if(i==1)
			colorbox(x1,y1-50,12);
			else if(i==0)
			colorbox(x1,y1-50,c);
		}
	}
	//Diagonal
	x1=x;y1=y;
	a=A[(x1+50)/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1-50);
		if(i==1)
		colorbox(x1+50,y1-50,12);
		else if(i==0)
		colorbox(x1+50,y1-50,c);
	}
	while(A[(x1+50)/50][(y1-50)/50]==0 && x1+50<450 && y1-50>50)
	{
		c=getpixel(x1+50,y1-50);
		if(i==1)
		colorbox(x1+50,y1-50,10);
		else if(i==0)
		colorbox(x1+50,y1-50,c);
		x1=x1+50;
		y1=y1-50;
		a=A[(x1+50)/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1-50);
			if(i==1)
			colorbox(x1+50,y1-50,12);
			else if(i==0)
			colorbox(x1+50,y1-50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1+50)/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1+50);
		if(i==1)
		colorbox(x1+50,y1+50,12);
		else if(i==0)
		colorbox(x1+50,y1+50,c);
	}
	while(A[(x1+50)/50][(y1+50)/50]==0 && x1+50<450 && y1+50<450)
	{
		c=getpixel(x1+50,y1+50);
		if(i==1)
		colorbox(x1+50,y1+50,10);
		else if(i==0)
		colorbox(x1+50,y1+50,c);
		x1=x1+50;
		y1=y1+50;
		a=A[(x1+50)/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1+50);
			if(i==1)
			colorbox(x1+50,y1+50,12);
			else if(i==0)
			colorbox(x1+50,y1+50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1-50);
		if(i==1)
		colorbox(x1-50,y1-50,12);
		else if(i==0)
		colorbox(x1-50,y1-50,c);
	}
	while(A[(x1-50)/50][(y1-50)/50]==0 && x1-50>50 && y1-50>50)
	{
		c=getpixel(x1-50,y1-50);
		if(i==1)
		colorbox(x1-50,y1-50,10);
		else if(i==0)
		colorbox(x1-50,y1-50,c);
		x1=x1-50;
		y1=y1-50;
		a=A[(x1-50)/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1-50);
			if(i==1)
			colorbox(x1-50,y1-50,12);
			else if(i==0)
			colorbox(x1-50,y1-50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1+50);
		if(i==1)
		colorbox(x1-50,y1+50,12);
		else if(i==0)
		colorbox(x1-50,y1+50,c);
	}
	while(A[(x1-50)/50][(y1+50)/50]==0 && x1-50>50 && y1+50<450)
	{
		c=getpixel(x1-50,y1+50);
		if(i==1)
		colorbox(x1-50,y1+50,10);
		else if(i==0)
		colorbox(x1-50,y1+50,c);
		x1=x1-50;
		y1=y1+50;
		a=A[(x1-50)/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1+50);
			if(i==1)
			colorbox(x1-50,y1+50,12);
			else if(i==0)
			colorbox(x1-50,y1+50,c);
		}
	}
}

/*Function to decide valid positions for KING */
void kingpos(int x,int y,int i)
{
	int c,j,x1,y1,a1,a;
	a1=A[x/50][y/50];
	for(j=8;j>=1;j--)
	{
		x1=x;
		y1=y;
		if(j==8)
		{
			x1=x1-50;
			y1=y1-50;
		}
		else if(j==7)
		{
			y1=y1-50;
		}
		else if(j==6)
		{
			x1=x1+50;
			y1=y1-50;
		}
		else if(j==5)
		{
			x1=x1+50;
		}
		else if(j==4)
		{
			x1=x1+50;
			y1=y1+50;
		}
		else if(j==3)
		{
			y1=y1+50;
		}
		else if(j==2)
		{
			x1=x1-50;
			y1=y1+50;
		}
		else if(j==1)
		{
			x1=x1-50;
		}
		a=A[x1/50][y1/50];
		if(x1>50 && x1<450 && y1>50 && y1<450)
		{
			if(a==0)
			{
				c=getpixel(x1,y1);
				if(i==1)
				colorbox(x1,y1,10);
				else if(i==0)
				colorbox(x1,y1,c);
			}
			else if(a!=0 && ((a%2==0 && a1%2!=0)||(a%2!=0 && a1%2==0)))
			{
				c=getpixel(x1-18,y1);
				if(i==1)
				colorbox(x1,y1,12);
				else if(i==0)
				colorbox(x1,y1,c);
			}
		}
	}
}

/*Function to decide valid positions for PAWN */
void pawnpos(int x,int y,int i)
{
	int c,a,b;
	if(A[x/50][y/50]==60 && y+50<450)
	{
		a=A[(x-50)/50][(y+50)/50];
		b=A[(x+50)/50][(y+50)/50];
		if(a!=0 && a%2!=0)
		{
			c=getpixel(x-50-18,y+50);
			if(i==1)
			colorbox(x-50,y+50,12);
			else if(i==0)
			colorbox(x-50,y+50,c);
		}
		if(b!=0 && b%2!=0)
		{
			c=getpixel(x+50-18,y+50);
			if(i==1)
			colorbox(x+50,y+50,12);
			else if(i==0)
			colorbox(x+50,y+50,c);
		}
		if(A[x/50][(y+50)/50]==0)
		{
			c=getpixel(x-18,y+50);
			if(i==1)
			colorbox(x,y+50,10);
			else if(i==0)
			colorbox(x,y+50,c);
		}
	}
	else if(A[x/50][y/50]==61 && y-50>50)
	{
		a=A[(x-50)/50][(y-50)/50];
		b=A[(x+50)/50][(y-50)/50];
		if(a!=0 && a%2==0)
		{
			c=getpixel(x-50-18,y-50);
			if(i==1)
			colorbox(x-50,y-50,12);
			else if(i==0)
			colorbox(x-50,y-50,c);
		}
		if(b!=0 && b%2==0)
		{
			c=getpixel(x+50-18,y-50);
			if(i==1)
			colorbox(x+50,y-50,12);
			else if(i==0)
			colorbox(x+50,y-50,c);
		}
		if(A[x/50][(y-50)/50]==0)
		{
			c=getpixel(x,y-50);
			if(i==1)
			colorbox(x,y-50,10);
			else if(i==0)
			colorbox(x,y-50,c);
		}
	}
}

void main()
{
   /* request auto detection */
   int gdriver=DETECT,gmode,errorcode,status,button;
   int x,y,x1,y1,i,j,color,hcolor,bcolor,x2,y2,turn,s,a,b;

   /* initialize graphics and local variables */
   initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

   /* read result of initialization */
   errorcode=graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   restart:		   /*Label to restart the game*/
   cleararray(A);
   turn=1;
   setbkcolor(7);
   setcolor(8);
   createboard(50,50);
   colorboard(75,75);
   putrooks(250,250);
   putknights(250,250);
   putbishops(250,250);
   putpawns(75,125);
   putkings(250,250);
   putqueens(250,250);

   /*Exit Button */
   line1(490,50,550,50,8);
   line1(550,50,550,80,8);
   line1(550,80,490,80,8);
   line1(490,80,490,50,8);
   setfillstyle(SOLID_FILL,12);
   floodfill(500,70,8);
   setcolor(15);
   outtextxy(505,64,"EXIT");

   /*Clear Selection Button */
   line1(490,100,630,100,8);
   line1(630,100,630,130,8);
   line1(630,130,490,130,8);
   line1(490,130,490,100,8);
   setfillstyle(SOLID_FILL,15);
   floodfill(495,105,8);
   setcolor(GREEN);
   outtextxy(500,114,"CLEAR SELECTION");

   /*Current Player's Turn Box */
   line1(490,150,630,150,8);
   line1(630,150,630,180,8);
   line1(630,180,490,180,8);
   line1(490,180,490,150,8);
   setfillstyle(SOLID_FILL,15);
   floodfill(495,155,8);
   setcolor(BLUE);
   outtextxy(500,164,"TURN : Player ");

   /*Instructions Button */
   line1(490,350,600,380,8);
   line1(600,350,600,380,8);
   line1(600,380,490,380,8);
   line1(490,380,490,350,8);
   setfillstyle(SOLID_FILL,3);
   floodfill(495,355,8);
   setcolor(15);
   outtextxy(500,364,"INSTRUCTIONS");

   /*Restart Button */
   line1(490,400,570,400,8);
   line1(570,400,570,430,8);
   line1(570,430,490,430,8);
   line1(490,430,490,400,8);
   setfillstyle(SOLID_FILL,3);
   floodfill(495,405,8);
   setcolor(15);
   outtextxy(500,414,"RESTART");

   /*Prints "CHESS" */
   setcolor(BROWN);
   settextstyle(DEFAULT_FONT,0,3);
   outtextxy(50,15,"CHESS");
   settextstyle(DEFAULT_FONT,0,1);

   /*Mouse Responses*/
   showmouseptr();
   while(!kbhit())
   {
	gotoxy(78,11);
	if(turn%2==0)
	printf("2");
	else
	printf("1");
	getmousepos(&button,&x,&y);

	/*Right click on any piece to select it*/
	 if((button==2) && (x>50 && x<450) && (y>50 && y<450))
	 {
		x1=midx(x);
		y1=midy(y);
		a=A[x1/50][y1/50];
		if((turn%2!=0 && A[x1/50][y1/50]%2==0)||(turn%2==0 && A[x1/50][y1/50]%2!=0))
		{
			goto B;
		}
		turn++;
		color=getpixel(x1-18,y1);
		if(A[x1/50][y1/50]!=0)
		{
			mousehide();
			colorbox(x1,y1,1);
			showmouseptr();
			if(A[x1/50][y1/50]==50 || A[x1/50][y1/50]==51)
			{
				mousehide();
				rookpos(x1,y1,1);
				showmouseptr();
			}
			else if(A[x1/50][y1/50]==40 || A[x1/50][y1/50]==41)
			{
				mousehide();
				knightpos(x1,y1,1);
				showmouseptr();
			}
			else if(A[x1/50][y1/50]==30 || A[x1/50][y1/50]==31)
			{
				mousehide();
				bishoppos(x1,y1,1);
				showmouseptr();
			}
			else if(A[x1/50][y1/50]==20 || A[x1/50][y1/50]==21)
			{
				mousehide();
				queenpos(x1,y1,1);
				showmouseptr();
			}
			else if(A[x1/50][y1/50]==10 || A[x1/50][y1/50]==11)
			{
				mousehide();
				kingpos(x1,y1,1);
				showmouseptr();
			}
			else if(A[x1/50][y1/50]==60 || A[x1/50][y1/50]==61)
			{
				mousehide();
				pawnpos(x1,y1,1);
				showmouseptr();
			}
		}
		else if(A[x1/50][y1/50]==0)
		{
			goto B;
		}
		while(!kbhit())
		{
			getmousepos(&button,&x,&y);
			x2=midx(x);
			y2=midy(y);

		       /*Left click on any valid postion to move
		       selected piece */
			if(button==1 && (x>50 && x<450) && (y>50 && y<450))
			{
				hcolor=getpixel(x2-23,y2);
				bcolor=getpixel(x2-18,y2);
				mousehide();
				if((A[x1/50][y1/50]==50 || A[x1/50][y1/50]==51))
				{

					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
						fillbox(x2,y2,bcolor);
						rookpos(x1,y1,0);
						rook(x2,y2);
						if(A[x1/50][y1/50]==50)
						{
							setfillstyle(SOLID_FILL,8);
							floodfill(x2,y2,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=50;
						}
						else if(A[x1/50][y1/50]==51)
						{
							setfillstyle(SOLID_FILL,15);
							floodfill(x2,y2,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=51;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}
				else if((A[x1/50][y1/50]==40)||(A[x1/50][y1/50]==41))
				{
					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
						fillbox(x2,y2,bcolor);
						knightpos(x1,y1,0);
						knight(x2,y2);
						if(A[x1/50][y1/50]==40)
						{
							setfillstyle(SOLID_FILL,8);
							floodfill(x2,y2,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=40;
						}
						else if(A[x1/50][y1/50]==41)
						{
							setfillstyle(SOLID_FILL,15);
							floodfill(x2,y2,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=41;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}
				else if(A[x1/50][y1/50]==30||A[x1/50][y1/50]==31)
				{
					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
						fillbox(x2,y2,bcolor);
						bishoppos(x1,y1,0);
						bishop(x2,y2);
						if(A[x1/50][y1/50]==30)
						{
							setfillstyle(SOLID_FILL,8);
							floodfill(x2,y2,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=30;
						}
						else if(A[x1/50][y1/50]==31)
						{
							setfillstyle(SOLID_FILL,15);
							floodfill(x2,y2,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=31;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}
				else if((A[x1/50][y1/50]==20)||(A[x1/50][y1/50]==21))
				{
					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
						fillbox(x2,y2,bcolor);
						queenpos(x1,y1,0);
						queen(x2,y2);
						if(A[x1/50][y1/50]==20)
						{
							setfillstyle(SOLID_FILL,8);
							floodfill(x2,y2,8);
							floodfill(x2,y2-18,8);
							floodfill(x2-15,y2-18,8);
							floodfill(x2+15,y2-18,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=20;
						}
						else if(A[x1/50][y1/50]==21)
						{
							setfillstyle(SOLID_FILL,15);
							floodfill(x2,y2,8);
							floodfill(x2,y2-18,8);
							floodfill(x2-15,y2-18,8);
							floodfill(x2+15,y2-18,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=21;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}
				else if((A[x1/50][y1/50]==10)||(A[x1/50][y1/50]==11))
				{
					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
						fillbox(x2,y2,bcolor);
						kingpos(x1,y1,0);
						king(x2,y2);
						if(A[x1/50][y1/50]==10)
						{
							setfillstyle(SOLID_FILL,8);
							floodfill(x2,y2,8);
							floodfill(x2,y2-18,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=10;
						}
						else if(A[x1/50][y1/50]==11)
						{

							setfillstyle(SOLID_FILL,15);
							floodfill(x2,y2,8);
							floodfill(x2,y2-18,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=11;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}
				else if(A[x1/50][y1/50]==60||A[x1/50][y1/50]==61)
				{
					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
						fillbox(x2,y2,bcolor);
						pawnpos(x1,y1,0);
						pawn(x2,y2);
						if(A[x1/50][y1/50]==60)
						{
							setfillstyle(SOLID_FILL,8);
							floodfill(x2,y2,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=60;
						}
						else if(A[x1/50][y1/50]==61)
						{
							setfillstyle(SOLID_FILL,15);
							floodfill(x2,y2,8);
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=61;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}

				else
				{
					showmouseptr();
					break;
				}

				A[x1/50][y1/50]=0;
				fillbox(x1,y1,color);
				showmouseptr();

				/*To show GAME OVER Dialogue*/
				if(s==1)
				{
					if((a%2!=0 && b==10)||(a%2==0 && b==11))
					{
						delay(500);
						mousehide();
						clearviewport();
						setfillstyle(SOLID_FILL,15);
						floodfill(10,10,7);
						setcolor(RED);
						settextstyle(DEFAULT_FONT,0,2);
						outtextxy(160,200,"...GAME OVER...");
						setcolor(BLUE);
						settextstyle(DEFAULT_FONT,0,1);
						if((a%2!=0 && b==10))
						outtextxy(230,230,"Player 1 Wins");
						else
						outtextxy(230,230,"Player 2 Wins");
						gameoverbuttons();
						setbkcolor(8);
						showmouseptr();
						while(!kbhit())
						{
							getmousepos(&button,&x,&y);
							if((button==1) && (x>210 && x<270) && (y>250 && y<280))
							{
								fflush(stdin);
								mousehide();
								clearviewport();
								goto restart;
							}
							else if((button==1) && (x>290 && x<350) && (y>250 && y<280))
							{
								mousehide();
								exitgame();
							}
						}
					}
				}
				break;
			}

			/*To clear the selected Piece */
			else if(button==1 && (A[x1/50][y1/50]!=0) && (x>490 && x<600) && (y>100 && y<130))
			{
				turn--;
				setcolor(YELLOW);
				outtextxy(500,114,"CLEAR SELECTION");
				delay(100);
				setcolor(GREEN);
				outtextxy(500,114,"CLEAR SELECTION");
				line1(x1-23,y1-23,x1-23,y1+23,color);
				line1(x1-21,y1+23,x1+21,y1+23,color);
				line1(x1+23,y1+23,x1+23,y1-23,color);
				line1(x1+21,y1-23,x1-21,y1-23,color);

				if((A[x1/50][y1/50]==50) || (A[x1/50][y1/50]==51))
				{
					mousehide();
					rookpos(x1,y1,0);
					showmouseptr();
				}
				else if((A[x1/50][y1/50]==40) || (A[x1/50][y1/50]==41))
				{
					mousehide();
					knightpos(x1,y1,0);
					showmouseptr();
				}
				else if((A[x1/50][y1/50]==30) || (A[x1/50][y1/50]==31))
				{
					mousehide();
					bishoppos(x1,y1,0);
					showmouseptr();
				}
				else if((A[x1/50][y1/50]==20) || (A[x1/50][y1/50]==21))
				{
					mousehide();
					queenpos(x1,y1,0);
					showmouseptr();
				}
				else if((A[x1/50][y1/50]==10) || (A[x1/50][y1/50]==11))
				{
					mousehide();
					kingpos(x1,y1,0);
					showmouseptr();
				}
				else if((A[x1/50][y1/50]==60) || (A[x1/50][y1/50]==61))
				{
					mousehide();
					pawnpos(x1,y1,0);
					showmouseptr();
				}
				showmouseptr();
				break;
			}
			A:fflush(stdin);
		}
		B:fflush(stdin);
	}

	/*To read the Instructions */
	else if((button==1) && (x>490 && x<600) && (y>350 && y<380))
	{
	    mousehide();
	    setcolor(15);
	    setfillstyle(SOLID_FILL,9);
	    floodfill(495,355,8);
	    outtextxy(500,364,"INSTRUCTIONS");
	    delay(50);
	    instructions();
	    fflush(stdin);
	    clearviewport();
	    goto restart;
	}

	/*To Restart the game */
	else if((button==1) && (x>490 && x<570) && (y>400 && y<430))
	{
	    mousehide();
	    setcolor(15);
	    setfillstyle(SOLID_FILL,9);
	    floodfill(495,405,8);
	    outtextxy(500,414,"RESTART");
	    delay(50);
	    setfillstyle(SOLID_FILL,3);
	    floodfill(495,405,8);
	    outtextxy(500,414,"RESTART");
	    delay(50);
	    fflush(stdin);
	    clearviewport();
	    goto restart;
	}
	/*To Exit the game */
	else if((button==1) && (x>490 && x<550) && (y>50 && y<80))
	{
	    mousehide();
	    setcolor(15);
	    setfillstyle(SOLID_FILL,14);
	    floodfill(500,70,8);
	    outtextxy(505,64,"EXIT");
	    delay(50);
	    setfillstyle(SOLID_FILL,12);
	    floodfill(500,70,8);
	    outtextxy(505,64,"EXIT");
	    delay(50);
	    exitgame();
	}

   }

   /* clean up */
   getch();
   closegraph();
}
