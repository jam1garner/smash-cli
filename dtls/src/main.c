#include <stdio.h>
#include <stdlib.h>
#include "ls.h"

int main(int argc, char **argv){
    FILE* file = fopen("/home/jam/Downloads/ls", "rb");
    LS_FILE *lsFile = ls_read(file);
    printf("Magic - %.*s\n", 2, (char*)lsFile);
    printf("Version - %i\n", lsFile->header.version);
    printf("Entry Count - %X\n", lsFile->header.entryCount);
    printf("------------------\n");
    LS_ENTRY_NODE *current = lsFile->first;
    while(current){
        printf("CRC - %08X\n", current->entry.crc);
        printf("Data Offset - %X\n", current->entry.dataOffset);
        printf("Length - %X\n", current->entry.length);
        printf("------------------\n");
        current = current->next;
    }
    free(lsFile);
    return 0;
}
