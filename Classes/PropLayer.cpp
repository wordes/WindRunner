//Created by luv on 15/3/7

#include "PropLayer.h"
#include "MainScene.h"

USING_NS_CC;
using namespace ui;

bool PropLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	_visibleSize = Director::getInstance()->getVisibleSize();

	_propLayer = CSLoader::createNode("PropLayer/PropLayer.csb");
	_propLayer->setAnchorPoint(Vec2(0.5f, 0.5f));
	_propLayer->setPosition(Vec2(_visibleSize.width / 2.0f, _visibleSize.height / 2.0f));

	_propRoleBtn = static_cast<Button*>(_propLayer->getChildByName("prop_role_btn"));
	_propRoleBtn->addTouchEventListener(this, toucheventselector(PropLayer::touchEvent));

	_propBackBtn = static_cast<Button*>(_propLayer->getChildByName("prop_back_btn"));
	_propBackBtn->addTouchEventListener(this, toucheventselector(PropLayer::touchEvent));


	auto propItem = CSLoader::createNode("PropLayer/PropRoleItemLayer.csb");
	auto propListView = static_cast<ListView*>(_propLayer->getChildByName("prop_lv_role"));

	auto panel = static_cast<Layout*>(propItem->getChildByName("ItemPanel"));

	auto lvItem1 = panel->clone();
	auto lvItem2 = panel->clone();

	propListView->addChild(lvItem1);
	propListView->addChild(lvItem2);

	this->addChild(_propLayer);

	return true;
}

void PropLayer::touchEvent(Ref* pSender, Widget::TouchEventType type)
{
	if (Widget::TouchEventType::ENDED == type)
	{
		if (_propRoleBtn == pSender)
		{
			_propLayer->setVisible(false);

			if (nullptr == _roleSelLayer)
			{
				_roleSelLayer = CSLoader::createNode("RoleSelLayer/RoleSelLayer.csb");

				_roleSelBackBtn = static_cast<Button*>(_roleSelLayer->getChildByName("role_sel_back_btn"));

				_roleSelBackBtn->addTouchEventListener(this, toucheventselector(PropLayer::touchEvent));

				auto roleSelNode = CSLoader::createNode("RoleSelLayer/RoleSelItemLayer.csb");

				auto roleSelItem = static_cast<Layout*>(roleSelNode->getChildByName("RoleSelItemLayer"));

				auto roleSelLv = static_cast<ListView*>(_roleSelLayer->getChildByName("role_sel_lv"));

				for (int i = 0; i < 8; i++)
				{
					auto item = roleSelItem->clone();
					roleSelLv->addChild(item);
				}

				this->addChild(_roleSelLayer);
			}
			else
			{
				_roleSelLayer->setVisible(true);
			}
		}
		else if (_roleSelBackBtn == pSender)
		{
			_roleSelLayer->setVisible(false);
			_propLayer->setVisible(true);
		}
		else if (_propBackBtn == pSender)
		{
			((MainScene*)(this->getParent()))->showGameEntry();
			this->removeFromParent();
		}
	}
}