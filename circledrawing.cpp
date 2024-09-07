
#include<stdio.h>  
#include<conio.h>  
#include<graphics.h>  
#include<dos.h> 

void drawCircle(int x1, int y1, int x, int y)
{
	putpixel(x1+y, y1+x, BLUE);
	putpixel(x1+x, y1+y, RED);
	putpixel(x1+x, y1-y, BLUE);
	putpixel(x1+y, y1-x, RED);
	putpixel(x1-y, y1-x, BLUE);
	putpixel(x1-x, y1-y, RED);		
	putpixel(x1-x, y1+y, BLUE);
	putpixel(x1-y, y1+x, RED);
}

void Bresenham(int x1, int y1, int r)
{
	int gd=DETECT, gm,color;
	initgraph(&gd, &gm, "");
	int x, y, d;
	x = 0, y = r;
	d = 3 - 2 * r;
	x1 = x1 + getmaxx()/2;
	y1 = getmaxy()/2 - y1;
	int q, w, e, R; 
	q = getmaxx()/2;
	w = getmaxy()/2;
	e = getmaxx();
	R = getmaxy();
	line(0, w, e, w);
	line(q, 0, q, R);
	drawCircle(x1, y1, x, y);
	
	while (y >= x)
	{
		x = x + 1 ;
		if (d > 0)
		{
			y = y - 1;
			d = d + 4 * x - 4 * y + 10;
		}
		else
		{
			d = d + 4 * x + 6;
		}
		drawCircle(x1, y1, x, y);
	    delay(100);
	}	
	getch(); 
	closegraph();
}

void MPoint(int x1, int y1, int r)
{
	int gd=DETECT, gm,color;
	initgraph(&gd, &gm, "");
	int x, y, d;
	x = r, y = 0;
	d = 1 - r;
	x1 = x1 + getmaxx()/2;
	y1 = getmaxy()/2 - y1;
	int q, w, e, R; 
	q = getmaxx()/2;
	w = getmaxy()/2;
	e = getmaxx();
	R = getmaxy();
	line(0, w, e, w);
	line(q, 0, q, R);
	while(x >= y)
	{
		y = y + 1;
		if(d <= 0)
		{
    		d = d + 2 * y + 1;
		}
		else
		{
			x = x - 1;
    		d = d + 2 * y - 2 * x + 1;
		}
		drawCircle(x1, y1, x, y);
        delay(100);
	}
	getch(); 
	closegraph();	
}

int main()
{
	int a;
	int r,x1,y1,x2,y2; 		
	printf("\nEnter the value of center x1 , y1 : ");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter the value of radius: ");
	scanf("%d",&r);
	printf(" \nselect the program to implement circle drawing algorithm ");
	printf(" \n1.Bresenham \n2.Mid Point \n");
	printf("\nenter the value :  ");
	scanf("%d", &a);
	
	switch(a)
	{
		case 1:
			printf(" \n1.Bresenham");
			Bresenham(x1, y1, r);			
		break;
		
		case 2:
			printf(" \n2.Mid Point");
			MPoint( x1, y1, r);	
		break;
	}
    return 0;
}
