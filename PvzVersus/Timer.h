#pragma once
#include "stdint.h"
#include <functional>
class Timer {
public:
	Timer() = default;
	~Timer() = default;

	void restart() {
		pass_time = 0;
		shotted = false;
	}

	void set_wait_time(uint32_t val) {
		wait_time = val;
	}

	void set_once_shotted(bool flag) {
		once_shotted = flag;
	}

	void set_callback(std::function<void()> callback) {
		this->callback = callback;
	}

	void pause() {
		paused = true;
	}

	void resume() {
		paused = false;
	}

	void on_update(uint32_t delta) {
		if (paused)
			return;
		pass_time += delta;
		if (pass_time >= wait_time) {
			if ((!once_shotted || (once_shotted && !shotted)) && callback)
				callback();
			shotted = true;
			pass_time = 0;
		}
	}
private:
	uint32_t pass_time = 0;			//已过时间
	uint32_t wait_time = 0;			//等待时间
	bool paused = false;				//是否暂停
	bool shotted = false;			//是否触发
	bool once_shotted = false;		//单次触发
	std::function<void()> callback;	//回调函数
};