#pragma once
#include "Atlas.h"
#include "util.h"
#include <stdint.h>
#include <functional>

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

	//core codes
	void update(uint32_t delta) {
		timer += delta;  // 累加当前帧的时间
		if (timer >= interval_ms) {  // 如果累计时间超过帧切换间隔
			timer = 0;  // 重置计时器
			frame_index++;  // 切换到下一帧
			if (frame_index >= atlas->get_size()) {  // 如果已经到了最后一帧
				frame_index = is_loop ? 0 : atlas->get_size() - 1;  // 如果是循环播放，回到第一帧；否则保持在最后一帧
				if (!is_loop && callback)  // 如果不是循环播放，并且有回调函数
					callback();  // 调用回调函数（可以用来触发一些事件）
			}
		}
	}


	void on_draw(uint32_t x, uint32_t y) const{
		putimage_alpha(x, y, atlas->get_image(frame_index));
	}

	void set_callback(std::function<void()> callback) {
		this->callback = callback;
	}

private:
	uint32_t timer = 0;			//计时器
	uint32_t interval_ms = 0;	//动画帧切换间隔时间，单位毫秒
	size_t frame_index = 0;		//当前动画帧索引
	bool is_loop = true;		//是否循环播放动画
	Atlas* atlas = nullptr;
	std::function<void()> callback;
};