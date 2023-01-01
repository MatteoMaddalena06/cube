#include "header/cube.h"
#include "header/utils.h"

void rotate_cube(cube_st cube, int angle)
{
    double rad = (double)angle * (M_PI/180.0);
    double** new_coordinate = apply_rotate(cube.coordinate_3D, rad);

    render_cube(new_coordinate, cube.window, cube.side*2);

    delete_matrix((void**)new_coordinate, 8, 3);
}

double** apply_rotate(double** coordinate_3D, double angle)
{
    double x, y, z, s, c;
    double** new_coordinate_3D = create_dmatrix(8, 3);

    for(int i = 0; i < 8; i++)
    {
        x = coordinate_3D[i][0];
        y = coordinate_3D[i][1];
        z = coordinate_3D[i][2];

        c = cos(angle); s = sin(angle);

        new_coordinate_3D[i][0] = APPLY_ROTATION_X;
        new_coordinate_3D[i][1] = APPLY_ROTATION_Y;
        new_coordinate_3D[i][2] = APPLY_ROTATION_Z;
    }

    return new_coordinate_3D;
}

void render_cube(double** coordinate_3D, int** window, int dim)
{
    int x1, y1, x2, y2, x3, y3;

    //render the cube
    for(int i = 0; i < 8; i++)
    {
        x1 = coordinate_3D[i][0]; y1 = coordinate_3D[i][1];

        if(i == 3 || i == 7)
        {
            x2 = coordinate_3D[i-3][0];
            y2 = coordinate_3D[i-3][1];
        }
        else
        {
            x2 = coordinate_3D[i+1][0];
            y2 = coordinate_3D[i+1][1];
        }

        if(i < 4)
        {
            x3 = coordinate_3D[i+4][0]; y3 = coordinate_3D[i+4][1];
            draw_line(x1, y1, x3, y3, window, dim/2);
        }

        draw_line(x1, y1, x2, y2, window, dim/2);

    }

    print_window(window, dim);
    clear_window(window, dim);
}

void draw_line(int x1, int y1, int x2, int y2, int** window, int half)
{
    double q, m;
    int step = 1, y, x, k = 1;

    if(x1 == x2 && y1 == y2)
    {
        window[half-y1][half+x2] = 1;
        return;
    }

    if(x1 == x2)
    {
        q = x1;
        m = 1;
    }
    else
    {
        m  = (double)(y2-y1)/(double)(x2-x1);
        q = (double)(x1*y2-x2*y1)/(double)(x1-x2);
    }

    if(abs(x2 - x1) >= abs(y2 - y1))
    {
        if(x1 > x2)
          step = -1;

        while(x1 != x2 + step)
        {
            y = (double)half - (m*(double)x1 + q);
            window[y][half+x1] = 1;
            x1 += step;
        }
    }
    else
    {
        if(y1 > y2)
          step = -1;

        while(y1 != y2 + step)
        {
            if(x1 == x2)
            {
                y = 0;
                k = -1;
            }
            else
              y = y1;

            x = (double)half-((q-(double)y)/m)*(double)k;
            window[half-y1][x] = 1;
            y1 += step;
        }
    }
}

void print_window(int** window, int dim)
{
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if(window[i][j])
              printf("1 ");

            else
              printf("  ");
        }

        printf("\n");
    }
}

void clear_window(int** window, int dim)
{
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
          window[i][j] = 0;
    }
}

cube_st create_cube(int side)
{
    cube_st new_cube;

    new_cube.side = side;
    new_cube.coordinate_3D = create_dmatrix(8, 3);
    new_cube.window = create_imatrix(side*2, side*2);

    init_coordinate(new_cube.coordinate_3D, side);

    return new_cube;
}

void delete_cube(cube_st* cube)
{
    delete_matrix((void**)cube->coordinate_3D, 8, 3);
    delete_matrix((void**)cube->window, cube->side*2, cube->side*2);
    cube->side = 0;
}

void init_coordinate(double** coordinate_3D, int side)
{
    // 1. vertex
    coordinate_3D[0][0] = coordinate_3D[0][1] = coordinate_3D[0][2] = -side/2;
    // 2. vertex
    coordinate_3D[1][1] = coordinate_3D[1][2] = -side/2; coordinate_3D[1][0] = side/2;
    // 3. vertex
    coordinate_3D[2][0] = coordinate_3D[2][2] = side/2; coordinate_3D[2][1] = -side/2;
    // 4. vertex
    coordinate_3D[3][0] = coordinate_3D[3][1] = -side/2; coordinate_3D[3][2] = side/2;
    // 5. vertex
    coordinate_3D[4][0] = coordinate_3D[4][2] = -side/2; coordinate_3D[4][1] = side/2;
    // 6. vertex
    coordinate_3D[5][0] = coordinate_3D[5][1] = side/2; coordinate_3D[5][2] = -side/2;
    // 7. vertex
    coordinate_3D[6][0] = coordinate_3D[6][1] = coordinate_3D[6][2] = side/2;
    // 8. vertex
    coordinate_3D[7][1] = coordinate_3D[7][2] = side/2; coordinate_3D[7][0] = -side/2;

}
