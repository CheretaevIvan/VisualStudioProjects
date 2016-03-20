using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using GameStore.Domain.Abstract;
using GameStore.Domain.Entities;


namespace GameStore.WebUI.Controllers
{
    public class GameController : Controller
    {
        private IGameRepository repository;
        // GET: Game
        public GameController(IGameRepository repo)
        {
            repository = repo;
        }

        public ViewResult List()
        {
            int count = repository.Subjects.Count();

            return View(repository.Subjects);
        }
    }
}