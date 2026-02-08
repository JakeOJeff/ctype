
/*
 * gcc main.cpp -o main.exe -I "D:\SDL\x86_64-w64-mingw32\include" -L "D:\SDL\x86_64-w64-mingw32\lib" -lSDL3
 gcc main.cpp -o main.exe -I"D:\SDL\x86_64-w64-mingw32\include" ^ -L"D:\SDL\x86_64-w64-mingw32\lib" -lSDL3 -lSDL3_ttf
g++ main.cpp -o main.exe -I "D:\SDL\x86_64-w64-mingw32\include" -L "D:\SDL\x86_64-w64-mingw32\lib" -lSDL3 -lSDL3_ttf
 */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

constexpr int kScreenWidth{640};
constexpr int kScreenHeight{480};

bool init();
void close();
void renderText(const std::string& text);

/* Globals */

SDL_Window* gWindow{nullptr};
SDL_Renderer* gRenderer{nullptr};
TTF_Font* gFont{nullptr};

std::string currentKey = "Press any key";

/* Implementing the Functions */

bool init()
{
    bool success{true};

    if (SDL_Init(SDL_INIT_VIDEO) == false)
    {
        SDL_Log("SDL Couldn't init %s", SDL_GetError());
        return false;
    }

    if (TTF_Init() == false)
    {
        SDL_Log("TTF Couldn't init %s", SDL_GetError());
        return false;
    }

    gWindow = SDL_CreateWindow("Key Indicator", kScreenWidth, kScreenHeight, 0);

    if (gWindow == nullptr)
    {
        SDL_Log("Window couldn't be created");
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, nullptr);

    if (gRenderer == nullptr)
    {
        SDL_Log("Renderer couldn't be created");
        return false;
    }

    // 👉 Put a font file next to your exe (e.g., arial.ttf)
    gFont = TTF_OpenFont("arial.ttf", 64);

    if (!gFont)
    {
        SDL_Log("Failed to load font: %s", SDL_GetError());
        return false;
    }

    return success;
}

void renderText(const std::string& text)
{
    SDL_Color white = {255, 255, 255, 255};

    SDL_Surface* surface =
        TTF_RenderText_Blended(gFont, text.c_str(), text.size(), white);

    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(gRenderer, surface);

    int w = surface->w;
    int h = surface->h;

    SDL_DestroySurface(surface);

    SDL_FRect dst{
        (kScreenWidth - w) / 2.0f,
        (kScreenHeight - h) / 2.0f,
        (float)w,
        (float)h
    };

    SDL_RenderTexture(gRenderer, texture, nullptr, &dst);

    SDL_DestroyTexture(texture);
}

void close()
{
    TTF_CloseFont(gFont);
    gFont = nullptr;

    SDL_DestroyRenderer(gRenderer);
    gRenderer = nullptr;

    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    TTF_Quit();
    SDL_Quit();
}

int main(int argc, char* args[])
{
    int exitCode{0};

    if (!init())
    {
        SDL_Log("Unable to Init");
        return 1;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
            {
                quit = true;
            }

            // 🎯 KEY PRESS DETECT
            if (e.type == SDL_EVENT_KEY_DOWN)
            {
                SDL_Keycode key = e.key.key;

                const char* name = SDL_GetKeyName(key);

                currentKey = std::string("Key: ") + name;
            }
        }

        // Clear screen (black)
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
        SDL_RenderClear(gRenderer);

        // Draw key text
        renderText(currentKey);

        SDL_RenderPresent(gRenderer);
    }

    close();

    return exitCode;
}
