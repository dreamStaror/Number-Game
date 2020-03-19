#include "GameLogic.h"

using namespace std;
GameLogic::GameLogic()
	:bGameRunning(false),
	moveManager(this->GetGameScene())
{
}

GameLogic::~GameLogic()
{
}

void GameLogic::initMainMenu() 
{
	cout << "欢迎来到2048小游戏！" << endl;
	cout << "1、开始游戏" << "2、退出游戏" << endl;
	int playerOption = 0;
	cin >> playerOption;
	switch (playerOption)
	{
	case 1:
		this->GameStart();
		break;
	case 2:
		return;
		break;
	default:
		cout << "请输入有效选项！" << endl;
		break;
	}
}

void GameLogic::GameStart()
{
	this->bGameRunning = true;
	this->gameScene.SpawnRandomNumInRandomPos();
	this->gameScene.SpawnRandomNumInRandomPos();
	this->gameScene.Update();

	char playerOption = '\0';
	while (this->bGameRunning)
	{
		this->PlayerMove(playerOption);
	}
}

void GameLogic::GameEnd() 
{
	this->bGameRunning = false;
	system("cls");
	this->gameScene.Reset();
	this->initMainMenu();
}

void GameLogic::PlayerMove(char playerOption)
{
	cout << "请移动:";
	cin >> playerOption;
	switch (playerOption)
	{
	case 'w':
		this->moveManager.MoveToUp();
		break;
	case 's':
		this->moveManager.MoveToDown();
		break;
	case 'a':
		this->moveManager.MoveToLeft();
		break;
	case 'd':
		this->moveManager.MoveToRight();
		break;
	case 'q':
		this->GameEnd();
		break;
	case 'h':
		break;
	default:
		break;
	}
}

GameScene* GameLogic::GetGameScene()
{
	GameScene *p = &this->gameScene;
	return p;
}