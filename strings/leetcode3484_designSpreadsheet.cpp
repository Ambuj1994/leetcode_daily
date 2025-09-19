class Spreadsheet {
public:
    vector<vector<int>> mat;

    Spreadsheet(int rows) {
        mat.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int i = 1;
        int row = 0;
        while(i < cell.length()){
            row = row * 10 + (cell[i] - '0');
            i++;
        }
        // cout<<"row got is "<<row<<endl;
        row = row - 1;

        int col = cell[0] - 'A';
        mat[row][col] = value;
        // cout<<"After inserting value "<<value<<" mat["<<row<<"]["<<col<<"]"<<mat[row][col]<<endl;
    }
    
    void resetCell(string cell) {
        int i = 1;
        int row = 0;
        while(i < cell.length()){
            row = row * 10 + (cell[i] - '0');
            i++;
        }
        row--;
        int col = cell[0] - 'A';
        mat[row][col] = 0;
    }
    
    int getValue(string formula) {

        //check for 1st col or num
        int num1 = 0;
        int col1 = -1;
        int i = 1;
        if(formula[1] >= 'A' && formula[1] <= 'Z'){
            col1 = formula[1] - 'A';
            i = 2;
        }
    
        while(formula[i] != '+'){
            num1 = num1 * 10 + (formula[i] - '0');
            i++;
        }

        //check for 2nd col or num
        int num2 = 0;
        int col2 = -1;
        int j = i + 1;
        if(formula[j] >= 'A' && formula[j] <= 'Z'){
            col2 = formula[j] - 'A';
            j++;
        }
    
        while(j < formula.length()){
            num2 = num2 * 10 + (formula[j] - '0');
            j++;
        }

        int sum = 0;
        if(col1 != -1){
            sum += mat[num1 - 1][col1];
        }
        else{
            sum += num1;
        }

        if(col2 != -1){
            sum += mat[num2 - 1][col2];
        }
        else{
            sum += num2;
        }

    return sum;
 
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
