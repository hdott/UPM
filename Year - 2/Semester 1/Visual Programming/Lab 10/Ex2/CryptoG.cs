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
        public static void Criptare(string fileIn)
        {
            FileStream fin = new FileStream(fileIn, FileMode.Open, FileAccess.Read);
            FileStream fout = new FileStream(fileIn + ".enc", FileMode.OpenOrCreate, FileAccess.Write);
            AesCryptoServiceProvider cryptoProvider = new AesCryptoServiceProvider();
            encKey = cryptoProvider.Key;
            encIV = cryptoProvider.IV;
            saveKeys();
            ICryptoTransform encryptor = cryptoProvider.CreateEncryptor();
            CryptoStream stream = new CryptoStream(fout, encryptor, CryptoStreamMode.Write);
            byte[] input = new byte[128];
            int inLen = -1;
            while ((inLen = fin.Read(input, 0, 128)) > 0)
            {
                stream.Write(input, 0, inLen);
            }
            stream.Close();
            fout.Close();
            fin.Close();
        }

        public static void Decriptare(string fileIn)
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
            byte[] input = new byte[128];
            int inLen = -1;
            while((inLen = fin.Read(input, 0, 128)) > 0)
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
    }
}
