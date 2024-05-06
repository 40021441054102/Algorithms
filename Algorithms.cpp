# ifndef ALGORITHMS_OMID_SOJOODI
    # include "Algorithms.hpp"
    //-- Constructor
    Algorithms::Algorithms(
        ENUM_SUPPORTED_ALGORITHMS algorithm,
        ENUM_ALGORITHM_ENVIRONMENT environment,
        ENUM_ALGORITHMS_DATA_METHOD dataMethod = USE_RANDOM_DATA,
        ENUM_ALGORIHTMS_PROCESSING_METHODS processingMethod = USE_SINGLE_THREAD
    ) {
        if (dataMethod == USE_RANDOM_DATA) {
            generateRandomData(
                MAX_RANDOM_DATA,
                0,
                int(MAX_RANDOM_DATA * 0.9)
            );
        }
        std::cout << LOG "Starting Algorithm Process Time" << RESET << std::endl;
        begin_time = std::chrono::high_resolution_clock::now();
    }
    //-- Destructor
    Algorithms::~Algorithms() {
        end_time = std::chrono::high_resolution_clock::now();
        algorithm_duration = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - begin_time);
        std::cout << LOG "Algorithm Process Time: " << algorithm_duration.count() << "s" << RESET << std::endl;
    }
    //-- Method to Generate Random Data
    void Algorithms::generateRandomData(
        int amount,
        int min,
        int max
    ) {
        std::cout << LOG "Generating Random Data ..." << RESET << std::endl;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(1, 100);
        int random_number = distribution(gen);
    }
# endif // ALGORITHMS_OMID_SOJOODI