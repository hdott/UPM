﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using PostingNews.Models;
using PostingNews.ViewModels;

// For more information on enabling MVC for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace PostingNews.Controllers
{
    public class HomeController : Controller
    {
        private readonly IPostRepository _postRepository;

        public HomeController(IPostRepository postRepository)
        {
            _postRepository = postRepository;
        }

        // GET: /<controller>/
        public IActionResult Index()
        {
            ViewBag.Title = "Posting news overview";
            //var posts = _postRepository.GetAllPosts();

            //return View(posts);
            var posts = _postRepository.GetAllPosts();
            var homeViewModel = new HomeViewModel()
            {
                Title = "News",
                Posts = posts.ToList()
            };

            return View(homeViewModel);
        }

        public IActionResult Details(int id)
        {
            var post = _postRepository.GetPostById(id);

            return View(post);
        }
    }
}
