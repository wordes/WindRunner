//
//  SigninScene.h
//  WindRunner
//
//  Created by jiaolong on 15/3/2.
//
//

#ifndef __WindRunner__SigninScene__
#define __WindRunner__SigninScene__

#include "cocos2d.h"
#include <stdio.h>

USING_NS_CC;

class SigninScene : public Layer
{
public:
    
    static Scene *createScene();
    
    bool init(void);
    
    SigninScene();
    
    ~SigninScene();
    
    CREATE_FUNC(SigninScene);
    
private:
    
};
#endif /* defined(__WindRunner__SigninScene__) */
