#include<iostream>
#include<cmath>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;
struct node {
	int x, y;
};
bool cmp1(node p1, node p2) {
	return p1.x < p2.x;
}
bool cmp2(node p1, node p2) {
	return p1.y < p2.y;
}
double distance(node p1, node p2) {
	return sqrt((p1.x - p2.x)* (p1.x - p2.x) + (p1.y - p2.y)* (p1.y - p2.y));
}
double find(node p[], int left, int right) {
	if (right - left == 1) {
		return distance(p[left], p[right]);
	}
	else if (right - left == 2) {
		double d1 = distance(p[left], p[left + 1]);
		double d2 = distance(p[left], p[right]);
		double d3 = distance(p[left + 1], p[right]);
		d2 = min(d1, d2);
		d3 = min(d2, d3);
		return d3;

	}
	int center = (left + right) / 2;
	double d1 = find(p, left, center);
	double d2 = find(p, center + 1, right);
	double d = min(d1, d2);
	int low = left, high = right;
	while (p[low].x < p[center].x - d && low <= right) {
		low++;
	}
	while (p[high].x > p[center].x + d && high>center) {
		high--;
	}
	double d3;
	sort(p + low, p + high + 1, cmp2);
	for (int i = low; i < high; i++) {
		for (int j = i + 1; j < high; j++) {
				d3 = distance(p[i], p[j]);
				if (d3 < d) {
					d = d3;
				}

		}

	}
	return d;
}
int main() {
	node p[20];
	cout << "请输入点的数量" << endl;
	int n;
	cin >> n;
	cout << "请输入坐标" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + n, cmp1);
	double d = find(p, 0, n-1);
	cout << d << endl;


}