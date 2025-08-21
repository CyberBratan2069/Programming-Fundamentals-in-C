CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = tool
SRCS = main.c tools.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: clean
