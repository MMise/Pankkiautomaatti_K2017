#ifndef RFID_GLOBAL_H
#define RFID_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RFID_LIBRARY)
#  define RFIDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RFIDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RFID_GLOBAL_H
