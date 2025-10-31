/*****************************************************************************
* Name: ch2pun.c                                                             *
* Purpose: Prints, to play league or not to play league..., and floating     *
* point errors stuffs.                                                       *
* Author: SubmergedDuck                                                      *
******************************************************************************/

// --- Vim --- //
// Ctrl-C: open text editor navigation 
// i: write text
// gg: move to beginning of doucment
// G: move to end of document
// w: move to beginning of next word
// b: move to beginning of previous word
// 0: move to beginning of line
// $: move to end of line

// --- Git --- //
// git branch -M main: rename local branch to match the remote
// git fetch origin main: brings files from already created GitHub repo
// git config --global user.signingkey [key ID]
// git config --global commit.gpgsign true
// git push -u origin main: push to main branch

// --- GPG Keys --- // 
// gpg --list-secret-keys --keyid-format=long: see your keys
// gpg --full-generate-key: making a new GPG key
// gpg --armor --export [KEY ID] 

// --- Terminal --- // 
// mv: move or rename file, args: [source] [dest]
// cc: Clang Compiler
// gcc: GNU Compiler 
// gcc -Wall -W -pedantic -ansi -std=c23 -o

// --- C Programming: A Modern Approach --- // 
// (1) Pre-processor reads the directives
// (2) The compiler compiles your code to machine (object) code. 
// (3) A linker links object code and other additional code together to create an executable. 
// Additional Code: Eg. printf function from stdio.h

// Math on floats can be slower than integers
// Floats can have rounding errors, Eg. Storing 0.1 as a float -> 0.09999999999999987
// We can force %f to print how many p digits past the decimal point, Eg. "%.pf"

#include <stdio.h> // The # is means it is a directive. 
#include <math.h> // For fabs() 

float profit; 
float profit2; 
int rounded_profit; 

int main (){ 
    printf("To play league or not to play league... \n"); 
    
    // Best to append "f" to floats to not mix types.  
    profit = 69.69f;
    profit2 = 69.69000f; 
    rounded_profit = 70; 

    printf("Profit: %f \n", profit); 
    printf("Rounded Profit: %d \n", rounded_profit);
    
    printf("Profit 1 + Profit 2: %f \n", (profit + profit2)); 

    printf("Floating Point Error Fix: %.2f \n", (profit + profit2)); 
    

    return 0; 
}
