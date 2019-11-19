using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PostingNews.Models
{
    public class Post
    {
        int Id;
        string Title;
        string url;
        string Description;
        string User;
        DateTime DateAdded;

        public Post(int id, string title, string URL, string descr, string user, DateTime date)
        {
            Id = id;
            Title = title;
            url = URL;
            Description = descr;
            User = user;
            DateAdded = date;
        }

        public int ID { get { return Id; } set { Id = value; } }
        public string TITLE { get { return Title; } set { Title = value; } }
        public string URL{ get { return url; } set { url = value; } }
        public string USER { get { return User; } set { User = value; } }
        public string DESCRIPTION { get { return Description; } set { Description = value; } }
        public DateTime DATEADD{ get { return DateAdded; } set { DateAdded = value; } }

    }
}
