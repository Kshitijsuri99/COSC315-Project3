# COSC315-Project3

Team Members:
Florencia Chomski, Ahmad Raza Jamal, Kshitij Suri
 
### Contributions
All team members contributed to the success of this project. 

## Part-1: Memory Management - paging 

The first part of the project implements a virtual address to physical address translator. The n lowest significant bits represents the offset, and the rest of the m bits represent the page number.  

The length of the number is always 16 bits and any number with more than 16 bits has it's remaining bit dropped. 

**n - the n lowest significant bits that represent the offset** <br/>
**m - the next m bits that represent the page number; assume that n+m is always 16**

Input: A .txt file with the first two lines representing n and m respectively and then n random integers to translate.
e.g. 

3 <br/>
13 <br/>
14503 <br/>
15603 <br/>
13450 <br/>
14560 <br/>
20342 <br/>
23233 <br/>
33451 <br/>

Output: Virtual addresses with the page number p and offset d

**virtual address v1 is in page number p and offset d <br/>
virtual address v2 is in page number p and offset d
...**

#### How to run? Just run the makefile!

Sample Output: 

<img src="https://github.com/Kshitijsuri99/COSC315-Project3/blob/main/Part1/partA_sample.png"/>

## Part-2: File Systems

All the code requested to be implemented can be found in the Part 2 folder in fileSystem.c file

5 functions that are asked to be implemented were:
Create, Delete, Read, Write and LS. They all have been implemented 

To create disk 0 
We had to make some changes in the source code as it was giving compilation error.
We had to add a line of code in lab3.create_fs.c "#include <stdlib.h>"
After adding the line the code was compiled using "gcc lab3.create_fs.c"
Then "./a.out disk0" function was executed which further led to adding the file disk0

Due to a lack of experience from our team members in C, we struggled to implement the main method to run the second part. We've used several resources including the lecture materials and still struggled to complete. We focused the little time we had on implementing the five methods highlighted in the assignment instructions on Canvas. Given more time, we would have been able to do more research into the language and its specifics in order to be able to successfully complete this project. 