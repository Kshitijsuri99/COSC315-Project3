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

**virtual address v1 is in page number p and offset d
virtual address v2 is in page number p and offset d
...**

Sample Output: 

<img src="https://github.com/Kshitijsuri99/COSC315-Project3/blob/main/Part1/partA_sample.png"/>
