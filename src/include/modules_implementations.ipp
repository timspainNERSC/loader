    // List of all module names
enum class Module {
        iceAlbedo,
        thermodynamics
    };

    // List of all possible implementations of any of the Modules
    enum class Implementation {
        SNUAlbedo,
        SNU2Albedo,
        CCSMAlbedo,
        thermoWinton,
        thermoIce0
    };
