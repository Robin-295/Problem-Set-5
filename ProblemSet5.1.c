#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 32;

void appendCharacter(int n, char chr, char chrs[]);
void saveNgram(int n, char chrs[], FILE *file);

int main(int argc, char *argv[]) {
  // Check for the argument count
  if(argc != 2){
    printf("Usage: $./Ngram (value of n between 2 ~ 32)\n");
    return 1;
  }

  // Get n from user. Keep the range of n between 2 ~ 32.
  int n;
  if(((n = atoi(argv[1])) < 1) || (n >= SIZE)){
    printf("The value of n is not valid.\n");
    return 1;
  }

  // character is for fgetc. charaters hold letter sequence for ngram.
  char character, characters[n];

  // Open text files
  FILE *readFile;
  FILE *writeFile;
  
  readFile = fopen("LoremIpsum.txt", "r");
  writeFile = fopen("Ngram.txt", "w");

  if(readFile == NULL){
    printf("File cannot be opened or does not exist.\n");
    return 1; //Return error
  }

  if(writeFile == NULL){
    printf("File cannot be opened.\n");
    return 1; //Return error
  }

  // Read the first n characters in the file
  for(int i = 0; i < n; i++){
    characters[i] = fgetc(readFile);
  }

  // Read one character at a time from a file until the end
  while((character = fgetc(readFile)) != EOF){
    if(character != '\n'){
      saveNgram(n, characters, writeFile);
      appendCharacter(n, character, characters);
    }
  }

  if(readFile) fclose(readFile);
  if(writeFile) fclose(writeFile);

  return 0;
}

void appendCharacter(int n, char chr, char chrs[]) {
//n is the size of the n-gram
//chr is the character to append
//chrs[] is the current n-gram that chr gets appended to

	//shift all characters in chrs one to the left
	for(int i = 0; i < n; i++){
		chrs[i] = chrs[i+1];
	}

	//add the new character
	chrs[n-1] = chr;

	return;
}

void saveNgram(int n, char chrs[], FILE *file) {
//n is the size of the n-gram
//chrs[] is the current n-gram to save
//file is the output file Ngram.txt

	//write the n-gram
	for(int i = 0; i < n; i++){
    		chrs[i] = fputc(chrs[i], file);
  	}

	//write the new-line
	fputc('\n', file);

	return;

}

