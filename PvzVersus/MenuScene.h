#pragma once
#include "scene.h"
#include "SceneManager.h"
#include "Atlas.h"
#include "Animation.h"

#include <iostream>

extern SceneManager scene_manager;

extern Atlas atlas_peashooter_run_right;

class MenuScene : public Scene {
public:
	MenuScene() = default;
	~MenuScene() = default;
	void on_enter() {
		animation_peashooter_run_right.set_atlas(&atlas_peashooter_run_right);
		animation_peashooter_run_right.set_interval(75);
		animation_peashooter_run_right.set_loop(true);
		animation_peashooter_run_right.set_callback([]() {
			scene_manager.switch_to(SceneManager::SceneType::Game);
			});
		std::cout << "Enter Menu Scene" << std::endl;
	}
	void on_input(const ExMessage& msg){
		if (msg.message == WM_KEYDOWN) {
			scene_manager.switch_to(SceneManager::SceneType::Game);
		}
	}

	void on_update(uint32_t delta) {
		animation_peashooter_run_right.update(delta);
	}
	void on_draw() {
		animation_peashooter_run_right.on_draw(100, 100);
	}
	void on_exit() {
		std::cout << "Exit Menu Scene" << std::endl;
	}

private:
	Animation animation_peashooter_run_right;
};
