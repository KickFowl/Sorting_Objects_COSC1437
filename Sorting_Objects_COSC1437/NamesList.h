#pragma once

#include <string>

// ---------------------------------------------------------------------------
// VOCABULARY LISTS(Conan & He - Man Pulp Fantasy / Techno - Barbarian Aesthetics)
// ---------------------------------------------------------------------------

namespace names {
    // List 1: Grand, savage, archaic, or techno - sorcerous adjectives
    std::string PREFIXE[55] = {
        // Archaic & Grand(like Magnanimous)
        "Magnanimous", "Imperious", "Illustrious", "Sovereign", "Omnipotent",
        "Inviolable", "Resplendent", "Peerless", "Venerable", "Righteous",

        // Barbaric, Savage & Brutal(Conan / Cimmerian)
        "Savage", "Blood-Forged", "Skull-Cleaving", "Ruthless", "Iron-Clad",
        "Primal", "Merciless", "Gore-Drenched", "Feral", "Relentless",
        "Grim", "Unflinching", "Battle-Scarred", "Carnivorous", "Wrathful",

        // Mythic, Doom & Primeval
        "Doom-Brought", "Cataclysmic", "Eldritch", "Obsidian", "Primeval",
        "Abyssal", "Dreaded", "Blasphemous", "Spectral", "Apocalyptic",
        "Shadow-Forged", "Brimstone", "Cursed", "Ancient", "Gargantuan",

        // Masters of the Universe / Techno - Sorcery & Cosmic Power
        "Thunderous", "Star-Forged", "Adamantine", "Cosmic", "Solar-Charged",
        "Hyper-Kinetic", "Eternian", "Plasma-Wrought", "Havoc-Infused", "Photon-Tempered",
        "Radiant", "Titan-Forged", "Galactic", "Storm-Bound", "Unstoppable"
    };

    // Base types and optional techno - barbarian subtypes
    std::string ITEM_TYPE[3][10] = {
        {
            "Sword", "Broadsword", "Claymore", "Greatsword", "Scimitar",
            "Blade", "Cleaver", "Edge", "Executioner", "Saber"
        } ,
        {
            "Shield", "Bulwark", "Aegis", "Tower-Shield", "Buckler",
            "Barricade", "Ward", "Carapace", "Great-Shield", "Pavise"
        } ,
        {
            "Gun", "Hand-Cannon", "Blaster", "Raygun", "Scattergun",
            "Laser-Carbine", "Thunder-Pistol", "Havoc-Rifle", "Plasma-Spitter", "Boom-Stick"
        }
    };

    // List 2: Legendary figures, barbarian kings, cosmic sorcerers, warlords
    std::string NAME[40] = {
        // Conan - esque(Howardian warlords, ancient kings, Stygian & Cimmerian heroes)
        "Horthrek", "Crom-Tor", "Thulsa", "Xaltotun", "Thoth-Amon",
        "Gor-Gath", "Valerius", "Kaelen-Vor", "Mor-Dath", "Zanthos",
        "Tarkus", "Brak-Thor", "Con-Gor", "Ravagore", "Kull-Rek",

        // He - Man - esque(Techno - barbarian lords, Snake Mountain / Eternian giants)
        "Grayskull", "Skeletok", "Strykor", "Zodak", "Keldor",
        "Trap-Garr", "Man-At-Arms", "Beast-Lord", "Hordok", "Tri-Klops",
        "Evil-Lyn", "Whiplor", "Fisto-Tor", "Ram-Zul", "Claw-Dred",

        // Primeval Titans, Cosmic Entities & Beast - Chieftains
        "Vok-Zul", "Dra-Karn", "Skelos", "Malakor", "Gorgoroth",
        "Zar-Kahn", "Tor-Mek", "Bravado", "Unyor", "Necro-Pharos"
    };

    // List 3: Epithets, deeds, titles, and barbaric monikers
    std::string TITLE[35] = {
        // Feats of Valor & Conquest
        "Bold", "Invincible", "Unconquered", "Relentless", "Defiant",
        "Lion-Hearted", "Unyielding", "Ever-Victorious", "Iron-Willed", "Dauntless",

        // Savage & Bloody Monikers
        "Blood-Drinker", "Skull-Crusher", "Bone-Cleaver", "Flesh-Render", "Savage",
        "Gore-Spiller", "Maimer", "Ruthless", "Beast-Slayer", "Warmonger",

        // Cosmic, Sorcerous & Apocalyptic Titles
        "Terrible", "Undying", "World-Breaker", "Star-Eater", "Mountain-Crusher",
        "Doom-Bringer", "Void-Walker", "Shadow-Born", "Soul-Ravager", "Sun-Shatterer",
        "God-Defier", "Immortal", "Storm-Caller", "Annihilator", "Death-Dealer"
    };

    // ============================================================================
    // CONAN & HE-MAN PROCEDURAL ITEM NAMING SYSTEM: C++ DATA ARRAYS
    // Pattern: [Prefix] [Item Type: Sword/Shield/Gun] of [Figure] the [Epithet]
    // ============================================================================

    // ----------------------------------------------------------------------------
    // AVERAGE / COMMON TIER (Standard-issue infantry, mercenary grit, utilitarian)
    // ----------------------------------------------------------------------------

    // List 1: Average Prefixes (Functional, mundane, weathered, mass-produced)
    const std::string AVARAGE_PREFIX[20]{
        "Standard",         // Factory or armory standard issue
        "Serviceable",      // Gets the job done, nothing fancy
        "Weathered",        // Worn down by common elements
        "Battle-Tested",    // Survived a few skirmishes
        "Tarnished",        // Lost its luster but functional
        "Iron",             // Plain iron, lacking sorcerous tempering
        "Hardened",         // Basic heat treatment
        "Crude",            // Rough-hewn forge craft
        "Mercenary's",      // Common sellsword gear
        "Rugged",           // Sturdy but unrefined
        "Cast-Iron",        // Heavy, unembellished casting
        "Scavenged",        // Looted from the battlefield floor
        "Utilitarian",      // Built purely for function, zero ornamentation
        "Militia",          // Town guard or conscript grade
        "Sturdy",           // Reliable, unremarkable resilience
        "Plain",            // Devoid of runes, crests, or jewels
        "Tempered",         // Basic metalwork
        "Garrison",         // Standard armory stock for fortresses
        "Workman's",        // Built by an ordinary apprentice smith
        "Repaired"          // Patched up after minor combat fractures
    };

    // List 2: Average Figures (Common grunts, petty raiders, tavern brawlers, footmen)
    const std::string AVARAGE_NAME[20]{
        "Grok",             // Everyday barbarian conscript
        "Tor",              // Common northern tribesman
        "Karl",             // City watchman or border guard
        "Bran",             // Lowland foot-soldier
        "Rogar",            // Seasoned caravan hireling
        "Durn",             // Quarry guard or stone-cutter
        "Gort",             // Hulking palace gatekeeper
        "Krunk",            // Henchman brawler
        "Vorn",             // Borderland scout
        "Harl",             // Outpost infantryman
        "Skag",             // Wasteland scavenger
        "Brak",             // Snake Mountain rank-and-file sentry
        "Jarek",            // Hired crossbowman or spearman
        "Malok",            // Desert raider grunt
        "Gnasher",          // Minor beast-tamer
        "Kurg",             // Trench digger or frontline meat
        "Sledge",           // Armory apprentice
        "Drak",             // Local militia veteran
        "Borgan",           // Caravan wagon guard
        "Wulf"              // Common woodland hunter
    };

    // List 3: Average Epithets (Everyday military ranks, ordinary deeds, modest trades)
    const std::string AVERAGE_TITLE[20]{
        "Mercenary",        // Fights for coin, nothing more
        "Foot-Soldier",     // Standard rank-and-file infantry
        "Watchman",         // Walks the fortress ramparts at night
        "Sentry",           // Guards the perimeter
        "Guard",            // Gatekeeper on routine shift
        "Survivor",         // Managed to stay alive through ordinary scraps
        "Scout",            // Out in front spotting ambushes
        "Raider",           // Participates in petty livestock raids
        "Brawler",          // Good in a tavern dust-up
        "Hunter",           // Tracks game through the steppes
        "Blacksmith",       // Spends days at the anvil
        "Steady",           // Keeps a level head under average pressure
        "Tough",            // Takes a beating without complaining
        "Journeyman",       // Competent craftsman or soldier
        "Vigilant",         // Doesn't fall asleep on watch
        "Stout",            // Broad-shouldered and dependable
        "Patroller",        // Marches the patrol perimeter
        "Pikeman",          // Standard wall of spears
        "Warden",           // Petty district supervisor
        "Resolute"          // Holds the line against standard opposition
    };

    // ----------------------------------------------------------------------------
    // POOR / JUNK TIER (Defective, rotten, cursed, cowardly, broken, joke stats)
    // ----------------------------------------------------------------------------

    // List 1: Poor Prefixes (Damaged, degraded, misfiring, brittle, pitiful)
    const std::string POOR_PREFIX[20]{
        "Rusted",           // Flaking orange with corrosion
        "Chipped",          // Edge notched from striking a rock
        "Pitiful",          // Inspires genuine secondhand embarrassment
        "Rickety",          // Rattles violently with every movement
        "Dented",           // Hammered out of shape
        "Fractured",        // Hairline cracks waiting to shatter
        "Feeble",           // Lacks tensile strength or stopping power
        "Misfiring",        // Gun sparks, jams, or backfires into your face
        "Dull",             // Couldn't slice soft butter
        "Warped",           // Bent out of alignment
        "Corroded",         // Eaten away by acid or swamp humidity
        "Brittle",          // Snaps on impact against bone or bronze
        "Decrepit",         // Falling apart from neglect and rot
        "Tainted",          // Smells rancid, faintly repulsive aura
        "Clumsy",           // Awkward center of gravity, trips the wielder
        "Junk-Rigged",      // Held together with twine, duct-tape, or wire
        "Shoddy",           // Hurriedly cobbled together from scrap metal
        "Flimsy",           // Bends under mild combat pressure
        "Blunted",          // Striking edge completely smoothed out
        "Rotten"            // Wooden core or leather grip decomposing
    };

    // List 2: Poor Figures (Bumbling minions, cowardly goblins, wretched beggars, losers)
    const std::string POOR_NAME[20]{
        "Snivel",           // Weeping lackey who drops his weapon
        "Worm-Eye",         // Skulking dungeon scavenger
        "Skulk",            // Coward hiding behind boulders
        "Grot",             // Bottom-tier dungeon goblin
        "Weevil",           // Petty thief caught in grain bins
        "Pustule",          // Diseased swamp outcast
        "Blunder",          // Drops grenades at his own feet
        "Dribble",          // Incoherent, slobbering mutant peon
        "Rat-Snout",        // Sewer dweller who steals scraps
        "Scab-Garr",        // Mangy minion left behind during retreat
        "Grime-Toof",       // Defeated bandit missing all his teeth
        "Wretch-Tor",       // Disgraced barbarian banished from the clan
        "Slime-Brak",       // Bog-creature covered in pond scum
        "Moldor",           // Sleeps in damp dungeon corners
        "Clod",             // Drops his shield on his own toes
        "Fumble",           // Incapable of holding a proper grip
        "Slink",            // Flees before the battle even begins
        "Nuisance",         // Annoying pest easily swatted aside
        "Bumbler",          // Triggers his own trapdoors
        "Cower"             // Always curling into the fetal position
    };

    // List 3: Poor Epithets (Disgraceful, cowardly, inept, cursed, laughingstock)
    const std::string POOR_TITLE[20]{
        "Coward",           // First to sprint in the opposite direction
        "Feeble",           // Incapable of lifting a full broadsword
        "Inept",            // Whiffs strikes by several feet
        "Fleeting",         // Vanishes the moment danger appears
        "Broken",           // Spirit and spine thoroughly shattered
        "Trembling",        // Shakes so hard weapons rattle in scabbards
        "Disgraced",        // Stripped of armor and driven into the dirt
        "Unlucky",          // Struck by stray arrows from his own allies
        "Runaway",          // Track record composed entirely of retreats
        "Clumsy",           // Constantly impaling his own belt or cloak
        "Rust-Ridden",      // Neglected gear to the point of structural failure
        "Cursed",           // Brings bizarre misfortune to anyone nearby
        "Craven",           // Begs enemies for mercy at sword-point
        "Toothless",        // All bark, zero bite
        "Malfunctioning",   // Fires backward or sparks uselessly
        "Deserter",         // Abandoned post five minutes into guard duty
        "Misguided",        // Charged the wrong army in broad daylight
        "Worthless",        // Pawnshop won't even accept as scrap
        "Defeated",         // Has never won a single duel in his life
        "Ignominious"       // Dies in an embarrassing, unheroic fashion
    };
}
