#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include "SDL/SDL.h"
#include "SDL2/SDL_render.h"

extern void init();

int main(void) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

  init();

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("SDL_Init Error: %s", SDL_GetError());
    return 1;
  }
  SDL_Window *win =
      SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (win == NULL) {
    printf("SDL_CreateWindow Error: %s", SDL_GetError());
    return 1;
  }
  SDL_Renderer *ren = SDL_CreateRenderer(
      win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == NULL) {
    printf("SDL_CreateRenderer Error: %s", SDL_GetError());
    return 1;
  }
  // while(true) {}

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    uint64_t delta_time = (end.tv_sec - start.tv_sec) * 1000000 +
                          (end.tv_nsec - start.tv_nsec) / 1000;
    printf("\nThe elapsed time is [%f] milliseconds\n", delta_time / 1000.0);
  return 0;
}