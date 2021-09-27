def iName(name):
    return "I" + name
            
def pName(i_name):
    return "p_" + i_name

def fName(impl):
    return "new" + impl

def headers(all_implementations, ipp_prefix, hpp_prefix):
    with open(ipp_prefix + "moduleLoaderHeaders.ipp", "w") as f:
        for interface in all_implementations:
            i_name = iName(interface["name"])
            f.write("#include \"" + hpp_prefix + i_name + ".hpp\"\n")
            for impl in interface["implementations"]:
                f.write("#include \"" +hpp_prefix + impl + ".hpp\"\n")
            # An extra line between interfaces
            f.write("\n")

def functions(all_implementations, ipp_prefix):
    with open(ipp_prefix + "moduleLoaderFunctions.ipp", "w") as f:
        for interface in all_implementations:
            # Define the pointer to function
            i_name = iName(interface["name"])
            p_name = pName(i_name)
            f.write("std::unique_ptr<" + i_name + "> (*" + p_name + ")();\n")
            # Define function that call the function pointer
            f.write(
                "template<>\n" +
                "std::unique_ptr<" + i_name + "> ModuleLoader::getImplementation() const\n" +
                "{\n" +
                "    return (*" + p_name + ")();\n" +
                "}\n"
                )
            for impl in interface["implementations"]:
                f.write("// " + impl + "\n")
                # The function that return the new unique_ptr for each implementation
                f.write(
                    "std::unique_ptr<" + i_name + "> " + fName(impl) + "()\n" +
                    "{\n" +
                    "    return std::unique_ptr<" + impl + ">(new " + impl + ");\n" +
                    "}\n"
                    )
            # An extra line between interfaces
            f.write("\n")

def names(all_implementations, ipp_prefix):
    with open(ipp_prefix + "moduleLoaderNames.ipp", "w") as f:
        f.write(
            "    m_availableImplementationNames = {\n" +
            "        "
            )
        for interface in all_implementations:
            name = interface["name"]
            f.write(
                "{\n" +
                "        \"" + name + "\", {\n"
                )
            for impl in interface["implementations"]:
                f.write("            \"" + impl + "\",\n")
            f.write(
                "            }\n" +
                "        },"
                )
        f.write("\n    };\n")
        

def assignments(all_implementations, ipp_prefix):
    with open(ipp_prefix + "moduleLoaderAssignments.ipp", "w") as f:
        f.write("        ")
        for interface in all_implementations:
            name = interface["name"]
            i_name = iName(name)
            f.write(
                "if (module == \"" + name + "\") {\n" +
                "            "
                )
            p_name = pName(i_name)
            for impl in interface["implementations"]:
                f.write(
                    "if (impl == \"" + impl + "\") {\n"
                    "                " + p_name + " = &" + fName(impl) + ";\n" +
                    "            } else "
                    )
            f.write(
                "{\n" +
                "                throwup(module, impl);\n" +
                "            }\n" +
                "\n" +
                "        } else "
                )
        f.write("{ }")

def generate(all_implementations, ipp_prefix = '', hpp_prefix = ''):
    """Generates the .ipp inclusion files for ModuleLoader.cpp

    :param all_implementations: The vector of dictionaries that defines the 
           interfaces and implementations thereof.
    :param prefix: A directory and file prefix that preceeds the file names to
           provide a path from the current working directory.
    """
    headers(all_implementations, ipp_prefix, hpp_prefix)
    functions(all_implementations, ipp_prefix)
    names(all_implementations, ipp_prefix)
    assignments(all_implementations, ipp_prefix)

if __name__ == "__main__":
#    i1 = {"name": "I1", "implementations": ["Impl11", "Impl12"]}
#    i2 = {"name": "I2", "implementations": ["Impl21", "Impl22"]}
#
#    alli = [i1, i2]

    iAlb = {"name": "Albedo", "implementations": ["SNUAlbedo", "SNU2Albedo", "CCSMAlbedo"]}
    ithe = {"name": "thermodynamics", "implementations": ["thermoWinton", "thermoIce0"]}

    alli = [iAlb, ithe]
    
    generate(alli, hpp_prefix = "include/")
