#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 30

int random(int N);
void menu_A(float (*arr1)[5],char *arr3);
void menu_B(int *arr2);
void menu_C(float (*arr1)[5],int*arr2,char*arr3);
void menu_D(float (*arr1)[5],int*arr2,char*arr3);
void menu_E(float (*arr1)[5],int*arr2,char*arr3);

int main(){
   srand(time(NULL));
   float arr1[30][5]={0};
   int arr2[5]={0},in;
   char arr3[30]={0};
   int i,j,student_number=101;
   for(i=0;i<30;i++){
      arr1[i][0]=student_number++;
   }
   for(i=0;i<30;i++){
      for(j=1;j<4;j++){
         if(j==3) arr1[i][j]=random(40);
         else arr1[i][j]=random(60);
      }
   }
   for(i=0;i<30;i++){
      arr1[i][4]=arr1[i][1]*0.2+arr1[i][2]*0.2+arr1[i][3]*0.6;
   }
   
   for(i=0;i<30;i++){
      if (arr1[i][4]>=90) arr3[i]='A';
      else if(arr1[i][4]>=80) arr3[i]='B';
      else if(arr1[i][4]>=70) arr3[i]='C';
      else if(arr1[i][4]>=60) arr3[i]='D';
      else arr3[i]='F';
   }
   for(i=0;i<30;i++){
      if(arr3[i]=='A') arr2[0]++;
      else if(arr3[i]=='B') arr2[1]++;
      else if(arr3[i]=='C') arr2[2]++;
      else if(arr3[i]=='D') arr2[3]++;
      else arr2[4]++;
   }
   while(1){
      printf("****************Menu****************\n");
      printf("**A. 모든 학생의 성적 출력   **\n");
      printf("**B. Grade에 따른 분포도 출력 **\n");
      printf("**C. 학번에 따른 성적 출력   **\n");
      printf("**D. 총 평점 출력      **\n");
      printf("**E. 정렬된 성적 출력      **\n");
      printf("**F. 프로그램 종료         **\n");
      printf("************************************\n");
      printf("원하는 menu를 입력하세요(A~F) : ");
      scanf(" %c",&in);
      if(in=='A'||in=='a') menu_A(arr1,arr3);   //A, a입력시 menu_A 함수 
      else if(in=='B'||in=='b') menu_B(arr2);
      else if(in=='C'||in=='c') menu_C(arr1,arr2,arr3);
      else if(in=='D'||in=='d') menu_D(arr1,arr2,arr3);
      else if(in=='E'||in=='e') menu_E(arr1,arr2,arr3);
      else if(in=='F'||in=='f') break;
      else printf("잘못 입력하셨습니다.\n ");
   }
   
} 

int random(int N){   //1,2,3번째 시험 성적 랜덤으로 넣어줌 
   int a;
   while(1){
      a=rand()%101;   
      if(a>=N)      //N이상의 수가 되도록 100이하의 수 랜덤 
         break;
   }
   return a;
}

void menu_A(float (*arr1)[5],char *arr3){
   int i,j;
   printf("ID   Exam1   Exam2   Exam3   Score   Grade");
   printf("===========================================");
   for(i=0;i<30;i++){
      for(j=0;j<5;j++){
         if(j==4) printf("%-5.1f",arr1[i][j]);
         else printf("%-5.f",arr1[i][j]);
      }
      printf("%-5c",arr3[i]);
      putchar('\n');
   }   
}

void menu_B(int *arr2){
   int i,j;
   printf("==========성적분포도=============\n");
   for(i=0;i<5;i++){
      if(i==0) printf("A: ");
      else if(i==1) printf("B: ");
      else if (i==2) printf("C: ");
      else if(i==3) printf("D: ");
      else printf("F: ");
      for(j=0;j<arr2[i];j++) printf("* "); 
      putchar('\n');
   }
} 

void menu_C(float (*arr1)[5],int *arr2,char *arr3){
   int std_number,i;
   while(1){
      printf("찾고자 하는 ID를 입력하세요(101~130):");
      scanf("%d",&std_number);
      if(std_number>=101&&std_number<=130){
         for(i=0;i<30;i++){
            if(arr1[i][0]==std_number){
               printf("%.1f",&arr1[i][3]);
               printf("%c",&arr3[i]);
            }
         }
         break;
      }
      else printf("찾는 학번없어요 다시 입력해주세요\n");
   }
}

void menu_D(float (*arr1)[5],int*arr2,char*arr3){
   float sum=0;
   sum=arr2[0]*4+arr2[1]*3+arr2[2]*2+arr2[1]*1;
   printf("총 평점은 %.1f 입니다.\n",sum/30);      
}

void menu_E(float (*arr1)[5],int*arr2,char*arr3){
   int i,j,k;
   float copyarr1[30][5]={0};
   char copyarr3[30]={0};
   float copy[5]={0};
   for(i=0;i<30;i++){
      for(j=0;j<5;j++) copyarr1[i][j]=arr1[i][j];
   }
   for(i=0;i<5;i++) copyarr3[i]=arr3[i];
   for(i=1;i<30;i++){
      float Maxscore=copyarr1[i-1][4];
      if(copyarr1[i][4]>=Maxscore){
         Maxscore=copyarr1[i][4];
         for(j=0;j<5;j++){
            copy[j]=copyarr1[i-1][j];
            copyarr1[i-1][j]=copyarr1[i][j];
            copyarr1[i][j]=copy[j];
         }
      }
   
   }
   for(k=0;k<30;k++){
      if (copyarr1[i][4]>=90) copyarr3[i]='A';
      else if(copyarr1[i][4]>=80) copyarr3[i]='B';
      else if(copyarr1[i][4]>=70) copyarr3[i]='C';
      else if(copyarr1[i][4]>=60) copyarr3[i]='D';
      else copyarr3[i]='F';
   }
   printf("ID\tExam1\tExam2\tExam3\tScore\tGrade\n");
   printf("==========================================================\n");
   for(i=0;i<30;i++){
      for(j=0;j<5;j++){
         if(j==4) printf("%.f\t",copyarr1[i][j]);
         else printf("%d\t",copyarr1[i][j]);
      }
      printf("%c\n",copyarr3[i]);
   }
   printf("==========================================================\n");
}