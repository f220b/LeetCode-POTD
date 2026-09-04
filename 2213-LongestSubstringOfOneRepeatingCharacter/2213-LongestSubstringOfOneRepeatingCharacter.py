# Last updated: 9/5/2026, 12:22:15 AM
class Node:
    def __init__(self, lch, rch, pre, suf, b, l):
        self.left_ch = lch
        self.right_ch = rch
        self.prefix = pre
        self.suffix = suf
        self.best = b
        self.length = l


class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [None] * (4 * self.n)
        self.build(1, 0, self.n - 1, arr)

    def build(self, node, l, r, arr):
        if l == r:
            self.tree[node] = Node(arr[l], arr[l], 1, 1, 1, 1)
            return
        mid = (l + r) // 2
        self.build(2 * node, l, mid, arr)
        self.build(2 * node + 1, mid + 1, r, arr)
        self.tree[node] = self.merge(self.tree[2 * node], self.tree[2 * node + 1])

    def merge(self, l, r):
        parent = Node(l.left_ch, r.right_ch, 1, 1, 1, 1)
        if l.right_ch == r.left_ch:
            parent.length = l.length + r.length
            cross = l.suffix + r.prefix
            parent.best = max(cross, l.best, r.best)
            if r.suffix == r.length:
                parent.suffix = r.suffix + l.suffix
            else:
                parent.suffix = r.suffix
            if l.prefix == l.length:
                parent.prefix = l.prefix + r.prefix
            else:
                parent.prefix = l.prefix
        else:
            parent.length = l.length + r.length
            parent.prefix = l.prefix
            parent.suffix = r.suffix
            parent.best = max(l.best, r.best)
        return parent

    def update(self, node, l, r, idx, val):
        if l == r:
            self.tree[node] = Node(val, val, 1, 1, 1, 1)
            return
        mid = (l + r) // 2
        if idx <= mid:
            self.update(2 * node, l, mid, idx, val)
        else:
            self.update(2 * node + 1, mid + 1, r, idx, val)
        self.tree[node] = self.merge(self.tree[2 * node], self.tree[2 * node + 1])

    """
    def query(self,node,l,r,ql,qr):
        if ql<=l and r<=qr:
            return self.tree[node]
        mid =(l+r)//2
        if qr<=mid:
            return self.query(2*node,l,mid,ql,qr)
        if ql>mid:
            return self.query(2*node+1,mid+1,r,ql,qr)
        left = self.query(2*node,l,mid,ql,qr)
        right = self.query(2*node+1,mid+1,r,ql,qr)
        return self.merge(left,right)
    """


class Solution:
    def longestRepeating(
        self, s: str, queryCharacters: str, queryIndices: List[int]
    ) -> List[int]:
        ans = []
        st = SegmentTree(s)
        for i in range(len(queryIndices)):
            st.update(1, 0, len(s) - 1, queryIndices[i], queryCharacters[i])
            ans.append(st.tree[1].best)
        return ans
