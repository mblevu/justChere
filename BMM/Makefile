CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
EXEC = memory_manager

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

check_headers:
	@echo "Checking header files..."
	@for file in $(SRC); do \
		if ! grep -q '#include "memory_manager.h"' $$file; then \
			echo "Error: Header file memory_manager.h is missing in $$file"; \
			exit 1; \
		fi; \
	done
	@echo "All header checks passed."

check: check_headers

