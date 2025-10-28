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

// --- C Programming: A Modern Approach --- // 
// (1) Pre-processor reads the directives
// (2) The compiler compiles your code to machine (object) code. 
// (3) A linker links object code and other additional code together to create an executable. 
// Additional Code: Eg. printf function from stdio.h

#include <stdio.h> // The # is means it is a directive. 

int main (){ 
    printf("To play league or not to play league... \n"); 
    return 0; 
}
