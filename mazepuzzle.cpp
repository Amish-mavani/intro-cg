#include <stdio.h>
#include <graphics.h>

void grind(int color) {
	setcolor(color);
	int q, w, e, r;
	q = getmaxx()/6;
	w = getmaxy()/6;
	for(int i = 0; i < 10;  i++) {
		line(0 + 55, i*w/3 + 55, 3*q + 55, i*w/3 + 55);
		line(i*q/3 + 55, 0 + 55, i*q/3 + 55 , 3*w + 55);
	}
}

void alphagrind(int color) {
	setcolor(color);
	int q, w, e, r;
	q = getmaxx()/27;
	w = getmaxy()/27;
	for(int i = 0; i < 28;  i++) {
		line(5 ,25*w, 27*q, 25*w);
		line(5 ,25*w + 25, 27*q, 25*w + 25);
		line(i*q + 5, 25*w, i*q , 25*w + 25);
	}
}

void text(int x, int y){    
    int font = 8;
    int direction = 0;
    int font_size = 2;
    settextstyle(font, direction, font_size);
}

printalpha(){
    settextstyle(5, 1, 2);
    
}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, " ");
	// alpha[30] = ('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z');
	
	printalpha();
	grind(BLUE);
	alphagrind(BLUE);
	text(120 , 120) ;
	{
		// diff in x is 36 ; 63, 99, 135, 171, 207, 243, 279, 315, 351
		// diff in y is 26 ; 57, 83, 109, 135, 161. 187, 213, 239, 265
		
		//saga
		outtextxy(63 , 57, "s");
		outtextxy(99 , 57, "a");
		outtextxy(135 , 57, "g");
		outtextxy(171 , 57, "a");
		//sage
		outtextxy(63 , 57, "s");
		outtextxy(63 , 83, "a");
		outtextxy(63 , 109, "g");
		outtextxy(63 , 135, "e");
		//blue
		outtextxy(63 , 57, "b");
		outtextxy(99 , 57, "l");
		outtextxy(135 , 57, "u");
		outtextxy(171 , 57, "e");
		//area
		outtextxy(63 , 57, "a");
		outtextxy(99 , 57, "r");
		outtextxy(135 , 57, "e");
		outtextxy(171 , 57, "a");
		//tip
		outtextxy(99 , 57, "t");
		outtextxy(135 , 57, "i");
		outtextxy(171 , 57, "p");
		//tale
		outtextxy(63 , 57, "t");
		outtextxy(99 , 57, "a");
		outtextxy(135 , 57, "l");
		outtextxy(171 , 57, "e");
		//amish
		outtextxy(63 , 57, "a");
		outtextxy(99 , 57, "m");
		outtextxy(135 , 57, "i");
		outtextxy(171 , 57, "s");
		outtextxy(171 , 57, "h");
	}
	
	text(120 , 120) ;
	{
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(53 , 427, "c");
		outtextxy(75 , 427, "d");
		outtextxy(97 , 427, "e");
		outtextxy(119 , 427, "f");
		outtextxy(141 , 427, "g");
		outtextxy(162 , 427, "h");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
		outtextxy(8 , 427, "a");
		outtextxy(30 , 427, "b");
	}
	
	getch();
	closegraph();
	return 0;
}
