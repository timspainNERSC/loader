        if (module == "Interface1") {
            if (impl == "Impl11") {
                Impl1 = &newImpl11;
            } else if (impl == "Impl12") {
                Impl1 = &newImpl12;
            } else {
                throwup(module, impl);
            }

        } else if (module == "Interface2") {
            if (impl == "Impl21") {
                Impl2 = &newImpl21;
            } else if (impl == "Impl22") {
                Impl2 = &newImpl22;
            } else {
                throwup(module, impl);
            }
        }
