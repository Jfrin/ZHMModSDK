#pragma once

#include "IPluginInterface.h"

class World : public IPluginInterface {
public:
    ~World() override;

    void OnEngineInitialized() override;
    void OnDrawMenu() override;
    void OnDrawUI(bool p_HasFocus) override;

private:
    void OnFrameUpdate(const SGameUpdateEvent& p_UpdateEvent);

    bool m_ShowWorldWindow = false;
    bool m_IsTimeMultiplierEnabled = false;

    // Slowdown applied when the hotkey toggles the multiplier on. Still adjustable via the World window.
    float m_GameTimeMultiplier = 0.25f;

    // Virtual-key code for the slowdown toggle (VK_F7). See https://learn.microsoft.com/windows/win32/inputdev/virtual-key-codes
    static constexpr int c_SlowdownHotkey = 0x76;
    bool m_HotkeyWasDown = false;
};

DECLARE_ZHM_PLUGIN(World)
