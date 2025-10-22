#include <graphics.h>
#include <stdint.h>

#include "Scene.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "SceneSelector.h"
#include "Atlas.h"
#include "util.h"

Scene* game_scene = nullptr;
Scene* menu_scene = nullptr;
Scene* scene_selector = nullptr;

SceneManager scene_manager;

void flip_altas(Atlas& src, Atlas& dst) {
	dst.clear();
	for (size_t i = 0; i < src.get_size(); i++) {
		IMAGE img_flipped;
		flip_image(src.get_image(i), &img_flipped);
		dst.add_image(img_flipped);
	}

}

int main(void) {
	initgraph(1280, 720);
	ExMessage msg;

	const uint32_t FPS = 60;

	BeginBatchDraw();

	menu_scene = new MenuScene();
	game_scene = new GameScene();
	scene_selector = new SceneSelector();

	scene_manager.set_current_scene(menu_scene);

	while (1) {
		DWORD frame_start_time = GetTickCount();

		while (peekmessage(&msg)) {
			scene_manager.on_input(msg);
		}

		scene_manager.on_update();

		cleardevice();

		scene_manager.on_draw();

		FlushBatchDraw();

		DWORD frame_end_time = GetTickCount();
		DWORD frame_delta_time = frame_end_time - frame_start_time;
		if (frame_delta_time < 1000 / FPS) {
			Sleep(1000 / FPS - frame_delta_time);
		}

		EndBatchDraw();
	}
	return 0;
}