//2:08 draw field
//4:40 random mines

#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(400, 400), "Minesweeper");

    int w = 32;
    int grid[12][12];
    int sgrid[12][12];
    
    Texture t;
    t.loadFromFile("Paint/tiles.png");
    Sprite tiles(t);

    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
            {
            sgrid[i][j] = 10;
            
            if(rand() % 5 == 0)
                grid[i][j] = 9;
            else
                grid[i][j] = 0;

            }
    
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
        {
            int n = 0;

            if(grid[i][j] == 9)
                continue;
            if(grid[i + 1][j] == 9)
                n++;
            if(grid[i][j + 1] == 9)
                n++;
            if(grid[i - 1][j] == 9)
                n++;
            if(grid[i][j - 1] == 9)
                n++;
            if(grid[i + 1][j + 1] == 9)
                n++;
            if(grid[i - 1][j - 1] == 9)
                n++;
            if(grid[i - 1][j + 1] == 9)
                n++;
            if(grid[i + 1][j - 1] == 9)
                n++;

            grid[i][j] = n;
        }

    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);

        for(int i = 1; i <= 10; i++)
            for(int j = 1; j <= 10; j++)
            {
                sgrid[i][j] = grid[i][j];
                tiles.setTextureRect(IntRect(sgrid[i][j] * w,  0, w, w));
                tiles.setPosition(i * w, j * w);

                window.draw(tiles);
            }

        window.display();
    }

    return 0;
}