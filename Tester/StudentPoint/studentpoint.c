#include <stdio.h>
#include <math.h>
//written by Tran Duy Khanh

int students(int n)
{
    int check_number = n;
    if (check_number != n)
        return 2;
    else if (n<=0||n>=10)
        return 3;
    else
        return 1;
        
}

int scores(int score)
{
    int check_score =score;
    if (check_score !=score)
        return 2;
    else if (score<-1||score>100)
        return 3;
    else if(score==-1)
        return 4;
    else
        return 1;
            
}

int value( int s){
    if (s>=60)
        return 2;
    else if (s==-1)
        return 3;
    else
        return 1;
}

int main(void)
{
  int n;
  int c1=0, c2=0, min=100, max=0;
  float count=0, passed, sum=0, average=0;
  printf("Input the number of students: ");
  scanf("%d", &n);
  students(n);
  if ( students(n)==2 || students(n)==3 )
  {
    printf("[ERROR] invalid number of students ");
    return 1;
  }
  else
  {
      printf("Score: ");
      int score[n];
      for(int i = 0; i < n; i++ )
      {
          scanf("%d", &score[i]);
          scores(n);
          if ( scores(score[i])==2||scores(score[i])==3 )
          {
            printf("[ERROR] invalid score %d \n", score[i]);
            return 1;
          }
      }
      for(int j = 0; j < (int)n; j++ )
      {
          if (value(score[j])==2)
          {
            count++ ;
           
          }
      }
      passed=(count/n)*100;
      
        for (int g=0; g<n; g++)
        {
            if (value(score[g])==3)
                c1++;
        }
        if (c1==n){
            printf("\nave: 0\nmax: 0\nmin: 0");
            return 0;
        } else{
            //Ave
            for (int h =0; h<n; h++){
                if (value(score[h]) == 2||value(score[h]) == 1)
                {
                    sum = sum + score[h];
                    c2++;
                }
            }
            //Max
            for (int m = 0; m<n; m++)
            {
                if (value(score[m])==2||value(score[m])==1)
                {
                    if (max < score[m])
                    {
                        max = score[m];
                    }
                }
            }
            //Min
            for (int q = 0; q<n; q++){
                if (value(score[q])==2||value(score[q])==1)
                {
                    if (min > score[q])
                    {
                        min = score[q];
                    }
                }
            }
        }
  
  }

  
  average=sum/c2;
  
  printf("\n");
  printf("======= score info =======\n\n");

  printf(" #student = %d \n", (int)n);
  printf(" #passed = %d", (int)count);
  printf(" (%d percent) \n",(int)passed);
  
  printf(" \nave = %.1f",average);
  printf(" \nmax = %d",max);
  printf(" \nmin = %d",min);
  printf(" \n========================================================");
  return 0;
}


