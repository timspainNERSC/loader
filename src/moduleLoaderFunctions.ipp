std::unique_ptr<I1> (*Impl1)();
template<>
std::unique_ptr<I1> ModuleLoader::getImplementation() const
{
    return (*Impl1)();
}
// Interface1
std::unique_ptr<I1> newImpl11()
{
    return std::unique_ptr<Impl11>(new Impl11);
}
std::unique_ptr<I1> newImpl12()
{
    return std::unique_ptr<Impl12>(new Impl12);
}

std::unique_ptr<I2> (*Impl2)();
template<>
std::unique_ptr<I2> ModuleLoader::getImplementation() const
{
    return (*Impl2)();
}
// Interface2
std::unique_ptr<I2> newImpl21()
{
return std::unique_ptr<Impl21>(new Impl21);
}
std::unique_ptr<I2> newImpl22()
{
return std::unique_ptr<Impl22>(new Impl22);
}
