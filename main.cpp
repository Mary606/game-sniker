#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <unistd.h> 
#include <termios.h> 
#include <fcntl.h> 
#include <ncurses.h>
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
    system ("clear");

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
    

 int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void Input()
{
     if (kbhit())
     {
        switch (getchar()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
        
        }
    }
}

void Logic()
{
   switch(dir){
    case LEFT:
        x--;
        break;
        
    case RIGHT:
        x++;
        break;
        
    case UP: 
        y--;
        break;
        
    case DOWN:
        y++;
        break;
        
    default:
        break;
   }
  
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    
    
}
int main(){
    
    initscr(); 
    clear();
    noecho();
    cbreak();
    curs_set(0); 
    
    srand(time(0));
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        usleep(100000);
    }
    
    return 0;
}
