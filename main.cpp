#include <iostream>
#include <vector>
using namespace std;
class Conway {
public:
    vector<vector<int>> find_add(vector<vector<int>>& board)
    {
        vector<vector<int>> temp(board.size(),vector<int>(board[0].size(),0));
        for (int i=1;i<board.size()-1;i++)
        {
            for (int j=1;j<board[0].size()-1;j++)
            {
                if (board[i][j] == 1)
                {
                    temp[i-1][j-1]++;
                    temp[i-1][j]++;
                    temp[i-1][j+1]++;
                    temp[i][j-1]++;
                    temp[i][j+1]++;
                    temp[i+1][j-1]++;
                    temp[i+1][j]++;
                    temp[i+1][j+1]++;
                }
            }
        }
        for (int j=1;j<board[0].size()-1;j++)
        {
            if (board[0][j] == 1)
            {
                temp[0][j-1]++;
                temp[0][j+1]++;
                temp[1][j-1]++;
                temp[1][j]++;
                temp[1][j+1]++;
            }
            if (board[board.size()-1][j] == 1)
            {
                temp[board.size()-1][j-1]++;
                temp[board.size()-1][j+1]++;
                temp[board.size()-2][j-1]++;
                temp[board.size()-2][j]++;
                temp[board.size()-2][j+1]++;
            }
        }
        /*for (int i=0;i<temp.size();i++)
        {
            for (int j=0;j<temp[0].size();j++)
                cout << temp[i][j] << " ";
            cout << endl;
        }*/ 
        for (int j=1;j<board.size()-1;j++)
        {
            if (board[j][0] == 1)
            {
                temp[j+1][0]++;
                temp[j-1][0]++;
                temp[j-1][1]++;
                temp[j][1]++;
                temp[j+1][1]++;
            }
            if (board[j][board[0].size()-1] == 1)
            {
                temp[j+1][board[0].size()-1]++;
                temp[j-1][board[0].size()-1]++;
                temp[j+1][board[0].size()-2]++;
                temp[j][board[0].size()-2]++;
                temp[j-1][board[0].size()-2]++;
            }
        }
        /*for (int i=0;i<temp.size();i++)
        {
            for (int j=0;j<temp[0].size();j++)
                cout << temp[i][j] << " ";
            cout << endl;
        }*/
        if (board[0][0] == 1)
        {
            temp[0][1]++;
            temp[1][0]++;
            temp[1][1]++;
        }
        if (board[board.size()-1][0] == 1)
        {
            temp[board.size()-2][0]++;
            temp[board.size()-1][1]++;
            temp[board.size()-2][1]++;
        }
        if (board[board.size()-1][board[0].size()-1] == 1)
        {
            temp[board.size()-2][board[0].size()-1]++;
            temp[board.size()-2][board[0].size()-2]++;
            temp[board.size()-1][board[0].size()-2]++;
        }
        if (board[0][board[0].size()-1] == 1)
        {
            temp[0][board[0].size()-2]++;
            temp[1][board[0].size()-1]++;
            temp[1][board[0].size()-2]++;
        }
        /*for (int i=0;i<temp.size();i++)
        {
            for (int j=0;j<temp[0].size();j++){
                cout << temp[i][j] << " ";
            }
            cout << endl;
        }*/
        // main code to find
        vector<vector<int>> temp2(board.size(),vector<int>(board[0].size(),0));
        for (int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {
                if (board[i][j] == 0 && temp[i][j] == 3) temp2[i][j]=1;
                else if (board[i][j] == 1 && (temp[i][j]==2 || temp[i][j]==3)) temp2[i][j] = 1;
            }
        }
        /*for (int i=0;i<temp.size();i++)
        {
            for (int j=0;j<temp[0].size();j++){
                cout << temp[i][j] << " ";}
            cout << "hello"<<endl;
        }   
        cout << "hello";*/
        return temp2;

    }
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size()==1 && board[0].size() == 1)
        {
            vector<vector<int>> temp(board.size(),vector<int>(board[0].size(),0));
            board = temp;
            return;
        }
        else if (board.size()==1 || board[0].size()==1)
        {
            vector<vector<int>> temp(board.size(),vector<int>(board[0].size(),0));
            if (board.size()==1){
                for (int j=1;j<board[0].size()-1;j++)
                {
                    if (board[0][j] == 1)
                    {
                        temp[0][j-1]++;
                        temp[0][j+1]++;
                    }
                }
                if (board[0][0] == 1)
                {
                    temp[0][1]++;
                }
                if (board[0][board[0].size()-1] == 1)
                {
                    temp[0][board[0].size()-2]++;
                }
            }
            else
            {
                for (int j=1;j<board.size()-1;j++)
                {
                    if (board[j][0] == 1)
                    {
                        temp[j+1][0]++;
                        temp[j-1][0]++;
                    }
                }
                if (board[board.size()-1][0] == 1)
                {
                    temp[board.size()-2][0]++;
                }
                if (board[0][0] == 1)
                {
                    temp[1][0]++;
                }
            }
            vector<vector<int>> temp2(board.size(),vector<int>(board[0].size(),0));
            for (int i=0;i<board.size();i++)
            {
                for (int j=0;j<board[0].size();j++)
                {
                    if (board[i][j] == 0 && temp[i][j] == 3) temp2[i][j]=1;
                    else if (board[i][j] == 1 && (temp[i][j]==2 || temp[i][j]==3)) temp2[i][j] = 1;
                }
            }
            board = temp2;
            return;

        }
        vector<vector<int>> temp1 = find_add(board);
        //vector<vector<int>> temp1 = find_del(board);
        board = temp1;
    }
};
int main(){
    vector<vector<int>> board = {{0,1,1,0,1,1,1,0},{1,1,0,1,1,0,0,0},{0,0,0,0,0,1,1,1},{1,1,1,1,0,0,0,0},{0,1,0,0,1,1,1,0}};
    class Conway obj;
    int n;
    cout << "Enter the number of iterations:";
    cin >> n;
    cout << "Initial board:" << endl << endl;
    for (int i=0;i<board.size();i++)
    {
        for (int j=0;j<board[0].size();j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0;i<n;i++){
        cout << "After " << i+1 << " iteration:" << endl << endl;
        obj.gameOfLife(board);
        for (int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
