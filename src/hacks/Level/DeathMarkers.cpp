#include <modules/gui/gui.hpp>
#include <modules/hack/hack.hpp>
#include <modules/config/config.hpp>

#include <Geode/modify/PlayLayer.hpp>

#include <vector>

namespace eclipse::hacks::Level {

    class DeathMarkers : public hack::Hack {
        void init() override {
            auto tab = gui::MenuTab::find("Level");

            tab->addToggle("Death Markers", "level.deathmarkers")
                ->setDescription("Marks where each player death happened. Markers remain until the level is restarted.")
                ->handleKeybinds();
        }

        [[nodiscard]] const char* getId() const override { return "Death Markers"; }
    };

    REGISTER_HACK(DeathMarkers)

    class $modify(DeathMarkersPLHook, PlayLayer) {
        struct Fields {
            std::vector<cocos2d::CCNode*> markers;
        };

        void destroyPlayer(PlayerObject* player, GameObject* object) {
            if (config::get<bool>("level.deathmarkers", false) &&
                player && (player == m_player1 || player == m_player2) && m_objectLayer) {
                auto marker = cocos2d::CCDrawNode::create();
                if (marker) {
                    marker->drawCircle(
                        cocos2d::CCPoint(0.f, 0.f),
                        5.f,
                        cocos2d::ccColor4F{1.f, 0.12f, 0.12f, 0.85f},
                        1.5f,
                        cocos2d::ccColor4F{1.f, 1.f, 1.f, 0.95f},
                        24
                    );

                    auto worldPosition = player->getParent()
                        ? player->getParent()->convertToWorldSpace(player->getPosition())
                        : player->getPosition();
                    marker->setPosition(m_objectLayer->convertToNodeSpace(worldPosition));
                    marker->setZOrder(1000);
                    m_objectLayer->addChild(marker);
                    m_fields->markers.push_back(marker);
                }
            }

            PlayLayer::destroyPlayer(player, object);
        }

        void clearMarkers() {
            for (auto marker : m_fields->markers) {
                if (marker)
                    marker->removeFromParentAndCleanup(true);
            }
            m_fields->markers.clear();
        }

        void resetLevel() {
            clearMarkers();
            PlayLayer::resetLevel();
        }

        void onQuit() {
            clearMarkers();
            PlayLayer::onQuit();
        }
    };
}
