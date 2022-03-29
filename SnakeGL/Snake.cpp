#include "Snake.h"

void Snake::move(Keys tar) {
	tar = dir;

	for (int i = tail.size() - 1;i > 1;i--)
		tail[i - 1] = tail[i];

	pair<int, int>& head = tail[0];

	switch (dir) {
	case Snake::N:
		head.second++;
		break;
	case Snake::E:
		head.first++;
		break;
	case Snake::S:
		head.second--;
		break;
	case Snake::W:
		head.first--;
		break;
	default:
		break;
	}
}

void Snake::coliderTail() {
	for (int i = 1;i < tail.size() && isAlive;i++)
		if (tail[0] == tail[i])
			alive = false;
}

void Snake::testPos(int ind1, int ind2) {
	if (tail.size() != 1) {
		double l = pow(tail[ind2].first - tail[ind1].first, 2);
		l += pow(tail[ind2].second - tail[ind1].second, 2);
		assert(sqrt(l) <= 1);
	}
}
