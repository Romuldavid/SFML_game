//1:09 add pipe
//2:23 add rotation pipe

#include <SFML/Graphics.hpp>

using namespace sf;

const int M = 7, N = 5;
int ts = 80;
Vector2f offset(65, 55);

struct Pipe{
    int orientation;
    float angle;

    Pipe() { angle = 0;}
} grid[M][N];

int main()
{
    RenderWindow window(VideoMode((M + 1) * ts - 20, (N + 1) * ts -20), "Water supply");

    Texture p;
    p.loadFromFile("Paint/pipe.png");
    Sprite pipe(p);
    pipe.setOrigin(ts / 2,  ts / 2);
    
    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();

            if(event.type == Event::MouseButtonPressed)
                if(event.key.code == Mouse::Left) {
                    Vector2i pos = Mouse::getPosition(window) + 
                        Vector2i(ts / 2, ts / 2) - Vector2i(offset);

                    pos /= ts;
                    grid[pos.x][pos.y].orientation++;
                }
        }

        window.clear(Color::White);

        for(int i = 0; i < N; i++)
            for(int j  = 0; j < M; j++)
                {

                Pipe& pe = grid[j][i];

                pe.angle += 5;
                if(pe.angle > pe.orientation * 90)
                    pe.angle  =  pe.orientation * 90;

                pipe.setRotation(pe.angle);

                pipe.setTextureRect(IntRect(ts * 2, 0, ts,  ts));

                pipe.setPosition(j * ts, i * ts);
                pipe.move(offset);
                window.draw(pipe);
                }
        window.display();
    }

    return 0;
}