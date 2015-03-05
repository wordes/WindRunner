//
//  SigninScene.cpp
//  WindRunner
//
//  Created by jiaolong on 15/3/2.
//
//

#include "SigninScene.h"


using namespace cocos2d::ui;

Scene * SigninScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = SigninScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

SigninScene::SigninScene()
{
    
}

SigninScene::~SigninScene()
{
    
}

bool SigninScene::init(void)
{
    if (!Layer::init())
    {
        return false;
    }
    
    
    return true;
}