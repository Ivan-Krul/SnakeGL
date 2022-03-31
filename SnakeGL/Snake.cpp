#include "Snake.h"
#include "mathSupport.h"

void Snake::setup(int mX, int mY) {
	pair<int, int> s;
	s.first = rand() % mX;
	s.second = rand() % mY;
	tail.push_back(s);
}

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
	for (int i = 1;i < tail.size() && alive;i++)
		if (tail[0] == tail[i])
			alive = false;
}

void Snake::teleport(int x, int y) {
	pair<int, int> s;
	s.first = x;
	s.second = y;
	tail[0] = s;
}

void Snake::testPos(int ind1, int ind2) {
	if (tail.size() != 1) {
		double x1 = tail[ind1 < tail.size() ? ind1 : tail.size() - 1].first;
		double y1 = tail[ind1 < tail.size() ? ind1 : tail.size() - 1].second;
		double x2 = tail[ind2 < tail.size() ? ind2 : tail.size() - 1].first;
		double y2 = tail[ind2 < tail.size() ? ind2 : tail.size() - 1].second;
		assert(mathSupport::piphagor(x1,y1,x2,y2) <= 1);
	}
}
