#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// t0 ~ t4의 chip sequence를 vector에 저장
// 0 --> -1 로 변환하여 저장
vector<vector<int>> transmitter(4, vector<int>(8));

// 전달할 bit sequence
// ex) 1011
vector<int> bit_sequence(4);

// 전달할 최종 sequence
vector<int> final_sequence(8, 0);

void SumChipSequence(vector<int> a, char op){
    if(op == '+'){
        for(int i=0;i<8;i++){
            final_sequence[i] += a[i];
        }
    }
    else{
        for(int i=0;i<8;i++){
            final_sequence[i] -= a[i];
        }
    }
}

int InnerProduct(vector<int> a, vector<int> b){
    int result = 0;
    for(int i=0;i<8;i++){
        result += a[i] * b[i];
    }

    return result / 8;
}

int main(){
    // Init chip sequence
    for(int i=0;i<4;i++){
        string s;
        cout << "Enter the transmitter's chip sequence length 8 (t" << i << "): ";
        cin >> s;

        // Input 확인
        if(s.length() != 8){
            cout << "Enter the chip sequence length 8" << endl;
            return -1;
        }
        else{
            for(int j=0;j<8;j++){
                if(s[j] != '0') transmitter[i][j] = s[j] - '0';
                else transmitter[i][j] = -1;
            }
        }
    }
    
    // Init bit sequence
    string s;
    cout << "Enter Bit Sequence length 4: ";
    cin >> s;

    if(s.length() != 4){
        cout << "Enter the bit sequence length 4: ";
        return -1;
    }
    else{
        for(int i=0;i<4;i++){
            bit_sequence[i] = s[i] - '0';
        }
    }
    
    // 최종 전달할 bit sequence 계산
    for(int i=0;i<4;i++){
        if(bit_sequence[i] == 1){
            SumChipSequence(transmitter[i], '+');
        }
        else if(bit_sequence[i] == 0){
            SumChipSequence(transmitter[i], '-');
        }
    }
    cout << "(Join)Final Bit Sequence: ";
    for(int i=0;i<8;i++){
        cout << final_sequence[i] << ", ";
    }
    cout << endl;

    // Recive bit 계산
    for(int i=0;i<4;i++){
        int receive = InnerProduct(final_sequence, transmitter[i]);
        cout << "Receiver (r" << i <<"): " << receive << endl;
    }

    return 0;
}