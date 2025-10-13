#pragma once

#include <vector>

class Context;

class ContextContainer
{
public:
    void Add(Context *context) { contents_.push_back(context); }
    void Create()
    {
        for (auto c : contents_)
        {
            c->Create();
        }
    }
    void Destroy()
    {
        for (auto c : contents_)
        {
            c->Destroy();
        }
    }
    // Data members
    std::vector<Context *> contents_;
};

class Context
{
public:
    virtual void Create() = 0;
    virtual void Destroy() = 0;
};