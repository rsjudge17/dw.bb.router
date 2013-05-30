/*
 * pgcdef.hh
 *
 *  Created on: May 21, 2013
 *      Author: ruel
 */

#ifndef PGCDEF_HH_
#define PGCDEF_HH_


//typedef unsigned char TUint8;
//typedef long long TInt64;
//typedef short int TInt16;
//typedef unsigned long int TUint32;
//typedef unsigned long long Uint64;
//typedef	Uint64	TUint64;
//typedef signed int TInt;
//typedef unsigned short int TUint16;
//typedef long int TInt32;
//typedef signed char TInt8;

#define	PGC_PEN_ID						0x0000
#define	PGC_PEN_SOFTWARE_VERSION		0x0001
#define	PGC_DAS_DIF						0x001f
#define	PGC_SYSTEM_TIME					0x0021
#define PGC_VERSION						0x0022
#define PGC_PEN_BRAND					0x0024

#define PGC_PEN_OWNER_LOCALE			0x2009
#define	PGC_PEN_OWNER_VCARD				0x200a
#define PGC_PEN_OWNER_EMAIL				0x200b
#define PGC_PEN_OWNER_CELL_PHONE		0x200c
#define	PGC_MANUFACTURER_DATA			0x0023

#define VALUE_HEADER_TYPE_BOOLEAN		0x01
#define VALUE_HEADER_TYPE_BYTE			0x02
#define VALUE_HEADER_TYPE_SHORT			0x03
#define VALUE_HEADER_TYPE_INTEGER		0x04
#define VALUE_HEADER_TYPE_LONG			0x05
#define VALUE_HEADER_TYPE_UNICODE		0x06

#endif /* PGCDEF_HH_ */
