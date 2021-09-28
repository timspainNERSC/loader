std::unique_ptr<IAlbedo> (*p_IAlbedo)();
template<>
std::unique_ptr<IAlbedo> ModuleLoader::getImplementation() const
{
    return (*p_IAlbedo)();
}
std::unique_ptr<IAlbedo> newSNUAlbedo()
{
    return std::unique_ptr<SNUAlbedo>(new SNUAlbedo);
}
std::unique_ptr<IAlbedo> newSNU2Albedo()
{
    return std::unique_ptr<SNU2Albedo>(new SNU2Albedo);
}
std::unique_ptr<IAlbedo> newCCSMAlbedo()
{
    return std::unique_ptr<CCSMAlbedo>(new CCSMAlbedo);
}

std::unique_ptr<Ithermodynamics> (*p_Ithermodynamics)();
template<>
std::unique_ptr<Ithermodynamics> ModuleLoader::getImplementation() const
{
    return (*p_Ithermodynamics)();
}
std::unique_ptr<Ithermodynamics> newthermoWinton()
{
    return std::unique_ptr<thermoWinton>(new thermoWinton);
}
std::unique_ptr<Ithermodynamics> newthermoIce0()
{
    return std::unique_ptr<thermoIce0>(new thermoIce0);
}

