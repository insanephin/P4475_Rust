#pragma once

#include <cstdint>

#include "xun_physics_state.hpp"

struct P4475XunPhysicsProbeSnapshot {
    std::uint32_t drive_event_calls;
    std::uint32_t physics_tick_calls;
    std::uint32_t charger_activations;
    std::uint32_t charger_deactivations;
    std::uint32_t active_karts;
    std::uint32_t speed_boost_gauge_adjustments;
    std::uint32_t charger_resource_registrations;
    std::uint32_t charger_effect_spawns;
    std::uint32_t charger_effect_removals;
};

struct P4475XunDashboardState {
    bool enabled;
    bool active;
    std::uint32_t pending_booster_uses;
    std::uint32_t required_booster_uses;
    std::uint32_t active_until_ms;
    std::uint32_t active_duration_ms;
};

void p4475_xun_configure_physics_probe(const p4475::xun::ChargerTuning& tuning) noexcept;
void p4475_xun_apply_server_profile(
    const p4475::xun::ChargerTuning& tuning,
    std::uint32_t generation,
    std::uint16_t kart_id,
    std::uint8_t exceed_type,
    std::uint8_t profile_state,
    std::uint8_t default_engine_type,
    std::uint8_t default_handle_type,
    std::uint8_t default_wheel_type,
    std::uint8_t default_booster_type) noexcept;
void p4475_xun_reset_server_profile() noexcept;
P4475XunPhysicsProbeSnapshot p4475_xun_physics_probe_snapshot() noexcept;
bool p4475_xun_dashboard_state(
    void* kart,
    P4475XunDashboardState* output) noexcept;
bool p4475_xun_correct_display_stat(
    std::uint32_t category,
    float body_value,
    std::int16_t* output) noexcept;

extern "C" void __cdecl p4475_xun_observe_drive_event(
    void* kart,
    std::uint32_t event_payload,
    std::uint32_t event_kind,
    std::uint32_t accepted,
    std::uint32_t client_booster_uses_before,
    std::uint32_t client_booster_uses_after) noexcept;
extern "C" void __cdecl p4475_xun_observe_physics_tick(
    void* kart,
    std::uint32_t now_ms) noexcept;
float p4475_xun_speed_boost_gauge_multiplier(void* kart) noexcept;
float p4475_xun_drift_gauge_coefficient(void* kart, float original) noexcept;
float p4475_xun_wall_gauge_coefficient(void* kart, float original) noexcept;
float p4475_xun_boost_gauge_coefficient(void* kart, float original) noexcept;
float p4475_xun_anti_collide_balance(void* kart, float original) noexcept;
float p4475_xun_collision_response_value(void* kart, float original) noexcept;
void p4475_xun_record_speed_boost_gauge_adjustment(
    void* kart,
    float original_addend,
    float scaled_addend,
    float multiplier) noexcept;
extern "C" std::uint32_t __cdecl p4475_xun_adjust_speed_boost_gauge_addend(
    void* protected_accumulator,
    std::uint32_t addend_bits) noexcept;
