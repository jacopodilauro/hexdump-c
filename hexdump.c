#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>
static size_t nline = 0;
#define HEXDUMP_CHARS_PER_LINE 16
void hexdump(char *buf, size_t len){
	printf("%08X  ", nline); nline++;
	for(int i = 0; i < len; i++){
		if((i % 8 == 0) && (i % 16 != 0) ) { printf(" "); }
		printf("%02X ", buf[i]);
	}
	int rest = len % HEXDUMP_CHARS_PER_LINE;
	if(rest != 0){
	//The line is filled with "~~ " if it's not divisible by 16
		for(int j = 0; j < (HEXDUMP_CHARS_PER_LINE - rest); j++){ 
			if(((j + rest) % 8 == 0) && ((j + rest) % 16 != 0)) { printf(" "); }
			printf("~~ "); 
		}
	}
	//Check that the character can be printed
	//Print 16 characters per line of the buffer (file)	
	//printf("\t|");
	printf("  |");
	for(int i = 0; i < len; i++){ 		
		char c = isprint((unsigned char)buf[i])? buf[i] : '.';
		printf("%c", c); 
	}
	printf("|\n");
}
int main(int argc, char *argv[]){
	if(argc != 2){
		fprintf(stderr, "Usage: <exc name> <filename>\n");
		return 1;
	}
	const char *filename = argv[1];
	int fp = open(filename, O_RDONLY);
	if(fp == -1){
		perror("Unable to open file");
		close(fp);
		return 1;
	}

	char buf[HEXDUMP_CHARS_PER_LINE];
	ssize_t p;
	while((p = read(fp, buf, sizeof(buf))) > 0){
		hexdump(buf, p);
	}
	if(p == -1){
		perror("Error reading file");
		close(fp);
		return 1;
	}
	printf("\n");
	close(fp);
	return 0;
}
