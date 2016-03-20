using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.System;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Animation;
using Windows.UI.Xaml.Navigation;
using Windows.UI.Popups;

// Шаблон элемента пустой страницы задокументирован по адресу http://go.microsoft.com/fwlink/?LinkId=234238

namespace HelloWorldApp
{
    /// <summary>
    /// Пустая страница, которую можно использовать саму по себе или для перехода внутри фрейма.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        private async void Button_Click(object sender, RoutedEventArgs e)
        {
            var dlg = new MessageDialog("Hello World!", "Head");

            dlg.Commands.Add(new UICommand("Command 1"));

            dlg.Commands.Add(new UICommand("Command 2"));
            dlg.Commands.Add(new UICommand("Command 3") { Id = 3 });

            dlg.DefaultCommandIndex = 1;
            dlg.CancelCommandIndex = 2;
            var command = await dlg.ShowAsync();
            //this.Frame.Navigate(typeof(SecondPage));

        }

        private void HyperlinkButton_Click(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(SecondPage), "string");
        }

        private void HyperlinkButton_Click_1(object sender, RoutedEventArgs e)
        {
            this.Frame.Navigate(typeof(SplitPage1));
        }

        private async void HyperlinkButton_Click_2(object sender, RoutedEventArgs e)
        {
            //var opts = new LauncherOptions();
            //opts.TreatAsUntrusted = true; //доверенная ссылка?
            //opts.DisplayApplicationPicker = true; //диалог выбора приложения
            //opts.PreferredApplicationDisplayName = "Мое приложение";
            //opts.PreferredApplicationPackageFamilyName = "My ApplicationFamilyName";

            //var success = await Launcher.LaunchUriAsync(new Uri("http://vk.com/feed"), opts);
        }
    }
}
