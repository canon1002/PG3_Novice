#pragma once

struct Vec2 {
	int x, y;

	Vec2 operator+(Vec2 other) {
		return Vec2(x + other.x , y + other.y);
	}

	Vec2 operator-(Vec2 other) {
		return Vec2(x - other.x, y - other.y);
	}

	Vec2 operator*(Vec2 other) {
		return Vec2(x * other.x , y * other.y);
	}

	Vec2 operator+=(Vec2 other) {
		return { x += other.x , y += other.y };
	}

	bool operator<(Vec2 other) {
		return x < other.x && y < other.y;
	}
};

class IObject
{
public:

	// 純粋仮想関数
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IObject();

};

