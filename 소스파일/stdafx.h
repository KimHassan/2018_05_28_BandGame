#pragma once

#include "targetver.h"

#include <Windows.h> //windows

#include <stdio.h> //c
#include <time.h>
#include <iostream> //c++
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

#include "D:\\SDL\\SDL2-2.0.7\\include\\sdl.h"
#include "D:\\SDL\\SDL2-2.0.7\\include\\sdl_main.h"


#include "Util.h"
#include "BaseWindow.h"
#include "TimeManager.h"
#include "FrameSkip.h"
#include "InputHandler.h"
#include "InputManager.h"
#include "System.h"
#include "image.h"
#include "imageManager.h"
#include "soundManager.h"
//extern PHASE phase;
#include "Tool.h"
#include "Title.h"
#include "InGame.h"


#define IMAGEMANAGER imageManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define WINSIZEX 1280
#define WINSIZEY 720

