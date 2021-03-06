// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#include <SAMRAIPluginInfo.h>
#include <avtSAMRAIFileFormat.h>
#include <avtSTMDFileFormatInterface.h>
#include <avtGenericDatabase.h>

// ****************************************************************************
//  Method:  SAMRAICommonPluginInfo::GetDatabaseType
//
//  Purpose:
//    Returns the type of a SAMRAI database.
//
//  Programmer:  generated by xml2info
//  Creation:    omitted
//
// ****************************************************************************
DatabaseType
SAMRAICommonPluginInfo::GetDatabaseType()
{
    return DB_TYPE_STMD;
}

// ****************************************************************************
//  Method: SAMRAICommonPluginInfo::SetupDatabase
//
//  Purpose:
//      Sets up a SAMRAI database.
//
//  Arguments:
//      list    A list of file names.
//      nList   The number of timesteps in list.
//      nBlocks The number of blocks in the list.
//
//  Returns:    A SAMRAI database from list.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************
avtDatabase *
SAMRAICommonPluginInfo::SetupDatabase(const char *const *list,
                                   int nList, int nBlock)
{
    avtSTMDFileFormat **ffl = new avtSTMDFileFormat*[nList];
    for (int i = 0; i < nList; i++)
    {
        ffl[i] = new avtSAMRAIFileFormat(list[i]);
    }
    avtSTMDFileFormatInterface *inter
           = new avtSTMDFileFormatInterface(ffl, nList);
    return new avtGenericDatabase(inter);
}
