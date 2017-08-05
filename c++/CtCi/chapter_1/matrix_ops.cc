#include<iostream>
#include<vector>
using namespace std;

void print(const vector<vector<int>> matrix){
    int n = matrix.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Rotate NxN matrix 90 degrees
void rotate_clockwise_90(vector<vector<int>> & matrix){
    int n = matrix.size();

    for(int i=0; i<n/2; i++){
        int first = i;
        int last = n-1-i;
        
        //In-layer rotation
        for(int j=first; j<last; j++){
            int step = j-first;

            //saving top value
            int top = matrix[first][j];
            //shifting left to top
            matrix[first][j] = matrix[last-step][first];
            //shifting bottom to left
            matrix[last-step][first] = matrix[last][last-step];
            //shifting right to bottom
            matrix[last][last-step] = matrix[j][last];
            //setting right to top
            matrix[j][last] = top; 
        }
    }
}


void set_row_zeros(vector<vector<int>> &matrix, int row){
    for(int i=0; i<matrix.size(); i++)
        matrix[row][i] = 0;
}

void set_column_zeros(vector<vector<int>> &matrix, int column){
    for(int j=0; j< matrix[0].size(); j++){
        matrix[j][column] = 0;
    }
}
//If an element in an MxN matrix is 0 set its row and column to 0
void set_zeros(vector<vector<int>> &matrix){
    if(matrix.size() <= 0)
        return;

    int length = matrix.size();
    int width = matrix[0].size();

    bool row[length] = { false };
    bool column[width] = { false };

    for(int i=0; i<length; i++){
        for(int j=0; j<width; j++){
            if(matrix[i][j] == 0){
                row[i] = true;
                column[j] = true;
            }
        }
    }

    for(int i=0; i<length; i++){
        if(row[i] == true)
            set_row_zeros(matrix, i);
    }

    for(int j=0; j<width; j++){
        if(column[j] == true)
            set_column_zeros(matrix, j);
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    cout<<"roatate_clockwisee_90\n";
    cout<<"---------------------\n";
    cout<<"Before:\n";
    print(matrix);
    cout<<"After:\n";
    rotate_clockwise_90(matrix);
    print(matrix);

    cout<<"set_zeros\n";
    cout<<"---------\n";
    matrix = {{1,2,3}, {4,0,6}, {7,8,9}};
    cout<<"Before:\n";
    print(matrix);
    cout<<"After:\n";
    set_zeros(matrix);
    print(matrix);

    return 0;
}
