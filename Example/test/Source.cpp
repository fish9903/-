    #include <string>
    #include <vector>
    #include <iostream>

    using namespace std;

    int start_x = 0, start_y = 0;


    int move_x[4] = { 0, 1, 0, -1 };
    int move_y[4] = { 1, 0, -1, 0 };
    // R, D, L, U

    int ShootLight(vector<vector<char>>& board, vector<int>& visit) {
        int head_direction = 0;
        int first_head_direction;
        int now_x = 0, now_y = 0;
        int next_x = 0, next_y = 0;
        int target = -1;
        for (int i = 0; i < 4; i++) {
            if (visit[i] == 0) {
                target = i;
                break;
            }
        }
        if (target == -1) return 0;
        visit[target] = 1;

        head_direction = target;
        //first_head_direction = target;
        int flag = 1;
        int cycle = 0;
        vector<pair<int, int>> first;

        while (1) {
            cout << next_x << " " << next_y << endl;
            if (board[next_x][next_y] == 'R') {
                head_direction = (head_direction + 1) % 4;
            }
            else if (board[next_x][next_y] == 'L') {
                if (head_direction == 0) head_direction = 3;
                else head_direction -= 1;
            }

            now_x = next_x;
            now_y = next_y;
            next_x += move_x[head_direction];
            next_y += move_y[head_direction];
            if (next_x == -1) next_x = board.size() - 1;
            else if (next_x == board.size()) next_x = 0;
            else if (next_y == -1) next_y = board[0].size() - 1;
            else if (next_y == board[0].size()) next_y = 0;

            if (flag) { // first time
                first.push_back({ now_x, now_y });
                first.push_back({ next_x, next_y });
                first_head_direction = head_direction;
                flag = 0;
            }
            else {
                if (first[0] == make_pair(now_x, now_y) && first[1] == make_pair(next_x, next_y) && first_head_direction == head_direction) {
                    for (int i = 0; i < 2; i++) {
                        cout << first[i].first << ", " << first[i].second << endl;
                    }
                    break;
                }
            }
            if (first[0] == make_pair(next_x, next_y) || first[0] == make_pair(now_x, now_y)) {
                visit[head_direction] = 1;
            }
            cycle++;
        }

        cout << "Out: " << cycle << endl;
        return cycle;
    }

    vector<int> solution(vector<string> grid) {
        vector<int> answer;

        vector<vector<char>> board(grid.size(), vector<char>(grid[0].size()));
        vector<int> visit(4, 0); // R, D, L, U

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                board[i][j] = grid[i][j];
            }
        }

        for (int i = 0; i < 4; i++) { // 4 direction
            int num = ShootLight(board, visit);
            if (num) answer.push_back(num);
        }

        return answer;
    }

    int main() {
        vector<string> grid = {
            "SL", "LR"
        };

        vector<int> a = solution(grid);
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << endl;
        }

        return 0;
    }