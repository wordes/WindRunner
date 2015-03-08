//
//  MainScene.cpp
//  WindRunner
//
//  Created by jiaolong on 15/3/7.
//
//

#include "MainScene.h"
#include "PropLayer.h"

const int PRIZE_CLOSE = 111;
const int INFORM_GET = 112;
const int INFORM_CLOSE = 113;
const int MAIN_BUYCOIN = 0;
const int MAIN_BUYDIAMOND = 1;
const int MAIN_BUYHEART = 2;
const int MAIN_SET = 3;
const int MAIN_MAIL = 4;
const int MAIN_MISSION = 5;
const int MAIN_FRIEND = 6;
const int MAIN_CLASSIC = 7;
const int MAIN_BOSS = 8;
const int SET_BACK = 101;
const int MAIL_BACK = 102;
const int MISSION_BACK = 103;
const int BUYCOIN_BACK = 104;
const int BUYDIAMOND_BACK = 105;
const int BUYHEART_BACK = 106;
const int BUYCOIN_BTN = 107;

using namespace cocos2d::ui;

Scene * MainScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MainScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

MainScene::MainScene()
:

_prize_close(nullptr),
_prize_layer(nullptr),
_main_root(nullptr),
_inform_root(nullptr),
_buycoin_root(nullptr),
_buydiamond_root(nullptr),
_buyheart_root(nullptr),
_mail_root(nullptr),
_mission_root(nullptr),
_prize_root(nullptr),
_set_root(nullptr),
_inform_close(nullptr),
_inform_get(nullptr),
_inform_layer(nullptr),
_set_layer(nullptr),
_mail_layer(nullptr),
_mission_layer(nullptr),
_buycoin_layer(nullptr),
_buydiamond_layer(nullptr),
_buyheart_layer(nullptr),
_buycoin_yn_layer(nullptr),
_buyheart_yn_layer(nullptr)

{
    for (int i = 0; i < sizeof(_main_btn)/sizeof(_main_btn[0]); i++)
    {
        _main_btn[i] = nullptr;
        
        log("sizeof(_main_btn) = %lu",sizeof(_main_btn)/sizeof(_main_btn[0]));
    }
    for (int i = 0; i < sizeof(_buycoin_btn)/sizeof(_buycoin_btn[0]); i++)
    {
        _buycoin_btn[i] = nullptr;
    }
}

MainScene::~MainScene()
{
    
}

bool MainScene::init(void)
{
    if (!Layer::init())
    {
        return false;
    }
    ////主场�?    
	_main_root = CSLoader::createNode("MainScene.csb");
    
    this->addChild(_main_root);

	//

	_someRank = static_cast<Sprite*>(_main_root->getChildByName("Panel_main")->getChildByName("bk2"));

	//
    
    auto main_panel = static_cast<Layout *>(_main_root->getChildByName("Panel_main"));
    
    std::string main_btn[9] = {"coinadd","diamondadd","heartadd","set","mail","mission","friend","classicalmode","bossmode"};
    
    for (int i = 0; i < sizeof(_main_btn)/sizeof(_main_btn[0]); i++)
    {
        _main_btn[i] = static_cast<Button *>(main_panel->getChildByName(main_btn[i]));
        
        _main_btn[i]->setTag(i);
        
        _main_btn[i]->addTouchEventListener(CC_CALLBACK_2(MainScene::mainBtnCallback, this));
    }
    
    
    ////通知
    _inform_root =CSLoader::createNode("InformLayer.csb");
    
    _inform_layer = static_cast<Layout *>(_inform_root->getChildByName("Panel_inform"));
    
    auto informpic = static_cast<Sprite *>(_inform_layer->getChildByName("inform"));
    
    this->addChild(_inform_root,3);
    
    _inform_close = static_cast<Button *>(informpic->getChildByName("close"));
    
    _inform_close->addTouchEventListener(CC_CALLBACK_2(MainScene::piBtnCallback, this));
    
    _inform_close->setTag(INFORM_CLOSE);
    
    _inform_get = static_cast<Button *>(informpic->getChildByName("get"));
    
    _inform_get->addTouchEventListener(CC_CALLBACK_2(MainScene::piBtnCallback, this));
    
    _inform_get->setTag(INFORM_GET);
    ////奖励
    _prize_root = CSLoader::createNode("PrizeLayer.csb");
    
    this->addChild(_prize_root, 2);
    
    _prize_layer = static_cast<Layout *>(_prize_root->getChildByName("Panel_prize"));
    
    auto prizepic = static_cast<Sprite *>(_prize_layer->getChildByName("login_layer"));
    
    _prize_close = static_cast<Button * >(prizepic->getChildByName("close"));
    
    _prize_close->setTag(PRIZE_CLOSE);
    
    _prize_close->addTouchEventListener(CC_CALLBACK_2(MainScene::piBtnCallback, this));
    ////
   
    
    
    
    return true;
}

//
void MainScene::showGameEntry()
{
	_main_btn[7]->setVisible(true);
	_main_btn[8]->setVisible(true);

	_someRank->setVisible(true);
}
//

void MainScene::piBtnCallback(Ref *psender, Widget::TouchEventType type)
{
    Button * btn = (Button *)psender;
    
    if (type == Widget::TouchEventType::ENDED)
    {
        switch (btn->getTag())
        {
            case PRIZE_CLOSE:
            {
                _prize_layer->removeFromParent();
            }
                break;
                
            case INFORM_GET:
            {
                _prize_layer->setVisible(true);
                
                auto isvisble = Sequence::create(ScaleTo::create(1, 0), NULL);
                
                _inform_layer->runAction(isvisble);
            }
                break;
                
            case INFORM_CLOSE:
            {
                _inform_layer->removeFromParent();
                
                _prize_layer->removeFromParent();
            }
                break;
                
            default:
                break;
        }
    }
}

void MainScene::mainBtnCallback(Ref *psender, Widget::TouchEventType type)
{
    Button * btn = (Button *)psender;
    
    if (type == Widget::TouchEventType::ENDED)
    {
        switch (btn->getTag())
        {
            case MAIN_SET:
            {
                _set_root = CSLoader::createNode("SetLayer.csb");
                
                this->addChild(_set_root,4);
                
                _set_layer = static_cast<Layout *>(_set_root->getChildByName("Panel_set"));
                
                auto close = static_cast<Button *>(_set_layer->getChildByName("back"));
                
                close->setTag(SET_BACK);
                
                close->addTouchEventListener(CC_CALLBACK_2(MainScene::inBtnCallback, this));
            }
                break;
                
            case MAIN_MAIL:
            {
                _mail_root = CSLoader::createNode("MailLayer.csb");
                
                this->addChild(_mail_root,4);
                
                _mail_layer = static_cast<Layout *>(_mail_root->getChildByName("Panel_mail"));
                
                auto back = static_cast<Button *>(_mail_layer->getChildByName("back"));
                
                back->setTag(MAIL_BACK);
                
                back->addTouchEventListener(CC_CALLBACK_2(MainScene::inBtnCallback, this));
            }
                break;
                
            case MAIN_MISSION:
            {
                _mission_root = CSLoader::createNode("MissionLayer.csb");
                
                this->addChild(_mission_root,4);
                
                _mission_layer = static_cast<Layout *>(_mission_root->getChildByName("Panel_mission"));
                
                auto back = static_cast<Button *>(_mission_layer->getChildByName("back"));
                
                back->setTag(MISSION_BACK);
                
                back->addTouchEventListener(CC_CALLBACK_2(MainScene::inBtnCallback, this));
            }
                break;
                
            case MAIN_FRIEND:
            {
				
            }
                break;
                
            case MAIN_CLASSIC:
            {
				//

				_main_btn[7]->setVisible(false);
				_main_btn[8]->setVisible(false);
				_someRank->setVisible(false);

				this->addChild(PropLayer::create());

				//
            }
                break;
                
            case MAIN_BOSS:
            {
                
            }
                break;
                
            case MAIN_BUYCOIN:
            {
                _buycoin_root = CSLoader::createNode("BuycoinLayer.csb");
                
                this->addChild(_buycoin_root,4);
                
                _buycoin_layer = static_cast<Layout *>(_buycoin_root->getChildByName("Panel_buycoin"));
                
                _buycoin_yn_layer = static_cast<Layout *>(_buycoin_root->getChildByName("Panel_yesorno"));
                
                auto back = static_cast<Button *>(_buycoin_layer->getChildByName("buycoin_back"));
                
                back->addTouchEventListener(CC_CALLBACK_2(MainScene::inBtnCallback, this));
                
                back->setTag(BUYCOIN_BACK);
                
                auto backpic = static_cast<Sprite *>(_buycoin_layer->getChildByName("buycoin_bk"));
                
                for (int i = 0; i < sizeof(_buycoin_btn)/sizeof(_buycoin_btn[0]); i++)
                {
                    std::stringstream ss;
                    ss<<"buycoin_btn0";
                    ss<<i+1;
                    _buycoin_btn[i] = static_cast<Button *>(backpic->getChildByName(ss.str().c_str()));
                    
                    _buycoin_btn[i]->addTouchEventListener(CC_CALLBACK_2(MainScene::inBtnCallback, this));
                }
                
            }
                break;
                
            case MAIN_BUYDIAMOND:
            {
                _buydiamond_root = CSLoader::createNode("BuydiamondLayer.csb");
                
                this->addChild(_buydiamond_root,4);
                
                _buydiamond_layer = static_cast<Layout *>(_buydiamond_root->getChildByName("Panel_buydiamond"));
                
                auto back = static_cast<Button *>(_buydiamond_layer->getChildByName("back"));
                
                back->addTouchEventListener(CC_CALLBACK_2(MainScene::inBtnCallback, this));
                
                back->setTag(BUYDIAMOND_BACK);
            }
                break;
                
            case MAIN_BUYHEART:
            {
                _buyheart_root = CSLoader::createNode("BuyheartLayer.csb");
                
                this->addChild(_buyheart_root,4);
                
                _buyheart_layer = static_cast<Layout *>(_buyheart_root->getChildByName("Panel_heart"));
                
                _buyheart_yn_layer = static_cast<Layout *>(_buyheart_root->getChildByName("Panel_yesorno"));
                
                auto back = static_cast<Button *>(_buyheart_layer->getChildByName("buyheart_back"));
                back->addTouchEventListener(CC_CALLBACK_2(MainScene::inBtnCallback, this));
                
                back->setTag(BUYHEART_BACK);
            }
                break;
                
                default:
                    break;
        }
    }
}

void MainScene::inBtnCallback(Ref *psender, Widget::TouchEventType type)
{
    Button * btn = (Button *)psender;
    
    if (type == Widget::TouchEventType::ENDED)
    {
        switch (btn->getTag())
        {
            case SET_BACK:
            {
                _set_layer->removeFromParent();
            }
                break;
                
            case MAIL_BACK:
            {
                _mail_layer->removeFromParent();
            }
                break;
                
            case MISSION_BACK:
            {
                _mission_layer->removeFromParent();
            }
                break;
                
            case BUYCOIN_BACK:
            {
                _buycoin_layer->removeFromParent();
                _buycoin_yn_layer->removeFromParent();
            }
                break;
                
            case BUYCOIN_BTN:
            {
                
            }
                break;
                
            case BUYHEART_BACK:
            {
                _buyheart_layer->removeFromParent();
                _buyheart_yn_layer->removeFromParent();
            }
                break;
                
            case BUYDIAMOND_BACK:
            {
                _buydiamond_layer->removeFromParent();
                
            }
                break;
                
            default:
                break;
        }
    }
}