//Abstract Factory Design Pattern

#include <iostream>
using namespace std;

class Window//Abstract ProductA class that creates interface for concrete Product classess
{
public:
    virtual void window_info() = 0;

    virtual ~Window() {};

};

class PM_Window : public Window//ProductA1
{
public:
    ~PM_Window() {}
    PM_Window()
    {
        cout << "PM_Window created" << endl;
    }
    void window_info()override
    {
        cout << "PM_Window info" << endl;
    }
};
class Motif_Window : public Window//ProductA2
{
public:
    ~Motif_Window() {}
    Motif_Window()
    {
        cout << "Motif_Window created" << endl;
    }
    void window_info()override
    {
        cout << "Motif_Window info" << endl;
    }
};
class ScrollBar//Abstract ProductB class that creates interface for concrete Product classess
{
public:
    virtual void scrollBar_info() = 0;
    virtual ~ScrollBar() {};
};

class PM_ScrollBar : public ScrollBar//ProductB1
{
public:
    ~PM_ScrollBar() {}
    PM_ScrollBar()
    {
        cout << "PM_ScrollBar created" << endl;
    }
    void scrollBar_info()override
    {
        cout << "PM_ScrollBar info" << endl;
    }

};

class Motif_ScrollBar : public ScrollBar//ProductB2
{
public:
    ~Motif_ScrollBar() {}
    Motif_ScrollBar()
    {
        cout << "Motif_ScrollBar created" << endl;
    }
    void scrollBar_info()override
    {
        cout << "Motif_ScrollBar info" << endl;
    }

};
class WidgetFactory//Abstract class that creates interface for concrete Factory classes
{
public:
    virtual ScrollBar* createScrollBar() = 0;
    virtual Window* createWindow() = 0;
    virtual ~WidgetFactory(){}
};

class MotifWidgetFactory: public WidgetFactory
{
public:
    ~MotifWidgetFactory() {}
    
    ScrollBar* createScrollBar() override
    {
        return new Motif_ScrollBar();
    }
    Window* createWindow() override
    {
        return new Motif_Window();
    }

};

class PMWidgetFactory : public WidgetFactory
{
public:
    ~PMWidgetFactory() {}
    ScrollBar* createScrollBar() override
    {
        return new PM_ScrollBar;
    }
    Window* createWindow() override
    {
        return new PM_Window;
    }

};

class Client//Class that uses only interfaces presented by AbstractFactory and AbstractProduct classes
{
private:
    WidgetFactory* widg_fact = nullptr;
    Window* wind = nullptr;
    ScrollBar* scroll = nullptr;

public:
    Client(string type)
    {
        if (type == "motif")
        {
            widg_fact = new MotifWidgetFactory;
            scroll=widg_fact->createScrollBar();
            wind=widg_fact->createWindow();

        }
        else if (type == "PM")
        {
            widg_fact = new PMWidgetFactory;
            scroll=widg_fact->createScrollBar();
            wind=widg_fact->createWindow();
        }
    }
    void getInfo()
    {
        wind->window_info();
        scroll->scrollBar_info();
    }
    ~Client()
    {
        delete scroll;
        delete wind;
        delete widg_fact;
        cout << "scroll,wind, widg_fact destroyed" << endl;
    }
    
};



int main()
{

    Client a("motif");
    a.getInfo();

    Client b("PM");
    b.getInfo();


    return 0;
}

