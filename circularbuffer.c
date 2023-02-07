/*******************************************************************************************
* File Name          : circularbuffer.c
* Description        : Circular Buffer
*                      This program should implement a circular buffer to write/read a string
*
* Author:              Arshdeep Singh
* Date:                2022-04-17
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE    20 // size of the buffer (should be larger than 1)

char circularbuffer[BUF_SIZE];
int size = 0;  // current buffer size
int start = 0; // read index
int end = 0;   // write index

// data used for test
char* iData[] = {
    "In computer science, a circular buffer, circular queue, cyclic buffer or ring buffer is a data structure that uses a single, fixed-size buffer as if it were connected end-to-end.",
    "This structure lends itself easily to buffering data streams.",
    "There were early circular buffer implementations in hardware."
};
// end of data for assignment

// circular buffer functions
int writeBuf(char);             // put a char into the buffer
char readBuf();                 // get a char out of the buffer

int main() {
    for (int test = 0; test < sizeof(iData)/sizeof(iData[0]); test++) {
        // for each test
        // reset buffer
        int nchars = 1;
        size = 0;
        start = 0;
        end = 0;

        // set write char (wc) pointer to a new test string
        char* wc = iData[test];
        while(1) {
            // keep putting into the buffer until blocked
            while (!writeBuf(*wc)) { wc++; }

            // read nchars, BUF_SIZE(nchars) == BUF_SIZE
            for (int i=0; i < nchars; i++) {
                char rc = readBuf();
                printf("%c", rc);
                if (rc == '\0') {
                    printf("\n");
                    goto out;
                }
            }
            printf("\n");
            // double the size of chars to read next time
            nchars = nchars*2 <= BUF_SIZE ? nchars*2 : BUF_SIZE;
        }
out:
        // extra newline to indicate the end of current test
        printf("\n");
    }
    return 0;
}

//====================== You should not modify anything above ==============================//
//==================== You should only modify following functions ==========================//
//============================= do not remove above comments  ==============================//

// FUNCTION      : writeBuf
//
// DESCRIPTION   :
//   This function will put new char into the circular buffer
//
// PARAMETERS    :
//   c - the char
//
// RETURNS       :
//   0 if successful, -1 if failed
int writeBuf(char c)
{
    int size = 200;
    ;
    if ((end + 1) % size == start)
    {
        return -1;
    }
    else
    {
        circularbuffer[end] = c;
        end++;
        return 0;
    }
}

// FUNCTION      : readBuf
//
// DESCRIPTION   :
//   This function will read a char from the circular buffer
//
// PARAMETERS    :
//   None
//
// RETURNS       :
//   char
char readBuf()
{
    char c = '\0';
    if ((start - 1) % BUF_SIZE == end)
    {
        return c;
    }
    else
    {
        c = circularbuffer[start];
        start++;
    }
    return c;
}
