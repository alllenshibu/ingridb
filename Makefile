SHELL = /bin/sh
CC = gcc

.SUFFIXES:
.SUFFIXES: .c .o

SRC_DIR = src
BUILD_DIR = build

.PHONY: engine isql clean

engine = $(wildcard $(SRC_DIR)/engine/*.c)

isql: $(BUILD_DIR)/isql.bin 

$(BUILD_DIR)/isql.bin: $(SRC_DIR)/bin/isql/main.c $(engine) | $(BUILD_DIR)
	$(CC) -I$(SRC_DIR)/engine $^ -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
