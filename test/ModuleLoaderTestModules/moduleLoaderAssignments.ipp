        if (module == "ITest") {
            if (impl == "Impl1") {
                p_ITest = &newImpl1;
            } else if (impl == "Impl2") {
                p_ITest = &newImpl2;
            } else {
                throwup(module, impl);
            }
        } else { }
