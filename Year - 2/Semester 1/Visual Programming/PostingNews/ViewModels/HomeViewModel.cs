using PostingNews.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PostingNews.ViewModels
{
    public class HomeViewModel
    {
        public string Title { get; set; }
        public List<Post> Posts { get; set; }
        //public string URL { get; set; }
        //public string Description { get; set; }
    }
}
