#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int A_i = A.size() - 1;
    int B_i = B.size() - 1;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    while (A_i >= 0)
    {
        if (A[A_i] < B[B_i])
        {
            ++answer;
            --B_i;
        }
        --A_i;
    }
    return answer;
}