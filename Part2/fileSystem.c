#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct inode {
  char name[8];
  int32_t size;
  int32_t blockPointers[8]; //direct block pointers
  int32_t used;
};

struct inode inodes[16];

struct super_block {
  char free_block_list[128];
};


void create(char name[8], int32_t size)
{ //create a file with this name and this size

  // high level pseudo code for creating a new file

  // Step 1: Look for a free inode by searching the collection of objects
  // representing inodes within the super block object.
  // If none exist, then return an error.
  // Also make sure that no other file in use with the same name exists.

    int availableInode = 16;
    printf("Creating a file...");
    for(int i=0; i<16; i++) { //file system supports a max of 16 files
        if(inodes[i].name == name) {
            printf("File Already Exists or the inode is being used...");
        }

        if(inodes[i].used == 1) {
            printf("inode already in use...");
        }
        else if (inodes[i].used == 0)
        {
            availableInode = i;
            break;
        }
    }

  // Step 2: Look for a number of free blocks equal to the size variable
  // passed to this method. If not enough free blocks exist, then return an error.

    if(availableInode == 16){
        printf("Not enough blocks free!");
    }

    for(int i = 0; i < size; i++){
        inodes[availableInode].blockPointers[i] = (availableInode+1);
    }

  // Step 3: Now we know we have an inode and free blocks necessary to
  // create the file. So mark the inode and blocks as used and update the rest of
  // the information in the inode.
    strcpy(inodes[availableInode].name, name);
    inodes[availableInode].size = size;
    inodes[availableInode].used = 1;
  // Step 4: Write the entire super block back to disk.
  //	An easy way to do this is to seek to the beginning of the disk
  //	and write the 1KB memory chunk.
  writeSuperBlock();
} // End Create



void delete(char name[8])
{
  // Step 1: Look for an inode that is in use with given name by searching the collection of objects
  // representing inodes within the super block object.
  int iIDX;
  for(int j=0; j<16; j++) { //file system supports a max of 16 files
    if(inodes[j].used == 1 || inodes[j].name == name) {
      iIDX = j;
    }
  }
  // If it does not exist, then return an error.
  if(iIDX != 15)
    printf("ERROR: File does not exist");
 
  // Step 2: Free blocks of the file being deleted by updating
  // the object representing the free block list in the super block object.
  struct inode node = inodes[iIDX];   //select the file being deleted
  for(int k=0; k<8; k++) {   //max size of a file is 8 blocks
    node.blockPointers[k] = 0; //set all block pointers to zero
  }

  // Step 3: Mark inode as free.
  inodes[iIDX] = node;
  inodes[iIDX].used = 0;

  // Step 4: Write the entire super block back to disk.
  writeSuperBlock();

} // End Delete

void ls(void)
{ 
  // List names of all files on disk

  // Step 1: Print the name and size fields of all used inodes.

} // End ls

void read(char name[8], int32_t blockNum, char buf[1024])
{

   // read this block from this file
   // Return an error if and when appropriate. For instance, make sure
   // blockNum does not exceed size-1.

   // Step 1: Locate the inode for this file as in Step 1 of delete.

   // Step 2: Seek to blockPointers[blockNum] and read the block
   // from disk to buf.

} // End read


void write(char name[8], int32_t blockNum, char buf[1024])
{

   // write this block to this file
   // Return an error if and when appropriate.

   // Step 1: Locate the inode for this file as in Step 1 of delete.

   // Step 2: Seek to blockPointers[blockNum] and write buf to disk.
   
} // end write