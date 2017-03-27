#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//gcc -Wall -ohello hello.c -lglut32cu -lglu32 -lopengl32
#define W 200
#define H 200 

int *pixels = new int[W*H*3]; 

void setPixel(int r, int g, int b, int x, int y){
    int rgb = (r << 16) | (g << 8) | b;
    pixels[x+y*W] = rgb;
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glDrawPixels(W, H, GL_BGRA_EXT, GL_UNSIGNED_BYTE, pixels);
    glFlush ();
}


void init (void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    srand(time(NULL)); 
    for (int i = 0; i < W; ++i){
        for (int j = 0; j < H; ++j){
            int r, g, b = 0;
            r = rand() % 256;
            g = rand() % 256;
            b = rand() % 256;
            setPixel(r, g, b, j, i);    
        }
    }
}

void resize(int width, int height) {
    // we ignore the params and do:
    glutReshapeWindow( W, H);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (W, H); 
    glutInitWindowPosition (W, H);
    glutCreateWindow ("Exercício PG");
    glutReshapeFunc(resize);
    init ();
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;  
}