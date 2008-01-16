/*=========================================================================

  Program: GDCM (Grass Root DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2008 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef __gdcmSpacingHelper_h
#define __gdcmSpacingHelper_h

#include "gdcmTag.h"
#include <vector>

namespace gdcm
{

/**
 * \brief Spacing
 * \note
 */
class MediaStorage;
class DataSet;
class GDCM_EXPORT SpacingHelper
{
public:
  static std::vector<double> GetSpacingValue(DataSet const & ds);

protected:
  static Tag GetSpacingTagFromMediaStorage(MediaStorage const &ms);
};

} // end namespace gdcm

#endif //__gdcmSpacing_h
