//Created by luv
#include "MapMgr.h"

USING_NS_CC;

MapMgr* MapMgr::_pInstance = nullptr;

MapMgr* MapMgr::getInstance()
{
	if (nullptr == _pInstance)
	{
		_pInstance = new MapMgr();
	}

	return _pInstance;
}

void MapMgr::clear()
{
	if (nullptr != _pInstance)
	{
		CC_SAFE_DELETE(_pInstance);
	}
}

bool MapMgr::init(Layer* targetLayer)
{
	CCASSERT(targetLayer != nullptr , "targetLayer is not nullptr!");

	_targetLayer = targetLayer;

	_visibleSize = Director::getInstance()->getVisibleSize();

	_firstBg = Sprite::create("GameScene/gs_bg1.png");
	_firstBg->setAnchorPoint(Vec2(0.0f, 1.0f));
	_firstBg->setPosition(Vec2(0, _visibleSize.height));
	_targetLayer->addChild(_firstBg, 1);


	_secondBg = Sprite::create("GameScene/gs_bg1.png");
	_secondBg->setAnchorPoint(Vec2(0.0f, 1.0f));
	_secondBg->setPosition(Vec2(_firstBg->getPositionX() + _firstBg->getContentSize().width, _visibleSize.height));
	_targetLayer->addChild(_secondBg, 1);

	return true;
}

void MapMgr::update(float t, float value)
{

}