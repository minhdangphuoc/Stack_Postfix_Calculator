# Stack_Profix_Calculator
- This is a repository for PostFix calculator using Stack.
- The source code is done for 5G00DM61-3003 Programming Languages 3.

## Concept

In this exercise, either different variations of the postfix calculator or different variations of the symbol balancing program are made. Specifications for variations are described below. Also below is a list of return requirements.
 
When doing the work, follow the order one-point job -> two-point job ->…, ie a job worth five points must contain all the required functions of levels 1 - 5. Thus, the work should be done incrementally, always step by step in this order. When moving to work worth the next point, don’t take any old qualities/code out of your work.
## Requirements

1.1.1 One-point job requirements
Implement a working PostFix calculator using the program codes given in the lecture materials. No additional operations are required for this version.

1.1.2 Two-point job requirements
The calculator must implement the requirements of a one point, and in addition, it must have an exchange function (for example, the command x (exchange) in it’s UI), which exchanges the contents of the two top elements in the stack used by the calculator during the run. For example, the calculation could be:
1 2 x -
, which calculates 2 - 1.

1.1.3 Three-point job requirements
Add a sum function to the calculator (command s (= sum)), which calculates the sum of all the numbers currently in the stack, then removes the numbers used for summing from the stack, and finally adds the total sum to the top of the stack.
E.g. running following:
1 2 3 s
Then afterwards there is only one item in the stack with a value of 6.

1.1.4 Four-point job requirements
Implement an average function to your calculator that calculates the average of all the numbers in the stack. The numbers involved in the averaging are removed from the stack (all) and the result (average) is pushed on the stack. Name this calculation a in UI (= average).

1.1.5 Five-point job requirements
Make an user interface on your calculator similar to the dc program found on most Unix / Linux systems, which does not print any prompts to the console but the user inputs directly to it the whole postfix expression and the program prints its value (see http://en.wikipedia.org/wiki/Dc_ (computer_program)). Example:
1 3 + 7.5 -
-3.5
The five-point calculator program must have the following calculations: addition (+), subtraction (-), multiplication (*), division (/), remainder operation (%), power increase (^), square root (v), and the calculations required above for four points.
Because five point program variant must include all requirements listed above include it it the possibility to use prompts if desired. For example you start the calculator program this way from cmd-tool if you want prompts: calculator.exe -p
(= prompt).

## Manual
This project using meson to build, so you have to download and install it to your computer.
[Meson Build](https://mesonbuild.com/)

### Build
``` cli
meson setup builddir //  Initialize the build
cd builddir // Move to build dirrectory
ninja && ./main // Run built
```

### Change name of built
Change this code in meson.build for changing the name.
```
// meson.build
...
executable('main', 'main.cpp', link_with : lib) // change main to another name
...
```
## Issues
- Not yet found.
