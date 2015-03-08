//Create by luv

#ifndef __MAP_MGR_H__
#define __MAP_MGR_H__

#include "cocos2d.h"

class MapMgr
{
public:
	static MapMgr* getInstance();
	
	bool init(cocos2d::Layer* _targetLayer);

	void clear();

	void update(float t, float value);

private:
	MapMgr()
		: _firstBg(nullptr)
		, _secondBg(nullptr)
		, _targetLayer(nullptr){}

	cocos2d::Size _visibleSize;

	static MapMgr* _pInstance;

private:
	cocos2d::Sprite* _firstBg;
	cocos2d::Sprite* _secondBg;

	cocos2d::Layer* _targetLayer;
};

#endif