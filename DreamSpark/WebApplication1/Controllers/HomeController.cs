using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using GameStore.Domain.Abstract;
using GameStore.Domain.Concrete;
using GameStore.Domain.Entities;
using System.IO;
using ExcelReader;

namespace WebApplication1.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Index(IEnumerable<HttpPostedFileBase> fileUpload)
        {
            foreach (var file in fileUpload)
            {
                if (file == null) continue;
                string path = AppDomain.CurrentDomain.BaseDirectory + "UploadedFiles\\";
                string filename = Path.GetFileName(file.FileName);
                if (filename != null) file.SaveAs(Path.Combine(path, filename));
                byte[] avatar = new byte[file.ContentLength];
                file.InputStream.Read(avatar, 0, file.ContentLength);
                MemoryStream stream = new MemoryStream(avatar);
                IEnumerable<Subject> subjs = TryExcelReader.startParse(stream);
                TempData["subjects"] = subjs;
                return RedirectToAction("List");
            }

            return RedirectToAction("Index");
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }

        public ViewResult List()
        {
            IEnumerable<Subject> Subjects = (IEnumerable<Subject>)TempData.Peek("subjects");
            //return View(new List<Subject>{new Subject{Name="Subject1", Points=100, Semestr="Весенний семестр"}, new Subject{Name="Subject2", Points=90}});
            return View(Subjects);
        }
    }
}