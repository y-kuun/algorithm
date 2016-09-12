#include <climits>
#include <iostream>

using namespace std;

// unfinished

class BigNum {
   public:
    explicit BigNum(int);
    explicit BigNum(long long);
    explicit BigNum(const string&);
    explicit BigNum(const BigNum&);

    BigNum operator+(const BigNum& lhs);
    BigNum operator=(const BigNum& lhs);
    BigNum operator==(const BigNum& lhss);
    BigNum operator<(const BigNum& lhs);

   private:
    bool m_sign_flag;  // flag which is not implemented yet
    string m_data;
};

BigNum::BigNum(const string& str_data) {
    this->m_data = str_data;
    this->m_sign_flag = false;
}

BigNum::BigNum(int num) {
    bool isExceeded = false;
    if (num < 0 && num != INT_MIN) {
        this->m_sign_flag = true;
        num = 0 - num;
    } else if (num == INT_MIN) {
        isExceeded = true;
    } else if (num >= 0) {
        this->m_sign_flag = false;
    }
    m_data = "";
    while (num) {
        m_data = m_data + (char)('0' + num % 10);
        num = num / 10;
    }
    if (isExceeded) {
        // since
        m_data[0] = m_data[0];
    }
}

BigNum::BigNum(long long num) {
    bool isExceeded = false;
    if (num < 0 && num != LLONG_MIN) {
        this->m_sign_flag = true;
        num = 0 - num;
    } else if (num == LLONG_MIN) {
        isExceeded = true;
    } else if (num >= 0) {
        this->m_sign_flag = false;
    }
    m_data = "";
    while (num) {
        m_data = m_data + (char)('0' + num % 10);
        num = num / 10;
    }
    if (isExceeded) {
        // since
        m_data[0] = m_data[0];
    }
}

BigNum BigNum::operator+(const BigNum& lhs) {
    int carry = 0;
    int len_rhs = this->m_data.size();
    int len_lhs = lhs.m_data.size();
    int loc = 0;
    string res;
    while (loc < len_rhs && loc < len_lhs) {
        int tmp = this->m_data[loc] - '0' + lhs.m_data[loc] - '0' + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res = res + (char)('0' + tmp);
        loc++;
    }
    while (loc < len_rhs) {
        int tmp = this->m_data[loc] - '0' + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res = res + (char)('0' + tmp);
        loc++;
    }
    while (loc < len_lhs) {
        int tmp = lhs.m_data[loc] - '0' + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res = res + (char)('0' + tmp);
        loc++;
    }
    loc = res.size() - 1;
    while (carry) {
        int tmp = res[loc] - '0' + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res = res + (char)('0' + tmp);
        loc++;
    }
    return BigNumres;
}