#include "string.h"
namespace HomeMadeString
{
String::String()
{
    pData = NULL;
    elementNum = 0;
}

String::String(const char* str)
{
    int len = 0;

    while (str[len] != '\0' || str[len] != NULL)
        len++;

    elementNum = len;
    char* temp = new char[len];
    for (int i = 0; i < len; i++)
        temp[i] = str[i];
    pData = temp;
}

String::String(const String& other)
{
    elementNum = other.elementNum;
    char* temp = new char[other.elementNum];
    for(int i = 0; i < other.elementNum; i++)
        temp[i] = other.pData[i];
    pData = temp;
}

String::String(const char c, const unsigned times)
{
    elementNum = times;
    char* temp = new char[times];
    for (int i = 0; i < times; i++)
        temp[i] = c;
    pData = temp;
}

String::~String()
{
    delete[] pData;
}

String String::concatenate(const String& str1, const String& str2)
{
    String ans;
    ans.elementNum = str1.elementNum + str2.elementNum;
    ans.pData = new char[ans.elementNum];   //lehet nem jo

    for(int i = 0; i < str1.elementNum; i++)
        ans.pData[i] = str1.pData[i];

    for(int i = str1.elementNum; i < ans.elementNum; i++)
        ans.pData[i] = str2.pData[i - str1.elementNum];

    return ans;
}

bool String::compare(const String& str1, const String& str2)
{
    if (str1.elementNum != str2.elementNum)
        return false;

    for(int i = 0; i < str1.elementNum; i++)
        if (str1.pData[i] != str2.pData[i])
            return false;
    return true;
}

void String::copy(String& str1, const String& str2)
{
    str1.elementNum = str2.elementNum;
    char *temp = new char[str2.elementNum];
    for (int i = 0; i < str2.elementNum; i++)
        temp[i] = str2.pData[i];
    str1.pData = temp;
}

char* String::getCString() const
{
    if (elementNum == 0 || pData == NULL)
        return NULL;

    char* temp = new char[elementNum + 1];
    for (int i = 0; i < elementNum; i++)
        temp[i] = pData[i];

    temp[elementNum] = '\0';
    return temp;
}

void String::print(std::ostream& os)
{
    if (elementNum == 0) {
        os << "ures";
        return;
    }

    for (unsigned i = 0; i < elementNum; ++i)
        os << pData[i];
}
}
