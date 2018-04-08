#pragma once

#include <string>

struct Foo
{
    explicit Foo(const std::string& name)
        : m_name(name) {}

    virtual ~Foo() {}

    std::string name() const
    {
        return m_name;
    }

    void change_name(const std::string& name)
    {
        m_name = name;
    }

    virtual std::string fun()
    {
        return "Foo";
    }

    std::string m_name;

    std::string m_read_only_name;
    std::string m_read_write_name;
};


struct Bar : public Foo
{
    using Foo::Foo;

    std::string fun() override
    {
        return "Bar";
    }
};