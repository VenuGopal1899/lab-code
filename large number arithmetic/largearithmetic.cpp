
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Arithmetic {

    private:
        string output;

    public:
        string add(string input1, string input2) {
            //no adds 0 to smaller string to make their length equal
            int no = 0, no1, no2;
            //string length
            int len1 = input1.length()-2;
            int len2 = input2.length()-1;
            no = len1-len2;

            //string to held the "000.." part to be appended
            string temp;

            if(no>=0) {
                while(no) {
                    temp = temp+'0';
                    no--;
                }
                input2 = temp+input2;
            }
            else {
                no = no*-1;
                while(no) {
                    temp = temp+'0';
                    no--;
                }
                input1 = temp+input1;
                len1 = len2;
            }
            no = 0;
            cout<<output<<endl;
            while(len1>=0) {
                no1 = input1[len1] - '0';
                no2 = input2[len1] - '0';

                if(input1[0] == '-') {
                    no1 = no1*-1;
                }
                //cout<<no1<<endl;
                if(input2[0] == '-') {
                    no2 = no2*-1;
                }
                
                no = no1+no2+no;
                no1 = no%10;
                no = no/10;
                
                //appending the 1's part of the added number to the resultant string
                output = to_string(no1)+output;
                len1--;
            }

            return output;
        };

        string sub(string input1, string input2) {
            //no adds 0 to smaller string to make their length equal
            int no = 0, no1, no2;
            //string length
            int len1 = input1.length()-1;
            int len2 = input2.length()-1;
            no = len1-len2;

            if(input2[0] != '-') {
                input2 = "-" + input2;
            }

            //string to held the "000.." part to be appended
            string temp;

            if(no>=0) {
                while(no) {
                    temp = temp+'0';
                    no--;
                }
                input2 = temp+input2;
            }
            else {
                no = no*-1;
                while(no) {
                    temp = temp+'0';
                    no--;
                }
                input1 = temp+input1;
                len1 = len2;
            }
            no = 0;

            while(len1>=0) {
                no1 = input1[len1] - '0';
                no2 = input2[len1] - '0';

                if(input1[0] == '-') {
                    no1 = no1*-1;
                }
                cout<<no1<<endl;
                if(input2[0] == '-') {
                    no2 = no2*-1;
                }
                
                no = no1+no2+no;
                no1 = no%10;
                no = no/10;
                
                //appending the 1's part of the added number to the resultant string
                output = to_string(no1)+output;
                len1--;
            }

            return output;
        };

        string multiply(string input1, string input2) {
            output="0";
            string temp="",temp2 = "";
            int no = 0, no1, no2;

            int len1 = input1.length()-2;
            int len2 = input2.length()-1;

            while(len2>=0) {
                no1 = input1[len1] - '0';
                while(len1>=1) {
                    no2 = input2[len2] - '0';
                    no = (no1*no2)+no;
                    no1 = no%10;
                    no = no/10;
                    temp = to_string(no1)+temp;
                    len1--;
                }
                output = add(output, temp);
                temp2 = temp2+"0";
                temp = temp+temp2; 
                len2--;
            }

            return output;
        };
}; 

int main() {
    string line1, line2;
    int choice;
    ifstream inputfile("./inputfile.txt");
    Arithmetic calc;
    getline(inputfile, line1);
    getline(inputfile, line2);
    
    cout<<"1.add, 2.subtract. 3.multiply"<<endl;
    cin>>choice;

    switch(choice) {
        case 1: cout<<calc.add(line1, line2)<<endl;
                break;
        case 2: cout<<calc.sub(line1, line2)<<endl;
                break;
        case 3: cout<<calc.multiply(line1, line2)<<endl;
                break;
    }

    return 0;
}