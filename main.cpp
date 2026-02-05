
/*
 * gcc main.cpp -o main.exe -I "D:\SDL\x86_64-w64-mingw32\include" -L "D:\SDL\x86_64-w64-mingw32\lib" -lSDL3
 */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

constexpr int kScreenWidth{640};
constexpr int kScreenHeight{480};

bool init();
bool loadMedia();
void close();

/* Globals */

SDL_Window *gWindow{nullptr};

SDL_Surface *gScreenSurface{nullptr};

SDL_Surface *gHelloWorld{nullptr};

/* Implementing the Functions */

bool init()
{
    // Init
    bool success{true};

    if (SDL_Init(SDL_INIT_VIDEO) == false)
    {
        SDL_Log("SDL Couldn't init %s", SDL_GetError());
        success = false;
    }
    else
    {
        // Create Window

        if (gWindow = SDL_CreateWindow("This is my window", kScreenWidth, kScreenHeight, 0); gWindow == nullptr)
        {
            SDL_Log(" Window couldn't be created");
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

void close()
{
    // Clean up

    SDL_DestroySurface(gHelloWorld);
    gHelloWorld = nullptr;

    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gScreenSurface = nullptr;

    SDL_Quit();
}

int main(int argc, char *args[])
{

    int exitCode{0};

    if (init() == false)
    {
        SDL_Log("Unable to Init");
        exitCode = 1;
    }
    else
    {
        bool quit = false;
        SDL_Event e;

        while (!quit)
        {
            // Handle events
            while (SDL_PollEvent(&e))
            {
                if (e.type == SDL_EVENT_QUIT)
                { // SDL3 uses SDL_EVENT_QUIT
                    quit = true;
                }
            }

            // Fill screen with white (optional)
            SDL_FillSurfaceRect( gScreenSurface, nullptr, SDL_MapSurfaceRGB( gScreenSurface, 0xFF, 0xFF, 0xFF ) );

            // Update the window surface
            SDL_UpdateWindowSurface(gWindow);
        }
    }

    close();

    return exitCode;
}