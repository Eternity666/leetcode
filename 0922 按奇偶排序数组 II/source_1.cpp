class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for(int i = 0; i < A.size(); i++)
        {
            if(i % 2 == 0 && A[i] % 2 != 0)
            {
                for(int j = i + 1; j < A.size(); j++)
                {
                    if(j % 2 != 0 && A[j] % 2 == 0)
                    {
                        swap(A[i], A[j]);
                        break;
                    }
                }
            }
            else if (i % 2 != 0 && A[i] % 2 == 0)
            {
                for(int j = i + 1; j < A.size(); j++)
                {
                    if(j % 2 == 0 && A[j] % 2 != 0)
                    {
                        swap(A[i], A[j]);
                        break;
                    }
                }
            }
        }
        return A;
    }
};
