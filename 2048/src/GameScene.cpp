#include "GameScene.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

bool GameScene::SetCellNum(unsigned int rowIndex, unsigned int columnIndex, unsigned int value)
{
	if (rowIndex > 3 || columnIndex > 3) return false;
	else
	{
		this->cell[rowIndex][columnIndex] = value;
		this->SetBlankCell(rowIndex, columnIndex, value == 0);
		return true;
	}
}

unsigned int GameScene::GetCellNum(unsigned int rowIndex, unsigned int columnIndex)
{
	if (rowIndex > 3 || columnIndex > 3) return -1;
	else
	{
		return this->cell[rowIndex][columnIndex];
	}
}

bool GameScene::SetBlankCell(unsigned int rowIndex, unsigned int columnIndex, bool value)
{
	unsigned int pos = rowIndex * 10 + columnIndex;
	auto x = this->blankCell.rend();
	for (auto index = this->blankCell.begin(); index != this->blankCell.end(); index++)
	{
		if (pos == *index)
		{
			if (value)
			{
				return false;
			}
			else
			{
				this->blankCell.erase(index);
				return true;
			}
		}
		else if (index == --this->blankCell.end())
		{
			if (value)
			{
				this->blankCell.push_back(pos);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

list<unsigned int> GameScene::GetBlankCell()
{
	return this->blankCell;
}

void GameScene::SpawnRandomNumInRandomPos()
{

	size_t blankCellCount = this->blankCell.size();
	srand((unsigned)time(NULL));
	if (blankCellCount)
	{
		unsigned int randomNum = rand() % blankCellCount;
		auto index = this->blankCell.begin();
		for (size_t i = 0; i < randomNum; i++)
		{
			index++;
		}
		unsigned int randomPos = *index;
		this->SetCellNum(randomPos / 10, randomPos % 10, 2);
		return;
	}
}

void GameScene::Update()
{
	system("cls");
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t column = 0; column < 4; column++)
		{
			cout << this->cell[row][column] << "\t";
		}
		cout << "\n";
	}
}

void GameScene::Reset()
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			this->SetCellNum(i, j, 0);
		}
	}
}