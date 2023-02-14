#include <SFML/Graphics.hpp>

using namespace sf;

const int M = 7, N = 5;
int ts = 80;
Vector2f offset(65, 55);

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
        }

        window.clear(Color::White);

        for(int i = 0; i < N; i++)
            for(int j  = 0; j < M; j++)
                {
                pipe.setTextureRect(IntRect(ts * 2, 0, ts,  ts));

                pipe.setPosition(j * ts, i * ts);
                pipe.move(offset);
                window.draw(pipe);
                }
        window.display();
    }

    return 0;
}