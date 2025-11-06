#pragma once
#include "scene.h"
#include "SceneManager.h"
#include "Atlas.h"
#include "Animation.h"
#include "Camera.h"
#include "Timer.h"
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
		/*animation_peashooter_run_right.set_callback([]() {
			scene_manager.switch_to(SceneManager::SceneType::Game);
			});*/

		timer.set_wait_time(1000);
		timer.set_once_shotted(false);
		timer.set_callback([]() {
			std::cout << "Shot!" << std::endl;
			});
	}
	void on_input(const ExMessage& msg){
		if (msg.message == WM_KEYDOWN) {
			scene_manager.switch_to(SceneManager::SceneType::Game);
		}
	}

	void on_update(uint32_t delta) {
		timer.on_update(delta);
		camera.on_update(delta);
		animation_peashooter_run_right.update(delta);
	}
	void on_draw() {
		const Vector2D& cam_pos = camera.get_position();
		animation_peashooter_run_right.on_draw((uint32_t)(100 - cam_pos.x), (uint32_t)(100 - cam_pos.y));
	}
	void on_exit() {
		std::cout << "Exit Menu Scene" << std::endl;
	}

private:
	Timer timer;
	Camera camera;
	Animation animation_peashooter_run_right;
};
