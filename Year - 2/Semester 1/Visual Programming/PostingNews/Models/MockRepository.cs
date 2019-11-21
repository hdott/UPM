using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PostingNews.Models
{
    public class MockRepository : IPostRepository
    {
        List<Post> _posts;

        public MockRepository()
        {
            if(_posts == null)
            {
                InitializePosts();
            }
        }
        IEnumerable<Post> IPostRepository.GetAllPosts()
        {
            return _posts.AsEnumerable();
            throw new NotImplementedException();
        }

       
        Post IPostRepository.GetPostById(int postId)
        {
            foreach(Post x in _posts)
            {
                if(x.ID == postId)
                {
                    return x;
                }
            }
            throw new NotImplementedException();
        }

        void InitializePosts()
        {
            _posts = new List<Post>();
            _posts.Add(new Post(1,
                                "Why Aren't there C Conferences?",
                                "https://nullprogram.com/blog/2018/11/21/",
                                "Most widely-used programming languages have at least one regular conference dedicated to discussing it.",
                                "alma",
                                new DateTime(2018, 11, 22)));
        }
    }
}
