TARGET=linux
CC=gcc
CC_TARGET=x86_64
CC_FLAGS= -I$(INCLUDE) -Wall -Wextra -Werror -c
RS=cargo

all: build run

build:
	$(RS) build --release
	$(CC) $(CC_FLAGS) ./src/entry_$(TARGET).c
	$(CC) entry_$(TARGET).o ./target/release/librandui.a -o randui

run:
	