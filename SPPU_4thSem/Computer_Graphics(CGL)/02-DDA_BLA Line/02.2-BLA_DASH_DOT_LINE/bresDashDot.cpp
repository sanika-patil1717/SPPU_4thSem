#include<iostream>
#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>

using namespace std;


struct  point
{
    GLint x;
    GLint y;
};

point p1, p2;                    // structure variables 

void bresenham(point p1, point p2)
{
    double dx, dy;
    double e, xinc, yinc, inc1, inc2;

}

void mouse(int button, int state, int x, int y)
{
    glColor3f(1.0, 1.0, 0.0);
    static int r = 0;     //for checking input points alternatively

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && r % 2 == 0)     //first point input
    {
        p1.x = x;
        p1.y = 480 - y;
        r++;
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && r % 2 == 1)    //next points
    {
        p2.x = x;
        p2.y = 480 - y;
        bresenham(p1, p2);
        p1 = p2;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)      //breakig continuety
        r = 0;
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);  //black
    glColor3f(1.0, 0.0, 0.0);                  //Red 
    glPointSize(2.0f);                              //line size 2.0f
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv)
{
    int ch, check = 0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham");
    init();
    glFlush();
    glBegin(GL_LINES);              //drawing X and Y axises
    glVertex2f(0, 240);
    glVertex2f(640, 240);
    glVertex2f(320, 0);
    glVertex2f(320, 480);
    glEnd();
    glFlush();

    do
    {
        cout << "\n*********************************************************\n";
        cout << "\nMenu \n1) With-Out Using Mouse \n2) With Using Mouse\n3) Exit\nEnter Your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:                 // line drawing Without using Mouse
            do
            {
                cout << "\n*********************************************************\n";
                cout << "\nEnter Initial Points \n\nEnter X Co-Ordinate : ";
                cin >> p1.x;
                cout << "\nEnter Y Co-Ordinate : ";
                cin >> p1.y;
                cout << "\n*********************************************************\n";
                cout << "\nEnter final Points \n\nEnter X Co-Ordinate :  ";
                cin >> p2.x;
                cout << "\nEnter Y Co-Ordinate :  ";
                cin >> p2.y;
                p1.x += 320;                      //parameters translated to origin
                p2.x += 320;                      // first and drawing next line between next point
                p1.y += 240;
                p2.y += 240;

                glColor3f(0.0, 1.0, 1.0);
                bresenham(p1, p2);
                cout << "\n*********************************************************\n";
                cout << "\nRevisit With-Out Mouse Function : \nPress 0 :\tNo\nPress 1 :\tyes\nEnter Your Choice : ";
                cin >> check;
            } while (check != 0);
            break;

        case 2:                         //line drawing with using mouse
            glutMouseFunc(mouse);
            glutMainLoop();
            break;
        case 3:                        //Exit
            cout << "\nProgram Ends\n";
            break;
        }
    } while (ch != 3);
}

