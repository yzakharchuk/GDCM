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
#include "gdcmGlobal.h"
#include "gdcmDicts.h"
#include "gdcmDict.h"

int TestGlobal(int, char *[])
{
  // case 1
  // Get the global singleton:
  const gdcm::Global& g = gdcm::GlobalInstance;
  // get the Part 6 dicts from it:
  const gdcm::Dicts &ds = g.GetDicts();
  const gdcm::Dict &pub = ds.GetPublicDict();
  const gdcm::PrivateDict &priv = ds.GetPrivateDict();

  // case 2
  gdcm::Dicts dicts;
  const gdcm::Dict &d1 = dicts.GetPublicDict();

  // case 3
  gdcm::Dict d2;

  // This one will be empty:
  std::cout << "Empty dict:" << std::endl;
  std::cout << d1 << std::endl;
  if( !d1.IsEmpty() )
    {
    return 1;
    }
  // This one will be empty:
  std::cout << "Empty dict:" << std::endl;
  std::cout << d2 << std::endl;
  if( !d2.IsEmpty() )
    {
    return 1;
    }
  // This should should be filled in:
  std::cout << "Global pub dict:" << std::endl;
  std::cout << pub << std::endl;
  if( pub.IsEmpty() )
    {
    return 1;
    }
  // This should should be filled in:
  std::cout << "Global priv dict:" << std::endl;
  std::cout << priv << std::endl;
  if( priv.IsEmpty() )
    {
    return 1;
    }
  //const gdcm::DictEntry& de = priv.GetDictEntry( gdcm::PrivateTag(0x0009,0x0016,"GEMS_IDEN_01") ); 
  //std::cout << de << std::endl;

#if 0
  const char *empty = "";
  std::string s = empty;
  std::cout << s.empty() << std::endl;
  const gdcm::DictEntry& de = pub.GetDictEntry( gdcm::Tag(0x0028,0x0015) );
  const char *v = de.GetName();
  //assert( v );
  std::cout << "TOTO:" << de << std::endl;
#endif

  return 0;
}