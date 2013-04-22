LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/AreneLayer.cpp \
                   ../../Classes/CocoCard.cpp \
                   ../../Classes/SpriteView.cpp \
                   ../../Classes/View.cpp \
                   ../../Classes/game_logic/Card.cpp \
                   ../../Classes/game_logic/Deck.cpp \
                   ../../Classes/game_logic/Player.cpp
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static
            
LOCAL_CFLAGS += -DCOCOS2D_DEBUG=2

include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions)
