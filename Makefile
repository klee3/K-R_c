CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lm 
.PHONY: run

run:
	@ $(CC) $(CFLAGS) -o app $(FILE) $(LDFLAGS)
	@ ./app
