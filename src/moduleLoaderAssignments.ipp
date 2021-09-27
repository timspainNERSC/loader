        if (module == "Albedo") {
            if (impl == "SNUAlbedo") {
                p_IAlbedo = &newSNUAlbedo;
            } else if (impl == "SNU2Albedo") {
                p_IAlbedo = &newSNU2Albedo;
            } else if (impl == "CCSMAlbedo") {
                p_IAlbedo = &newCCSMAlbedo;
            } else {
                throwup(module, impl);
            }

        } else if (module == "thermodynamics") {
            if (impl == "thermoWinton") {
                p_Ithermodynamics = &newthermoWinton;
            } else if (impl == "thermoIce0") {
                p_Ithermodynamics = &newthermoIce0;
            } else {
                throwup(module, impl);
            }

        } else { }