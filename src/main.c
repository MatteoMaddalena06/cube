#include "header/cube.h"
#include "header/utils.h"

int main(int argv, char** args)
{
    int angle = 0;
    cube_st cube;

    if(argv != 2)
    {
        printf("Use: ./cube <side>.\n");
        return -1;
    }
    else if(args[1][0] == 0x2D)
    {
        printf("The side must be positive.\n");
        return -1;
    }

    cube = create_cube(char2int(args[1]));

    while(1)
    {
        CLRSCRN
        rotate_cube(cube, angle);

        angle++;

        if(angle == 361)
          angle = 0;

        usleep(9250);
    }

    delete_cube(&cube);
}
