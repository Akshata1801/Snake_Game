#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();
  Renderer(){};

  void Render(Snake const snake, SDL_Point const &food, SDL_Point const &obstacle);
  void UpdateWindowTitle(int score, int fps);

  std::size_t GetGridHeight();
  std::size_t GetGridWidth();


 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

   std::size_t screen_width;
   std::size_t screen_height;
   std::size_t grid_width;
   std::size_t grid_height;
};

#endif