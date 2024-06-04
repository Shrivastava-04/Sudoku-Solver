#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid(9,vector<int>(9,0));
void print_grid(){
    cout<<"----------------------------"<<endl;
	for(int i=0;i<9;i++){
	    cout<<"|";
		for(int j=0;j<9;j++){
            if(grid[i][j]==0){
                cout<<" "<<" |";
                continue;
            }
			cout<<grid[i][j]<<" |";
		}
		cout<<endl;
		cout<<"----------------------------";
		cout<<endl;
	}
}

void print_grid_ans(){
    cout<<"The required output is:"<<endl;
    cout<<"----------------------------"<<endl;
	for(int i=0;i<9;i++){
	    cout<<"|";
		for(int j=0;j<9;j++){
            if(grid[i][j]==0){
                cout<<" "<<" |";
                continue;
            }
			cout<<grid[i][j]<<" |";
		}
		cout<<endl;
		cout<<"----------------------------";
		cout<<endl;
	}
	cout<<"There may be more solution of the given Sudoku."<<endl;
}

void get_grid(){
	for(int i=0;i<9;i++){
        cout<<"Please enter the values below of the Sudoku you want to solve.";
    cout<<endl;
    cout<<"Please enter the values in form of rows, one at a time with space in between two numbers in adajacent squares."<<endl;
    cout<<"Make sure to enter ""0"" in place of empty space in the puzzle"<<endl;
    print_grid();
        if(i>2)cout<<"Enter the "<<i+1<<"'th row"<<endl;
        else if(i==0)cout<<"Enter the 1st row"<<endl;
        else if(i==1)cout<<"Enter the 2nd row"<<endl;
        else if(i==2)cout<<"Enter the 3rd row"<<endl;
        for(int j=0;j<9;j++){
            char a;
            cin>>a;
            if(a!='0'){
                int b = a-'0';
                grid[i][j]=b;
            }
            else{
                grid[i][j]=0;
            }
            system("cls");
		}
	}
}

bool is_valid(int curr_row,int curr_col,int curr_num){
	if(curr_row>9||curr_row<0||curr_col<0||curr_row>9)
		return false;
	if(curr_num>9||curr_num<0)return false;
	for(int i=0;i<9;i++){
		if(grid[i][curr_col]==curr_num)return false;
		if(grid[curr_row][i]==curr_num)return false;
	}
	for(int i=(curr_row/3)*3;i<((curr_row+3)/3)*3;i++){
		for(int j=(curr_col/3)*3;j<((curr_col+3)/3)*3;j++){
			if(i==curr_row&&j==curr_col)continue;
			if(grid[i][j]==curr_num)return false;
		}
	}
	return true;
}

bool solve_grid(int row,int col){
	if(row==9)return true;
	else if(col==9) return solve_grid(row+1,0);
	else if(grid[row][col]!=0)return solve_grid(row,col+1);
	else{
		for(int i=1;i<=9;i++){
			if(is_valid(row,col,i)){
				grid[row][col] = i;
				if(solve_grid(row,col+1)){
					return true;
				}
				grid[row][col]=0;
			}
		}
		return false;
	}
}

int main(){
	get_grid();
	bool a = solve_grid(0,0);
	print_grid_ans();
}
