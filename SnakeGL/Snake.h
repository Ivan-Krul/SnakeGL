#pragma once
#include <vector>
#include <assert.h>

using std::vector;
using std::pair;

class Snake {
	vector<pair<int, int>> tail;
	bool alive;
public:
enum Keys { Null = 0,N, E, S, W } dir;

	Snake() {}

	void setup(int mX, int mY);

	void move(Keys tar);

	void coliderTail();

	int getSize() {
		return tail.size();
	}

	pair<int, int> getPosition(unsigned int ind) {
		return tail[ind < tail.size()?ind:tail.size()-1];
	}

	bool isAlive() {
		return alive;
	}

	void addTail() {
		tail.push_back(tail[tail.size() - 1]);
	}

	void teleport(int x, int y);

	void madeDeath() {
		alive = false;
	}

	void testPos(int ind1, int ind2);
};

