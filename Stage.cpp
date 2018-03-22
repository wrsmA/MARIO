#include "Stage.h"
#include "MyEngine\\CsvReader.h"

Stage::Stage()
{
	Load("Assets\\map.png");
	CsvReader reader;
	reader.Load("Assets\\MAP1.csv");
	for (int x = 0; x < 100; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			_mapTable[x][y] = reader.GetValue(x, y);
		}
	}
}


Stage::~Stage()
{
}
void Stage::Draw()
{
	for (int x = 0; x < 100; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			DrawRectGraph(x* 64, y * 64, 0,64*_mapTable[x][y], 64, 64, _graphicHandle, TRUE, FALSE);
		}
	}
	
}
bool Stage::IsTraffic(int x, int y)
{

	/*return _mapTable[x][y] < 2;*/

	static const bool b[] = { true, true, false, false };
	return b[_mapTable[x][y]];
}