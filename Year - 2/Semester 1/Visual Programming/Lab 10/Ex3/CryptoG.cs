using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Ex1
{
    class CryptoG
    {
        private static byte[] encKey;
        private static byte[] encIV;

        public static void Criptare(string path, string serviceP, int size)
        {
            if (serviceP.Equals("AES"))
            {
                CriptareAES(path, size);
            }else if (serviceP.Equals("DES")){
                CriptareDES(path, size);
            }else if (serviceP.Equals("3DES"))
            {
                Criptare3DES(path, size);
            }
        }

        public static void Decriptare(string path, string serviceP, int size)
        {
            if (serviceP.Equals("AES"))
            {
                DecriptareAES(path, size);
            }
            else if (serviceP.Equals("DES"))
            {
                DecriptareDES(path, size);
            }
            else if (serviceP.Equals("3DES"))
            {
                Decriptare3DES(path, size);
            }
        }
        private static void CriptareAES(string fileIn, int size)
        {
            FileStream fin = new FileStream(fileIn, FileMode.Open, FileAccess.Read);
            FileStream fout = new FileStream(fileIn + ".enc", FileMode.OpenOrCreate, FileAccess.Write);
            AesCryptoServiceProvider cryptoProvider = new AesCryptoServiceProvider();
            encKey = cryptoProvider.Key;
            encIV = cryptoProvider.IV;
            saveKeys();
            ICryptoTransform encryptor = cryptoProvider.CreateEncryptor();
            CryptoStream stream = new CryptoStream(fout, encryptor, CryptoStreamMode.Write);
            byte[] input = new byte[size];
            int inLen = -1;
            while ((inLen = fin.Read(input, 0, size)) > 0)
            {
                stream.Write(input, 0, inLen);
            }
            stream.Close();
            fout.Close();
            fin.Close();
        }

        private static void DecriptareAES(string fileIn, int size)
        {
            FileStream fin = new FileStream(fileIn, FileMode.Open, FileAccess.Read);
            string fileOut = fileIn.Substring(0, fileIn.Length - 4);
            string ext = fileOut.Substring(fileOut.Length - 4);
            fileOut = fileOut.Substring(0, fileOut.Length - 4);
            FileStream fout = new FileStream(fileOut + "DEC" + ext, FileMode.OpenOrCreate, FileAccess.Write);
            AesCryptoServiceProvider cryptoProvider = new AesCryptoServiceProvider();
            readKeys();
            ICryptoTransform decryptor = cryptoProvider.CreateDecryptor(encKey, encIV);
            CryptoStream stream = new CryptoStream(fout, decryptor, CryptoStreamMode.Write);
            byte[] input = new byte[size];
            int inLen = -1;
            while((inLen = fin.Read(input, 0, size)) > 0)
            {
                stream.Write(input, 0, inLen);
            }
            stream.Close();
            fout.Close();
            fin.Close();
        }

        private static void saveKeys()
        {
            File.WriteAllBytes("encKey.dat", encKey);
            File.WriteAllBytes("encIV.dat", encIV);
        }

        private static void readKeys()
        {
            encKey = File.ReadAllBytes("encKey.dat");
            encIV = File.ReadAllBytes("encIV.dat");
        }

        private static void CriptareDES(string fileIn, int size)
        {
            FileStream fin = new FileStream(fileIn, FileMode.Open, FileAccess.Read);
            FileStream fout = new FileStream(fileIn + ".enc", FileMode.OpenOrCreate, FileAccess.Write);
            DESCryptoServiceProvider cryptoProvider = new DESCryptoServiceProvider();
            encKey = cryptoProvider.Key;
            encIV = cryptoProvider.IV;
            saveKeys();
            ICryptoTransform encryptor = cryptoProvider.CreateEncryptor();
            CryptoStream stream = new CryptoStream(fout, encryptor, CryptoStreamMode.Write);
            byte[] input = new byte[size];
            int inLen = -1;
            while ((inLen = fin.Read(input, 0, size)) > 0)
            {
                stream.Write(input, 0, inLen);
            }
            stream.Close();
            fout.Close();
            fin.Close();
        }

        private static void DecriptareDES(string fileIn, int size)
        {
            FileStream fin = new FileStream(fileIn, FileMode.Open, FileAccess.Read);
            string fileOut = fileIn.Substring(0, fileIn.Length - 4);
            string ext = fileOut.Substring(fileOut.Length - 4);
            fileOut = fileOut.Substring(0, fileOut.Length - 4);
            FileStream fout = new FileStream(fileOut + "DEC" + ext, FileMode.OpenOrCreate, FileAccess.Write);
            DESCryptoServiceProvider cryptoProvider = new DESCryptoServiceProvider();
            readKeys();
            ICryptoTransform decryptor = cryptoProvider.CreateDecryptor(encKey, encIV);
            CryptoStream stream = new CryptoStream(fout, decryptor, CryptoStreamMode.Write);
            byte[] input = new byte[size];
            int inLen = -1;
            while ((inLen = fin.Read(input, 0, size)) > 0)
            {
                stream.Write(input, 0, inLen);
            }
            stream.Close();
            fout.Close();
            fin.Close();
        }

        private static void Criptare3DES(string fileIn, int size)
        {
            FileStream fin = new FileStream(fileIn, FileMode.Open, FileAccess.Read);
            FileStream fout = new FileStream(fileIn + ".enc", FileMode.OpenOrCreate, FileAccess.Write);
            TripleDESCryptoServiceProvider cryptoProvider = new TripleDESCryptoServiceProvider();
            encKey = cryptoProvider.Key;
            encIV = cryptoProvider.IV;
            saveKeys();
            ICryptoTransform encryptor = cryptoProvider.CreateEncryptor();
            CryptoStream stream = new CryptoStream(fout, encryptor, CryptoStreamMode.Write);
            byte[] input = new byte[size];
            int inLen = -1;
            while ((inLen = fin.Read(input, 0, size)) > 0)
            {
                stream.Write(input, 0, inLen);
            }
            stream.Close();
            fout.Close();
            fin.Close();
        }

        private static void Decriptare3DES(string fileIn, int size)
        {
            FileStream fin = new FileStream(fileIn, FileMode.Open, FileAccess.Read);
            string fileOut = fileIn.Substring(0, fileIn.Length - 4);
            string ext = fileOut.Substring(fileOut.Length - 4);
            fileOut = fileOut.Substring(0, fileOut.Length - 4);
            FileStream fout = new FileStream(fileOut + "DEC" + ext, FileMode.OpenOrCreate, FileAccess.Write);
            TripleDESCryptoServiceProvider cryptoProvider = new TripleDESCryptoServiceProvider();
            readKeys();
            ICryptoTransform decryptor = cryptoProvider.CreateDecryptor(encKey, encIV);
            CryptoStream stream = new CryptoStream(fout, decryptor, CryptoStreamMode.Write);
            byte[] input = new byte[size];
            int inLen = -1;
            while ((inLen = fin.Read(input, 0, size)) > 0)
            {
                stream.Write(input, 0, inLen);
            }
            stream.Close();
            fout.Close();
            fin.Close();
        }
    }
}
