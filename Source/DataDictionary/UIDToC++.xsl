<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:output method="text" indent="yes"/>
<!-- XSL to convert XML Part6.xml UIDs into C++ code -->
<!--
  Program: GDCM (Grass Root DICOM). A DICOM library
  Module:  $URL: https://gdcm.svn.sourceforge.net/svnroot/gdcm/trunk/Source/DataDictionary/TagToType.xsl $

  Copyright (c) 2006-2008 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.
-->
  <xsl:template match="/dicts">
    <xsl:text>
// GENERATED FILE DO NOT EDIT
// $ xsltproc UIDToC++.xsl Part6.xml &gt; gdcmUIDs.cxx

/*=========================================================================

  Program: GDCM (Grass Root DICOM). A DICOM library
  Module:  $URL: https://gdcm.svn.sourceforge.net/svnroot/gdcm/trunk/Source/DataDictionary/TagToType.xsl $

  Copyright (c) 2006-2008 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
</xsl:text>

<xsl:text>
#ifndef __gdcmUIDs_h
#define __gdcmUIDs_h

  typedef enum {
</xsl:text>
    <xsl:for-each select="table/uid">
        <xsl:value-of select="translate(@value,'.','_')"/>
        <xsl:text> = </xsl:text>
        <xsl:number value="position()" format="1" />
        <xsl:text>, // </xsl:text>
        <xsl:value-of select="@name"/>
<xsl:text>
</xsl:text>
    </xsl:for-each>
<xsl:text>} TSType;
#endif //__gdcmUIDs_h
</xsl:text>
#ifdef __gdcmUIDs_cxx
        <xsl:text>static const char * const TransferSyntaxStrings[][2] = {
</xsl:text>
    <xsl:for-each select="table/uid">
        <xsl:text>{"</xsl:text>
        <xsl:value-of select="@value"/>
        <xsl:text>","</xsl:text>
        <xsl:value-of select="@name"/>
        <xsl:text>"},
</xsl:text>
    </xsl:for-each>
        <xsl:text>{ 0, 0 }
};
#endif //__gdcmUIDs_cxx
</xsl:text>
  </xsl:template>
</xsl:stylesheet>