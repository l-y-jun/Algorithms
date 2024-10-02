from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        return func(nums);

def func(arr):
    i = 0;
    ret = [1];
    v = 1;
    while i < len(arr) - 1:
        v = v * arr[i];
        ret.append(v);
        i += 1;
    v = 1;

    while i > 0:
        v = v * arr[i];
        ret[i - 1] = ret[i - 1] * v;
        i -= 1;
    return (ret);
    

if __name__ == "__main__":
    sol = Solution();

    arr = [1,2,3,4];
    ret = [24,12,8,6];
    print(sol.productExceptSelf(arr));

    assert(sol.productExceptSelf(arr) == ret);

    arr = [1];
    ret = [1];
    print(sol.productExceptSelf(arr));

    assert(sol.productExceptSelf(arr) == ret);

    arr = [2,4];
    ret = [4,2];
    print(sol.productExceptSelf(arr));

    assert(sol.productExceptSelf(arr) == ret);
