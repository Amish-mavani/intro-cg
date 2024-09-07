
//Implement a program to draw any solid object (square, rectangle, triangle etc). Apply listed below 2D transformation on it.
//1. Translation
//2. Scaling
//3. Rotation via clockwise and anticlockwise
//4. Reflection w.r.to X-axis, Y-axis, line Y=X, at origin and line y=mx+c
//5. Shearing w.r.to X-axis, Y-axis and XY-axis

#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>

using namespace std;

//------------------------------------------------//
void figure(int n,int coordinates[])
{
    
    int xmax = getmaxx(), ymax = getmaxy();
    for(int i=0;i<(2*(n-1));i+=2)
	{
		line((xmax/2+coordinates[i]),(ymax/2-coordinates[(i+1)]),(xmax/2+coordinates[(i+2)]),(ymax/2-coordinates[(i+3)]));
	}
    line((xmax/2+coordinates[(2*n)-2]),(ymax/2-coordinates[(2*n)-1]),(xmax/2+coordinates[0]),(ymax/2-coordinates[1]));
}

//------------------------------------------------//
void translate(int n,int coordinates[],int Tx,int Ty)
{
    for(int i=0;i<n;i++)
	{
		coordinates[(2*i)]+=Tx;
		coordinates[(2*i+1)]+=Ty;
	}
    
}

//------------------------------------------------//
void scaling(int n,int coordinates[],float Sx,float Sy)
{
    for(int i=0;i<n;i++)
	{
		coordinates[(2*i)]=round(coordinates[(2*i)]*Sx);
		coordinates[(2*i+1)]=round(coordinates[(2*i)+1]*Sy);
	}
}

//------------------------------------------------//
void rotation(int n,int coordinates[],int theta)
{
    for(int i=0;i<n;i++)
	{
		float X_new=coordinates[(2*i)]*cos(theta*3.14/180)-coordinates[(2*i+1)]*sin(theta*3.14/180);
		float Y_new=coordinates[(2*i)]*sin(theta*3.14/180)+coordinates[(2*i+1)]*cos(theta*3.14/180);
		coordinates[(2*i)]=round(X_new);
		coordinates[(2*i+1)]=round(Y_new);
	}

}

//------------------------------------------------//
void reflection(int n,int coordinates[],int fx,int fy)
{
    for(int i=0;i<n;i++)
	{
		coordinates[(2*i)]=round(coordinates[(2*i)]*fx);
		coordinates[(2*i+1)]=round(coordinates[(2*i)+1]*fy);
	}

}


//------------------------------------------------//
void shearing(int n,int coordinates[],float Shx,float Shy)
{
    for(int i=0;i<n;i++)
	{
		int X_new=coordinates[(2*i)]+round(Shx*coordinates[(2*i+1)]);
		int Y_new=coordinates[(2*i+1)]+round(Shy*coordinates[(2*i)]);
		coordinates[(2*i)]=X_new;
		coordinates[(2*i+1)]=Y_new;
	}
}

//------------------------------------------------//
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int xmax = getmaxx(), ymax = getmaxy(), code = 1;

    // xmax=639
    // ymax=479

    line(xmax / 2, 0, xmax / 2, ymax);
    line(0, ymax / 2, xmax, ymax / 2);

	int n=3;
	
	cout<<"Number of Sides in Polygon ? :-";
    cin>>n;
    	
    int coordinates[2*n];
    int old_coordinates[2*n];
   	for(int i=0;i<n;i++)
    {
   		int x=0,y=0;
		cout<<"Co-ordinates of Point"<<(i+1)<<endl;
    	cout<<"x"<<(i+1)<<"=";
   		cin>>x;
    	cout<<"y"<<(i+1)<<"=";
    	cin>>y;
   		coordinates[2*i]=x;
    	coordinates[2*i+1]=y;
   		old_coordinates[2*i]=x;
    	old_coordinates[2*i+1]=y;
	}
	
    while (code == 1)
    {
    	cleardevice();
    	line(xmax / 2, 0, xmax / 2, ymax);
    	line(0, ymax / 2, xmax, ymax / 2);
		figure(n,coordinates);
		
		for(int i=0;i<n;i++)
    	{ 
   			old_coordinates[2*i]=coordinates[2*i];
    		old_coordinates[2*i+1]=coordinates[2*i+1];
		}
        
		int choice = 1;
        cout << "Choose the 2-D Transformation you want to Perform :-" << endl;
        cout << "1. Translation " << endl;
        cout << "2. Scaling " << endl;
        cout << "3. Rotation " << endl;
        cout << "4. Reflection " << endl;
        cout << "5. Shearing " << endl;
        cout << "6. Exit the Program " << endl;
        cin >> choice;
        
        if(choice==1)
        {
        	int Tx=0,Ty=0;
			cout<<"Enter the translation factor along X-axis Tx=";
			cin>>Tx;
			cout<<"Enter the translation factor along Y-axis Ty=";
			cin>>Ty;
			translate(n,coordinates,Tx,Ty);
			cout<<coordinates[0]<<endl;
		}
        else if (choice == 2)
        {
            float Sx=1,Sy=1;
			cout<<"Enter the Scaling factor for X Co-ordinates Sx=";
			cin>>Sx;
			cout<<"Enter the Scaling factor for Y Co-ordinates Sy=";
			cin>>Sy;
			scaling(n,coordinates,Sx,Sy);
        }
        else if (choice == 3)
        {
            int rotateangle=1,theta=0;
			cout<<"Choose the direction about which Rotation is to be Performed:-"<<endl;
            cout<<"1. Clockwise "<<endl;
            cout<<"2. Anti-Clockwise "<<endl;
            cin>>rotateangle;
            cout<<"Enter the Angle by which Rotation is to be performed:-"<<endl;
			cout<<"Theta=";
			cin>>theta;
            if(rotateangle==2)
            {
            	theta*=-1;
			}
			rotation(n,coordinates,theta);
        }
        else if (choice == 4)
        {
            int rotateaxis=1,fx=1,fy=1;
			cout<<"Choose the axis about which Reflection is to be Performed:-"<<endl;
            cout<<"1. X-axis "<<endl;
            cout<<"2. Y-axis "<<endl;
            cout<<"3. Origin "<<endl;
            cout<<"4. Y=X "<<endl;
            cout<<"5. Y=-X "<<endl;
            cout<<"6. Y=mX+c "<<endl;
            cin>>rotateaxis;
            switch(rotateaxis)
            {
            	case 1:
            		fy=-1;
            		reflection(n,coordinates,fx,fy);
            		break;
            	case 2:
            		fx=-1;
            		reflection(n,coordinates,fx,fy);
            		break;
            	case 3:
            		fx=-1;
            		fy=-1;
            		reflection(n,coordinates,fx,fy);
            		break;
            	case 4:
            		rotation(n,coordinates,-45);
            		fy=-1;
            		reflection(n,coordinates,fx,fy);
            		rotation(n,coordinates,45);
            		break;
            	case 5:
            		rotation(n,coordinates,45);
            		fy=-1;
            		reflection(n,coordinates,fx,fy);
            		rotation(n,coordinates,-45);
            		break;
            	case 6:
            		int theta=45,c=0;
            		cout<<"For equation of line y=mx+c.Enter the value of theta for the slope m=tan (Theta) is "<<endl;
            		cin>>theta;
            		cout<<"For equation of line y=mx+c.Enter the value of the constant c= "<<endl;
            		cin>>c;
            		translate(n,coordinates,c,0);
            		rotation(n,coordinates,theta);
            		fx=-1;
            		fy=1;
            		reflection(n,coordinates,fx,fy);
            		theta*=-1;
            		rotation(n,coordinates,theta);
            		translate(n,coordinates,-c,0);
            		break;
			}
            
        }
        else if (choice == 5)
        {
        	float Shx=0,Shy=0,shearchoice=1;
        	cout<<"Choose the axis about which Shearing is to be Performed:-"<<endl;
            cout<<"1. X-axis "<<endl;
            cout<<"2. Y-axis "<<endl;
            cout<<"3. Both X-axis and Y-axis "<<endl;
            cin>>shearchoice;
            if(shearchoice==1)
            {
            	cout<<"Enter the Shearing factor for X Co-ordinates Shx=";
				cin>>Shx;
			}
			else if(shearchoice==2)
            {
            	cout<<"Enter the Shearing factor for Y Co-ordinates Shy=";
				cin>>Shy;
			}
			else
			{
				cout<<"Enter the Shearing factor for X Co-ordinates Shx=";
				cin>>Shx;
            	cout<<"Enter the Shearing factor for Y Co-ordinates Shy=";
				cin>>Shy;
			}
			shearing(n,coordinates,Shx,Shy);
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "INVALID INPUT!Enter valid input." << endl;
        }
        
    }

    getch();
    closegraph();
    return 0;
}
