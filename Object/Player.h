#pragma once
#include <stdint.h>

struct Vec2Int {
	int32_t x, y;

	Vec2Int operator=(Vec2Int other) {
		return{
			x = other.x,
			y = other.y
		};
	}

	Vec2Int operator+=(Vec2Int other) {
		return{
			x += other.x,
			y += other.y
		};
	}
};

class Player
{
public:

	Player();
	~Player();
	void Init();
	void Update();
	void Draw();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

private:

	 Vec2Int pos_;
	 Vec2Int rad_;
	 Vec2Int vel_;
	 Vec2Int speed_;
	 uint32_t color_;

};

