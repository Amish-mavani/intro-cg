#include<stdio.h>  
#include<conio.h>  
#include<graphics.h>  
#include<dos.h> 

void DDA(int x1, int y1, int x2, int y2)
{
	float x, y, dx, dy, m;
	float xi, yi;
	int i, gd=DETECT, gm, M, color;
	initgraph(&gd,&gm,""); 
	
	int q, w, e, r; 
	q = getmaxx()/2;
	w = getmaxy()/2;
	e = getmaxx();
	r = getmaxy();
	line(0, w, e, w);
	line(q, 0, q, r);
	
	dx = abs ( x2 - x1 );
	dy = abs ( y2 - y1 );
	m = dy/dx;

	if(m>1)
	{
	M = dy;
	}
	else if(m<1)
	{
	M = dx;
	}
	else
	{
	M = dx;
	}
	x = (float)x1;	
	y = (float)y1;
	xi = dx/M;
	yi = dy/M;
		
	for (int i = 0; i <= M; i++) 
	{
    putpixel(x,y,GREEN);
	x += xi;
	y += yi;
	}
	getch(); 
	closegraph();
}

void Bresenham(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, d, m;
	int gd=DETECT, gm, color;
	initgraph(&gd,&gm,""); 
	
	int q, w, e, r; 
	q = getmaxx()/2;
	w = getmaxy()/2;
	e = getmaxx();
	r = getmaxy();
	line(0, w, e, w);
	line(q, 0, q, r);
	
	dx = x2-x1;
	dy = y2-y1;
	m = dy/dx;
	x =  x1;	
	y = y1;
	d = 2*dy - dx;
	
	
	if(m >= 0)
	{
		while(x < x2)
		{
		x = x+1;
		if(d>=0)
		{
			putpixel(x,y,GREEN);
			y = y + 1;
			d = d + 2*dy - 2*dx;
		}
		else
		{	
			putpixel(x,y,GREEN);
			d = d + 2*dy;
		}
		}
	}
	else
	{
		while(x > x2)
		{
		x = x-1;
		if(d>=0)
		{
			putpixel(x,y,GREEN);
			y = y + 1;
			d = d + 2*dy - 2*dx;
		}
		else
		{	
			putpixel(x,y,GREEN);
			d = d + 2*dy;
		}
	}
	}
	
	getch(); 
	closegraph();	
}
	

void MPoint(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, d;
	int gd=DETECT, gm, color;
	initgraph(&gd,&gm,"");
	
	int q, w, e, r; 
	q = getmaxx()/2;
	w = getmaxy()/2;
	e = getmaxx();
	r = getmaxy();
	line(0, w, e, w);
	line(q, 0, q, r);
	
	dx = x2-x1;
	dy = y2-y1;
	x = x1;	
	y = y1;
	d = dy - (dx/2); 
	
	while(x < x2)
	{
		x = x+1;
		if(d>=0)
		{
			putpixel(x,y,GREEN);
			y = y + 1;
			d = d + (dy - dx);
		}
		else
		{	
			putpixel(x,y,GREEN);
			d = d + dy;
		}
	}
	getch(); 
	closegraph();		
}

int main()
{
	int a;
	int x1,x2,y1,y2; 		
	printf("\nEnter the value of x1 and y1 : ");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter the value of x2 and y2: ");
	scanf("%d%d",&x2,&y2);
	printf(" select the program to implement line drawing algorithm ");
	printf(" \n1.DDA  \n2.Bresenham \n3.Mid Point \n");
	printf("\nenter the value :  ");
	scanf("%d", &a);
	
	switch(a)
	{
		case 1:
			printf(" \n1.DDA ");
			DDA(x1, y1, x2, y2);
		break;
		
		case 2:
			printf(" \n2.Bresenham");
			Bresenham(x1, y1, x2, y2);
				
		break;
		
		case 3:
			printf(" \n3.Mid Point");
			MPoint(x1, y1, x2, y2);	
		break;
	}
    return 0;
}
