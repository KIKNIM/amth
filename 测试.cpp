#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


// 函数用于处理数组
void processArray(vector<vector<int>>& arr, int rows, int cols) {
    // 依次检查每一列
    for (int col = 0; col < cols; ++col) {
        bool hasOne = false;  // 是否该列含有1
        int firstRowValue = arr[col][col];  // 第一行对应元素的值
        for (int i = 0; i < rows; ++i) {
            if (arr[i][col] == 1) {
                hasOne = true;
                // 对第一行和包含1的行进行处理
                for (int j = 0; j < cols; ++j) {
                    // 如果第一行和当前行的元素中有一个为1，就将当前行对应位置改为1
                    if (arr[col][j] == 1 || arr[i][j] == 1) {
                        arr[i][j] = 1;
                    }
                }
            }
        }
    }
    cout << "答案是：";
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            int Value = arr[row][col];  // 第一行对应元素的值
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

    cout << "选择数组初始化方式:\n";
    cout << "1. 直接输入处理后的只有1或0\n";
    cout << "2. 输入数组的元素的行列号 (一次性输入，两位数，用空格隔开)\n";
    cout << "选择: ";
    cin >> initializationChoice;

    cout << "输入行数: ";
    cin >> rows;

    cout << "输入列数: ";
    cin >> cols;

    vector<vector<int>> arr(rows, vector<int>(cols, 0));  // Initialize with zeros

    // 根据用户选择初始化数组
    if (initializationChoice == 1) {
        cout << "逐行输入数组的元素 (直接输入处理后的只有1或0):\n";
        for (int i = 0; i < rows; ++i) {
            cout << "第 " << i + 1 << " 行: ";

            for (int j = 0; j < cols; ++j) {
                cin >> arr[i][j];
            }
        }
    }
    else if (initializationChoice == 2) {
        cout << "输入数组的元素的行列号 (一次性输入，两位数，用空格隔开，输入-1结束输入):\n";
        string input;
        cout << "输入行列号 (例如，11 12 23 45 表示第1行1列、1行2列、2行3列、4行5列): ";
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
        cout << "无效选择。程序退出。\n";
        return 0;
    }

    // 打印二维数组
    cout << "关系矩阵是:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // 处理数组
    
    processArray(arr, rows, cols);
    
    // 打印处理后的数组（一行输出）
    cout << "\n" << "传递闭包的结果是:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j]<<" ";
        }
        cout << "\n";
    }
    return 0;
}
