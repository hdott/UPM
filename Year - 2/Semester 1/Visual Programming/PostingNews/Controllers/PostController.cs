using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using PostingNews.Models;
using PostingNews.ViewModels;

// For more information on enabling MVC for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace PostingNews.Controllers
{
    public class PostController : Controller
    {
        private readonly IPostRepository _postRepository;

        public PostController(IPostRepository postRepository)
        {
            _postRepository = postRepository;
        }
        // GET: /<controller>/
        public IActionResult Index()
        {
            var posts = _postRepository.GetAllPosts();
            var postViewModel = new PostViewModel();
            postViewModel.Posts = posts.OrderByDescending(o => o.DATEADD).ToList();
            return View(postViewModel);
        }
    }
}
