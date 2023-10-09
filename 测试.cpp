#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


// �������ڴ�������
void processArray(vector<vector<int>>& arr, int rows, int cols) {
    // ���μ��ÿһ��
    for (int col = 0; col < cols; ++col) {
        bool hasOne = false;  // �Ƿ���к���1
        int firstRowValue = arr[col][col];  // ��һ�ж�ӦԪ�ص�ֵ
        for (int i = 0; i < rows; ++i) {
            if (arr[i][col] == 1) {
                hasOne = true;
                // �Ե�һ�кͰ���1���н��д���
                for (int j = 0; j < cols; ++j) {
                    // �����һ�к͵�ǰ�е�Ԫ������һ��Ϊ1���ͽ���ǰ�ж�Ӧλ�ø�Ϊ1
                    if (arr[col][j] == 1 || arr[i][j] == 1) {
                        arr[i][j] = 1;
                    }
                }
            }
        }
    }
    cout << "���ǣ�";
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            int Value = arr[row][col];  // ��һ�ж�ӦԪ�ص�ֵ
            if (Value == 1)
            {
                cout << "{" << row + 1 << "," << col + 1 << "} " ;
            }
        }
    }
}

int main() {
    int rows, cols;
    int initializationChoice;

    cout << "ѡ�������ʼ����ʽ:\n";
    cout << "1. ֱ�����봦����ֻ��1��0\n";
    cout << "2. ���������Ԫ�ص����к� (һ�������룬��λ�����ÿո����)\n";
    cout << "ѡ��: ";
    cin >> initializationChoice;

    cout << "��������: ";
    cin >> rows;

    cout << "��������: ";
    cin >> cols;

    vector<vector<int>> arr(rows, vector<int>(cols, 0));  // Initialize with zeros

    // �����û�ѡ���ʼ������
    if (initializationChoice == 1) {
        cout << "�������������Ԫ�� (ֱ�����봦����ֻ��1��0):\n";
        for (int i = 0; i < rows; ++i) {
            cout << "�� " << i + 1 << " ��: ";

            for (int j = 0; j < cols; ++j) {
                cin >> arr[i][j];
            }
        }
    }
    else if (initializationChoice == 2) {
        cout << "���������Ԫ�ص����к� (һ�������룬��λ�����ÿո����������-1��������):\n";
        string input;
        cout << "�������к� (���磬11 12 23 45 ��ʾ��1��1�С�1��2�С�2��3�С�4��5��): ";
        cin.ignore();  // Ignore newline after choosing option
        getline(cin, input);

        istringstream iss(input);
        int number;

        while (iss >> number) {
            if (number == -1)
                break;

            int row = (number / 10) - 1;  // Extract row (subtract 1 to convert to 0-based indexing)
            int col = (number % 10) - 1;  // Extract column (subtract 1 to convert to 0-based indexing)

            // Ensure the input is within valid range
            if (row >= 0 && row < rows && col >= 0 && col < cols)
                arr[row][col] = 1;
            else
                cout << "Invalid input for row " << row + 1 << " and column " << col + 1 << ". Skipping.\n";
        }
    }
    else {
        cout << "��Чѡ�񡣳����˳���\n";
        return 0;
    }

    // ��ӡ��ά����
    cout << "��ϵ������:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // ��������
    
    processArray(arr, rows, cols);
    
    // ��ӡ���������飨һ�������
    cout << "\n" << "���ݱհ��Ľ����:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j]<<" ";
        }
        cout << "\n";
    }
    return 0;
}
