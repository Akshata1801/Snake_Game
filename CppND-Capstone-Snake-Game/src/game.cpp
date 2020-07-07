#include "game.h"
#include <iostream>
#include "SDL.h"
#include <memory>
#include <thread>
#include "renderer.h"
#include "snake.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      engineObs(devObs()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
    
    //PlaceObjects();
    PlaceFood();
  //PlaceObstacle();
}


Game::Game()
{

}



void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake,food,obstacle);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PrintMsg()
{
  
  std::cout<<"You did a good job !!"<<std::endl;
}


void Game::PlaceFood() {
  int x, y, x_obs,y_obs;
  Game ga;
  //Game game;
  while (true) {
    
    std::vector<int> size_x,size_y;

    x = random_w(engine);
    y = random_h(engine);

    x_obs = random_w(engineObs);
    y_obs = random_h(engineObs);

    if (!snake.SnakeCell(x, y)) {
      if(x == x_obs && y == y_obs)
      {
        std::cout<<"same coordinates"<<std::endl;
      }
      else{
      food.x = x;
      food.y = y;
      obstacle.x = x_obs;
      obstacle.y = y_obs;

      return;
    }
    }
  }
}



void Game::SetInitialMode()
{
  std::cout<<"Initial mode"<<std::endl;
  snake.SetMode();
}

void Game::Update() {
  if (!snake.alive) 
  {
    std::cout << "Snake is dead"<<std::endl;
    //std::cout << "Your score is : "<<this->GetScore()<<std::endl;
    
    return;
  }
  
  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
    snake.InitialiseThread();
  }

  //Check if there is obstacle over here
  if(score == 1 && obstacle.x == new_x && obstacle.y == new_y)
  {
    std::cout<<"You hit the Obstacle !!!! "<<std::endl;
    std::cout<<"Your snake has no more energy left"<<std::endl;
    -- score;
    snake.alive = false;
  }
  else if(score == 0 && obstacle.x == new_x && obstacle.y == new_y)
  {
    snake.alive = false;
  }
  else if(obstacle.x == new_x && obstacle.y == new_y)
  {
    std::cout<<"You hit the Obstacle !!!! "<<std::endl;
    -- score;
    std::cout<<"score : "<<score<<std::endl;
    PlaceFood();

    
    
    
  }

  //std::cout<<"size: "<<snake.size<<std::endl;
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }