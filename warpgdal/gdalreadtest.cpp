/*************************************************************************
  > File Name: gdalreadtest.cpp
  > Author: Chenliang-Wang
  > Mail: chenliangwang08ms@gmail.com
  > Created Time: Wed 13 Dec 2017 02:57:51 PM CST
 ************************************************************************/
#include <iostream>
#include "gdal.h"
#include "gdal_priv.h"
#include "cpl_conv.h" // for CPLMalloc()
int main(int argc, const char *argv[]) {
    /* opening the file */
    GDALDataset *poDataset ;
    GDALAllRegister();
    poDataset =  (GDALDataset *) GDALOpen("in.tif",GA_ReadOnly);
    /* getting datase information */
    double        adfGeoTransform[6];
    printf( "Driver: %s/%s\n",
            poDataset->GetDriver()->GetDescription(),
            poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) );
    printf( "Size is %dx%dx%d\n",
            poDataset->GetRasterXSize(), poDataset->GetRasterYSize(),
            poDataset->GetRasterCount() );
    if( poDataset->GetProjectionRef()  != NULL )
        printf( "Projection is `%s'\n", poDataset->GetProjectionRef() );
    if( poDataset->GetGeoTransform( adfGeoTransform ) == CE_None ) {
        printf( "Origin = (%.6f,%.6f)\n",
                adfGeoTransform[0], adfGeoTransform[3] );
        printf( "Pixel Size = (%.6f,%.6f)\n",
                adfGeoTransform[1], adfGeoTransform[5] );
    }
    /* fetching a raster band */
    GDALRasterBand  *poBand;
    int             nBlockXSize, nBlockYSize;
    int             bGotMin, bGotMax;
    double          adfMinMax[2];
    poBand = poDataset->GetRasterBand( 1 );
    poBand->GetBlockSize( &nBlockXSize, &nBlockYSize );
    printf( "Block=%dx%d Type=%s, ColorInterp=%s\n",
            nBlockXSize, nBlockYSize,
            GDALGetDataTypeName(poBand->GetRasterDataType()),
            GDALGetColorInterpretationName(
                poBand->GetColorInterpretation()) );
    adfMinMax[0] = poBand->GetMinimum( &bGotMin );
    adfMinMax[1] = poBand->GetMaximum( &bGotMax );
    if( ! (bGotMin && bGotMax) )
        GDALComputeRasterMinMax((GDALRasterBandH)poBand, TRUE, adfMinMax);
    printf( "Min=%.3f, Max=%.3f\n", adfMinMax[0], adfMinMax[1] );
    if( poBand->GetOverviewCount() > 0 )
        printf( "Band has %d overviews.\n", poBand->GetOverviewCount() );
    if( poBand->GetColorTable() != NULL )
        printf( "Band has a color table with %d entries.\n",
                poBand->GetColorTable()->GetColorEntryCount() );
    /* reading raster data */
    float *pafScanline;
    int   nCols = poBand->GetXSize(); // nCols
    int   nRows = poBand->GetYSize(); // nRows
    pafScanline = (float *) CPLMalloc(sizeof(float)*nCols*nRows);
    poBand->RasterIO( GF_Read, 0, 0, nCols, nRows,
                      pafScanline, nCols, nRows, GDT_Float32,
                      0, 0 );
    /* std::vector<float> vec_data{pafScanline,pafScanline+nCols*nRows} ; ; */
    for(int i=0; i<nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            //  if(pafScanline[j]>1) {
            std::cout << "data point ";
            int ij = i*nCols +j;
            printf("%d", ij+1);
            std::cout << " is: ";
            printf("%.3f", pafScanline[ij]);
            std::cout << std::endl;

            //   }
        }
    }
    // pafScanline should be freed with CPLFree() when it is no longer used
    CPLFree(pafScanline);
    /* closing the dataset */
    GDALClose(poDataset);

    return 0;
}
