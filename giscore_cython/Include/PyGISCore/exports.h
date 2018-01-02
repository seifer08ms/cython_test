//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file exports.h
//!  \brief Class 。
//!  \details 。
//!  \author liyq。
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef EXPORT_INCLUDE_H
#define EXPORT_INCLUDE_H

#ifdef WIN32
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#else
#define EXPORT
#define IMPORT
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef GISCORE_EXPORTS
#define GISCORE_API EXPORT
#else
#define GISCORE_API IMPORT
#endif

#ifdef PYCONVERSION_EXPORTS
#define PYCONVERSION_API EXPORT
#else
#define PYCONVERSION_API IMPORT
#endif

#ifdef PYDATA_EXPORTS
#define PYDATA_API EXPORT
#else
#define PYDATA_API IMPORT
#endif

#ifdef PYMAPPING_EXPORTS
#define PYMAPPING_API EXPORT
#else
#define PYMAPPING_API IMPORT
#endif

#endif
