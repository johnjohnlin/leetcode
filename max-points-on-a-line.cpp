#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;
struct Point {
	int x, y;
	Point(int a, int b): x(a), y(b) {}
};

/* Integer square root by Halleck's method, with Legalize's speedup */
long isqrt(long x) {
	long squaredbit, remainder, root;

	if (x<1) return 0;

	/* Load the binary constant 01 00 00 ... 00, where the number
	 * of zero bits to the right of the single one bit
	 * is even, and the one bit is as far left as is consistant
	 * with that condition.)
	 */
	squaredbit  = (long) ((((unsigned long) ~0L) >> 1) &
			~(((unsigned long) ~0L) >> 2));
	/* This portable load replaces the loop that used to be
	 * here, and was donated by  legalize@xmission.com
	 */

	/* Form bits of the answer. */
	remainder = x;  root = 0;
	while (squaredbit > 0) {
		if (remainder >= (squaredbit | root)) {
			remainder -= (squaredbit | root);
			root >>= 1; root |= squaredbit;
		} else {
			root >>= 1;
		}
		squaredbit >>= 2;
	}

	return root;
}

long Gcd(long a, long b)
{
	long gcd = 1;
	while (a != b) {
		const bool a_even = a%2 == 0;
		const bool b_even = b%2 == 0;
		if (a_even and b_even) {
			gcd *= 2;
			a /= 2;
			b /= 2;
		} else if (a_even) {
			a /= 2;
		} else if (b_even) {
			b /= 2;
		} else {
			if (a > b) {
				a = (a-b)/2;
			} else {
				b = (b-a)/2;
			}
		}
	}
	return gcd * a;
}

struct Line {
	// ax+by=c, a>0, gcd(a,|b|)=1
	long a, b, c;
	Line(const Point p1, const Point p2)
	{
		const bool same_x = p1.x == p2.x;
		const bool same_y = p1.y == p2.y;
		assert(not (same_x and same_y));
		if (same_x) {
			a = 1;
			b = 0;
			c = p1.x;
			return;
		}
		if (same_y) {
			a = 0;
			b = 1;
			c = p1.y;
			return;
		}

		if (p1.y > p2.y) {
			a = p1.y - p2.y;
			b = p2.x - p1.x;
		} else {
			a = p2.y - p1.y;
			b = p1.x - p2.x;
		}
		assert(a > 0);
		long gcd = Gcd(a, abs(b));
		a /= gcd;
		b /= gcd;
		c = a*p1.x+b*p1.y;
		assert(c == a*p2.x+b*p2.y);
	}
	friend bool operator==(const Line &l1, const Line &l2) {
		return l1.a == l2.a and l1.b == l2.b and l1.c == l2.c;
	}
};

class Solution {
		vector<pair<Point,int>> SortPoints(vector<Point>& points)
		{
			const size_t n = points.size();
			assert(n != 0);
			vector<pair<Point,int>> ret;
			sort(points.begin(), points.end(), [](const Point &p1, const Point &p2) -> bool {
				if (p1.x != p2.x) {
					return p1.x > p2.x;
				}
				return p1.y > p2.y;
			});
			Point cur_point = points[0];
			int cur_point_count = 1;
			for (size_t i = 1; i < points.size(); ++i) {
				if (points[i].x == cur_point.x and points[i].y == cur_point.y) {
					++cur_point_count;
				} else {
					ret.emplace_back(cur_point, cur_point_count);
					cur_point = points[i];
					cur_point_count = 1;
				}
			}
			ret.emplace_back(cur_point, cur_point_count);
			return ret;
		}
	public:
		int maxPoints(vector<Point>& points) {
			if (points.size() == 0) {
				return 0;
			}
			auto point_and_counts = SortPoints(points);
			const size_t n_unique_points = point_and_counts.size();
			assert(n_unique_points != 0);
			if (n_unique_points == 1) {
				return point_and_counts[0].second;
			}
			struct LineAndCount {
				Line line;
				int inter, intra;
			};
			vector<LineAndCount> line_and_counts;
			for (size_t i = 0; i < n_unique_points; ++i) {
				for (size_t j = i+1; j < n_unique_points; ++j) {
					Point pi = point_and_counts[i].first;
					Point pj = point_and_counts[j].first;
					const int ni = point_and_counts[i].second;
					const int nj = point_and_counts[j].second;
					line_and_counts.push_back({{pi, pj}, ni*nj, (ni*(ni-1)+nj*(nj-1))/2});
				}
			}
			assert(line_and_counts.size() != 0);
			sort(line_and_counts.begin(), line_and_counts.end(), [](const LineAndCount &lc1, const LineAndCount &lc2) -> bool {
				auto &l1 = lc1.line;
				auto &l2 = lc2.line;
				if (l1.a != l2.a) {
					return l1.a > l2.a;
				}
				if (l1.b != l2.b) {
					return l1.b > l2.b;
				}
				return l1.c > l2.c;
			});
			Line cur_line = line_and_counts[0].line;
			int inter_sum = 0;
			int intra_sum = 0;
			int n_line_unique = 0;
			int max_line_count = -1;
			for (size_t i = 0; i < line_and_counts.size(); ++i) {
				auto &line_and_count = line_and_counts[i];
				if (line_and_count.line == cur_line) {
					inter_sum += line_and_count.inter;
					intra_sum += line_and_count.intra;
					n_line_unique += 1;
				} else {
					const int point_count = (1+isqrt(n_line_unique*8+1))/2;
					max_line_count = max(max_line_count, inter_sum + intra_sum/(point_count-1));
					cur_line = line_and_count.line;
					inter_sum = 0;
					intra_sum = 0;
					n_line_unique = 0;
					--i;
				}
			}
			const int point_count = (1+isqrt(n_line_unique*8+1))/2;
			max_line_count = max(max_line_count, inter_sum + intra_sum/(point_count-1));
			return (1+isqrt(max_line_count*8+1))/2;
		}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<Point> p1{Point(0,0),Point(1,0)};
	vector<Point> p2{
		Point(0,0),Point(1,0),
		Point(0,0),Point(1,0)
	};
	vector<Point> p3{
		Point(84,250),Point(0,0),Point(1,0),Point(0,-70),
		Point(0,-70),Point(1,-1),Point(21,10),Point(42,90),Point(-42,-230)
	};
	printf("%d\n", s.maxPoints(p1)); // 2
	printf("%d\n", s.maxPoints(p2)); // 4
	printf("%d\n", s.maxPoints(p3)); // 6
	return 0;
}
