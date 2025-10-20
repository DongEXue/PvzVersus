#pragma once
#include <vector>
#include <graphics.h>
#include <stdint.h>

class Atlas {
public:
	Atlas() = default;
	~Atlas() = default;

	void load_from_file(LPCTSTR path_template, uint32_t num) {
		images_list.clear();
		images_list.resize(num);

		TCHAR path_file[256];
		for (size_t i = 0; i < num; i++) {
			_stprintf_s(path_file, path_template, i + 1);
			loadimage(&images_list[i], path_file);
		}
	}

	void clear() {
		images_list.clear();
	}

	size_t get_size() {
		return (uint32_t)images_list.size();
	}

	IMAGE* get_image(size_t index) {
		if (index >= images_list.size()) {
			return nullptr;
		}
		return &images_list[index];
	}

private:
	std::vector<IMAGE> images_list;
};
