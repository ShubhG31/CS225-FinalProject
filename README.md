# paulj3-shubhg3-devg2-pat4
[Describe project] by bug smashers

Github Organization – You should describe the physical location of all major files and deliverables (code, tests, data, the written report, the presentation video, etc…)

Running Instructions – You should provide full instructions on how to build and run your executable, including how to define the input data and output location for each method. You should also have instructions on how to build and run your test suite, including a general description on what tests you have created. It is in your best interest to make the instructions (and the running of your executables and tests) as simple and straightforward as possible.

## Running Instructions
   To run our project on your machine, you first need to clone this repository on your machine. After doing so, you will need to go into the cs225final file. To run the 



## Github Organization
   All our code is stored inside the css225final folder. The folder contains cpp files, such as main.cpp, StickerSheet.cpp, graph.cpp, Image.cpp, contain the major files that the project uses. The txt files in the folder are the files that are parsed to store in  data structures, such vectors etc, to be used in the rest of the code. 
   ### CSV_tests 
   Contains our txt files that we use for test cases to check our parsing functions. They are used to see if the values provided for each node or each location are read and stored correctly.   
  #### Files 
  - edges.csv
  - edge2.csv
  - node.csv

  ### cs225 
   This file is provided in all MP code to students of cs225 at UIUC, to be able to change PNGs. This code is used by our stickersheet.cpp in order to create our png image containing our shortest path from locations. 
   #### Folders 
   - Catch
      - catch.hpp
      - catchmain.cpp
   - lodepng
     - lodepng.cpp
     - lodepng.h
   - make
      - cs225.mk
   #### Files 
   - HSLAPixel.cpp
   - HSLAPixel.h
   - PNG.cpp
   - PNG.h
   - RGB_HSL.h
 ### tests
  this folder holds the files related to testing our project. The file checks our Dkjistras Algorithm, Drawing Connections, Zoom in, and BFS. 
   #### Files
   - tests.cpp
```bash
./cs225final>dir 
  


```
