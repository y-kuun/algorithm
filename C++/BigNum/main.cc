#include <climits>
#include <iostream>

using namespace std;

// unfinished

class BigNum {
   public:
    BigNum(int);
    BigNum(long long);
    BigNum(string&);
    BigNum(const BigNum&);

    BigNum operator+(const BigNum& lhs);
    BigNum operator=(const BigNum& lhs);
    BigNum operator*(const BigNum& lhs);
    BigNum operator==(const BigNum& lhss);
    BigNum operator<(const BigNum& lhs);

   private:
    bool m_sign_flag;  // flag which is not implemented yet
    string m_data;
};

BigNum::BigNum(string& str_data) {
    this->m_data = str_data;
    this->m_sign_flag = false;
}

BigNum::BigNum(const BigNum& lhs) {
    this->m_data = lhs.m_data;
    this->m_sign_flag = lhs.m_sign_flag;
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
    return BigNum(res);
}

BigNum BigNum::operator*(const BigNum& lhs) {
    int carry = 0;
    int len_rhs = this->m_data.size();
    int len_lhs = lhs.m_data.size();
    int loc = 0;
    int tmp;
    string res;
    for (int i = 0; i < len_lhs; i++) {
        for (int j = 0; j < len_rhs; i++) {
            tmp = (this->m_data[loc] - '0') * (lhs.m_data[loc] - '0') + carry;
            carry = tmp / 10;
            tmp = tmp % 10;
            if (i + j == res.size()) {
                res = res + (char)('0' + tmp);
            } else {
                tmp = tmp + res[i + j] - '0';
                carry += tmp / 10;
                res[i + j] = char(tmp % 10 + '0');
            }
        }
    }
    return BigNum(res);
}

BigNum BigNum::operator=(const BigNum& lhs) {
    this->m_data = lhs.m_data;
    this->m_sign_flag = lhs.m_sign_flag;
}

int main() {
    BigNum bna(0x7FFFFFFF);
    bna = bna + bna;
    return 0;
}