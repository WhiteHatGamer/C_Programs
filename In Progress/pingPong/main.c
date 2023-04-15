#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#define pass (void)0

const int WIDTH = 1024, HEIGHT = 768,FPS = 60,SPEED = 5.0,BALLSPEED = 4;
enum Bool {false, true};
enum Bool Direction = false,YDirection = false;

void SDL_DrawCircle(SDL_Renderer *renderer,int xpos,int ypos,int radius);
void SDL_DrawFillCircle(SDL_Renderer *renderer,int xpos,int ypos,int radius);
void SDL_UpdateBallPosition(enum Bool *firstFlag,int *xpos,int *ypos);

int main(int argc,char *argv[])
{
    int P1vert=0,P2vert=0;
    enum Bool doneFlag = false;
    enum Bool firstFlag = true;
    GameReset:
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *Window;
    SDL_Renderer *Renderer;
    Window = SDL_CreateWindow(
        "Ping Pong HD",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_FULLSCREEN|SDL_WINDOW_OPENGL
    );
    if (Window==NULL)
    {
        printf("Some Error occured while Creating Window: %s",SDL_GetError);
    }
    Renderer = SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);
    int P1X = 0,P1Y = 70,P2X = 1004,P2Y = 70;
    int ballPosX = WIDTH/2,ballPosY = HEIGHT/2;
    SDL_Event WindowEvent;
    while (!doneFlag)
    {
        while (SDL_PollEvent(&WindowEvent))
        {
            switch(WindowEvent.type)
            {
                case SDL_WINDOWEVENT_CLOSE:
                {
                    doneFlag = true;
                    break;
                }
                case SDL_KEYDOWN:
                {
                    switch (WindowEvent.key.keysym.sym)
                    {
                        case SDLK_w:
                        {
                            P1vert = -1;//Plaayer1 move up;
                            continue;
                        }
                        case SDLK_s:
                        {
                            P1vert = 1;//PLayer 1 Move down;
                            continue;
                        }
                        case SDLK_a:
                        {
                            P1vert = 0;//PLayer 1 Move down;
                            continue;
                        }
                        case SDLK_UP:
                        {
                            P2vert = -1;//player 2 move up;
                            continue;;
                        }
                        case SDLK_DOWN:
                        {
                            P2vert = 1;//player2 Move Down;
                            continue;
                        }
                        case SDLK_RIGHT:
                        {
                            P2vert = 0;//player2 Move Down;
                            continue;
                        }
                        //case SDLK_SPACE:
                        //{
                        //    goto GameReset;//reset game;
                        //    continue;
                        //}
                        case SDLK_q:
                        {
                            printf("Wuit queue");
                            doneFlag = true;
                            break;
                        }
                        default:
                        {
                            continue;
                        }
                    }
                }
                case SDL_QUIT:
                {
                    doneFlag = true;
                    break;
                }
                default:
                {
                    continue;
                }
            }
        }
        P1Y += P1vert * SPEED;
        P2Y += P2vert * SPEED;
        P1Y = P1Y<0? 0 : (P1Y>668? 668 : P1Y); 
        P2Y = P2Y<0? 0 : (P2Y>668? 668 : P2Y);
        SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
        SDL_RenderClear(Renderer);
        SDL_SetRenderDrawColor(Renderer, 253, 62, 62, 255);
        SDL_RenderDrawLine(Renderer,0,HEIGHT/2,WIDTH,HEIGHT/2);
        SDL_UpdateBallPosition(&firstFlag,&ballPosX,&ballPosY);
        SDL_DrawFillCircle(Renderer,ballPosX,ballPosY,20);
        SDL_RenderDrawRect(Renderer,&(SDL_Rect){(WIDTH/2)-5,0,10,HEIGHT});
        SDL_SetRenderDrawColor(Renderer, 3, 238, 241,255);
        SDL_Rect rectP1 = {P1X, P1Y, 20, 100};
        SDL_RenderFillRect(Renderer, &rectP1);
        SDL_SetRenderDrawColor(Renderer, 254, 231, 21, 255);
        SDL_Rect rectP2 = {P2X, P2Y, 20, 100};
        //Program to find if colision happened
        SDL_RenderFillRect(Renderer,&rectP2);
        SDL_RenderPresent(Renderer);
        SDL_Delay(5);

    }
    if (Window)
    {
        SDL_DestroyWindow(Window);
    }
    SDL_DestroyRenderer(Renderer);
    return true;
}

void SDL_DrawCircle(SDL_Renderer *renderer,int xpos,int ypos,int radius)
{
    const int diameter = (radius*2); //20
    int x = (radius-1);
    int y = 0;
    int tx= 1, ty= 1;
    int error = tx-diameter;

    while(x>=y)//9>0:9>1:9>2:::::::5=5:4>=5-X-Exited
    {
        //Each iteration Renders octants of the circle
        SDL_RenderDrawPoint(renderer,xpos + x,ypos + y); //40+9,40+0:49,41:49,42:::49,45:48,45
        SDL_RenderDrawPoint(renderer,xpos + x,ypos - y); //40+9,40-0:49,39:49,38:::49,35:48,35
        SDL_RenderDrawPoint(renderer,xpos - x,ypos + y); //40-9,40+0:31,41:31,42:::31,45:32,45
        SDL_RenderDrawPoint(renderer,xpos - x,ypos - y); //40-9,40-0:31,39:31,38:::31,35:32,35
        SDL_RenderDrawPoint(renderer,xpos + y,ypos + x); //40+0,40+9:41,49:42,49:::45,49:45,48
        SDL_RenderDrawPoint(renderer,xpos + y,ypos - x); //40+0,40-9:41,31:42,31:::45,31:45,32
        SDL_RenderDrawPoint(renderer,xpos - y,ypos + x); //40-0,40+9:39,49:38,49:::35,49:35,48
        SDL_RenderDrawPoint(renderer,xpos - y,ypos - x); //40-0,40-9:39,31:38,31:::35,31:35,32

        if (error <= 0)
        {
            y++;//0:1:2:3:4:5
            error += ty; //-19:-16:-13:-8:-1:8:-9:
            ty += 2;//1:3:5:7:9:11:13
        }
        else if (error > 0)
        {
            x--;//9:8:7:6:5 - Exited
            tx += 2;//1:3
            error += (tx-diameter);//-9
        }
    }
}

void SDL_DrawFillCircle(SDL_Renderer *renderer,int xpos,int ypos,int radius)
{
    const int diameter = (radius*2);

    int x = (radius-1);
    int y = 0;
    int tx = 1,ty=1;
    int error = (tx-diameter);

    while (x>=y)
    {
        SDL_RenderDrawLine(renderer,xpos,ypos,xpos+x,ypos+y);
        SDL_RenderDrawLine(renderer,xpos,ypos,xpos+x,ypos-y);
        SDL_RenderDrawLine(renderer,xpos,ypos,xpos-x,ypos+y);
        SDL_RenderDrawLine(renderer,xpos,ypos,xpos-x,ypos-y);
        SDL_RenderDrawLine(renderer,xpos,ypos,xpos+y,ypos+x);
        SDL_RenderDrawLine(renderer,xpos,ypos,xpos+y,ypos-x);
        SDL_RenderDrawLine(renderer,xpos,ypos,xpos-y,ypos+x);
        SDL_RenderDrawLine(renderer,xpos,ypos,xpos-y,ypos-x);

        if (error<=0)
        {
            y++;
            error += ty;
            ty += 2;
        }
        else if(error>0)
        {
            x--;
            tx+=2;
            error += (tx-diameter);
        }
    }   
}

// Updates tthe position of the ball to new random value
void SDL_UpdateBallPosition(enum Bool *firstFlag,int *xpos,int *ypos)
{
    int randomNo = (rand() % 3);
    *firstFlag? (Direction = rand()%2)&&(YDirection = rand()%2)&&(*firstFlag = false) : pass;
    if(Direction == true)
    {
        if (randomNo == 0)
        {
            *xpos<=0? (Direction = false) : (*(xpos)-=BALLSPEED);
            YDirection? (*ypos<0? (YDirection = false) : (*(ypos)-=BALLSPEED)) : (*ypos>HEIGHT? (YDirection = true) : (*(ypos)+=BALLSPEED));
            //*ypos>HEIGHT? (*ypos<0? pass : (*(ypos)-=BALLSPEED)) : (*(ypos)+=BALLSPEED);
        }
        else if(randomNo == 1)
        {
            *xpos<=0? (Direction = false) : (*(xpos)-=BALLSPEED);
            *ypos>HEIGHT? (YDirection = true) : (*(ypos)+=BALLSPEED);
        }
        else
        {
            *xpos<=0? (Direction = false) : (*(xpos)-=BALLSPEED);
            *ypos<0? (YDirection = false) : (*(ypos)-=BALLSPEED);
        }
    }
    else if(Direction == false)
    {
        if (randomNo == 0)
        {
            *xpos>WIDTH? (Direction = true) : (*(xpos)+=BALLSPEED);
            YDirection? (*ypos<0? (YDirection = false) : (*(ypos)-=BALLSPEED)) : (*ypos>HEIGHT? (YDirection = true) : (*(ypos)+=BALLSPEED));
            //*ypos<0? (*ypos>HEIGHT? pass : (*(ypos)+=BALLSPEED)) : (*(ypos)-=BALLSPEED);
        }
        else if(randomNo == 1)
        {
            *xpos>=WIDTH? (Direction = true) : (*(xpos)+=BALLSPEED);
            *ypos>HEIGHT? (YDirection = true) : (*(ypos)+=BALLSPEED);
        }
        else
        {
            *xpos>=WIDTH? (Direction = true) : (*(xpos)+=BALLSPEED);
            *ypos<0? (YDirection = false) : (*(ypos)-=BALLSPEED);
        }
    }
    //printf("Ball position changed to %d %d \n",*xpos,*ypos);
    return;
}