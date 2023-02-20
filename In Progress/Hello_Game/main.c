#include <stdio.h>
#include <SDL2/SDL.h>

const int WIDTH = 1920,HEIGHT = 1080,SPEED = 18;

typedef struct
{
    int x,y;
    short life;
    char *name;
}Man;

int main(int argc,char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO); //initialising SDL2
    SDL_Window *window; //Declaring a window
    SDL_Renderer *renderer; //Declaring a renderer
    //Creating window
    window = SDL_CreateWindow(
        "Hello_Game",               //Title
        SDL_WINDOWPOS_CENTERED,     //initial x position
        SDL_WINDOWPOS_CENTERED,     //initial y position
        WIDTH,                      //width in pixel
        HEIGHT,                     //Height in pixel
        SDL_WINDOW_FULLSCREEN|SDL_WINDOW_OPENGL                           //SDL_WINDOW_FULLSCREEN|SDL_WINDOW_OPENGL - Flags
    );
    if (window == NULL)
    {
        printf("Couldnt Create Window %s", SDL_GetError());
        return 1;
    }
    //SDL_GL_CreateContext(window); //Creating SDl Using Opengl
    //Creating Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    int doneFlag = 0;
    SDL_Event WindowEvent; //
    int posX = 880, posY = 540;
    while (!doneFlag)
    {
        while(SDL_PollEvent(&WindowEvent))
        {
            switch (WindowEvent.type)
            {
                case SDL_WINDOWEVENT_CLOSE:
                    if(window)
                    {
                        SDL_DestroyWindow(window);
                        window = NULL;
                        doneFlag = 1;
                    }
                    break;
                case SDL_KEYDOWN:
                    switch (WindowEvent.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            doneFlag = 1;
                            continue;
                        case SDLK_w:
                            printf("Going up\n");
                            posY-=SPEED;
                            continue;
                        case SDLK_s:
                            printf("going down\n");
                            posY+=SPEED;
                            continue;
                        case SDLK_a:
                            printf("going left\n");
                            posX-=SPEED;
                            continue;
                        case SDLK_d:
                            printf("going right\n");
                            posX+=SPEED;
                            continue;
                        //case SDLK_f:
                        //    printf("Inside F");
                        //    int i,j;
                        //    for(i=0;i<HEIGHT;i++)
                        //    {
                        //        for (j=0;j<WIDTH;j++)
                        //        {
                        //            SDL_SetRenderDrawColor(renderer,3,238,241,255); //setting renderer colour to white
                        //            SDL_Rect rect = {j, i, 1, 1}; //Creating a rectangle structure
                        //            SDL_RenderFillRect(renderer,&rect);
                        //            SDL_RenderPresent(renderer); //displaying the rendere we just drawn
                        //            SDL_Delay(5)
                        //        }
                        //    }
                        //    SDL_Delay(2500);
                        //    break;
                    }
                case SDL_QUIT:
                    doneFlag = 1;
                    break;
            }
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,255); //Setting Renderer Colour as r,g,b,a
        SDL_RenderClear(renderer); //Clearing screen to drawing colour intitiated above
        SDL_SetRenderDrawColor(renderer,3,238,241,255); //setting renderer colour to white
        //SDL_Rect rect = {posX, posY, 20, 20}; //Creating a rectangle structure
        //SDL_RenderFillRect(renderer,&rect);
        SDL_RenderPresent(renderer); //displaying the rendere we just drawn
        SDL_Delay(5); //delay is important to not overload CPU
    }
    
    exitLoop:
    //SDL_GL_SwapWindow(window);
    if(window)
    {
        SDL_DestroyWindow(window);
    }
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
