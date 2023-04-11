/*
 * Author: Nicole Hardy
 * Created: 29 March 2023
 * Edited: 30 March 2023 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *);

FILE* file;
FILE* outFile;
#define bufferLen 255
char input[bufferLen];

int main(int argc, char** argv) {

    if( argc > 2 || argc < 2) {
	exit(1);
    }

    file = fopen(argv[1], "r");

    if(file == NULL) { 
        printf("No such file\n");
	exit(1);
    } else {
        while(fgets(input, bufferLen, file)) {
	    compress(input);
	}
    }
    
    fclose(file);

    return 1;
}

void compress(char* input) {

    char current = input[0];
    int cnt = 1;

    for(int i = 1; input[i] != '\0'; i++) {
        if(input[i] == current) {
	    cnt++;
	} else {
	    fwrite(&cnt, 1,sizeof(cnt), stdout);
	    printf("%c", current);
	    current = input[i];
	    cnt = 1;
	}
    }
}
