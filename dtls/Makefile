OUT_FILE ?= dtls
SRC_DIR ?= src
GCC ?= gcc

all: $(SRC_DIR)/main.c
	$(GCC) -g -Wall -o $(OUT_FILE) $(SRC_DIR)/main.c

clean:
	rm -f $(OUT_FILE)
