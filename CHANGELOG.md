# 24.12.2019
- **Integrated functionality for multiplying signals between neurons.**
  - changed addNeuronConnection function parameters (removed redundant id)
  - updated NeuronConnection class structure
  - created multiplying step in NeuronController
  - now, Signal power can be setted
  - wrote neuron connection tests

# 22.12.2019
- Small changes for auto-connecting files in CmakeLists files.
- Created new constants for repository storage sizes.
- Updated NeuronController. If the neuron is Inhibitory spike power will be negated.
- Created separated storage for Base, Inhibitory and Excitatory neurons.
- Wrote tests for NeuronRepository and NeuronFactory based on Inhibitory and Excitatory neurons

# 21.12.2019
- Added tests functionality ( Google tests )

# 06.11.2019
- created simples neuron structure generator
- created drawer class which works with matplotlib
- added 2 statistic vectors for neuron class
- added neuron loss per tick (need debug) currently has graphs

# 03.11.2019
- removed infinite cycle from brain proceed
- a removed redundant function definition in brain.h
- created neuron connection class
- created signal class
- added functionality: attaching connections, proceed inside the neuron and sending signals to other connected neurons.
- removed redundant code in `main.cpp`
- now the app can be built and ran without any errors

# 31.10.2019
- created elements factories.
- created main repositories.
- prepared brain class which should work with neurons and neuron controllers
- created base timing entity named `Ticker`
- created simplest README