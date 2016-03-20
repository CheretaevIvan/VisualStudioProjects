#include<stdio.h>
#include<inttypes.h>
#include<stdint.h>
#include <malloc.h>


struct Block
{
    int width, length, heigth;
};


int main()
{
    /* Reads the number of blocks */
    int number_of_blocks = 0;
	scanf("%"SCNi32, &number_of_blocks);
    /*  Allocates memory for data storage 
         Initialization of arrays*/
	struct Block *blocks = (struct Block*)calloc(number_of_blocks, sizeof(struct Block));
    if (!blocks)
        return -1;
    /* In the array number_of_incoming_blocks is stored number of blocks that can be invested in the i-th block*/
	int *number_of_incoming_blocks = (int*)calloc(number_of_blocks, sizeof(int));
	if (!number_of_incoming_blocks)
        return -1;
    /* Read the parameters of blocks: width, length, c*/
	for (int i = 0; i < number_of_blocks; ++i)
	{
		scanf("%"SCNi32" %"SCNi32" %"SCNi32, &(blocks[i].width), &(blocks[i].length), &(blocks[i].heigth));
	}
    /* Using dynamic programming */
	for (int i = 0; i < number_of_blocks; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (blocks[i].width > blocks[j].width &&
                blocks[i].length > blocks[j].length &&
                blocks[i].heigth > blocks[j].heigth &&
				number_of_incoming_blocks[i] <= number_of_incoming_blocks[j])
				number_of_incoming_blocks[i] = number_of_incoming_blocks[j] + 1;
        }
    }
    /* We are looking for the maximum number of blocks*/
	int number_of_incoming_blocks_max = number_of_incoming_blocks[0];
	for (int i = 1; i < number_of_blocks; ++i)
		if (number_of_incoming_blocks[i]>number_of_incoming_blocks_max)
			number_of_incoming_blocks_max = number_of_incoming_blocks[i];
    /* Conclusions the result*/
	printf("\n%"PRIi32, number_of_incoming_blocks_max + 1);
	/* frees memory */
    free(blocks);
	free(number_of_incoming_blocks);
    return 0;
}