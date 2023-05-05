    #include <string>
    #include <vector>
    #include <unordered_map>
    #include <unordered_set>
    #include <sstream>

    using namespace std;

    vector<int> solution(vector<string> id_list, vector<string> report, int k) {
        unordered_map<string, unordered_set<string>> reportedBy;
        unordered_map<string, int> numMail;

        for (const string &s : report) {
            stringstream ss(s);
            string from, to;
            ss >> from >> to;
            if (from == to) continue;
            reportedBy[to].emplace(from);
        }

        for (auto& [to, froms] : reportedBy) {
            if (froms.size() >= k) {
                for (const string &from : froms) {
                    numMail[from]++;
                }
            }
        }

        vector<int> answer(id_list.size());
        for (int i = 0; i < id_list.size(); i++) {
            answer[i] = numMail[id_list[i]];
        }
        return answer;
    }