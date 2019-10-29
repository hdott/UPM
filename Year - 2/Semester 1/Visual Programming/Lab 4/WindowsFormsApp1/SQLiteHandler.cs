using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public sealed class SQLiteHandler
    {
        private static SQLiteHandler instance = null;
        private static readonly object padlock = new object();
        private static SQLiteConnection _conn = null;
        private string initStatement = "CREATE TABLE IF NOT EXISTS Keywords" +
                                        "(id INTEGER PRIMARY KEY AUTOINCREMENT," +
                                        "keywords TEXT)";

        public static SQLiteHandler Instance
        {
            get
            {
                lock(padlock)
                    if(instance == null)
                    {
                        instance = new SQLiteHandler();
                    }

                return instance;
            }
        }

        public void ConnectToDb()
        {
            if (!File.Exists("MyDatabase.sqlite"))
            {
                SQLiteConnection.CreateFile("MyDatabase.sqlite");
            }

            _conn = new SQLiteConnection("DataSource=MyDatabase.sqlite;" +
                "                                   Version=3;");
            _conn.Open();
        }

        public void DisconnectFromDb()
        {
            if(_conn != null)
            {
                _conn.Close();
                _conn.Dispose();
                _conn = null;
            }
        }

        public void InsertKeyword(string k)
        {
            SQLiteCommand init = new SQLiteCommand(initStatement, _conn);
            try
            {
                init.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Unable to create table!\nERROR: " + ex.ToString());
            }

            string insertKey = $"INSERT INTO Keywords(keywords) VALUES('" +
                                k + "')";
            SQLiteCommand insert = new SQLiteCommand(insertKey, _conn);
            try
            {
                insert.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Unable to insert into table!\nERROR: " + ex.ToString());
            }
        }

        public List<string> GetAllKeywords(bool st)
        {
            string getKey = "SELECT * FROM Keywords";
            SQLiteCommand get = new SQLiteCommand(getKey, _conn);
            SQLiteDataReader reader = null;
            try
            {
                reader = get.ExecuteReader();
            }
            catch(Exception ex)
            {
                MessageBox.Show("Unable to read from the table!\nERROR: " + ex.ToString());
            }

            
            string data = "";
            for (int i = 0; i < reader.FieldCount; ++i)
            {
                data += reader.GetName(i) + "\t";
            }
            data += "\n";
            List<string> list = new List<string>();

            //data += "DATA: \n";
            while (reader.Read())
            {
                string tmp;
                data += reader.GetInt32(0).ToString() + "\t";
                data += (tmp = reader.GetString(1));
                list.Add(tmp);
                data += "\n";
            }
            reader.Close();

            if (st)
            {
                MessageBox.Show(data);
            }
            
            return list;
        }

        public bool isOpen()
        {
            if(_conn != null)
            {
                return true;
            }

            return false;
        }

        public bool isClose()
        {
            if(_conn == null)
            {
                return true;
            }

            return false;
        }
    }
}
