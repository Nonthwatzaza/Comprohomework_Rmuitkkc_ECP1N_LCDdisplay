#include <stdio.h>

// LCD display Homework code
// 98.99% convert code
// @author original java code by Aj prasan @ECP Rmuit kkc
// convert code to c by Thanapun Thongjurai @ECP1N Rmuit kkc
// test and arrange c code by Nonthwat zaza @ECP1N Rmuit kkc

void LCDPRINTF(int length ,char Number[]);

int main(){
    printf("Enter length and number :");
  int length = 0; //ค่าความยาว
  char Number[10]; // array ขนาด 10 ตัวอักษร
  {
    scanf("%d %s",&length,&Number);
    if(length > 0 && Number[0] != ' ') //ความยาวมากกว่า 0 และ ตัวเลขไม่ว่างเปล่า
        LCDPRINTF(length,Number); // เข้าฟังชั่น
    else
      return 0;
  }
  return 0;
}

void LCDPRINTF(int length ,char Number[]){
                      //0   1   2   3   4   5   6   7   8
  char LCD[10][10] = {{'E','-','|',' ','|','-','|','E','|'},  //0
                      {'E',' ',' ',' ','|',' ',' ','E','|'},  //1
                      {'E','-',' ','-','|','-','|','E',' '},  //2
                      {'E','-',' ','-','|','-',' ','E','|'},  //3
                      {'E',' ','|','-','|',' ',' ','E','|'},  //4
                      {'E','-','|','-',' ','-',' ','E','|'},  //5
                      {'E','-','|','-',' ','-','|','E','|'},  //6
                      {'E','-',' ',' ','|',' ',' ','E','|'},  //7
                      {'E','-','|','-','|','-','|','E','|'},  //8
                      {'E','-','|','-','|','-',' ','E','|'},  //9
                      };

  for(int segmentNo=1;segmentNo<=5;segmentNo++) // ( ให้ sno =1;ถ้า snoน้อยกว่า 5 ; เพิ่ม sno
    {
    if(segmentNo%2!=0) //ถ้า sno ไม่เป็นจำนวนคู่
    {
      for(int i=0;i<strlen(Number);i++) // ให้ i =1;ถ้า iน้อยกว่า ความยาว Number ; เพิ่ม i
      {
        int postNo = Number[i]-48; // postNo = ตัวเลข [i] -48
            printf(" ");
                for(int j=0;j<length;j++) //ตวามยาว
                {
                    printf("%c",LCD[postNo][segmentNo]); //แสดงผล [ตำแหน่ง][ตำแหน่ง]
                }
        printf(" ");
      }
      printf(" \n");
    }
    else
    {
      for(int k=0;k<length;k++) // ความยาว
      {
        if(segmentNo==2) //ถ้า sno เป็นจำนวนคู่
        {
          for(int i=0;i<strlen(Number);i++)
          {
            int postNo = Number[i]-48;
            printf("%c",LCD[postNo][2]);
            for(int j=0;j<length;j++)
            {
              printf(" ");
            }
            printf("%c",LCD[postNo][4]);
          }
          printf(" \n");
        }
        else
        {
          for(int i=0;i<strlen(Number);i++)
          {
            int postNo = Number[i]-48;
            printf("%c",LCD[postNo][6]);
            for(int j=0;j<length;j++)
            {
              printf(" ");
            }
            printf("%c",LCD[postNo][8]);
          }
          printf(" \n");
        }
      }
    }
  }
}

