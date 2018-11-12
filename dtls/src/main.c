#include <stdio.h>
#include <stdlib.h>
#include "ls.h"

int main(int argc, char **argv){
    FILE* file = fopen("/home/jam/Downloads/ls", "rb");
    LS_FILE *lsFile = ls_read(file);
	printf("Magic - %.*s\n", 2, (char*)lsFile);
	printf("Version - %i\n", lsFile->header.version);
	printf("Entry Count - %i\n", lsFile->header.entryCount);
    free(lsFile);
    return 0;
}
