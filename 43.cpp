#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class interger
{
public:
    int nums[221] = {0};
    int digits = 0;
    int carry = 0;
    bool is_zero = false;

    interger operator*(const interger &) const;

    interger operator*(int) const;

    interger operator+(interger &) const;

    interger &operator=(const interger &);

    void offset(int);

    void str2num(string &);

    string num2str();
};

interger interger::operator*(const interger &b) const
{
    interger res;
    if (this->is_zero || b.is_zero)
    {
        res.digits = 1;
        return res;
    }
    res.digits = max(this->digits, b.digits);
    int i = 1;
    for (; i <= b.digits; ++i)
    {
        auto temp = *this * b.nums[i];
        temp.offset(i - 1);
        res = res + temp;
    }
    return res;
}

interger interger::operator+(interger &b) const
{
    interger res;
    for (int i = 1; i <= max(this->digits, b.digits); ++i)
    {
        auto temp = this->nums[i] + b.nums[i] + res.carry;
        res.nums[i] = temp % 10;
        if (temp > 9)
            res.carry = 1;
        else
            res.carry = 0;
    }
    if (res.carry)
    {
        res.digits = max(this->digits, b.digits) + 1;
        res.nums[res.digits] = 1;
        res.carry = 0;
    }
    else
        res.digits = max(this->digits, b.digits);
    return res;
}

interger interger::operator*(int b) const
{
    interger res;
    for (int i = 1; i <= this->digits; ++i)
    {
        int temp = this->nums[i] * b + res.carry;
        res.carry = temp / 10;
        res.nums[i] = temp % 10;
    }
    if (res.carry)
    {
        res.digits = this->digits + 1;
        res.nums[res.digits] = res.carry;
    }
    else
        res.digits = this->digits;
    return res;
}

interger &interger::operator=(const interger &b)
{
    if (&b == this)
        return *this;
    this->digits = b.digits;
    for (int i = 1; i <= this->digits; ++i)
        this->nums[i] = b.nums[i];
    return *this;
}

void interger::offset(int bias)
{
    if (!bias)
        return;
    for (int i = this->digits; i > 0; --i)
    {
        this->nums[i + bias] = this->nums[i];
        this->nums[i] = 0;
    }
    this->digits += bias;
}

void interger::str2num(string &str)
{
    int len = str.length();
    for (int i = 0; i < len; ++i)
        nums[len - i] = str[i] - '0';
    digits = len;
    if (digits == 1 && nums[1] == 0)
        is_zero = true;
}

string interger::num2str()
{
    string str;
    for (int i = this->digits; i > 0; --i)
    {
        str.push_back(this->nums[i] + '0');
    }
    return str;
}

string multiply(string num1, string num2)
{
    interger a, b;
    a.str2num(num1);
    b.str2num(num2);
    auto ans = a * b;
    return ans.num2str();
}

int main()
{
    cout << multiply("0","456");
    return 0;
}