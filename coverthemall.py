class Fenwick:
  def __init__(self, n):
    self.tree = [0]*(n+1)
    self.n = n
  def update_point(self, i, val):  # O(log n)
    i += 1
    while i <= self.n:
      self.tree[i] += val
      i += i & -i
  def read_prefix(self, i):        # O(log n)
    i += 1
    sum = 0
    while i > 0:
      sum += self.tree[i]
      i -= i & -i
    return sum

def solve(a):
  rank = { v[0] : i for i, v in enumerate(sorted(a,key=lambda x:x[0])) }
  res = []
  counts, sums = Fenwick(len(a)), Fenwick(len(a))
  total_sum = 0
  for i, x in enumerate(a):
    r = rank[x[0]]
    num_smaller = counts.read_prefix(r)
    sum_smaller = sums.read_prefix(r)
    res.append((total_sum - 2*sum_smaller + x[0] * (2*num_smaller - i))*x[1])
    counts.update_point(r, 1)
    sums.update_point(r, x[0])
    total_sum += x[0]
  return res

t = int(input())
k=0
while k < t:
	n = int(input())
	array = [i for i in map(int,input().split(' '))]
	weight = [i for i in map(int,input().split(' '))]
	arr = [i for i in zip(array,weight)]
	arr = sorted(arr, key=lambda x: x[1])
	res=sum(solve(arr))
	print(res%(1000000007))
	k+=1

