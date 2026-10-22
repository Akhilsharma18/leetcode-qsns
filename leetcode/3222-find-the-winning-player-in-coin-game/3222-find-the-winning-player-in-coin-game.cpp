class Solution {
public:
    string winningPlayer(int x, int y) {
        int turns = min(x, y / 4);
        return (turns % 2) ? "Alice" : "Bob";
    }
};
