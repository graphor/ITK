/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include "itkImage.h"
#include "itkFFTTest.h"

#include "itkVnlFFTComplexConjugateToRealImageFilter.h"

// Test FFT using VNL Libraries. The test is performed for 2 3d array one of
// them having the same dimension(4,4,4) and the other having different
// dimensions (3,4,5).  Images are created with different dimensions in the
// test function based on the second template argument    and  the size of
// these dimensions are taken from the array.  The data types used are float
// and double.
int itkVnlFFTTest(int, char *[])
{
  typedef itk::Image< float, 1>               ImageF1;
  typedef itk::Image< std::complex<float>, 1> ImageCF1;
  typedef itk::Image< float, 2>               ImageF2;
  typedef itk::Image< std::complex<float>, 2> ImageCF2;
  typedef itk::Image< float, 3>               ImageF3;
  typedef itk::Image< std::complex<float>, 3> ImageCF3;

  typedef itk::Image< double, 1>               ImageD1;
  typedef itk::Image< std::complex<double>, 1> ImageCD1;
  typedef itk::Image< double, 2>               ImageD2;
  typedef itk::Image< std::complex<double>, 2> ImageCD2;
  typedef itk::Image< double, 3>               ImageD3;
  typedef itk::Image< std::complex<double>, 3> ImageCD3;

  unsigned int SizeOfDimensions1[] = { 4,4,4 };
  unsigned int SizeOfDimensions2[] = { 3,5,4 };
  int rval = 0;
  std::cerr << "Vnl float,1 (4,4,4)" << std::endl;
  if((test_fft<float,1,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageF1> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCF1> >(SizeOfDimensions1)) != 0)
    {
    rval++;
    std::cerr << "--------------------- Failed!" << std::endl;
    }
  std::cerr << "Vnl float,2 (4,4,4)"<< std::endl;
  if((test_fft<float,2,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageF2> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCF2> >(SizeOfDimensions1)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  std::cerr << "Vnl float,3 (4,4,4)"<< std::endl;
  if((test_fft<float,3,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageF3> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCF3> >(SizeOfDimensions1)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  std::cerr << "Vnl double,1 (4,4,4)"<< std::endl;
  if((test_fft<double,1,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageD1> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCD1> >(SizeOfDimensions1)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  std::cerr << "Vnl double,2 (4,4,4)"<< std::endl;
  if((test_fft<double,2,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageD2> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCD2> >(SizeOfDimensions1)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  std::cerr << "Vnl double,3 (4,4,4)"<< std::endl;
  if((test_fft<double,3,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageD3> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCD3> >(SizeOfDimensions1)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  std::cerr << "Vnl float,1 (3,5,4)" << std::endl;
  if((test_fft<float,1,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageF1> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCF1> >(SizeOfDimensions2)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  std::cerr << "Vnl float,2 (3,5,4)"<< std::endl;
  if((test_fft<float,2,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageF2> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCF2> >(SizeOfDimensions2)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  std::cerr << "Vnl float,3 (3,5,4)"<< std::endl;
  if((test_fft<float,3,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageF3> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCF3> >(SizeOfDimensions2)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  std::cerr << "Vnl double,1 (3,5,4)"<< std::endl;
  if((test_fft<double,1,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageD1> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCD1> >(SizeOfDimensions2)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  std::cerr << "Vnl double,2 (3,5,4)"<< std::endl;
  if((test_fft<double,2,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageD2> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCD2> >(SizeOfDimensions2)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  std::cerr << "Vnl double,3 (3,5,4)"<< std::endl;
  if((test_fft<double,3,
      itk::VnlFFTRealToComplexConjugateImageFilter<ImageD3> ,
      itk::VnlFFTComplexConjugateToRealImageFilter<ImageCD3> >(SizeOfDimensions2)) != 0)
    {
    std::cerr << "--------------------- Failed!" << std::endl;
    rval++;
    }
  return rval == 0 ? 0 : -1;
}
