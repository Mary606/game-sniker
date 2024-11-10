#include <iostream>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x , y, fruitX , fruitY, score;
enum eDirecton {STOP = 0,  LEFT, RIGHT, UP , DOWN};
eDirecton dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height; 
    score =  0;

}
void Draw()
{
    system("clear"); // Limpa a tela

    // Desenha o topo do mapa
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Desenha as laterais e o conteúdo do mapa
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (j == 0 || j == width + 1)
                cout << "#"; // Laterais do mapa
            else if (i == y && j == x + 1)
                cout << "O"; // Cabeça da cobra
            else if (i == fruitY && j == fruitX + 1)
                cout << "F"; // Fruta
            else
                cout << " "; // Espaço vazio
        }
        cout << endl;
    }

    // Desenha a parte inferior do mapa
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
}
    
    


void Input()
{

}
void Logic()
{

}
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    
    return 0;
}
