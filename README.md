Downdloading GLFW
-

Downdload GLFW's Source package [here](https://www.glfw.org/download.html)

Unzip the file:

![Alt text](https://github.com/miikapalosaari/OpenGL/blob/master/Docs/1.png)

Create "build" folder to the unzipped folder.


Generating GLFW solution with CMake
-

Downdload CMake [here](https://cmake.org/download/)

![Alt text](https://github.com/miikapalosaari/OpenGL/blob/master/Docs/2.png)

1. Browse for the source code. 
2. Browse for the build folder. 

![Alt text](https://github.com/miikapalosaari/OpenGL/blob/master/Docs/3.png)

Press configure button below.

Under "Specify the generator for this project" select the newest version.

Then select Finish.

Press configure button again and then generate.

Now when you go to the build folder, you can find GLFW.sln file which you can open with visual studio.


Creating glfw3.lib
-

![Alt text](https://github.com/miikapalosaari/OpenGL/blob/master/Docs/4.png)

Select "Release" and "x64" then build the solution.

Next go to folder build -> src -> release and take the lib file from it.

Create root folder named opengl_lib (c/opengl_lib).

Put glfw3.lib in to opengl_lib folder.

Next go to the unzipped glfw folder and inside that there is "GLFW folder" which you need to put to opengl_lib folder.

Setting up glad
-

Download glad for opengl [here](https://glad.dav1d.de/)

![Alt text](https://github.com/miikapalosaari/OpenGL/blob/master/Docs/5.png)

1. Set language to C/C++
2. Set specification to OpenGL
3. Set gl API to newest release
4. Hit generate button below
5. Download glad.zip

Unzip the glad.zip and open the folder.

Go to glad -> src and take the glad.c file and put it to opengl_lib folder.

Next go to glad -> include and take folders "glad" and "KHR" and put them in to folder opengl_lib.

Setting up a visual studio project
-

Create or open visual studio project.

Go to Project -> Properties -> VC++ Directories:

![Alt text](https://github.com/miikapalosaari/OpenGL/blob/master/Docs/6.png)

In both "Include directories" and "Library directories" select path c/opengl_lib.

Next in project properties go to Linker -> input -> additional dependencies and add these:

"opengl32.lib" and "glfw3.lib"

Lastly you need to add glad.c from the opengl_lib folder to your visual studio project in the source files.


