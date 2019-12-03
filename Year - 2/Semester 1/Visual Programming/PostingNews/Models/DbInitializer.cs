using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PostingNews.Models
{
    public class DbInitializer
    {
        public static void Seed(AppDbContext context)
        {
            if (!context.Posts.Any())
            {
                context.AddRange(
                    //copy data
                    new Post
                    {
                        Id = 1,
                        Title = "Why Aren't There C Conferences?",
                        URL = "https://nullprogram.com/blog/2018/11/21/",
                        Description = "Most widely-used programming languages have at least one regular conference dedicated to discussing it.",
                        DateAdded = new DateTime(2018, 11, 22),
                        User = "alma"
                    },
                    new Post
                    {
                        Id = 2,
                        Title = "Why Aren't There C Conferences?.2",
                        URL = "https://nullprogram.com/blog/2018/11/21/",
                        Description = "Most widely-used programming languages have at least one regular conference dedicated to discussing it.",
                        DateAdded = new DateTime(2018, 11, 22),
                        User = "alma"
                    }
                    );
                context.SaveChanges();
            }
        }
    }
}
