using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PostingNews.Models
{
    public interface IPostRepository
    {
        IEnumerable<Post> GetAllPosts();
        Post GetPostById(int postId);
    }
}
