#include <stdint.h>

typedef struct LS_HEADER {
	char magic[2];
	uint16_t version;
   	uint16_t entryCount;	
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
