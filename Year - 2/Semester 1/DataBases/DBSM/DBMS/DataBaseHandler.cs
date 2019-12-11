using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SQLite;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBMS
{
    public sealed class DataBaseHandler
    {
        private static DataBaseHandler instance = null;
        private static readonly object padlock = new object();
        private SQLiteConnection dbConn = null;

        public static DataBaseHandler Instance
        {
            get
            {
                lock (padlock)
                {
                    if(instance == null)
                    {
                        instance = new DataBaseHandler();
                    }
                }

                return instance;
            }
        }

        public bool NewDataBase(string path)
        {
            if(dbConn == null)
            {
                if (!File.Exists(path))
                {
                    SQLiteConnection.CreateFile(Path.GetFileName(path));
                    dbConn = new SQLiteConnection($"DataSource='{Path.GetFileName(path)}'Version=3");
                    //dbConn
                    dbConn.Open();

                    return true;
                }
                else
                {
                    return false;
                }
            }

            return false;
        }

        public bool OpenDataBase(string path)
        {
            if(dbConn == null)
            {
                dbConn = new SQLiteConnection($"DataSource='{Path.GetFileName(path)}'Version=3");
                dbConn.Open();

                return true;
            }

            return false;
        }

        public bool DisconnectDataBase()
        {
            if(dbConn != null)
            {
                dbConn.Close();
                dbConn.Dispose();
                dbConn = null;

                return true;
            }

            return false;
        }

        public bool CreateTableCommand(string cmd)
        {
            SQLiteCommand command = new SQLiteCommand(cmd, dbConn);

            try
            {
                command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return false;
            }

            return true;
        }

        public bool ModifyCommand(string cmd)
        {
            SQLiteCommand command = new SQLiteCommand(cmd, dbConn);

            try
            {
                command.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
                return false;
            }

            return true;
        }

        public DataTable ReadCommand(string cmd)
        {
            DataTable dt = new DataTable();

            try
            {
                SQLiteDataAdapter adapter = new SQLiteDataAdapter(cmd, dbConn);
                adapter.Fill(dt);
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
                return null;
            }
            

            return dt;
        }
    }
}
