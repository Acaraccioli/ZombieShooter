#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<SDL_mixer.h>
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *backg,*zombie,*sol,*sold,*character2,*zombie2,*zombie3,*zombie4, *menu, *gameover,*bang, *ganar;
SDL_Rect rect_backg,rect_zombie,rect_sol,rect_sold,rect_character2,rect_zombie2,rect_zombie3,rect_zombie4,rect_menu, rect_gameover, rect_bang, rect_ganar;
int dir = 1;
using namespace std;

int main( int argc, char* args[] )
{

    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Zombie Shooter", 100, 100, 1024/*WIDTH*/, 512/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }
    SDL_Init( SDL_INIT_AUDIO );
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    Mix_Music *gMusica= Mix_LoadMUS( "savage.wav" );
    Mix_Music *Gshot=Mix_LoadMUS( "gun.wav");
    Mix_PlayMusic( gMusica, -1 );




    //Init textures
    int w=0,h=0;

    backg = IMG_LoadTexture(renderer,"fondo.jpg");
    SDL_QueryTexture(backg, NULL, NULL, &w, &h);
    rect_backg.x = 0; rect_backg.y = 0; rect_backg.w = w; rect_backg.h = h;

    gameover = IMG_LoadTexture(renderer,"gameover.png");
    SDL_QueryTexture(gameover, NULL, NULL, &w, &h);
    rect_gameover.x = 0; rect_gameover.y = 0; rect_gameover.w = w; rect_gameover.h = h;

    ganar = IMG_LoadTexture(renderer,"ganar.png");
    SDL_QueryTexture(ganar, NULL, NULL, &w, &h);
    rect_ganar.x = 0; rect_ganar.y = 0; rect_ganar.w = w; rect_ganar.h = h;

    menu = IMG_LoadTexture(renderer,"fondomenu.png");
    SDL_QueryTexture(menu, NULL, NULL, &w, &h);
    rect_menu.x = 0; rect_menu.y = 0; rect_menu.w = w; rect_menu.h = h;

    character2 = IMG_LoadTexture(renderer,"rsz_sprite1flip.png");
    SDL_QueryTexture(character2, NULL, NULL, &w, &h);
    rect_character2.x = 370; rect_character2.y = 242; rect_character2.w = w; rect_character2.h = h;

    zombie = IMG_LoadTexture(renderer, "zombie1.png");
    SDL_QueryTexture(zombie, NULL, NULL, &w, &h);
    rect_zombie.x = -200; rect_zombie.y = 220; rect_zombie.w = w; rect_zombie.h = h;

    zombie3 = IMG_LoadTexture(renderer, "zombie1.png");
    SDL_QueryTexture(zombie3, NULL, NULL, &w, &h);
    rect_zombie3.x = -200; rect_zombie3.y = 220; rect_zombie3.w = w; rect_zombie3.h = h;


    zombie2 = IMG_LoadTexture(renderer, "zombie1flip.png");
    SDL_QueryTexture(zombie2, NULL, NULL, &w, &h);
    rect_zombie2.x = 900; rect_zombie2.y = 220; rect_zombie2.w = w; rect_zombie2.h = h;

    zombie4 = IMG_LoadTexture(renderer, "zombie1flip.png");
    SDL_QueryTexture(zombie4, NULL, NULL, &w, &h);
    rect_zombie4.x = 900; rect_zombie4.y = 220; rect_zombie4.w = w; rect_zombie4.h = h;

    sol = IMG_LoadTexture(renderer,"nube1.png");
    SDL_QueryTexture(sol, NULL, NULL, &w, &h);
    rect_sol.x = 700; rect_sol.y = 10; rect_sol.w = w; rect_sol.h = h;

    sold = IMG_LoadTexture(renderer,"rsz_sprite1.png");
    SDL_QueryTexture(sold, NULL, NULL, &w, &h);
    rect_sold.x = 370; rect_sold.y = 242; rect_sold.w = w; rect_sold.h = h;


    bang = IMG_LoadTexture(renderer,"rsz_boom.png");
    SDL_QueryTexture(bang, NULL, NULL, &w, &h);
    rect_bang.x = 310; rect_bang.y = 292; rect_bang.w = w; rect_bang.h = h;

int mover=0, mover2=0, mover3=0, mover4=0, estado=1, dificultad=7, vida1=4, vida2=4, vida3=4,vida4=4, sobrevivir=0, modo=10;
bool vivo1=false, vivo2=false;
    //Main Loop
    while(true)
    {

        switch(estado)
        {
        case 1:

            SDL_RenderCopy(renderer, menu, NULL, &rect_menu);

            while(SDL_PollEvent(&Event))
            {
                if(Event.type == SDL_QUIT)
                    return 0;

                if(Event.type == SDL_KEYDOWN)
                {
                    if(Event.key.keysym.sym == SDLK_1)
                        dificultad=12;
                    if(Event.key.keysym.sym == SDLK_2)
                        dificultad=7;
                    if(Event.key.keysym.sym == SDLK_3)
                        dificultad=3;
                    if(Event.key.keysym.sym == SDLK_3)
                        modo=1000;
                    if(Event.key.keysym.sym == SDLK_RETURN)
                        {
                            vivo1=false; vivo2=false;
                            rect_zombie3.x=-110;
                            rect_zombie.x=-90;
                            rect_zombie2.x=900;
                            rect_zombie4.x=900;
                            vida1=4; vida2=4; vida3=4; vida4=4;
                            sobrevivir=0;
                            modo=10;
                            estado=2;

                        }

                }
            }

            SDL_RenderPresent(renderer);

            break;


            case 2:
                //reset de vidas y demas

                if (vida1<=0 && vida2<=0 && vida3<=0 && vida4<=2)
                {
                    sobrevivir++;
                     vivo1=false; vivo2=false;
                            rect_zombie3.x=-250;
                            rect_zombie.x=-250;
                            rect_zombie2.x=900;
                            rect_zombie4.x=900;
                            vida1=4; vida2=4; vida3=4; vida4=4;
                }


                if(rect_zombie.x>250 || rect_zombie2.x<500 || rect_zombie3.x>250 || rect_zombie4.x<500)
                  {
                     estado=3;
                     break;
                  }
                  if(sobrevivir==modo)
                  {
                      estado=4;
                      break;
                  }
                  //evaluar que se crearon
                  if(vida1==0)
                    vivo1=true;
                  if(vida2==0)
                  vivo2=true;
                  //movimiento de zombie1


                if (mover%dificultad==0 &&vida1>0)
                    rect_zombie.x++;

                if(vida1>=0)
                    mover++;

                if(mover==10,000)
                    mover=0;
                    //movimiento zombie 2


                if (mover2%dificultad==0 &&vida2>0)
                    rect_zombie2.x--;

                if(vida2>=0)
                    mover2++;


                if(mover2==10,000)
                    mover2=0;
                    //movimiento zombie 3

                if (mover3%dificultad==0 && vivo1 && vida3>0)
                    rect_zombie3.x++;

                if(vida3>=0)
                    mover3++;

                if(mover3==10,000)
                    mover3=0;

                    //movimiento zombie 4

                if (mover4%dificultad==0 && vivo2 && vida4>0)
                    rect_zombie4.x--;

                if(vida4>=0)
                    mover4++;

                if(mover4==10,000)
                    mover4=0;
                while(SDL_PollEvent(&Event)) {


                    if(Event.type == SDL_QUIT)
                        return 0;

                    if(Event.type == SDL_KEYDOWN)
                    {
                        if (Event.key.keysym.sym == SDLK_SPACE && dir==2)
                            {
                                if(vida1>0)
                                    vida1--;
                                if(vida1<=0)
                                    vida3--;
                                    Mix_PlayMusic(Gshot,1);
                            }

                        if (Event.key.keysym.sym == SDLK_SPACE && dir==1)
                            {
                                rect_bang.x = 310; rect_bang.y = 292;
                                if(vida2>0)
                                    vida2--;
                                else
                                    vida4--;
                           }
                                Mix_PlayMusic(Gshot,1);
                        if(Event.key.keysym.sym == SDLK_RIGHT)
                            dir=1;


                        if(Event.key.keysym.sym == SDLK_LEFT)
                            dir=2;
                    }
                }

                SDL_RenderCopy(renderer, backg, NULL, &rect_backg);
                SDL_RenderCopy(renderer, sol, NULL, &rect_sol);
                if(dir==1){
                    SDL_RenderCopy(renderer, sold, NULL, &rect_sold);
                        rect_bang.x = 630; rect_bang.y = 292;
                    if (Event.key.keysym.sym == SDLK_SPACE)
                    {
                        SDL_RenderCopy(renderer, bang, NULL, &rect_bang);
                    }

                }else if(dir!=1){
                    SDL_RenderCopy(renderer, character2, NULL, &rect_character2);
                        rect_bang.x = 310; rect_bang.y = 292;
                    if (Event.key.keysym.sym == SDLK_SPACE)
                    {
                        SDL_RenderCopy(renderer, bang, NULL, &rect_bang);
                    }

                }
                if(vida1>0)
                    SDL_RenderCopy(renderer, zombie, NULL, &rect_zombie);

                if(vida1<=2 && vida2>0)
                    SDL_RenderCopy(renderer, zombie2, NULL, &rect_zombie2);

                if(vida1<=1 && vida3>0)
                    SDL_RenderCopy(renderer, zombie3, NULL, &rect_zombie3);

                if(vida2<=1 && vida4>0)
                    SDL_RenderCopy(renderer, zombie4, NULL, &rect_zombie4);


                SDL_RenderPresent(renderer);
                break;

            case 3:
                 SDL_RenderCopy(renderer, gameover, NULL, &rect_gameover);

                while(SDL_PollEvent(&Event))
                {
                   if(Event.type == SDL_QUIT)
                        return 0;

                   if(Event.type == SDL_KEYDOWN)
                    {
                    if(Event.key.keysym.sym == SDLK_RETURN)
                        estado=1;
                    }
                }
                SDL_RenderPresent(renderer);

                break;

                          case 4:
                 SDL_RenderCopy(renderer, ganar, NULL, &rect_ganar);

                while(SDL_PollEvent(&Event))
                {
                   if(Event.type == SDL_QUIT)
                        return 0;

                   if(Event.type == SDL_KEYDOWN)
                    {
                    if(Event.key.keysym.sym == SDLK_RETURN)
                        estado=1;
                    }
                }
                SDL_RenderPresent(renderer);

                break;



        }







    }

	return 0;
}
//
