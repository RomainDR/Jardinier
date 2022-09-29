#include <iostream>
#include <string>

using namespace std;

const short sizeX = 5;
const short sizeY = 3;

int cursorX = 0, cursorY = 0;

bool content[sizeY][sizeX] = {
    {false, false, true, false, true},
    {false, true, true, false, false},
    {false, false, true, false, false}
};


#pragma region init method
string ReadGrid();

void MoveCursor();
void Game();
void PlantOrDestroy();
#pragma endregion


void Game()
{
    cout << ReadGrid();
    MoveCursor();    
}

string ReadGrid()
{
    string _tmp = "";
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            _tmp += content[y][x] ? " X " : " - ";
        }
        _tmp += "\n";
    }
    return _tmp;
}
void MoveCursor()
{
    bool _isValid = false;
    char _input;
    while (!_isValid) {
        cout << "Move cursor (z,q,s,d): ";
        cin >> _input;
        _isValid = (_input == 'z' || _input == 's' || _input == 'q' || _input == 'd');
    }
    bool _up = _input == 'z',
        _down = _input == 's',
        _right = _input == 'd',
        _left = _input == 'q';
    if (_up) cursorY = cursorY - 1 >= 0 ? cursorY - 1 : cursorY;
    else if (_down) cursorY = cursorY + 1 < sizeY ? cursorY + 1 : cursorY;
    else if (_left) cursorX = cursorX - 1 >= 0 ? cursorX - 1 : cursorX;
    else if (_right) cursorX = cursorX + 1 < sizeX ? cursorX + 1 : cursorX;
    cout << "Current position (y: " << cursorY << ", x: " << cursorX << ")" << endl;
    PlantOrDestroy();
}

void PlantOrDestroy()
{
    bool _isValid = false;
    int _select;
    while (!_isValid) {
        cout << "What you do ?" << endl << "[1] Plant" << endl << "[2] Destroy" << endl  << "Choose option: ";
        cin >> _select;
        _isValid = _select == 1 || _select == 2;
    }
    bool _plant = _select == 1 ? true : false;
    if (_plant && !content[cursorY][cursorX]) {
        cout << "You have been plant a tree";
        content[cursorY][cursorX] = true;
    }
    else if (!_plant && content[cursorY][cursorX]) {
        cout << "You have been destroy a tree";
        content[cursorY][cursorX] = false;
    }
    else
        cout << "Cannot make an action";
    cout << endl;
    }
int main()
{
    while (true) {
        Game();
    }
}
