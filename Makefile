TARGET = lenia

SRCS = src/main.c src/window_manager.c

OBJS = $(SRCS:.c=.o)

BREW_PREFIX = /opt/homebrew

CFLAGS = -Wall -I$(BREW_PREFIX)/include
LDFLAGS = -L$(BREW_PREFIX)/lib -lSDL2

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

