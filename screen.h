#include <SDL2/SDL.h>
#include <vector>

class Screen{
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<SDL_FPoint> points;

    public:
    Screen(){
        SDL_Init(SDL_INIT_VIDEO);
        SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);      
        SDL_RenderSetScale(renderer, 2, 2);
    }

    void pixel(float x, float y){
        SDL_FPoint point{x,y};
        points.emplace_back(point);    // creates a new point structure to the vector or use pushback
    }
    
    void show(){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // draw color is black
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // set the color to white to draw pixels
        for(auto& point : points){
            SDL_RenderDrawPointF(renderer, point.x, point.y);
        }
        SDL_RenderPresent(renderer);
    }
    void clear(){
        points.clear();
    }
    void input(){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                SDL_Quit();
                exit(0);
            }
        }
    }

};