#pragma once
#include "scene.h"
#include <iostream>
#include "SceneManager.h"

extern SceneManager scene_manager;

class GameScene : public Scene {
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter() {
		std::cout << "Enter Game Scene" << std::endl;
	}
	void on_input(const ExMessage& msg) {
		if (msg.message == WM_KEYDOWN) {
			scene_manager.switch_to(SceneManager::SceneType::Menu);
		}
	}

	void on_update(uint32_t delta) {
		std::cout << "Update Game Scene" << std::endl;
	}
	void on_draw() {
		outtextxy(10, 10, _T("Game Scene"));
	}
	void on_exit() {
		std::cout << "Exit Game Scene" << std::endl;
	}
private:
};