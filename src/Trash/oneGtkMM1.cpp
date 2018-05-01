#include </usr/include/gtkmm-3.0/gtkmm.h>

int main(int argc, char* argv[])
{
    auto application = Gtk::Application::create(argc, argv,"MyFirstWindowOnLinux");
    Gtk::Window window;
    window.set_default_size(1000,1000);


    return application->run(window);
}




/*g++ /home/bomb/proga/gtkmm.cpp -o gtkmm `pkg-config gtkmm-3.0 --cflags --libs`
*/
