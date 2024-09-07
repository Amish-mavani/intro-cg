#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;

void drawEllipseMidPoint(int x_center, int y_center, int rx, int ry) 
{
    int xorigin = getmaxx() / 2;
    int yorigin = getmaxy() / 2;
    for (int i = 0; i <= getmaxx(); i++)
    {
        putpixel(i, yorigin, GREEN);
    }

    for (int i = 0; i <= getmaxy(); i++)
    {
        putpixel(xorigin, i, GREEN);
    }
    
    x_center = xorigin + x_center;
    y_center = yorigin - y_center;
    int x = 0, y = ry;
    int rxSq = rx * rx;
    int rySq = ry * ry;
    int twoRxSq = 2 * rxSq;
    int twoRySq = 2 * rySq;
    int p;


    int x0 = x;
    int y0 = y;
    int dx0 = 0;
    int dy0 = twoRxSq * y0;
    p = rySq - (rxSq * ry) + (0.25 * rxSq);
    while (dx0 < dy0) {
        putpixel(x_center + x0, y_center - y0, WHITE);
        putpixel(x_center - x0, y_center - y0, WHITE);
        putpixel(x_center - x0, y_center + y0, WHITE);
        putpixel(x_center + x0, y_center + y0, WHITE);

        x0++;
        dx0 += twoRySq;
        if (p < 0)
            p += rySq + dx0;
        else {
            y0--;
            dy0 -= twoRxSq;
            p += rySq + dx0 - dy0;
        }
    }


    int dx1 = twoRySq * x0;
    int dy1 = twoRxSq * y0;
    p = rySq * (x0 + 0.5) * (x0 + 0.5) + rxSq * (y0 - 1) * (y0 - 1) - rxSq * rySq;

    while (y0 >= 0) {
        putpixel(x_center + x0, y_center - y0, WHITE);
        putpixel(x_center - x0, y_center - y0, WHITE);
        putpixel(x_center - x0, y_center + y0, WHITE);
        putpixel(x_center + x0, y_center + y0, WHITE);

        y0--;
        dy1 -= twoRxSq;
        if (p > 0)
            p += rxSq - dy1;
        else {
            x0++;
            dx1 += twoRySq;
            p += rxSq - dy1 + dx1;
        }
    }
}

void floodFill(int x, int y, int fillColor, int oldColor) {
    if (getpixel(x, y) == oldColor) 
	{
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, oldColor);
        floodFill(x - 1, y, fillColor, oldColor);
        floodFill(x, y + 1, fillColor, oldColor);
        floodFill(x, y - 1, fillColor, oldColor);
    }
}
void boundaryFill(int x, int y, int fillColor, int boundaryColor, int xo,int yo) 
{
   
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) 
	{
        putpixel(x, y, fillColor);
        boundaryFill(x + 1, y, fillColor, boundaryColor,xo,yo);
        boundaryFill(x - 1, y, fillColor, boundaryColor,xo,yo);
        boundaryFill(x, y + 1, fillColor, boundaryColor,xo,yo);
        boundaryFill(x, y - 1, fillColor, boundaryColor,xo,yo);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int choice;
    int x_center, y_center, rx, ry;
    int xorigin = getmaxx() / 2;
    int yorigin = getmaxy() / 2;
    while (1) {
        cout << "Menu:" << endl;
        cout << "1. Ellipse Algorithm" << endl;
        cout << "2. Boundary Fill " << endl;
        cout << "3. Flood Fill " << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter x_center: ";
                cin >> x_center;
                cout << "Enter y_center: ";
                cin >> y_center;
                cout << "Enter rx: ";
                cin >> rx;
                cout << "Enter ry: ";
                cin >> ry;
                drawEllipseMidPoint(x_center, y_center, rx, ry);
                break;

            case 2:
                cout << "Enter start point (x, y): ";
                cin >> x_center >> y_center;
                 x_center=x_center+xorigin;
                 y_center=yorigin-y_center;
                boundaryFill(x_center, y_center, YELLOW, WHITE,xorigin,yorigin);
                break;
            case 3:
                 cout << "Enter start point (x, y): ";
                 cin >> x_center >> y_center;
                 x_center=x_center+xorigin;
                 y_center=yorigin-y_center;
                floodFill(x_center, y_center, BLUE, getpixel(x_center, y_center));
                break;

            case 4:
                closegraph();
                exit(0);

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}


