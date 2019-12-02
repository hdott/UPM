using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PostingNews.Models
{
    public class MockRepository : IPostRepository
    {
        public List<Post> list { get; set; }

        public MockRepository()
        {
            if(list == null)
            {
                InitializePosts();
            }
        }

        void InitializePosts()
        {
            list = new List<Post>();
            list.Add(new Post
            {
                Id = 1,
                Title = "Why Aren't There C Conferences?",
                URL = "https://nullprogram.com/blog/2018/11/21/",
                Description = "Most widely-used programming languages have at least one regular conference dedicated to discussing it.",
                DateAdded = new DateTime(2018, 11, 22),
                User = "alma"
            });
        }

        public IEnumerable<Post> GetAllPosts()
        {
            return list.AsEnumerable();
            //throw new NotImplementedException();
        }

        public Post GetPostById(int postId)
        {
            foreach (Post post in list)
            {
                if (post.Id == postId)
                {
                    return post;
                }
            }
            return null;
            //throw new NotImplementedException();
        }
    }
}
