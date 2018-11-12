#include <stdint.h>
#include <stdio.h>

// Definitions of LS file structs
typedef struct LS_HEADER {
	char magic[2];
	uint16_t version;
   	uint32_t entryCount;	
} LS_HEADER;

typedef struct LS_ENTRY {
	uint32_t crc;
	uint32_t dataOffset;
	uint32_t length;
} LS_ENTRY;

typedef struct LS_ENTRY_V2 {
	uint32_t crc;
	uint32_t dataOffset;
	uint32_t length;
	uint16_t dtIndex;
	uint16_t unk;
} LS_ENTRY_V2;

// Definitions for LS interfacing
typedef struct LS_ENTRY_NODE {
	struct LS_ENTRY_NODE *next;
	union {
		LS_ENTRY entry;
		LS_ENTRY_V2 entry_v2;
	};
} LS_ENTRY_NODE;

typedef struct LS_FILE {
	LS_HEADER header;
	LS_ENTRY_NODE *first;
} LS_FILE;


// Provided functions
LS_FILE *ls_read(FILE *file){
    LS_FILE *lsFile = malloc(sizeof(LS_FILE));
	fread(lsFile, sizeof(LS_HEADER), 1, file);
	return lsFile;	
}
