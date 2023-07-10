// Link : https://leetcode.com/problems/add-binary/


// Code :
class Solution {
public:
    char ccarry(char x,char y,char z)
    {
        if((x=='0' && y!='0' && z!='0') || (x!='0' && y=='0' && z!='0') || (x!='0' && y!='0' && z=='0') || (x!='0' && y!='0' && z!='0'))
        return '1';
        else
        return '0';
    }

    char sum(char x,char y,char z)
    {
        if((x=='0' && y=='1' && z=='1') || (x=='1' && y=='0' && z=='1') || (x=='1' && y=='1' && z=='0') || (x=='0' && y=='0' && z=='0'))
        return '0';
        else 
        return '1';
    }

    string addBinary(string a, string b) {
        char carry='0';
        int i=a.length()-1;
        int j=b.length()-1;
        char c1,c2;
        string ans="";
        while(i>=0 && j>=0)
        {
            c1=a[i];
            c2=b[j];

            // adding both binaries
            // cout << "sum is " << sum(c1,c2,carry) << " carry is " << ccarry(c1,c2,carry) << endl;
            ans = sum(c1,c2,carry) + ans;
            carry = ccarry(c1,c2,carry);

            i--;
            j--;
        }

        while(i>=0)
        {
            // cout << "I am here\n"<< carry << endl;
            c1=a[i];
            ans = sum(c1,'0',carry) + ans;
            carry = ccarry(c1,'0',carry);

            i--;
        }

        while(j>=0)
        {
            c2=b[j];
            // cout << c2 << endl;
            // cout << "sum is (0,"<<c2<<","<<carry<<")"  << sum('0',c2,carry) << " carry is " << ccarry('0',c2,carry) << endl;
            ans = sum('0',c2,carry) + ans;
            carry = ccarry('0',c2,carry);

            j--;
        }

        if(carry=='1')
        ans = '1'+ans;

        return ans;
    }
};
