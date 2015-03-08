//
//  LoadingScene.cpp
//  WindRunner
//
//  Created by jiaolong on 15/3/1.
//
//

#include "LoadingScene.h"
#include "MainScene.h"

const int HOW_MANY_TIPS = 4;

using namespace cocos2d::ui;

Scene * LoadingScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = LoadingScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

LoadingScene::LoadingScene()
:
_tips(nullptr)

{
    
}

LoadingScene::~LoadingScene()
{
    
}

bool LoadingScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

	srand(time(NULL));
    
    auto load_root = CSLoader::createNode("LoadingScene.csb");
    
    this->addChild(load_root);
    
    _tips = static_cast<ui::Text *>(load_root->getChildByName("tips"));
    
    _tips->setFontSize(30);
    
    _tips->setString("睡觉前要洗脸！！");
    
    schedule(schedule_selector(LoadingScene::updata), 2);
    
    schedule(schedule_selector(LoadingScene::changeScene), 5);
    
    return true;
}

void LoadingScene::changeScene(float dt)
{
    Director::getInstance()->replaceScene(TransitionCrossFade::create(1, MainScene::createScene()));
}

void LoadingScene::updata(float dt)
{
    std::stringstream ss;
    
    auto random = rand() % HOW_MANY_TIPS;
    
    switch (random)
    {
        case 0:
        {
            ss<<"睡觉前要吃饭！！";
        }
            break;
            
        case 1:
        {
            ss<<"睡觉前要洗脸！！";
        }
            break;
        case 2:
        {
            ss<<"睡觉前要刷牙！！";
        }
            break;
        case 3:
        {
            ss<<"睡觉前要上厕所！！";
        }
            break;
        case 4:
        {
            ss<<"睡觉前要上喝水！！";
        }
            break;
            
        default:
            break;
    }
    _tips->setString(ss.str());
}
