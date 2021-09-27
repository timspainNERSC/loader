        if (module == "I1") {
            if (impl == "Impl11") {
                p_I1 = &newImpl11;
            } else if (impl == "Impl12") {
                p_I1 = &newImpl12;
            } else {
                throwup(module, impl);
            }

        } else if (module == "I2") {
            if (impl == "Impl21") {
                p_I2 = &newImpl21;
            } else if (impl == "Impl22") {
                p_I2 = &newImpl22;
            } else {
                throwup(module, impl);
            }
        }
