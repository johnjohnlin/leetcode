#include "template_matrix.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <memory>
#include <cassert>
#include <cstdio>
using namespace std;

class NumArray {
	unique_ptr<int[]> mipmap_data;
	vector<int*> mipmap_layer;
	int n_;
public:
	NumArray(const vector<int> &nums) {
		if (nums.size() == 0) {
			return;
		}
		int n = this->n_ = nums.size();
		this->mipmap_data.reset(new int[n*2]);

		int *cur_layer = this->mipmap_data.get();
		this->mipmap_layer.push_back(cur_layer);
		copy(nums.begin(), nums.end(), cur_layer);
		cur_layer += n;

		while (n != 0) {
			n /= 2;
			const int *prev_layer = this->mipmap_layer.back();
			this->mipmap_layer.push_back(cur_layer);
			for (int i = 0; i < n; ++i) {
				cur_layer[i] = prev_layer[i*2+0] + prev_layer[i*2+1];
			}
			cur_layer += n;
		}
	}
	void update(int i, int val) {
		const int diff = val - mipmap_layer[0][i];
		int n = this->n_;
		for (int *layer: mipmap_layer) {
			if (i == n) {
				break;
			}
			layer[i] += diff;
			i = i/2;
			n /= 2;
		}
	}
	int sumRange(int i, int j) {
		++j;
		int sum = 0;
		int l = 0;
		int chunk = 1;
		while (i + chunk <= j) {
			if ((i&chunk) != 0) {
				int mipmap_i = i >> l;
				sum += this->mipmap_layer[l][mipmap_i];
				i += chunk;
			}
			chunk *= 2;
			++l;
		}
		do {
			--l;
			chunk /= 2;
			if (i + chunk <= j) {
				int mipmap_i = i >> l;
				sum += this->mipmap_layer[l][mipmap_i];
				i += chunk;
			}
		} while (i != j);
		return sum;
	}
};

int main(int argc, char const* argv[])
{
	NumArray n1({1,2,3,4,5,6});
	printf("%d\n", n1.sumRange(0, 3)); // 10
	printf("%d\n", n1.sumRange(1, 3)); // 9
	printf("%d\n", n1.sumRange(2, 3)); // 7
	printf("%d\n", n1.sumRange(2, 5)); // 18
	printf("%d\n", n1.sumRange(5, 5)); // 6

	NumArray n2({7,2,7,2,0});
	n2.update(4,6);
	n2.update(0,2);
	n2.update(0,9);
	printf("%d\n", n2.sumRange(4,4)); // 6
	n2.update(3,8);
	printf("%d\n", n2.sumRange(0,4)); // 32
	n2.update(4,1);
	printf("%d\n", n2.sumRange(0,3)); // 26
	printf("%d\n", n2.sumRange(0,4)); // 27
	n2.update(0,4);
	return 0;
}
