//
//  LoadingScene.h
//  WindRunner
//
//  Created by jiaolong on 15/3/1.
//
//

#ifndef __WindRunner__LoadingScene__
#define __WindRunner__LoadingScene__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

class LoadingScene: public Layer
{
public:
    
    static Scene *createScene();
    
    bool init(void);
    
    void updata(float dt);
    
    void changeScene(float dt);
    
    LoadingScene();
    
    ~LoadingScene();
    
    CREATE_FUNC(LoadingScene);
    
private:
    
    ui::Text *_tips;
    
    
};
#endif /* defined(__WindRunner__LoadingScene__) */
