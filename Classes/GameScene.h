// Created by luv on 15/3/5


#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
	GameScene(){}

	~GameScene(){}

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);

private:
	cocos2d::Size _visibleSize;

private:
	cocos2d::Sprite* _firstBg;
	cocos2d::Sprite* _secondBg;
};
#endif