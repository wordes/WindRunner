//
//  MainScene.h
//  WindRunner
//
//  Created by jiaolong on 15/3/7.
//
//

#ifndef __WindRunner__MainScene__
#define __WindRunner__MainScene__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocos2d::ui;

class MainScene : public Layer
{
public:
    
    static Scene *createScene();
    
    bool init(void);
    
    void piBtnCallback(Ref *psender, Widget::TouchEventType type);
    
    void mainBtnCallback(Ref *psender, Widget::TouchEventType type);
    
    void inBtnCallback(Ref *psender, Widget::TouchEventType type);
	//
	void showGameEntry();
    //
    MainScene();
    
    ~MainScene();
    
    CREATE_FUNC(MainScene);
    
private:
    
    Node *_main_root;
    
    Node *_inform_root;
    
    Node *_buycoin_root;
    
    Node *_buydiamond_root;
    
    Node *_buyheart_root;
    
    Node *_mail_root;
    
    Node *_mission_root;
    
    Node *_prize_root;
    
    Node *_set_root;

    Button *_prize_close;
    
    Button *_inform_close;
    
    Button *_inform_get;
    
    Button *_main_btn[9];
    
    Button *_buycoin_btn[4];
    
    Layout *_inform_layer;
    
    Layout *_prize_layer;
    
    Layout *_set_layer;
    
    Layout *_mail_layer;
    
    Layout *_mission_layer;
    
    Layout *_buycoin_layer;
    
    Layout *_buycoin_yn_layer;
    
    Layout *_buydiamond_layer;
    
    Layout *_buyheart_layer;
    
    Layout *_buyheart_yn_layer;
    
    Layout *_set;

	//
	Sprite* _someRank;
	//
};
#endif /* defined(__WindRunner__MainScene__) */
