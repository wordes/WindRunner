//Create by luv on 15/3/5

#include "GameScene.h"
#include "MapMgr.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	MapMgr::getInstance()->clear();
	MapMgr::getInstance()->init(this);

	return true;
}

