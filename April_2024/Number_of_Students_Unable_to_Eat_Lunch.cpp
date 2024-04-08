class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int i = 0;
        int count = 0;
        while (students.size())
        {
            if (students[0] == sandwiches[i])
            {
                count = 0;
                i++;
                students.erase(students.begin());
            }
            else
            {
                count++;
                students.push_back(students[0]);
                students.erase(students.begin());
            }
            if (count == students.size())
                break;
        }
        return count;
    }
};