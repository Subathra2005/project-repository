#include<iostream>
void showMenu(){
    std::cout<<"1. ADDITION"<<std::endl;
    std::cout<<"2. SUBTRACTION"<<std::endl;
    std::cout<<"3. MUTIPLICATION"<<std::endl;
    std::cout<<"4. TRANSPOSE"<<std::endl;
    std::cout<<"5. EXIT"<<std::endl;
    
}
int main(){
    std::cout<<"**********MATRIX CALCULATOR**********"<<std::endl; 
    int r1,r2,c1,c2;  
    std::cout<<"Enter the number of rows for matrix A"<<std::endl;
    std::cin>>r1;
    std::cout<<"Enter the number of columns for matrix A"<<std::endl;
    std::cin>>c1;
    std::cout<<"Enter the number of rows for matrix B"<<std::endl;
    std::cin>>r2;
    std::cout<<"Enter the number of columns for matrix B"<<std::endl;
    std::cin>>c2;
    int A[r1][c1];
    int B[r2][c2];
    int C[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            std::cout<<"A"<<i+1<<j+1<<" ";
            std::cin>>A[i][j];
        }
        std::cout<<std::endl;
    }
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            std::cout<<"B"<<i+1<<j+1<<" ";
            std::cin>>B[i][j];
        }
        std::cout<<std::endl;
    }
    std::cout<<"Matrix A"<<std::endl;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            std::cout<<A[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"Matrix B"<<std::endl;
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            std::cout<<B[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    int option;
    do{
        showMenu();
        std::cout<<std::endl;
        std::cout<<"Enter an option to perform desired calculation:";
        std::cin>>option;
        std::cout<<std::endl;
        system("cls");
        switch(option){
            case 1:
            if(r1==r2 && c1==c2){
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c1;j++){
                        C[i][j]=A[i][j]+B[i][j];
                    } std::cout<<std::endl;
                }
                std::cout<<"A + B :"<<std::endl;
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c1;j++){
                        std::cout<<C[i][j]<<" ";
                    }
                    std::cout<<std::endl;
                }
            }
            else{
                std::cout<<"Matrix of different orders cannot be added"<<std::endl;
            }
            std::cout<<std::endl;
            break;
            case 2:
            if(r1==r2 && c1==c2){
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c1;j++){
                        C[i][j]=A[i][j]-B[i][j];
                    } std::cout<<std::endl;
                }
                std::cout<<"A - B :"<<std::endl;
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c1;j++){
                        std::cout<<C[i][j]<<" ";
                    }
                    std::cout<<std::endl;
                }
            }
            else{
               std::cout<<"Matrix of different orders cannot be subtracted"<<std::endl; 
            }
            std::cout<<std::endl;
            break;
            case 3:
            if(c1=r2){
                for (int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++) {
                        C[i][j] = 0; 

                    for (int k = 0; k < c1; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                    }
                }
                std::cout<<"A X B:"<<std::endl;
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c1;j++){
                        std::cout<<C[i][j]<<" ";
                    }
                    std::cout<<std::endl;
                }
            }
            else{
                std::cout<<"Given matrices cannot be multiplied"<<std::endl;
            }
            std::cout<<std::endl;
            break;
            case 4:
            for(int i=0;i<r1;i++){
                for(int j=i+1;j<c1;j++){
                    int temp = A[i][j];
                    A[i][j] = A[j][i];
                    A[j][i] = temp;
                }
            }
            std::cout<<"Tranposed matrix:"<<std::endl;
            for(int i=0;i<r1;i++){
                for(int j=0;j<c1;j++){
                    std::cout<<A[i][j]<<" ";
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl; 
            break;
            case 5:
            std::cout<<"Thanks for using matrix calculator"<<std::endl;
            break; 
        }
        

    } while(option!=5);

      return 0;
}