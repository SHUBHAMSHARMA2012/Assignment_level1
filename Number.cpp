#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class MyNumber
{
public:
    bool isSpyNumber(int n)
    {
        int sum = 0, product = 1;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }
        return sum == product;
    }

    bool isDuckNumber(int n)
    {
        string str = to_string(n);
        if (str[0] == '0')
            return false;
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] == '0')
                return true;
        }
        return false;
    }

    bool isTechNumber(int n)
    {
        string str = to_string(n);
        if (str.length() % 2 != 0)
            return false;

        int halfLength = str.length() / 2;
        int firstHalf = stoi(str.substr(0, halfLength));
        int secondHalf = stoi(str.substr(halfLength));
        int sum = (firstHalf + secondHalf) * (firstHalf + secondHalf);

        return sum == n;
    }

    bool isBuzzNumber(int n)
    {
        return (n % 7 == 0) || (n % 10 == 7);
    }

    bool isDisariumNumber(int n)
    {
        int sum = 0, temp = n;
        int count = to_string(n).length();
        while (temp > 0)
        {
            int digit = temp % 10;
            sum += pow(digit, count--);
            temp /= 10;
        }
        return sum == n;
    }

    long TribonacciNumber(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        long a = 0, b = 1, c = 1, result = 0;
        for (int i = 3; i <= n; i++)
        {
            result = a + b + c;
            a = b;
            b = c;
            c = result;
        }
        return result;
    }

    bool isMagicNumber(int num)
    {
        while (num >= 10)
        {
            int sumOfSquares = 0;
            while (num > 0)
            {
                int digit = num % 10;
                sumOfSquares += digit * digit;
                num /= 10;
            }
            num = sumOfSquares;
        }
        return (num == 1);
    }

    bool isAbundantNumber(int n)
    {
        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
                sum += i;
        }
        return sum > n;
    }

    bool isNeonNumber(int n)
    {
        int square = n * n;
        int sum = 0;
        while (square > 0)
        {
            int digit = square % 10;
            sum += digit;
            square /= 10;
        }
        return n == sum;
    }

    bool isArmstrongNumber(int n)
    {
        int sum = 0, temp = n;
        int count = to_string(n).length();
        while (temp > 0)
        {
            int digit = temp % 10;
            sum += pow(digit, count);
            temp /= 10;
        }
        return sum == n;
    }

    bool isPronicNumber(int n)
    {
        int k = static_cast<int>(sqrt(n));
        return k * (k + 1) == n;
    }

    bool isHarshadNumber(int n)
    {
        int sum = 0, temp = n;
        while (temp > 0)
        {
            int digit = temp % 10;
            sum += digit;
            temp /= 10;
        }
        return n % sum == 0;
    }

    bool HarshadMagicNumber(int n)
    {
        return isHarshadNumber(n) && isMagicNumber(n);
    }

    bool isDudeneyNumber(int n)
    {
        int sum = 0, temp = n;
        while (temp > 0)
        {
            int digit = temp % 10;
            sum += digit;
            temp /= 10;
        }
        int cubeRoot = static_cast<int>(cbrt(n));
        return sum == cubeRoot;
    }

    bool isNivenNumber(int n)
    {
        return isHarshadNumber(n);
    }

    bool isBouncyNumber(int n)
    {
        string str = to_string(n);
        bool hasIncreasing = false, hasDecreasing = false;

        for (int i = 0; i < str.length() - 1; i++)
        {
            if (str[i] < str[i + 1])
                hasIncreasing = true;
            else if (str[i] > str[i + 1])
                hasDecreasing = true;
        }
        return hasIncreasing && hasDecreasing;
    }
};

int main()
{
    MyNumber ob;

    cout << "Is 112 a Spy Number? " << ob.isSpyNumber(112) << endl;
    cout << "Is 203 a Duck Number? " << ob.isDuckNumber(203) << endl;
    cout << "Is 3025 a Tech Number? " << ob.isTechNumber(3025) << endl;
    cout << "Is 49 a Buzz Number? " << ob.isBuzzNumber(49) << endl;
    cout << "Is 175 a Disarium Number? " << ob.isDisariumNumber(175) << endl;
    cout << "Is 1729 a Magic Number? " << ob.isMagicNumber(1729) << endl;
    cout << "Is 18 an Abundant Number? " << ob.isAbundantNumber(18) << endl;
    cout << "Is 9 a Neon Number? " << ob.isNeonNumber(9) << endl;
    cout << "Is 153 an Armstrong Number? " << ob.isArmstrongNumber(153) << endl;
    cout << "Is 20 a Pronic Number? " << ob.isPronicNumber(20) << endl;
    cout << "Is 1729 a Harshad Number? " << ob.isHarshadNumber(1729) << endl;
    cout << "Is 1729 a Harshad-Magic Number? " << ob.HarshadMagicNumber(1729) << endl;
    cout << "Is 512 a Dudeney Number? " << ob.isDudeneyNumber(512) << endl;
    cout << "Is 24 a Niven Number? " << ob.isNivenNumber(24) << endl;
    cout << "Is 253 a Bouncy Number? " << ob.isBouncyNumber(253) << endl;

    return 0;
}
