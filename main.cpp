#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>

//paleta de colores basicos para ir llamando con punteros

float blanco[]={1,1,1};
float negro[]={0,0,0},azul[]={0,0,1}, antu[]={0.7,0.7,0.7};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0}, marron[]={0.4,0.2,0.1};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6}, morado[]={0.2588,0.1804,0.9059};

//funcion para trabajar con mas valores en pantalla y no restringido a -1 a 1


void pantalla()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10,10,-10,10);

}

void cuadrado1 (float x, float y, float lado)
{
    glVertex2d(x,y);
    glVertex2d(x,y+lado);
    glVertex2d(x+lado,y+lado);
    glVertex2d(x+lado,y);

}

void linea (float x, float y, float lado)
{
    glVertex2d(x,y);
    glVertex2d(x,y+lado);
}

void cuadrado(float x, float y, int patron1, int patron2, float lado, float *rgb)
{
    glColor3fv(rgb);
    glEnable(GL_LINE_STIPPLE);

    switch(patron1)
    {
        case 1: glLineStipple(1,0x0101); break;
        case 2: glLineStipple(1,0xAAAA); break;
        case 3: glLineStipple(1,0x00FF); break;
        case 4: glLineStipple(1,0x0C0F); break;
        case 5: glLineStipple(1,0x1C47); break;
    }

    switch(patron2)
    {
        case 1: glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); break;
        case 2: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
        case 3: glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
    }

    glLineWidth(4);
    glBegin(GL_POLYGON);
    cuadrado1(x,y,lado);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    for(float i=0.2; i<lado ; i=i+0.2)
    {
        glEnable(GL_LINE_STIPPLE);
        glLineWidth(4);
        glBegin(GL_LINES);
        glLineStipple(1,0x0101);
        linea(x+i,y,lado);
        glEnd();
        glDisable(GL_LINE_STIPPLE);

    }

}

void triangulo (float x, float y, float z, float a, float b, float c, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_TRIANGLES);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glEnd();


}

void display(void)
{
glClearColor(0,0.6,1,0.6);//color de la ventana negro
glClear(GL_COLOR_BUFFER_BIT);

    cuadrado(4,-4,2,2,2,marron);
    cuadrado(6,-4,2,2,2,marron);
    cuadrado(2,-4,2,2,2,marron);
    cuadrado(0,-4,2,2,2,marron);
    cuadrado(-2,-4,2,2,2,marron);
    cuadrado(-4,-4,2,2,2,marron);
    cuadrado(-6,-4,2,2,2,marron);


    cuadrado(7,-6,2,2,2,marron);
    cuadrado(5,-6,2,2,2,marron);
    cuadrado(3,-6,2,2,2,marron);
    cuadrado(1,-6,2,2,2,marron);
    cuadrado(-1,-6,2,2,2,marron);
    cuadrado(-3,-6,2,2,2,marron);
    cuadrado(-5,-6,2,2,2,marron);
    cuadrado(-7,-6,2,2,2,marron);



    cuadrado(4,-4,2,3,2,gris);
    cuadrado(6,-4,2,3,2,gris);
    cuadrado(2,-4,2,3,2,gris);
    cuadrado(0,-4,2,3,2,gris);
    cuadrado(-2,-4,2,3,2,gris);
    cuadrado(-4,-4,2,3,2,gris);
    cuadrado(-6,-4,2,3,2,gris);

    cuadrado(7,-6,2,3,2,gris);
    cuadrado(5,-6,2,3,2,gris);
    cuadrado(3,-6,2,3,2,gris);
    cuadrado(1,-6,2,3,2,gris);
    cuadrado(-1,-6,2,3,2,gris);
    cuadrado(-3,-6,2,3,2,gris);
    cuadrado(-5,-6,2,3,2,gris);
    cuadrado(-7,-6,2,3,2,gris);


    cuadrado(4,-2,2,2,2,marron);
    cuadrado(6,-2,2,2,2,marron);

    cuadrado(4,-2,2,3,2,gris);
    cuadrado(6,-2,2,3,2,gris);

    cuadrado(4,0,2,2,3,marron);

    cuadrado(4,0,2,3,3,gris);

    cuadrado(4,3,2,2,2.5,marron);

    cuadrado(4,3,2,3,2.5,gris);

    cuadrado(4,5.5,2,2,2,marron);

    cuadrado(4,5.5,2,3,2,gris);

    cuadrado(4,7.5,2,2,1.5,marron);
    cuadrado(2.5,7.5,2,2,1.5,marron);
    cuadrado(1,7.5,2,2,1.5,marron);
    cuadrado(-0.5,7.5,2,2,1.5,marron);
    cuadrado(-2,7.5,2,2,1.5,marron);

    cuadrado(4,7.5,2,3,1.5,gris);
    cuadrado(2.5,7.5,2,3,1.5,gris);
    cuadrado(1,7.5,2,3,1.5,gris);
    cuadrado(-0.5,7.5,2,3,1.5,gris);
    cuadrado(-2,7.5,2,3,1.5,gris);


    cuadrado(-2.5,-2,2,2,2,marron);
    cuadrado(-4.5,-2,2,2,2,marron);

    cuadrado(-2.5,-2,2,3,2,gris);
    cuadrado(-4.5,-2,2,3,2,gris);

    cuadrado(-3.5,0,2,2,3,marron);

    cuadrado(-3.5,0,2,3,3,gris);

    cuadrado(-3,3,2,2,2.5,marron);

    cuadrado(-3,3,2,3,2.5,gris);

    cuadrado(-2.5,5.5,2,2,2,marron);

    cuadrado(-2.5,5.5,2,3,2,gris);
   // cuadrado(-3,2,-3,-2,2,-2,2,2,5,2,gris);
    //cuadrado(-3,2,-3,-2,2,-2,2,2,5,3,negro);

                    //glPointSize(7); // incrementa el tamaño del punto
                    //glLineWidth(5);//incrementa el ancho de la linea



//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

 glutSwapBuffers();                 // opcional funciona para algunos con esta funcion,... glFlush()
}






                            //funcion principal, siempre es de esa manera
int main(int argc, char *argv[])
{

    glutInit(&argc, argv);              //Sirve para inicializar mi ventana de opengl
    glutInitWindowPosition(0,0);        //parte la ventana en 4 partes y en (0,0) esta en el centro,posicion de mi ventana
    glutInitWindowSize(600,600);        //tamaño de mi ventana tamaño normal (600,600)
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);           //tipo de modo de visualizacion de la ventana

    glutCreateWindow("Primer programa");        //Colocar el nombre que se le da a la ventana
    glutDisplayFunc(display);                   //nombre de la función
    pantalla();
                            //glClearColor(1,1,1,1);//color de la ventana negro
    glutMainLoop();             //hace que aparezca la ventana
    return EXIT_SUCCESS;            //tambien se puede usar el return
}
