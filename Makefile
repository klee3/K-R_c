CC = gcc
CFLAGS = -Wall -Wextra -O2

.PHONY: run

run:
	@ $(CC) $(CFLAGS) -o app $(FILE)
	@ ./app
