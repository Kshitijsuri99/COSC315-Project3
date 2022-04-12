# COSC315-Project3

##Part-1: Memory Management - paging 

The first part of the project implements a virtual address to physical address translator. The n lowest significant bits represents the offset, and the rest of the m bits represent the page number.  

The length of the number is always 16 bits and any number with more than 16 bits has the remaining bit dropped. 

**n - the n lowest significant bits that represent the offset**
**m - the next m bits that represent the page number; assume that n+m is always 16**

Input: A .txt file with first two lines representing n and m respectively and then n random integers to translate.
e.g. 

`3
13
14503
15603
13450
14560
20342
23233
33451`

Output: Virtual addresses with the page number p and offset d

**virtual address v1 is in page number p and offset d
virtual address v2 is in page number p and offset d
...**
