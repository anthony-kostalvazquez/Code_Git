#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*

//basically just brute force checks all of them 
int maxArea(int* height, int heightSize)
{
    int max = 0;
    int current_vol = 0;

    for (int i = 0; i < heightSize; i++)
    {
        current_vol = 0;
        for (int j = i+1; ((height[i] * (heightSize - i)) > max) && (j < heightSize); j++)
        {
            current_vol = MinInt(height[i], height[j]) * (j-i);

            if(current_vol > max)
            {
                max = current_vol;
            }
            assert(printf("At positions %d and %d the volume is %d \n", i,j,current_vol));
        }
    }
    



    return(max);
}
*/
int MinInt(int a, int b)
{
    if(a <= b)
    {
        return(a);
    }
    else
    {
        return(b);
    }
}

int maxArea(int* height, int heightSize)
{
    int max = 0;
    int current_vol = 0;
    int Left = 0;
    int Right = heightSize -1;

    while(Left < Right)
    {
        if(height[Right] < height[Left])
        {
            current_vol = height[Right] * (Right - Left);
            Right--;
        }
        else
        {
            current_vol = height[Left] * (Right - Left);
            Left++;
        }

        if(current_vol > max)
        {
            max = current_vol;
        }
    }


    return(max);
}


int main()
{
    int height[] = {1,8,6,2,5,4,8,3,7};

    printf("%d \n", maxArea(height, 9));

    return 0;
}