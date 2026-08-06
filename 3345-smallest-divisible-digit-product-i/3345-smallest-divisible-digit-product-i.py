class Solution:
    def give_product(self, n: int) -> int:
        ans = 1
        while n > 0:
            ans = ans * (n % 10)
            n //= 10
        return ans

    def smallestNumber(self, n: int, t: int) -> int:
        for i in range(n, n+10):
            if self.give_product(i) % t == 0:
                return i

        return -1
        