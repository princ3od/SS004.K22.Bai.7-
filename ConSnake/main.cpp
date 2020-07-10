#include "Library.h"
#include "Menu.h"
#include "SnakeKun.h"

int main()
{
	setFont();
	hideCursor();
	//cout << Menu::StartMenu();
	cout << (char)Symbol::BOTTOM_RIGHT << (char)Symbol::LONG_BLOCK << (char)Symbol::BOTTOM_LEFT << endl;
	cout << (char)Symbol::TALL_BLOCK << " " << (char)Symbol::TALL_BLOCK << endl;
	cout << (char)Symbol::TOP_RIGHT << (char)Symbol::LONG_BLOCK << (char)Symbol::TOP_LEFT << endl;
	SnakeKun* snake;
	MapData _map[MAX][MAX];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			_map[i][j] = MapData::NOTHING;
	unsigned short int n;
	cin >> n;
	snake = new SnakeKun(_map);
	_beginthread(userInput, 0, (void*)0);
	for (int i = 0; i < 40; i++)
	{
		snake->update(n, _map);
	}

	return 0;
}