#include "AppDelegate.h"
#include <iostream>
#include "AreneLayer.h"
#include "ArenaScene.h"


AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    CCSize designResolutionSize = CCSizeMake(800, 1280);
    
    CCDirector *pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    pDirector->setOpenGLView(pEGLView);

    // Set the design resolution
    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);

    CCSize frameSize = pEGLView->getFrameSize();
    
    pDirector->setContentScaleFactor(frameSize.height/designResolutionSize.height);
    
    
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
	
	/*********************************
	
    // create a generic scene
    CCScene* scene = CCScene::create();
    
    // add the layer
    AreneLayer* layer = new AreneLayer;
    scene->addChild(layer, 1);
    layer->release(); // addChild() retained so we release

	 ********************************/
	 
	ArenaScene* scene = new ArenaScene;
	scene->createArenaScene (); 

	scene->init();

    // run the first scene
    CCDirector::sharedDirector()->runWithScene(scene);
    
    return true;
}


// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
