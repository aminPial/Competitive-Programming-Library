from collections import deque
class Solution:
    def floodFill(self, image, sr, sc, newColor):
        if image[sr][sc] == newColor:
            return image
        point = image[sr][sc]
        row, col = len(image), len(image[0])
        queue = deque([(sr, sc)])  # (x,y)

        while queue:
            x, y = queue.popleft()
            image[x][y] = newColor # re draw or flood fill
            points = [(x+1, y), (x, y+1), (x-1, y), (x, y-1)]
            for r, c in points:
                if 0 <= r < row and 0 <= c < col and image[r][c] == point:
                    queue.append((r, c))
        return image


test = Solution()
print(test.floodFill([[1,1,1],[1,1,0],[1,0,1]],
sr = 1, sc = 1, newColor = 2))
print(test.floodFill([[0, 0, 0], [0, 1, 1]],
sr = 1, sc = 1, newColor = 1))
