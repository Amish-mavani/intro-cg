// Implement Quadric Bezier Curve and Cubic Bezier Curve for user defined control points.

#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>

int getPt( int n1 , int n2 , float perc )
{
    int diff = n2 - n1;
    return n1 + ( diff * perc );
}   

int main()
{
int x[4],y[4],xa[3],ya[3],xb[2],yb[2],i,n;
double t,xc,yc;
int gr=DETECT,gm;
initgraph(&gr,&gm,"");
int q, w, e, r; 
q = getmaxx()/2;
w = getmaxy()/2;
e = getmaxx();
r = getmaxy();
line(0, w, e, w);
line(q, 0, q, r);
printf("\n****** Bezier Curve ***********");
printf("\n Please enter the number of points : \n");
scanf("%d",&n);
printf("\n Please enter x and y coordinates \n");
for(i=0;i<n;i++)                 
{
scanf("%d%d",&x[i],&y[i]);
x[i] += q;
y[i] = w - y[i];
putpixel(x[i],y[i],3);                
}

if(n == 4)
{
	printf("\n****** Quadric Bezier Curve ***********");
	for( float j = 0.0 ; j < 1.0 ; j += 0.001 )
	{
    for(i=0; i<3; i++)                 
	{
	xa[i] = getPt(x[i],x[i+1], j );
    ya[i] = getPt(y[i],y[i+1], j );              
	}
	
	for(i=0; i<2; i++)                 
	{
	xb[i] = getPt(xa[i],xa[i+1], j );
    yb[i] = getPt(ya[i],ya[i+1], j );              
	}

	xc = getPt(xb[0],xb[1], j );
    yc = getPt(yb[0],yb[1], j );
    
	putpixel( xc , yc , 5);
	xc = xc - q;
	yc = w - yc;
	printf("\n ( %f , %f ) ", xc , yc); 
	}
}
else if(n == 3)
{
	printf("\n****** Cubic Bezier Curve ***********");
	for( float j = 0.0 ; j < 1.0 ; j += 0.001 )
	{
    for(i=0; i<2; i++)                 
	{
	xa[i] = getPt(x[i],x[i+1], j );
    ya[i] = getPt(y[i],y[i+1], j );              
	}
	
	xc = getPt(xa[0],xa[1], j );
    yc = getPt(ya[0],ya[1], j ); 
    
	putpixel( xc , yc , 5);
	xc = xc - q;
	yc = w - yc;
	printf("\n ( %f , %f ) ", xc , yc); 
	}	
}
else if(n == 2)
{
	for( float j = 0.0 ; j < 1.0 ; j += 0.001 )
	{
	xc = getPt(x[0],x[1], j );
    yc = getPt(y[0],y[1], j );
    
	putpixel( xc , yc , 5);
	xc = xc - q;
	yc = w - yc;
	printf("\n ( %f , %f ) ", xc , yc);   
	}
}
else
{
	printf("\n*****************");
}

getch();
closegraph();
}

