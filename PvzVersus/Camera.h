#pragma once
#include "Vector2D.h"
#include <stdint.h>
class Camera {
public:
	Camera() = default;
	~Camera() = default;

	const Vector2D& get_position() const {
		return position;
	}

	void reset() {
		position.x = 0;
		position.y = 0;
	}

	void on_update(uint32_t delta) {
		const Vector2D speed = { -0.35f, 0 };
		position += speed * (float)delta;
	}
	
private:
	Vector2D position;
};