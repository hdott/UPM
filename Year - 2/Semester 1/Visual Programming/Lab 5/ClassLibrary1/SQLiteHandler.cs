using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.IO;
using System.Text;

namespace DatabaseHandler
{
    public sealed class SQLiteHandler
    {
        private static SQLiteHandler instance = null;
        private static readonly object padlock = new object();
        private SQLiteConnection dbConexion = null;
   
        public static SQLiteHandler Instance
        {
            get
            {
                lock (padlock)
                {
                    if(instance == null)
                    {
                        instance = new SQLiteHandler();
                    }
                }

                return instance;
            }
        }

        public bool ConnectToDb()
        {
            if(dbConexion == null)
            {
                if (!File.Exists("mydb.sqlite"))
                {
                    SQLiteConnection.CreateFile("mydb.sqlite");
                }

                dbConexion = new SQLiteConnection("DataSource=mydb.sqliteVersion=3;");
                dbConexion.Open();
                return true;
            }

            return false;
        }

        public void DisconnectFromDb()
        {
            if(dbConexion != null)
            {

            }
        }
    }
}