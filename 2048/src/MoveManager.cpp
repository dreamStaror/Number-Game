#include "MoveManager.h"

MoveManager::MoveManager(GameScene* obj)
	:pGameScene(obj)
{
}
MoveManager::~MoveManager()
{
}
void MoveManager::MoveToUp()
{
	for (size_t column = 0; column < 4; column++)
	{
		for (size_t row = 0; row < 4; row++)
		{
			this->tmp[row] = this->pGameScene->GetCellNum(row, column);
		}
		this->dealNum();
		for (size_t row2 = 0; row2 < 4; row2++)
		{
			this->pGameScene->SetCellNum(row2, column, this->tmp[row2]);
		}
	}
	this->pGameScene->SpawnRandomNumInRandomPos();
	this->pGameScene->Update();
}
void MoveManager::MoveToDown()
{
	for (size_t column = 0; column < 4; column++)
	{
		for (size_t row = 0; row < 4; row++)
		{
			this->tmp[row] = this->pGameScene->GetCellNum(3-row, column);
		}
		this->dealNum();
		for (size_t row2 = 0; row2 < 4; row2++)
		{
			this->pGameScene->SetCellNum(3-row2, column, this->tmp[row2]);
		}
	}
	this->pGameScene->SpawnRandomNumInRandomPos();
	this->pGameScene->Update();
}
void MoveManager::MoveToLeft()
{
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t column = 0; column < 4; column++)
		{
			this->tmp[column] = this->pGameScene->GetCellNum(row, column);
		}
		this->dealNum();
		for (size_t column2 = 0; column2 < 4; column2++)
		{
			this->pGameScene->SetCellNum(row, column2, this->tmp[column2]);
		}
	}
	this->pGameScene->SpawnRandomNumInRandomPos();
	this->pGameScene->Update();
}
void MoveManager::MoveToRight()
{
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t column = 0; column < 4; column++)
		{
			this->tmp[column] = this->pGameScene->GetCellNum(row, 3-column);
		}
		this->dealNum();
		for (size_t column2 = 0; column2 < 4; column2++)
		{
			this->pGameScene->SetCellNum(row, 3 - column2, this->tmp[column2]);
		}
	}
	this->pGameScene->SpawnRandomNumInRandomPos();
	this->pGameScene->Update();
}

void MoveManager::dealNum()
{
	for (size_t sortI = 1; sortI < 4; sortI++)
	{
		if (this->tmp[sortI])
		{
			for (size_t sortJ = 0; sortJ < sortI; sortJ++)
			{
				if (tmp[sortJ] == 0)
				{
					tmp[sortJ] = tmp[sortI];
					tmp[sortI] = 0;
				}
			}
		}
	}
	for (size_t i = 0; i < 3; )
	{
		if (this->tmp[i] && this->tmp[i] == this->tmp[i + 1])
		{
			this->tmp[i] *= 2;
			for (size_t j = i+1; j < 4; j++)
			{
				if (j != 3)
				{
					this->tmp[j] = this->tmp[j + 1];
				}
				else
				{
					this->tmp[j] = 0;
				}
			}
		}
		else
		{
			i++;
		}
	}
}