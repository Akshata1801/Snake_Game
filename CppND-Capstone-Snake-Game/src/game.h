#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include <thread>
#include <mutex>
#include <memory>

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void PrintMsg();
  Game();

  void SetInitialMode();

  std::mutex _mutex1;
  //std::shared_ptr<Renderer> rend;
  //std::shared_ptr<Game> ga{new Game()};
  

 private:
  Snake snake;
  SDL_Point food;
  SDL_Point obstacle;
  

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  std::random_device devObs;
  std::mt19937 engineObs;
  std::uniform_int_distribution<int> Obsrandom_w;
  std::uniform_int_distribution<int> Obsrandom_h;

  std::random_device dev_rand;
  std::mt19937 engine_rand;
  std::uniform_int_distribution<int> temprandom_w;
  std::uniform_int_distribution<int> temprandom_h;


  int score{0};

  void PlaceObjects();
  void PlaceFood();
  void PlaceObstacle();
  void Update();
};

#endif