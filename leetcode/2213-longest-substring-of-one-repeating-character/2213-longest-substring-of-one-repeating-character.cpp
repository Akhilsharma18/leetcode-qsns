class Solution {
public:
 struct Node {
        int len;
        int left;
        int right;
        int best;
        char lc, rc;
      Node() {
            len = left = right = best = 0;
            lc = rc = '#';
        }
    };
  vector<Node> seg;
    string s;
    Node merge(Node a, Node b) {
     if (a.len == 0) return b;
        if (b.len == 0) return a;
  Node res;
      res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;
    res.left = a.left;
        res.right = b.right;
     res.best = max(a.best, b.best);
     if (a.rc == b.lc) {
      res.best = max(res.best, a.right + b.left);
        if (a.left == a.len)
                res.left = a.len + b.left;
          if (b.right == b.len)
                res.right = b.len + a.right;
        }
  return res;
    }
 void build(int idx, int l, int r) {
  if (l == r) {
            seg[idx].len = 1;
            seg[idx].left = 1;
            seg[idx].right = 1;
            seg[idx].best = 1;
            seg[idx].lc = s[l];
            seg[idx].rc = s[l];
            return;
        }
  int mid = (l + r) / 2;
 build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }
 void update(int idx, int l, int r, int pos, char ch) {
 if (l == r) {
            seg[idx].lc = ch;
            seg[idx].rc = ch;
            seg[idx].len = 1;
            seg[idx].left = 1;
            seg[idx].right = 1;
            seg[idx].best = 1;
            return;
        }
 int mid = (l + r) / 2;
 if (pos <= mid)
            update(idx * 2, l, mid, pos, ch);
        else
            update(idx * 2 + 1, mid + 1, r, pos, ch);
 seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }
  vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;
 int n = s.size();
 seg.resize(4 * n);
  build(1, 0, n - 1);

        vector<int> ans;
for (int i = 0; i < queryIndices.size(); i++) {
  int pos = queryIndices[i];
            char ch = queryCharacters[i];
 update(1, 0, n - 1, pos, ch);
 ans.push_back(seg[1].best);
        }
   return ans;
    }
};