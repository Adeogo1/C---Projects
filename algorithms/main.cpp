#include <iostream>
#include <vector>
#include <map>
#include <optional>
using namespace std;

struct Grid{
    int row;
    int col;

    Grid(int _row , int _col){
        row = _row;
        col = _col;
    }

    void NewGrid(int _row , int _col){
        row = _row;
        col = _col;
    }

    bool isOneByOne(){
        if (row == 1 && col == 1 ) return true;
        return false;
    }
    bool RealGrid(){
        if (col == 0 || row == 0) return false;
        return true;
    }

    bool operator == (const Grid& grid2) const {
        return (row == grid2.row && col == grid2.col);
    }



    bool operator<(const Grid &o)  const {
        return row < o.row || (row == o.row && col < o.col);
    }

};

long long Fib(long long n);
long long Fib2(long long n);
long long gridTraveller(Grid grid);
bool CanSum(int targetSum, vector<int> &vec);
bool howsum(int n,int m,vector<int>a);
optional<std::vector<int>>howSum(int targetSum, const std::vector<int>& numbers);


map<long long, long long> memoFib;
map<Grid, long long> memoGrid;
map<int, bool> memoSum;
int check[10000];
vector<int> v;// vector where you store the results if the sum exists (basically the numbers that sum up to the target number)



int main() {
/*
    cout << Fib(6) <<endl;
    cout << Fib(7) <<endl;
    cout << Fib(8) <<endl;
    cout << Fib(20) <<endl;
    cout << Fib(70) <<endl;


    Grid grid(1,1);

    cout << gridTraveller(grid) <<endl;
    grid.NewGrid(2,3);

    cout << gridTraveller(grid) <<endl;
    grid.NewGrid(3,2);

    cout << gridTraveller(grid) <<endl;
    grid.NewGrid(3,3);

    cout << gridTraveller(grid) <<endl;
    grid.NewGrid(18,18);

    cout << gridTraveller(grid) <<endl;

*/
vector <vector<int>> canSumVect {
        { 2,3},
        {5,3,4,7},
        {2,4,},
        {2,3,5},
        {7,14}
};

    vector<int> targetSums = {7,7,7,8,300};

    vector<int> vector1{7, 14};
    int sum = 300;
    map<int, bool> memo;
    if (CanSum(sum, vector1))
        cout << "true";
    else
        cout << "false";

    if (CanSum(7, canSumVect[1])){
        cout << "true " << endl;
    }else{
        cout << "false" << endl;
    }

    if (CanSum(7, canSumVect[2])){
        cout << "true " << endl;
    }else{
        cout << "false" << endl;
    }

    if (CanSum(8, canSumVect[3])){
        cout << "true " << endl;
    }else{
        cout << "false" << endl;
    }

    if (CanSum(300, canSumVect[4])){
        cout << "true " << endl;
    }else{
        cout << "false" << endl;
    }
/*
    if(howsum(targetSums[0],canSumVect[0].size(),canSumVect[0])==true){
        cout<<"yes"<<endl;
        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"no ans"<<endl;
*/
    return 0;
}




long long Fib(long long n){
    if (memoFib.count(n) > 0) {

        return memoFib.at(n);
    }
    if (n <= 2 ) return 1;
    memoFib.emplace(n, Fib(n - 1) + Fib(n - 2));
    return memoFib.at(n);
}

long long Fib2(long long n){

    if (n <= 2 ) return 1;

    return Fib(n - 1) + Fib(n - 2);
}

long long gridTraveller(Grid grid){

    map<Grid, long long>::iterator it;


    it = memoGrid.find(grid);
    if (it != memoGrid.end())
        return memoGrid.at(grid);

    if (grid.isOneByOne()) return 1;
    if (!grid.RealGrid()) return 0;

    Grid grid1(grid.row-1,grid.col);
    Grid grid2(grid.row,grid.col-1);

    memoGrid.emplace(grid, gridTraveller(grid1) + gridTraveller(grid2));
    
    return gridTraveller(grid1) + gridTraveller(grid2);
}

bool CanSum(int targetSum, vector<int> &vec) {
    int remainder;
    auto it = mem.find('c');
    if (memoSum.find(targetSum))
        return true;
    else if (targetSum == 0)
        return true;
    else if (targetSum < 0)
        return false;
    else
        for (auto i : vec) {
            remainder = targetSum - i;
            if (CanSum(remainder, vec)) {
                memoSum.emplace(remainder, true);
                return true;
            }
        }
    memoSum.emplace(remainder, false);
    return false;
}

bool howsum(int n,int m,vector<int>a)
{
    if(n==0)
    {
        cout<<"hurrah"<<endl;
        return true;
    }
    if(n<0)return false;
    if(check[n]==1)return true;
    if(check[n]==-1)return false;
    for(int i=0; i<m; i++)
    {
        int r=n-a[i];
        if(howsum(r,m,a)==true)
        {
            v.push_back(a[i]);
            check[n]=1;
            return true;
        }
        else
        {
            check[n]=-1;
        }
    }
    return false;
}

optional<std::vector<int>>howSum(int targetSum, const std::vector<int>& numbers) {
    if (targetSum == 0)
        return std::vector<int>{};
    if (targetSum < 0)
        return std::nullopt;
    for (auto numer : numbers) {
        const auto remainder = targetSum - numer;
        auto remainderResult = howSum(remainder, numbers);
        if (remainderResult) {
            remainderResult->push_back(targetSum);
            return remainderResult;
        }
    }
    return std::nullopt;
}