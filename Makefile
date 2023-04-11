TARGET=linux
CC=clang
CC_TARGET=x86_64
CC_FLAGS=`sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -lm -Wall -Wextra -Werror \
-I$(INCLUDE)
INCLUDE=./include
RS=cargo

all: build run

build:
	@$(RS) build --release
	@$(CC) $(CC_FLAGS) ./src/entry_$(TARGET).c ./target/release/librandui.a ./lib/lib*.a \
	-o randui

run:
	@./randui
