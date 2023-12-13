#include <ctime>
#include <iostream>
using namespace std;
/*
矩阵螺旋打印问题
如，有如下矩阵，
[ 1, 2, 3, 4, 5, 6]
[ 7, 8, 9,10,11,12]
[13,14,15,16,17,18]
[19,20,21,22,23,24]

顺时针螺旋打印：1,2,3,4,5,6,12,18,24,23,22,21,20,19,13,7,8,9,10,11,17...

解析:确定矩阵的点，matrix[0][0],matrix[0][5],matrix[3][5],natrix[3][0]
游标从[0][0]位置开始，先向右递增，到右上角，再向下递增，到右下角，向左递减，到左下角，向上递减。然后一圈结束；
一圈结束的位置就是下一圈开始的位置，然后重复上述过程。
*/

#define ARR_ROW 1
#define ARR_COL 1


void print_line(int (*arr)[ARR_COL], int lt_row, int lt_col, int rd_row, int rd_col) {
    if (lt_row <= rd_row) { //为防止单列或者单行的时候，出现重复的打印，针对行打印时，打印完成后，行数自增1，也就是说只有判断lt_row和rd_row在不冲突的情况下才进行行的打印
        // cout<<"->";
        for (int i = lt_col; i <= rd_col; i++) {
            cout << arr[lt_row][i] << " ";
        }
        cout << "\n";
        lt_row += 1; //行数移动1
    } 

    if (lt_col <= rd_col) { //和上方的行数处理类似，在列处理完后，列数移动1，防止lt_col和rd_col冲突
        // cout<<"\|/";
        for (int i = lt_row; i <= rd_row; i++) {
            cout << arr[i][rd_col] << " ";
        }
        cout << "\n";
        rd_col -= 1;  //列数移动1
    }

    if (lt_row <= rd_row) {
        // cout<<"<-";
        for (int i = rd_col; i >= lt_col; i--) {
            cout << arr[rd_row][i] << " ";
        }
        cout << "\n";
        rd_row -= 1;
    }

    if (lt_col <= rd_col) {
        // cout<<"/|";
        for (int i = rd_row; i >= lt_row; i--) {
            cout << arr[i][lt_col] << " ";
        }
        cout << "\n";
        lt_col += 1;
    }
}

int main(int argc, char const *argv[]) {
    int arr[ARR_ROW][ARR_COL] = {};

    srand(time(nullptr));
    for (size_t i = 0; i < ARR_ROW; i++) {
        for (size_t j = 0; j < ARR_COL; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    for (size_t i = 0; i < ARR_ROW; i++) {
        for (auto &item : arr[i])
            cout << item << " ";
        cout << "\n";
    }
    cout<<"______________________"<<"\n";

    int lt_row = 0, lt_col = 0;
    int rd_row = ARR_ROW-1, rd_col = ARR_COL-1;
    while (lt_row <= rd_row && lt_col <= rd_col)
    {
      print_line(arr,lt_row++,lt_col++,rd_row--,rd_col--);
    }
    // print_line(arr, lt_row++, lt_col++, rd_row--, rd_col--);

    return 0;
}