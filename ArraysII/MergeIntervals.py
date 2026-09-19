class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        if not intervals :
            return []

        intervals.sort(key = lambda x : x[0])

        ans = []

        curr = intervals[0]

        for nextInterval in intervals[1:] :

            if curr[1] >= nextInterval[0]:
                curr[1] = max(curr[1], nextInterval[1])

            else :
                ans.append(curr)
                curr = nextInterval

        ans.append(curr)

        return ans
