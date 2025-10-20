#pragma once
#include "scene.h"
#include <iostream>
#include "SceneManager.h"

extern SceneManager scene_manager;

class MenuScene : public Scene {
public:
	MenuScene() = default;
	~MenuScene() = default;
	void on_enter() {
		std::cout << "Enter Menu Scene" << std::endl;
	}
	void on_input(const ExMessage& msg){
		if (msg.message == WM_KEYDOWN) {
			scene_manager.switch_to(SceneManager::SceneType::Game);
		}
	}

	void on_update() {
		std::cout << "Update Menu Scene" << std::endl;
	}
	void on_draw() {
		outtextxy(10, 10, _T("Menu Scene"));
	}
	void on_exit() {
		std::cout << "Exit Menu Scene" << std::endl;
	}

private:
};
