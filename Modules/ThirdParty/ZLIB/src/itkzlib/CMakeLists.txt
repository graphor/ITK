project(ITKZLIB)
include_regular_expression("^(itk|deflate|inf|trees|zconf|zlib|zutil).*$")

include_directories(BEFORE ${ITKZLIB_SOURCE_DIR})

# source files for zlib
set(ZLIB_SRCS
  adler32.c  compress.c  crc32.c  deflate.c  gzio.c   inffast.c
  inflate.c  inftrees.c  trees.c  uncompr.c  zutil.c
  )

# for windows add the .def and .rc files to the source list
# if building shared libs
if(WIN32)
  if(BUILD_SHARED_LIBS)
    set(ZLIB_DLL 1)
    if(NOT UNIX)
      if(NOT BORLAND)
        if(NOT MINGW)
          set(ZLIB_SRCS ${ZLIB_SRCS} zlib.def zlib.rc  )
        endif(NOT MINGW)
      endif(NOT BORLAND)
    endif(NOT UNIX)
  endif(BUILD_SHARED_LIBS)
endif(WIN32)

configure_file(${ITKZLIB_SOURCE_DIR}/zlibDllConfig.h.in
               ${ITKZLIB_BINARY_DIR}/zlibDllConfig.h)

add_library(itkzlib ${ZLIB_SRCS})

# Apply user-defined properties to the library target.
if(ITK_LIBRARY_PROPERTIES)
  set_target_properties(itkzlib PROPERTIES ${ITK_LIBRARY_PROPERTIES})
endif(ITK_LIBRARY_PROPERTIES)

if(NOT ITK_INSTALL_NO_LIBRARIES)
  install(TARGETS itkzlib
    EXPORT ${ITK3P_INSTALL_EXPORT_NAME}
    RUNTIME DESTINATION ${ITK3P_INSTALL_RUNTIME_DIR} COMPONENT RuntimeLibraries
    LIBRARY DESTINATION ${ITK3P_INSTALL_LIBRARY_DIR} COMPONENT RuntimeLibraries
    ARCHIVE DESTINATION ${ITK3P_INSTALL_ARCHIVE_DIR} COMPONENT Development
    )
endif(NOT ITK_INSTALL_NO_LIBRARIES)

if(NOT ITK_INSTALL_NO_DEVELOPMENT)
  install(FILES
    ${ITKZLIB_SOURCE_DIR}/zlib.h
    ${ITKZLIB_SOURCE_DIR}/zconf.h
    ${ITKZLIB_SOURCE_DIR}/itk_zlib_mangle.h
    ${ITKZLIB_BINARY_DIR}/zlibDllConfig.h
    DESTINATION ${ITK3P_INSTALL_INCLUDE_DIR}/itkzlib # itk_zlib.h #include "itkzlib/zlib.h"
    COMPONENT Development)
endif(NOT ITK_INSTALL_NO_DEVELOPMENT)
