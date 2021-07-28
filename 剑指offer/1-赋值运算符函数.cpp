#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
// #include <unordered_map>  // can't compile on poj
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

class CMyString
{
public:
    CMyString(char *pData = nullptr)
    {
        m_pData = pData;
    };

    CMyString(const CMyString &str)
    {
        m_pData = str.m_pData;
    };

    ~CMyString()
    {
        delete[] m_pData;
        m_pData = nullptr;
    };
    // Solution 1
    CMyString &operator=(const CMyString &str)
    {
        if (this != &str)
        {
            delete[] m_pData;
            m_pData = nullptr;

            m_pData = new char[strlen(str.m_pData) + 1];
            strcpy(m_pData, str.m_pData);
        }
        return *this;
    }

private:
    char *m_pData;
};

// // Solution 2
// CMyString &CMyString::operator=(const CMyString &str)
// {
//     if (this != &str)
//     {
//         CMyString strTemp(str);
//         char *pTemp = strTemp.m_pData;
//         strTemp.m_pData = m_pData;
//         m_pData = pTemp;
//     }
//     return *this;
// }

void _test()
{
    CMyString str1((char *)"heyyy!!");
    CMyString str2(str1);
    CMyString str3 = str1;
}

int main()
{
    _test();
    return 0;
}
