class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = static_cast<int>(seq.size());
        vector<int> level(n);
        int depth = 0;
        int maxDepth = 0;
  for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                ++depth;
                level[i] = depth;
                maxDepth = max(maxDepth, depth);
            } else {
                level[i] = depth;
                --depth;
            }
        }
 int bestCutoff = 0;
        int bestScore = n + 1;
        for (int k = 0; k <= maxDepth; ++k) {
            int score = max(k, maxDepth - k);
            if (score < bestScore) {
                bestScore = score;
                bestCutoff = k;
            }
        }
 vector<int> answer(n);
        for (int i = 0; i < n; ++i) {
            answer[i] = (level[i] <= bestCutoff) ? 0 : 1;
        }
        return answer;
    }
};