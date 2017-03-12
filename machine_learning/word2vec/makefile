CC = gcc
#Using -Ofast instead of -O3 might result in faster code, but is supported only by newer GCC versions
#CFLAGS = -lm -pthread -O3 -march=native -Wall -funroll-loops -Wno-unused-result
CFLAGS = -lm -pthread -Ofast -march=native -Wall -funroll-loops -Wno-unused-result

SRC_PATH=./src
BIN_PATH=./bin
MAKE_DIR := $(shell mkdir -p $(BIN_PATH))

SOURCE = $(wildcard $(SRC_PATH)/*.c)
BIN = $(addprefix $(BIN_PATH)/, $(foreach obj, $(subst .c,,$(SOURCE)), $(shell basename $(obj))))

all : $(BIN)

$(BIN) : $(BIN_PATH)/%: $(SRC_PATH)/%.c
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm -rf $(BIN_PATH)
