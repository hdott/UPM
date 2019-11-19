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
        private SQLiteConnection dbConnection = null;

        public class User
        {
            public string Nume { get; set; }
            public string Prenume { get; set; }
            public string Adresa { get; set; }
            public string CNP { get; set; }
        }

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
            bool _exists = File.Exists("mydb.sqlite");
            if(dbConnection == null)
            {

                if (!File.Exists("mydb.sqlite"))
                {
                    SQLiteConnection.CreateFile("mydb.sqlite");
                }

                dbConnection = new SQLiteConnection("DataSource=mydb.sqliteVersion=3;");
                dbConnection.Open();

                if (!_exists)
                {
                    initDb();
                }

                return true;
            }

            return false;
        }

        public bool DisconnectFromDb()
        {
            if(dbConnection != null)
            {
                dbConnection.Close();
                dbConnection.Dispose();
                dbConnection = null;
                return true;
            }
            return false;
        }

        private void initDb()
        {
            string _init = "CREATE TABLE IF NOT EXISTS Users(id INTEGER PRIMARY KEY" +
                            " AUTOINCREMENT, nume TEXT, prenume TEXT, adresa TEXT, CNP TEXT)";
            SQLiteCommand init = new SQLiteCommand(_init, dbConnection);

            try
            {
                init.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                Console.Error.WriteLine("Unable to create table!\n");
                Console.Error.WriteLine(ex);
            }
        }

        public bool InsertUser(string nume, string prenume, string adresa, string CNP)
        {
            string _insert = "INSERT INTO Users(nume, prenume, adresa, CNP) VALUES(" +
                            $"{nume}, {prenume}, {adresa}, {CNP})";

            SQLiteCommand insert = new SQLiteCommand(_insert, dbConnection);
            try
            {
                insert.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                Console.Error.WriteLine("Unable to insert into table!\n");
                Console.Error.WriteLine(ex);
                return false;
            }
            return true;
        }

        public bool DeleteUser(string CNP)
        {
            string _delete = $"DELETE FROM Users WHERE CNP = {CNP}";

            SQLiteCommand delete = new SQLiteCommand(_delete, dbConnection);
            try
            {
                delete.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.Error.WriteLine("Unable to delete from table!\n");
                Console.Error.WriteLine(ex);
                return false;
            }
            return true;
        }

        public User ExistsUser(string CNP)
        {
            string _find = $"SELECT EXISTS DISTINCT FROM Users WHERE CNP = {CNP}";

            SQLiteCommand find = new SQLiteCommand(_find, dbConnection);
            SQLiteDataReader reader = null;
            try
            {
                reader = find.ExecuteReader();
            }
            catch(Exception ex)
            {
                Console.Error.WriteLine("Unable to find Where CNP in table!\n");
                Console.Error.WriteLine(ex);
            }

            User user = new User();
            reader.Read();
            if (reader.HasRows)
            {
                user.Nume = reader.GetString(1);
                user.Prenume = reader.GetString(2);
                user.Adresa = reader.GetString(3);
                user.CNP = reader.GetString(4);
                reader.Close();
                return user;
            }
            reader.Close();
            return null;
        }

        public User ExistsUser(string nume, string prenume)
        {
            string _find = $"SELECT EXISTS FROM Users WHERE nume = {nume} AND" +
                            $" prenume = {prenume}";

            SQLiteCommand find = new SQLiteCommand(_find, dbConnection);
            SQLiteDataReader reader = null;
            try
            {
                reader = find.ExecuteReader();
            }
            catch (Exception ex)
            {
                Console.Error.WriteLine("Unable to find Where nume & prenume in table!\n");
                Console.Error.WriteLine(ex);
            }

            User user = new User();
            reader.Read();
            if (reader.HasRows)
            {
                user.Nume = reader.GetString(1);
                user.Prenume = reader.GetString(2);
                user.Adresa = reader.GetString(3);
                user.CNP = reader.GetString(4);
                reader.Close();
                return user;
            }
            reader.Close();
            return null;
        }

        public List<User> GetAllUsers()
        {
            List<User> listU = new List<User>();
            string _getAll = "SELECT * FROM Users";

            SQLiteCommand getAll = new SQLiteCommand(_getAll, dbConnection);
            SQLiteDataReader reader = null;
            try
            {
                reader = getAll.ExecuteReader();
            }
            catch (Exception ex)
            {
                Console.Error.WriteLine("Unable to find Where ALL in table!\n");
                Console.Error.WriteLine(ex);
            }

            while (reader.Read())
            {
                User user = new User();
                user.Nume = reader.GetString(1);
                user.Prenume = reader.GetString(2);
                user.Adresa = reader.GetString(3);
                user.CNP = reader.GetString(4);
                listU.Add(user);
            }

            return listU;
        }
    }
}