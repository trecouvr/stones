#pragma once


#include "cocos2d.h"
USING_NS_CC;


class AreneLayer : public CCLayer
{
    protected:
        /// The background color layer
        CCLayerColor* colorLayer;

    public:
        AreneLayer();
        ~AreneLayer();

        CCPoint touchToPoint(CCTouch* touch);

        void ccTouchesBegan(CCSet* touches, CCEvent* event);
        void ccTouchesMoved(CCSet* touches, CCEvent* event);
        void ccTouchesEnded(CCSet* touches, CCEvent* event);
};


