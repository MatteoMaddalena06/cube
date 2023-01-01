#ifndef CUBE_H
#define CUBE_H

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define APPLY_ROTATION_X x*c*c - y*s*c + z*s
#define APPLY_ROTATION_Y x*(s*s*c+s*c) + y*(c*c-s*s*s) - z*s*c
#define APPLY_ROTATION_Z x*(s*s-s*c*c) + y*(s*s*c+s*c) + z*c*c

typedef struct cube_data
{
    unsigned int side;
    double**     coordinate_3D;
    int**        window;

} cube_st;

cube_st  create_cube(int);
void     delete_cube(cube_st*);
void     rotate_cube(cube_st, int);
double** apply_rotate(double**, double);
void     render_cube(double**, int**, int);
void     print_window(int**, int);
void     clear_window(int**, int);
void     draw_line(int, int, int, int, int**, int);
void     init_coordinate(double**, int);

#endif
