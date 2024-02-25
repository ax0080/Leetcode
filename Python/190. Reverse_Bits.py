class Solution:
    def reverseBits(self, n: int) -> int:
        sum = 0
        #0101 -> 0010 -> 0001 -> 0000
        #0001 -> 0010 -> 0101 -> 1010
        for i in range(32):
            sum = (sum << 1) | (n & 1)
            n = n >> 1
        return (sum)
