# Graphic-Visualization-of-classroom
Code is in C++ language. 
## OpenGL Installation
### Ubuntu
Open terminal and run the following
```sh
sudo apt install freeglut3-dev
```
To run the code
```sh
cd Code
g++ ./cg_classroom.cpp -o classroom -lGL -lGLU -lglut
./classroom
```

### Mac
Open terminal and run the following 
```sh
cd Code
gcc cg_classroom.cpp -o classroom -framework OpenGL  -framework GLUT
```
