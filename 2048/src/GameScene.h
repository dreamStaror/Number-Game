#pragma once
#include <list>

using std::list;

class GameScene
{
public:
	GameScene();
	~GameScene();
	bool SetCellNum(unsigned int rowIndex, unsigned int columnIndex, unsigned int value);
	unsigned int GetCellNum(unsigned int rowIndex, unsigned int columnIndex);
	bool SetBlankCell(unsigned int rowIndex, unsigned int columnIndex, bool value);
	list<unsigned int> GetBlankCell();
	void SpawnRandomNumInRandomPos();
	void Update();
	void Reset();

private:
	unsigned int cell[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	list<unsigned int> blankCell{ 0,1,2,3,10,11,12,13,20,21,22,23,30,31,32,33 };
};