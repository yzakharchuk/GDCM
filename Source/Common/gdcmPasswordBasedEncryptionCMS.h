#ifndef gdcmPasswordBasedEncryptionCMS_H
#define gdcmPasswordBasedEncryptionCMS_H

#include <iostream>
using namespace std;

#include "gdcmTypes.h"

namespace gdcm
{
class GDCM_EXPORT PasswordBasedEncryptionCMS
{
public:
  PasswordBasedEncryptionCMS() : cipherType(AES128_CIPHER)
  {
  }

  typedef enum {
    DES_CIPHER,    // DES
    DES3_CIPHER,   // Triple DES
    AES128_CIPHER, // CBC AES
    AES192_CIPHER, // '   '
    AES256_CIPHER  // '   '
  } CipherTypes;

  virtual void SetPassword(const char * pass) = 0; // For null-terminated strings
  virtual void SetPassword(const char * pass, size_t passLen) = 0; //For general binary data

  /// create a PKCS#7 envelopedData structure
  virtual bool Encrypt(char *output, size_t &outlen, const char *array, size_t len) const = 0;
  virtual bool Decrypt(char *output, size_t &outlen, const char *array, size_t len) const = 0;

  virtual void SetCipherType(CipherTypes type)
  {
    cipherType = type;
  }

  //TODO: virtual ???
  CipherTypes GetCipherType() const
  {
    return cipherType;
  }

protected:
  CipherTypes cipherType;

};
}

#endif //gdcmOpenSSLPasswordBasedEncryptionCMS_H