#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 32;
const int MAX_ARRAY_SIZE = 196605;

void sort(char arr[MAX_ARRAY_SIZE][SIZE], int size);
void countUniqueItems(int n, char ngram[MAX_ARRAY_SIZE][SIZE]);

int main(int argc, char *argv[]){
  int size = 0;
  char ngram[MAX_ARRAY_SIZE][SIZE];

  // Open text file in read mode
  FILE *readFile;
  readFile = fopen("Ngram.txt", "r");

  if(readFile == NULL){
    printf("File cannot be opened or does not exist.\n");
    return 1; //Return error
  }

  // Read each line in the text file using fgets()
  while(fgets(ngram[size], SIZE, readFile) != NULL){
    // Remove new line from the item
    for(int i = 0; i < SIZE; i++){
      if(ngram[size][i] == '\n'){
        ngram[size][i] = '\0';
      }
    }

    //Check to make sure we don't read more items than we can store in the ngram array
    if(size >= MAX_ARRAY_SIZE){
      fprintf(stderr, "Reached the maximum number of strings that the ngram array can hold.\n");
      break;
    }

    size++;
  }

  // Close the file since we are done reading it.
  if(!readFile) fclose(readFile);

  // Sort our ngram  
  sort(ngram, size);

  // Count unique items in the array and print it out on CLI
  countUniqueItems(size, ngram);

  return 0;
}

void sort(char arr[MAX_ARRAY_SIZE][SIZE], int size){
//arr is the group of strings to sort
//size is the number of strings to sort

	//if only one item to sort, nothing to do
	if(size == 1) return;

	// sort arr
	char temp[SIZE]; //temp string
    	for(int ii = 0; ii < size-1; ii++){
        	for(int i = ii+1; i < size; i++){
            		if(strcmp(arr[ii], arr[i]) > 0){
                		strcpy(temp, arr[ii]); 
                		strcpy(arr[ii], arr[i]); 
                		strcpy(arr[i], temp); 
            		} 
        	} 
    	}

	return;
}

void countUniqueItems(int n, char ngram[MAX_ARRAY_SIZE][SIZE]) {
//n is the number of ngrams
//ngram is the array of ngrams

	int i;	
	int count;

	for(i = 0; i < n; i++){
		count = 1;
		while(strcmp(ngram[i], ngram[i+1]) == 0){
			i++;
			count++;
		}
		printf("%s -> %d\n", ngram[i], count);
	}
	
	return;
}