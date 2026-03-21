class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        t = "".join(sorted(s))
        if s == t: return 0
        if n < 2: return -1
        if n <= 6:
            q, v = [(s, 0)], {s}
            while q:
                c, d = q.pop(0)
                for i in range(n):
                    for j in range(i + 1, n + 1):
                        if i == 0 and j == n: continue
                        x = c[:i] + "".join(sorted(c[i:j])) + c[j:]
                        if x == t: return d + 1
                        if x not in v:
                            v.add(x)
                            q.append((x, d + 1))
            return -1
        if s[0] == t[0] or s[-1] == t[-1]: return 1
        l, r = 0, n - 1
        while l < n and s[l] == t[l]: l += 1
        while r >= 0 and s[r] == t[r]: r -= 1
        if r - l + 1 < n: return 1
        if s[0] == t[-1] and s[-1] == t[0]:
            h = False
            for i in range(1, n - 1):
                if s[i] == t[0] or s[i] == t[-1]:
                    h = True
                    break
            return 2 if h else 3
        return 2