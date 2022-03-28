#include <stdio.h>
void swap (int *, int *);
int main ()
{
  int size, i,j, burst = 0,minvalue=0,minIndex;
  int AT[10], BT[10], WT[10], T_turn_around_time[10];
  float A_waiting, A_turn_around, t_t_around = 0, t_waiting = 0;
  printf ("Enter the no of process in the ready queue: ");
  scanf ("%d", &size);
  printf
    ("Enter the arrival time and the burst time of the processes one by one\n");
  for (i = 0; i < size; i++)
    {
      scanf ("%d%d", &AT[i], &BT[i]);
    }

    for(i=0;i<size;i++){
        minvalue=BT[i];
        minIndex=i;
        for(j=i;j<size;j++){
            if(minvalue >=BT[j])
            {
                minvalue = BT[j];
                minIndex=j;
            }
        }
        swap(&BT[i],&BT[minIndex]);
        swap(&AT[i],&AT[minIndex]);
    }
  printf ("Process\tArrival Time\tBurst Time\n");
  for (i = 0; i < size; i++)
    {
      printf ("P%d\t%d\t\t%d\n", i, AT[i], BT[i]);
      printf ("\n");
    }
  for (i = 0; i < size; i++)
    {
      if (i == 0){
	    WT[i] = 0;
	    T_turn_around_time[i] = BT[i];}
      else{
	    WT[i] = burst - AT[i];
	  }
      burst += BT[i];
      if (i!=0)
        T_turn_around_time[i] = burst - AT[i];
      t_waiting += WT[i];
      t_t_around += T_turn_around_time[i];
    }
    for(i=0;i<size;i++)
        printf("\n%d\t%d",WT[i],T_turn_around_time[i]);
  A_waiting = t_waiting / size;
  A_turn_around = t_t_around / size;

  printf ("\nThe Average wait time : %f\n", A_waiting);
  printf ("The Average turn around time : %f", A_turn_around);
  return 0;
}

void swap (int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
