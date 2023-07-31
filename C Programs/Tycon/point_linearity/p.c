#include <stdio.h>

int main()
{
  /* code */
  int a1,b1,c1,a2,b2,c2,a3,b3,c3;
  int dir_x, dir_y, dir_z;

  printf("Enter the coordinates of Point 1 \n");
  printf("Enter a1 : ");
  scanf("%d",&a1);
  printf("Enter b1 : ");
  scanf("%d", &b1);
  printf("Enter c1 : ");
  scanf("%d", &c1);
  printf("Enter the coordinates of Point 2 \n");
  printf("Enter a2 : ");
  scanf("%d", &a2);
  printf("Enter b2 : ");
  scanf("%d", &b2);
  printf("Enter c2 : ");
  scanf("%d", &c2);
  printf("Enter the coordinates of Point 3 \n");
  printf("Enter a3 : ");
  scanf("%d", &a3);
  printf("Enter b3 : ");
  scanf("%d", &b3);
  printf("Enter c3 : ");
  scanf("%d", &c3);

  dir_x = a2 - a1;
  dir_y = b2 - b1;
  dir_z = c2 - c1;

  int dir_x2, dir_y2, dir_z2; 

  dir_x2 = a3 - a2;
  dir_y2 = b3 - b2;
  dir_z2 = c3 - c2;

  if (((dir_x2 / dir_x) == (dir_y2 / dir_y)) && ((dir_y2 / dir_y) == (dir_z2 / dir_z)))
  printf("Points are collinear...");
  else
  printf("Points are not collinear...");

    return 0;
}
