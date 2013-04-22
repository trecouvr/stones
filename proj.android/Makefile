PROJ_NAME=stones
PROJ_NS=fr.stones

all: native java
	@echo "Finish build all"
native:
	./build_native.sh
java:
	ant -Dsdk.dir=$(SDK_ROOT) debug
install:
	adb uninstall $(PROJ_NS)
	adb install bin/$(PROJ_NAME)-debug.apk
reinstall:
	adb install -r bin/$(PROJ_NAME)-debug.apk
run:
	adb shell am start -n $(PROJ_NS)/$(PROJ_NS).$(PROJ_NAME)
logs:
	adb logcat
clean:
	rm -rf obj/
	rm -rf bin/*
	rm -rf gen/
	rm -rf assets/*

