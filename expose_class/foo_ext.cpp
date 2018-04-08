#include "foo.h"

#include <boost/python.hpp>

using namespace boost::python;

// inherit from wrapper<Bar> so that the Bar::fun() can 
// be override in python
struct BarWrap : public Bar, public wrapper<Bar>
{
    BarWrap() : Bar("bar_wrap1") {}
    std::string fun()
    {
        if (override fun = this->get_override("fun"))
        {
            return fun();
        }
        else
        {
            return Bar::fun();
        }
    }

    std::string default_fun()
    {
        return this->Bar::fun();
    }
};


BOOST_PYTHON_MODULE(foo_ext)
{
    class_<Foo>("Foo", init<const std::string&>())
    // access to the member function
        .def("name", &Foo::name)
        .def("change_name", &Foo::change_name)
        .def("fun", &Foo::fun)
    // access to the member variable    
        .def_readonly("read_only_name", &Foo::m_read_only_name)
        .def_readwrite("read_write_name", &Foo::m_read_write_name)
        ;

    class_<Bar, bases<Foo> >("Bar", init<const std::string&>())
        .def("fun", &Bar::fun)
        ;

    class_<BarWrap, boost::noncopyable >("BarWrap")
        .def("fun", &Bar::fun, &BarWrap::default_fun)
        ;

}