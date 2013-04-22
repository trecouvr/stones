#pragma once

#include <string>

#include "View.h"

class SpriteView : public View
{
    public:
        SpriteView(std::string file_path, int x=0, int y=0);
        virtual ~SpriteView();
        void show();
        void hide();
        bool isPointIn(const CCPoint& point);
        const CCPoint& getPosition() const;
        void setPosition(const CCPoint& pos);
        CCSprite* getSprite();
        
        
    protected:
        CCSprite* sprite_;
        
};

