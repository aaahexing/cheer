/************************************
Max Points on a Line : https://leetcode.com/problems/max-points-on-a-line/

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
**/

// Definition for a point.
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

//@time complexity: O(n^2)
//@space complexity: O(n)
int maxPoints(vector<Point> &points) {
	map<float, int> m;
	int max = INT_MIN;
	if (points.size() <= 1) {
		return points.size();
	}

	for (int i = 0; i < points.size(); i++) {
		int duplicate = 1;
		int iMax = 0;
		m.clear();
		for (int j = i + 1; j < points.size(); j++) {
			if ((points[j].x == points[i].x) && (points[j].y == points[i].y)) {
				duplicate++;
				continue;
			}

			float slope = points[j].x == points[i].x ? INT_MAX : ((float) (points[j].y - points[i].y) / (float) (points[j].x - points[i].x));
			if (m.find(slope) == m.end()) {
				m[slope] = 1;
			} else {
				m[slope]++;
			}
		}

		for(map<float, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
			if (itr->second > iMax) {
				iMax = itr->second;
			}
		}

		if (iMax + duplicate > max) {
			max = iMax + duplicate;
		}
	}

	return max;
}