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
	cout << "��ӭ����2048С��Ϸ��" << endl;
	cout << "1����ʼ��Ϸ" << "2���˳���Ϸ" << endl;
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
		cout << "��������Чѡ�" << endl;
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
	cout << "���ƶ�:";
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