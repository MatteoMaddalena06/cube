# Cube
The program loaded in this repository displays a rotating cube on the screen. The rotation is done using the concepts exposed in this Wikipedia page https://en.wikipedia.org/wiki/Rotation_matrix:
The program stores the eight coordinates in the three-dimensional space of the cube by applying a rotation to them and projecting them onto the two-dimensional plane, thus displaying the cube on the screen.
# Source analysis
The program consists of 3 modules and 2 header files:

  • main.c ➜ it is the main module which takes care, through two special functions, of creating the       structure suitable for storing the data of the cube and making it rotate.
  
  • cube.c ➜ is the module containing the functions to manage the cube: it contains the functions to allocate and deallocate the structure containing the data of the cube and those to draw and rotate the latter.
  
  • utils.c ➜ it is the module containing the general utility functions such as those for converting a string into a numeric value and allocating the necessary matrices to manage the cube.
  
  • cube.h ➜ it is the header file containing the declarations of the structure capable of storing the data of the cube and of the functions to manage it.

  • utils.h ➜ is the header file containing the declarations of the general utility functions.
 
 # Run
To compile the program, use the following command:

	make 
    
To delete the program executable and its object files type the following command:

	make clean
    
To run the program instead, type the following command:

	./cube <side>
  
Where "side" indicates the size of the sides of the cube.

Note: the size of the cube can be any but for too large values you may not see it rotate. This is due to the size of the terminal, which in fact could wrap around the display of the cube and therefore not allow the rotation to be displayed correctly.
Before being displayed, the cube is stored in a square matrix with a dimension equal to twice its sides, if these dimensions exceed the vertical or horizontal ones of the terminal then this problem will occur.

You can tweak the program slightly to display the rotation of other objects, such as a pyramid or 3D pentagon, on the screen.
