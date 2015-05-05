class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = (n&0x55555555) + ((n>>1)&0x55555555);
        n = (n&0x33333333) + ((n>>2)&0x33333333);
        n = (n+(n>>4))&0x0f0f0f0f;
        n = (n+(n>>8))&0x00ff00ff;
        n = (n+(n>>16))&0x0000ffff;
        return n;
    }
};

int main(int argc, char const* argv[])
{
	// I don't want to test...
	return 0;
}
