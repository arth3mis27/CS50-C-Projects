#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("File couldn't been opened.\n");
        return 1;
    }
    // create a buffer for a block of data
    uint8_t buffer[512];
    int file_count = 0;
    FILE *img = NULL;
    // while there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Close teh open file
            if (img != NULL)
            {
                fclose(img);
            }
            // Create a new file name
            char nfile[10];
            sprintf(nfile, "%03i.jpg", file_count);

            // write file
            img = fopen(nfile, "w");
            file_count++;
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
    return 0;
}
