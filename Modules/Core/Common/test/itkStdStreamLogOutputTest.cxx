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
   //Warning about: identifier was truncated to '255' characters in the debug information (MVC6.0 Debug)
#pragma warning( disable : 4786 )
#endif

#include <iostream>
#include <fstream>
#include "itkStdStreamLogOutput.h"

int itkStdStreamLogOutputTest( int argc, char *argv [] )
{
  try
    {

    if (argc < 2)
      {
      std::cout << "Usage: " << argv[0] << " logFilename" << std::endl;
      return EXIT_FAILURE;
      }

    // Create an ITK StdStreamLogOutput
    itk::StdStreamLogOutput::Pointer output = itk::StdStreamLogOutput::New();

    std::cout << "Testing itk::StdStreamLogOutput" << std::endl;
    std::cout.precision(15);

    std::cout << "  Testing with standard console stream" << std::endl;
    output->SetStream(std::cout);
    output->Write(1.2345);
    output->Write("This is the test message.\n");
    output->Write("This is the second test message.\n", 1.2345);
    output->Flush();

    std::cout << "  Testing with a file stream" << std::endl;
    std::ofstream fout(argv[1]);
    output->SetStream(fout);
    output->Write(1.2345);
    output->Write("This is the test message.\n");
    output->Write("This is the second test message.\n", 1.2345);
    output->Flush();
    output->Print(std::cout);
    }
  catch(...)
    {
    std::cerr << "Exception caught !!" << std::endl;
    return EXIT_FAILURE;
    }

  std::cout << "[PASSED]" << std::endl;
  return EXIT_SUCCESS;
}


