// Created by luv on 15/3/7

#ifndef __PROP_LAYER_H__
#define __PROP_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

class PropLayer : public cocos2d::Layer
{
public:
	PropLayer()
		: _propLayer(nullptr)
		, _roleSelLayer(nullptr)
		, _propRoleBtn(nullptr)
		, _roleSelBackBtn(nullptr)
		, _propBackBtn(nullptr){}
	~PropLayer(){}

	virtual bool init();

	void touchEvent(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);

	CREATE_FUNC(PropLayer);

private:
	cocos2d::Node* _propLayer;
	cocos2d::Node* _roleSelLayer;

	cocos2d::ui::Button* _propRoleBtn;

	cocos2d::ui::Button* _roleSelBackBtn;
	cocos2d::ui::Button* _propBackBtn;

	cocos2d::Size _visibleSize;
};
#endif