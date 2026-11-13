using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace D12Editor.GameProject
{
    /// <summary>
    /// Interaction logic for ProjectBrowserDialg.xaml
    /// </summary>
    public partial class ProjectBrowserDialog : Window
    {
        private readonly CubicEase _easing = new() { EasingMode = EasingMode.EaseInOut };
        public ProjectBrowserDialog()
        {
            InitializeComponent();
            Loaded += OnProjectBrowserDialogLoaded;
        }

        private void OnProjectBrowserDialogLoaded(object sender, RoutedEventArgs e)
        {
            Loaded -= OnProjectBrowserDialogLoaded;
            if (!OpenProject.Projects.Any())
            {
                openProjectButton.IsEnabled = false;
                openProjectView.Visibility = Visibility.Hidden;
                OnToggleButton_Click(createProjectButton, new RoutedEventArgs());
            }
        }

        private void AnimateToCreateProject()
        {
            var higlightAnim = new DoubleAnimation(131, 409, new Duration(TimeSpan.FromSeconds(0.2)));
            var animation = new ThicknessAnimation(new Thickness(0), new Thickness(-1600, 0, 0, 0), new Duration(TimeSpan.FromSeconds(0.5)));
            animation.EasingFunction = _easing;
            browserContent.BeginAnimation(MarginProperty, animation);

            highlightRect.BeginAnimation(Canvas.LeftProperty, higlightAnim);
        }

        private void AnimateToOpenProject()
        {
            var higlightAnim = new DoubleAnimation(409, 131, new Duration(TimeSpan.FromSeconds(0.2)));
            var animation = new ThicknessAnimation(new Thickness(-1600, 0, 0, 0), new Thickness(0), new Duration(TimeSpan.FromSeconds(0.5)));
            animation.EasingFunction = _easing;
            browserContent.BeginAnimation(MarginProperty, animation);

            highlightRect.BeginAnimation(Canvas.LeftProperty, higlightAnim);
        }

        private void OnToggleButton_Click(object sender, RoutedEventArgs e)
        {
            if (sender == openProjectButton)
            {
                if (createProjectButton.IsChecked == true)
                {
                    createProjectButton.IsChecked = false;
                    AnimateToOpenProject();
                    openProjectView.IsEnabled = true;
                    newProjectView.IsEnabled = false;
                }
                openProjectButton.IsChecked = true;
            }
            else
            {
                if (openProjectButton.IsChecked == true)
                {
                    openProjectButton.IsChecked = false;
                    AnimateToCreateProject();
                    newProjectView.IsEnabled = true;
                    openProjectView.IsEnabled = false;
                }
                createProjectButton.IsChecked = true;
            }
        }
    }
}
