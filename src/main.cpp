#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "BatteryStatus.hpp"

using namespace geode::prelude;

class $modify(StatusMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Prevent duplicates inside this layer
        if (!this->getChildByID("battery-status")) {
            if (auto status = BatteryStatus::create()) {
                status->setID("battery-status");
                status->setPosition({ 50, 50 }); // tweak later
                this->addChild(status);

                log::debug("hi from battery status");
            }
        }

        return true;
    }
};
