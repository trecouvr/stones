LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS += -DCOCOS2D_DEBUG=2
LOCAL_CPPFLAGS += -std=c++11

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/ArenaScene.cpp \
		   ../../Classes/game_logic/BattleManager.cpp \
                   ../../Classes/CocoPlayer.cpp \
                   ../../Classes/CocoPlayerAi.cpp \
                   ../../Classes/CocoPlayerHuman.cpp \
                   ../../Classes/Display.cpp \
                   ../../Classes/GeneralOperators.cpp \
                   ../../Classes/HandCardDisplay.cpp \
                   ../../Classes/LayerCocoPlayer.cpp \
                   ../../Classes/LayerHumanCocoPlayer.cpp \
                   ../../Classes/MonsterDisplay.cpp \
                   ../../Classes/PlayerHpDisplay.cpp \
                   ../../Classes/Utils.cpp \
                   ../../Classes/game_logic/Ai.cpp \
                   ../../Classes/game_logic/Action.cpp \
                   ../../Classes/game_logic/Card.cpp \
                   ../../Classes/game_logic/CardSet.cpp \
                   ../../Classes/game_logic/Deck.cpp \
                   ../../Classes/game_logic/Event.cpp \
                   ../../Classes/game_logic/GameManager.cpp \
                   ../../Classes/game_logic/Graveyard.cpp \
                   ../../Classes/game_logic/Observable.cpp \
                   ../../Classes/game_logic/Observer.cpp \
                   ../../Classes/game_logic/Player.cpp \
                   ../../Classes/game_logic/UserInterface.cpp \

                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions)
