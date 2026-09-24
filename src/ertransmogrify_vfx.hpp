#pragma once

namespace ertransmogrify {
namespace vfx {
// Fake armor set used as the transformProtector for transmogrification. The params that this ID
// resolves to changes at runtime based on the player's transmog selection.
static constexpr long long transmog_set_base_id = 69000000;
static constexpr long long transmog_set_alt_base_id = 69100000;

// VFX IDs that apply the transmog visuals. In multiplayer, these IDs are offset by +1, +2, +3,
// etc., so each player has a different VFX param.
static constexpr long long transmog_head_base_vfx_id = 6901000;
static constexpr long long transmog_body_base_vfx_id = 6902000;

// SpEffects applied to enable the transmog VFX. These are chosen at random in order to avoid
// conflicts in Seamless Co-op.
static constexpr long long transmog_vfx_speffect_start_id = 169000000;
static constexpr long long transmog_vfx_speffect_end_id = 169500000;

// Magic SpEffect applied to the player to undo transmogrification. This decouples the VFX from the
// talkscript system, so we can disable talkscript patching and allow modpack authors to dispel
// transmogrification in some other way.
static constexpr long long undo_transmog_speffect_id = 169999999;

/**
 * Signal SpEffect given by the grace menu to toggle Furled Finger's Trick-Mirror
 */
static constexpr long long trick_mirror_toggle_speffect_id = 169999998;

/**
 * SpEffect put on the local player while Furled Finger's Trick-Mirror is enabled. It carries the
 * talisman's VFX row and HUD icon, but the ID itself is unknown to the base game. Judging by the net
 * player note in get_speffect_param_detour, a player's SpEffects reach other clients, which can only
 * apply those they have a param for. Other clients shouldn't apply this one, keeping it local.
 */
static constexpr long long trick_mirror_effect_speffect_id = 169999997;

/**
 * VFX row and HUD icon of the real talisman's SpEffect 360800
 */
static constexpr int trick_mirror_vfx_id = 360800;
static constexpr int trick_mirror_icon_id = 20297;

static constexpr long long head_protector_offset = 0;
static constexpr long long chest_protector_offset = 100;
static constexpr long long arms_protector_offset = 200;
static constexpr long long legs_protector_offset = 300;

// Hack: the character creation menu shows a copy of the player model, but it has some odd behavior
// with transform protectors. Make the player temporarily naked while this menu is up.
extern bool is_in_chr_make_menu;

struct player_state_st {
    int head_protector_id{-1};
    int chest_protector_id{-1};
    int arms_protector_id{-1};
    int legs_protector_id{-1};
};

/**
 * Hook the internal get_*_param() functions to return the new params used for the transmog VFX
 */
void initialize();

}
}
