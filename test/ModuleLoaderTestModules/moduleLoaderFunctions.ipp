std::unique_ptr<ITest> (*p_ITest)();
template<>
std::unique_ptr<ITest> ModuleLoader::getImplementation() const
{
    return (*p_ITest)();
}
std::unique_ptr<ITest> newImpl1()
{
    return std::unique_ptr<ITest>(new Impl1);
}
std::unique_ptr<ITest> newImpl2()
{
    return std::unique_ptr<ITest>(new Impl2);
}
