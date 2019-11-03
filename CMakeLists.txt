cmake_minimum_required(VERSION 3.14)
project(brain_need_eat)

set(CMAKE_CXX_STANDARD 14)

add_executable(brain_need_eat main.cpp classes/Brain.cpp classes/Brain.h classes/Tick.h classes/NeuronController.cpp classes/NeuronController.h classes/Neuron.h classes/factories/NeuronFactory.cpp classes/factories/NeuronFactory.h classes/factories/NeuronControllerFactory.cpp classes/factories/NeuronControllerFactory.h classes/factories/BrainFactory.cpp classes/factories/BrainFactory.h constants.h classes/repositories/NeuronRepository.h classes/repositories/NeuronConrollerRepository.h classes/Ticker.cpp classes/Ticker.h classes/NeuronConnection.h classes/Signal.h)