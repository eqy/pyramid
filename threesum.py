class Solution:
    def threeSum(self, nums):
        res = set()
        z_list = set(nums)
        count_list = dict()
        if len(nums) < 3:
            return []
        for num in nums:
            if num in count_list:
                count_list[num] += 1 
            else:
                count_list[num] = 1

        for z in z_list:
            for key in count_list.keys():
                if z == key and count_list[key] == 1:
                    continue
                new_key = -(z + key)
                if new_key not in count_list or (z == new_key and count_list[new_key] == 1):
                    continue
                if new_key == key and count_list[new_key] == 1:
                    continue
                if new_key == key and new_key == z and count_list[new_key] < 3:
                    continue
                res.add(tuple(sorted((z, key, new_key)))) 
        return [list(item) for item in res]

    def threeSum2(self, nums):
        res = set()
        nums = sorted(nums)
        precomp = dict()
        if len(nums) < 3:
            return res
        maximum = nums[-1]
        minimum = nums[0]
        for i in range(0, len(nums) - 1):
            a = nums[i]
            for j in range(i+1, len(nums)):
                b = nums[j]
                if (a + b + maximum < 0):
                    continue
                if (a + b + minimum > 0):
                    break;
                key = -(a + b)
                if key in precomp:
                    precomp[key].append((a, b, j))
                else:
                    precomp[key] = [(a, b, j)]

        for k in range(0, len(nums)):
            key = nums[k]
            if k < (len(nums) - 1) and nums[k+1] == key:
                continue
            if key in precomp:
                entries = precomp[key]
                for entry in entries:
                    if k > entry[-1]:
                        res.add((entry[0], entry[1], key))
                    else:
                        break
        
        res = [list(item) for item in res]
        return res

def main():
    print(Solution().threeSum([-1, 0, 1, 0]))

if __name__ == '__main__':
    main() 
