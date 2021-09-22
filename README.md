# loader

A repo to try out designs of how to load modules in a semi-runtime way in C++.

## Brief
Given a program with multiple implementations of a given function, how can we choose at the start of run time which implementation to use? For example, there might be three different ways of calculating sea-ice albedo. Only one will be used in a particular model run, but we don't want to have to recompile the model just to change to a different implementation.

The configuration will come from a config file, and preferably will use an instance of the boost class that parses such files to drive the selection. The selections should be done as soon as possible after run-time. They should also throw an exception if the entry in the config file is not a valid selection. Then the correct module is loaded, and possibly loads its own configured modules.

The alternative implementations will all inherit from an interface class, and somewhere a pointer to the base will be stored. The specific implementation is then accessed through the base class pointer and executes the chosen implementation using virtual functions. This part can be context dependent, and does not need to be uniform across all classes that might try to instantiate alternatives.
