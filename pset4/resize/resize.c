/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include "bmp.h"

bool is_float( char *str )
{
    double d;
    return sscanf(str, "%lf", &d);
}

int main(int argc, char *argv[])
{
    float factor; //factor to be resized to
    // ensure proper usage
    if (argc != 4 || !is_float(argv[1]))
    {
        fprintf(stderr, "Usage: ./resize float infile outfile\n");
        return 1;
    }
    
    factor = atof(argv[1]);
    
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 1;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, buffer_bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    buffer_bf = bf;
    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, buffer_bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    buffer_bi = bi;
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 2;
    }
    
    //resizing
    buffer_bi.biHeight = bi.biHeight * factor;
    buffer_bi.biWidth = bi.biWidth * factor;
    
    //padding will change
    int new_padding = (4 - (buffer_bi.biWidth * sizeof(RGBTRIPLE)) %4) % 4;
    
    //more changes
    buffer_bi.biSizeImage = (buffer_bi.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(buffer_bi.biHeight);
    buffer_bf.bfSize = bf.bfSize - bi.biSizeImage + buffer_bi.biSizeImage;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&buffer_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&buffer_bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Read each scanline
        for (int j = 0; j < factor; j++)
        {  
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile, multiplied by factor
                for (int l = 0; l < factor; l++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);    
            }
            
            // Add  padding
            for (int a = 0; a < new_padding; a++)
                fputc(0x00, outptr);
            
            // move to the beginning
            if (j < factor - 1)
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
        }
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}