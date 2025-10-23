#pragma once
#include "Atlas.h"
#include <stdint.h>

class Animation {
public:
	Animation() = default;
	~Animation() = default;

	void reset() {
		timer = 0;
		frame_index = 0;
	}

	void set_interval(uint32_t interval) {
		interval_ms = interval;
	}

	void set_atlas(Atlas* new_atlas) {
		reset();
		atlas = new_atlas;
	}

	void set_loop(bool flag) {
		is_loop = flag;
	}

	size_t get_frame_index() {
		return frame_index;
	}

	IMAGE* get_frame() {
		return atlas->get_image(frame_index);
	}

	bool check_finished() {
		if (is_loop) return false;
		return (frame_index == atlas->get_size() - 1);
	}

private:
	uint32_t timer = 0;			//计时器
	uint32_t interval_ms = 0;	//动画帧切换间隔时间，单位毫秒
	size_t frame_index = 0;		//当前动画帧索引
	bool is_loop = true;		//是否循环播放动画
	Atlas* atlas = nullptr;
};