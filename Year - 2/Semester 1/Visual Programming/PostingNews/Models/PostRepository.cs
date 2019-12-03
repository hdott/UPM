using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PostingNews.Models
{
    public class PostRepository : IPostRepository
    {
        private readonly AppDbContext _appDbContext;
        
        public PostRepository(AppDbContext appDbContext)
        {
            _appDbContext = appDbContext;
        }

        public void AddNewPost(Post post)
        {
            _appDbContext.Posts.Add(post);
            _appDbContext.SaveChanges();
            //throw new NotImplementedException();
        }

        public IEnumerable<Post> GetAllPosts()
        {
            return _appDbContext.Posts;
            //throw new NotImplementedException();
        }

        public Post GetPostById(int postId)
        {
            return _appDbContext.Posts.FirstOrDefault(p => p.Id == postId);
            //throw new NotImplementedException();
        }
    }
}
