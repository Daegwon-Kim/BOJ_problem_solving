import sys

# 전처리 부분
input = sys.stdin.readline
INF = sys.maxsize

# 알고리즘 부분
def floyd():
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            for k in range(1, n + 1):
                if dist[j][k] > dist[j][i] + dist[i][k]:
                    dist[j][k] = dist[j][i] + dist[i][k]

# 변수 선언 및 초기화 부분
n = int(input())
m = int(input())
dist = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    dist[i][i] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    dist[a][b] = min(dist[a][b], c)

# 메인 코드 부분
floyd()

for i in range(1, n + 1):
    for j in range(1, n + 1):
        print(0 if dist[i][j] == INF else dist[i][j], end = " ")
    print()