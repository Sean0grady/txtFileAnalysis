/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Sean O'Grady
 *
 * Created on April 14, 2021, 10:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * lab 3
 * This program will read in a .dat or .txt file
 * and print out the number of newlines '\n'
 * the number of words(Non contiguous white space)
 * and the number of bytes(So really any character)
 */
int main(int argc, char** argv) {
    int  wordCount = 0, nlCount = 0, byteCount = 0, flag = 1;
    char buffer[201];
    
    //as explained in handout element [1] of argv contains our filename 
    //we pass that as an arg to fopen in place of prompting for the filename
    FILE *infile = fopen(argv[1], "r");
    
    
    //check if file passed if valid
    if(infile == NULL){
        perror("The file you're looking for could not be located");
        exit(1);
    }
    
    
    //While loop to iterate through entirety of file
    while(fgets(buffer, sizeof(buffer), infile) != NULL){
        for(int i = 0; buffer[i] != '\0'; i++){
            
            //Our flag lets us know if we're encountering null
            //whitespace or a new line if it is any of these
            //that indicates we're not in a word so flag is false
            if(buffer[i] == 32 || buffer[i] == 0 || buffer[i] == 10){
                flag = 0;
            } else {
                flag = 1; //flag = 1 indicates we're in word
            }
            
            //If we're not inside a word and our prev element
            //in buffer was not more white space then we increment
            //wordCount
            if(flag == 0 && buffer[i-1] != 32){
                wordCount++;
            }
            
            
            //if newline character found increment
            if(buffer[i] == '\n'){
                nlCount++;
            }
            
            //if our next element is NULL then our loop wont iterate
            //Take a peak at the next array element, check for null, 
            //and increment bytes if found to account for this
            if(buffer[i + 1] == '\0') byteCount++;
            
            //increment byte count every iteration
            byteCount++;
        }
        
    }
    
    
    //print results
    printf("Word Count: %d \n", wordCount);
    printf("Newline count: %d \n", nlCount);
    printf("Byte count: %d \n", byteCount);
    
    
    //close file
    fclose(infile);
    
    return (EXIT_SUCCESS);
}

