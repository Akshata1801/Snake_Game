# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Rubric Items Matching

## 1  `Object Oriented Programming - The project uses Object Oriented Programming techniques.
> The project is well divided into different classes and grouped according to the functionality like the information related to inclusion of obstacle rendering in defined in the render.cpp file from line no 61 as well as the constructor of renderer class is updates accordingly at line no.  15 in renderer.h file and corresponding changes are made to renderer.cpp file as well.

## 2 `Object Oriented Programming - Classes use appropriate access specifiers for class members.

> The project uses appropriate access specifiers. Like for example, in game.h at line no. 33, we have used the variable obstacles as private so that no one is able to mutate the variable. But the Function PrintMsg() in declared as public so that it can be called from the classes outside of game.

### 3 `Object Oriented Programming - Class constructors utilize member initialization lists.`

> Member initialiser lists are used wherever needed. For example, at line no. 9 in game.cpp file, the engine for generating the random co-ordinates for the obstacle is provided with the concerned random_device by passing it as input in member initialisation list.


### 4 `Object Oriented Programming - Classes abstract implementation details from their interfaces.`

> As required , member functions are declared in the header file and later on defined in the respective class. To name a few, in file snake.cpp from line no. 109, we have defined the class whereas declarartion in given in snake.h file at line no 28. Same is the case with InitialiseThread function the same file.

### 5 `Loops, Functions, I/O - The project accepts user input and processes the input.`

> The project takes the user input for setting up the mode and speed accordingly. The project validates the input and then proceeds forward.
For example in line no 20 in snake.cpp file.The function encapsulates the private variable snake of Gmae class in line no 31 and is called via SetMode member function of the same class.

### 6 The project uses smart pointers instead of raw pointers.

> The project uses smart pointers as compared to raw pointers for proper memory management as seen in line no. 48 of snake.cpp file.

### 7 The project uses multithreading.

> We have used the concept of threading in the project at line no. 49 in snake.cpp file. 

