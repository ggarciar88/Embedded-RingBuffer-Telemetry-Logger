#iostream
#thread
#chrono
#vector
#string
#include "RingBufferLogger.hpp"

void producer_task(TelemetryLogger& logger, int id) {
    for (int i = 0; i < 5; ++i) {
        std::string msg = "Producer " + std::to_string(id) + " - Event " + std::to_string(i);
        logger.log(msg);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer_task(TelemetryLogger& logger) {
    std::string msg;
    while (logger.is_ready() || !logger.empty_queue()) {
        if (logger.fetch(msg)) {
            // Procesamiento de telemetría simulado
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main() {
    TelemetryLogger logger(100);

    std::thread c(consumer_task, std::ref(logger));
    std::vector<std::thread> producers;
    for (int i = 0; i < 3; ++i) {
        producers.emplace_back(producer_task, std::ref(logger), i);
    }

    for (auto& p : producers) {
        p.join();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    logger.stop();
    c.join();

    return 0;
}
