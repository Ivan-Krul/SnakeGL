#pragma once
#include <vector>
#include <assert.h>

using std::vector;
using std::pair;

class Snake {
	vector<pair<int, int>> tail;
	bool alive = true;
public:
	static enum Keys { N = 0, E, S, W } dir;

	Snake(int mX, int mY) {
		pair<int, int> s;
		s.first = rand() % mX;
		s.second = rand() % mY;
		tail.push_back(s);
	}

	void move(Keys tar);

	void coliderTail();

	bool isAlive() {
		return alive;
	}

	void madeDeath() {
		alive = false;
	}

	void testPos(int ind1, int ind2);
};

