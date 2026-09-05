class Solution {
public:
    void getxy(string &num1, int &x1, int &y1){
        string a1, b1;  a1 = b1 = "";
        int i = 0; 
        for(; i < num1.size(); i++){
            if(num1[i] == '+')break;
            a1 += num1[i];
        }
        i++;
        for(; i < num1.size(); i++){
            b1 += num1[i];
        }
        x1 = stoi(a1); 
        y1 = stoi(b1);
    }
    string complexNumberMultiply(string num1, string num2) {
        int x1, y1, x2, y2;
        getxy(num1, x1, y1); getxy(num2, x2, y2);
        return to_string(x1 * x2 + y1 * y2 * -1) + "+" + to_string(x1 * y2 + x2 * y1) + "i";
    }
};