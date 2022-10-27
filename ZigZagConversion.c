//Looking at the example I want to try to create a similar matrix 
//There seem to be two types of actions taken when making the matrix:
//moving down and moving on a diagonal
//there should also be a function to write each char after we reached the respective
//cell in the matrix
//after making the matrix, traversing it and filling it up
//we want to go through all of the matrix and read only the legal chars

char** createMat(int numRows,int numCols){
    char **matrix = (char**) calloc(numRows, sizeof(char*)+1);//I actually had to read about how to allocate 
        //a matrix and how to use calloc before writting these lines of code, I feel
        //like that is a bit of cheating
    for(int i=0; i<numRows;i++){
        matrix[i] = (char*) calloc(numCols,sizeof(char)+1);//this creates an nxn matrix
    }
    return matrix;
}
void goDown(char *mat, int numCols){//we need numRows to know how many elements to
    //traverse in order to go down a line
    mat += numCols-1;
}
void goDiag(char *mat,int numCols){
    mat-= (numCols-1-1);
}
void writeToMat(char *mat,char c){
    *mat = c;
}
int countCol(char* str,int numRows){
    int len = strlen(str);
    int cnt = 0;
    while(len>0){
        if(cnt==0){//we emulate the traversal of the matrix
            cnt++;
            for(int i=0;i<numRows&&len>0;i++){
                len--;
            }
        }else{
            for(int i=0;i<numRows-1&&len>0;i++){
                len--;
            }
        }
        for(int i=0;i<numRows-1&&len>0;i++){
            len--;
            cnt++;
        }
    }
    return cnt;
}

void findZigzagedStr(char* dest, char* src,int numRows,int numCols){
    int i=0;
    int j=0;
    int k=0;
    while(*src!='\0'){
        if((*src>='A'&&*src<='Z')||*src==','||*src==','){
            dest[i] = *src;
            i++;
        }
        src++;
    }
}

char * convert(char * s, int numRows){
    if(numRows==1){
        return s;
    }
    char *ret = (char *)malloc(strlen(s)*sizeof(char)+1);
    ret[strlen(s)] = '\0';
    //I was thinkning of just writing two for loops but then I thought that it is not 
    //maintanable, nor is it scalable
    int numCols = countCol(s,numRows);
    char **mat = createMat(numRows,numCols);
    for(int i=0; i<numRows;i++){
        mat[i] = (char*) calloc(numCols,sizeof(char)+1);//this creates an nxn matrix
    }
    // char *temp = &mat[0][0];//we rather work on a copy than the original so it is easier to traverse the original later
     for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            mat[i][j]='@';
        }
    }
    //I switched to using x y coordinates instead of incrementing/decrementing 
    //a pointer so this is why it looks this way, I know it is not the
    //most scalable.
    int x=0;
    int y=0;
    while(*s!='\0'){
        if(x==0){
            mat[y][x]=*s;
            s++;
        }
        for(int i =0;i<numRows-1&&*s!='\0';i++){
            y++;
            mat[y][x]=*s;
            s++;
        }
        for(int i =0;i<numRows-1&&*s!='\0';i++){
            y--;
            x++;
            mat[y][x]=*s;
            s++;
        }

    }
    int count =0;
    for(int i=0;i<numRows&&count<strlen(ret);i++){
        for(int j=0;j<numCols&&count<strlen(ret);j++){
            if(mat[i][j]!='@'){
            // if((mat[i][j]>='A'&&mat[i][j]<='Z') || mat[i][j]==',' || mat[i][j]=='.'){
                ret[count]=mat[i][j];
                count++;
            }
        }
    }
    return ret;
}

//above is my original bad time complexity solution^^

//smarty pants solution:



char * convert(char * s, int numRows){
    if(numRows==1){
        return s;
    }
    char *ret = (char *)malloc(strlen(s)*sizeof(char)+1);
    ret[strlen(s)] = '\0';
    char* ret_cpy = ret;
    for(int r =0;r<numRows;r++){
        int step  = 2*(numRows-1);
        for(int i=r;i<strlen(s)&&*ret!='\0';i+=step){
            *ret = s[i];
            ret++;
            if(r>0 && r<numRows-1 && ((i+step -2*r)<strlen(s))&&*ret!='\0'){
                *ret = s[i+step-2*r];
                ret++;
            }
        }
    }
    return ret_cpy;
}