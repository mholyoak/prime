#include <iostream>

bool IsPrime(int num);

bool IsDevisableByPrime(int num)
{
    for (int devisor = 2; devisor < num; devisor++)
    {
        if (IsPrime(devisor) &&
            num % devisor == 0 )
        {
            return true;
        }
    }

    return false;
}

bool IsPrime(int num)
{
    if (num < 1)
    {
        return false;
    }
    else if (num <= 3)
    {
        return true;
    }
    else
    {
        return !IsDevisableByPrime(num);
    }

}

void PrintPrime(int max)
{
    for(int i = 1; i <= max; i++)
    {
        if (IsPrime(i))
        {
            std::cout << std::to_string(i) << std::endl;
        }
    }
}

using std::string;

string addBinary(string a, string b) {

    string sumStr;
    int maxStr = std::max(a.length(), b.length());

    while (a.length() < maxStr)
    {
        a = string("0") + a;
    }

    while (b.length() < maxStr)
    {
        b = string("0") + b;
    }

    int carryVal = 0;
    for (int idx = maxStr - 1; idx >= 0; idx--)
    {
        auto curentBit = '0';
        int aVal = a[idx] - '0';
        int bVal = b[idx] - '0';
        int curVal = aVal + bVal + carryVal;

        carryVal = 0;
        if (curVal % 2 == 1)
        {
            curentBit = '1';
        }
        if (curVal > 1)
        {
            carryVal = 1;
        }

        sumStr = curentBit + sumStr;
    }

    if (carryVal > 0)
    {
        sumStr = '1' + sumStr;
    }

    return sumStr;
}

int main() {
    std::cout << "Hello, VS Code World!" << std::endl;

    //PrintPrime(50);
    std::cout << "addBinary 10: " << addBinary("1", "0") << std::endl;
    std::cout << "addBinary 10: " << addBinary("11", "1") << std::endl;
    std::cout << "addBinary \"10101\": " << addBinary("1010", "1011") << std::endl;

    return 0;
}