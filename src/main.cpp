#include <windows.h>

#include <iostream>
#include <string>

static bool block{ true };

struct stKeys {
    stKeys() {};
    ~stKeys() {};

    int keys[254] = {
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
        0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
        0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
        0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
        0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
        0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
        0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
        0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
        0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
        0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
        0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE
    };

    std::string value_table[255] = { "None",
        "0x01", "0x02", "0x03", "0x04", "0x05", "0x06", "0x07", "0x08", "0x09", "0x0A", "0x0B", "0x0C", "0x0D", "0x0E", "0x0F",
        "0x10", "0x11", "0x12", "0x13", "0x14", "0x15", "0x16", "0x17", "0x18", "0x19", "0x1A", "0x1B", "0x1C", "0x1D", "0x1E", "0x1F",
        "0x20", "0x21", "0x22", "0x23", "0x24", "0x25", "0x26", "0x27", "0x28", "0x29", "0x2A", "0x2B", "0x2C", "0x2D", "0x2E", "0x2F",
        "0x30", "0x31", "0x32", "0x33", "0x34", "0x35", "0x36", "0x37", "0x38", "0x39", "0x3A", "0x3B", "0x3C", "0x3D", "0x3E", "0x3F",
        "0x40", "0x41", "0x42", "0x43", "0x44", "0x45", "0x46", "0x47", "0x48", "0x49", "0x4A", "0x4B", "0x4C", "0x4D", "0x4E", "0x4F",
        "0x50", "0x51", "0x52", "0x53", "0x54", "0x55", "0x56", "0x57", "0x58", "0x59", "0x5A", "0x5B", "0x5C", "0x5D", "0x5E", "0x5F",
        "0x60", "0x61", "0x62", "0x63", "0x64", "0x65", "0x66", "0x67", "0x68", "0x69", "0x6A", "0x6B", "0x6C", "0x6D", "0x6E", "0x6F",
        "0x70", "0x71", "0x72", "0x73", "0x74", "0x75", "0x76", "0x77", "0x78", "0x79", "0x7A", "0x7B", "0x7C", "0x7D", "0x7E", "0x7F",
        "0x80", "0x81", "0x82", "0x83", "0x84", "0x85", "0x86", "0x87", "0x88", "0x89", "0x8A", "0x8B", "0x8C", "0x8D", "0x8E", "0x8F",
        "0x90", "0x91", "0x92", "0x93", "0x94", "0x95", "0x96", "0x97", "0x98", "0x99", "0x9A", "0x9B", "0x9C", "0x9D", "0x9E", "0x9F",
        "0xA0", "0xA1", "0xA2", "0xA3", "0xA4", "0xA5", "0xA6", "0xA7", "0xA8", "0xA9", "0xAA", "0xAB", "0xAC", "0xAD", "0xAE", "0xAF",
        "0xB0", "0xB1", "0xB2", "0xB3", "0xB4", "0xB5", "0xB6", "0xB7", "0xB8", "0xB9", "0xBA", "0xBB", "0xBC", "0xBD", "0xBE", "0xBF",
        "0xC0", "0xC1", "0xC2", "0xC3", "0xC4", "0xC5", "0xC6", "0xC7", "0xC8", "0xC9", "0xCA", "0xCB", "0xCC", "0xCD", "0xCE", "0xCF",
        "0xD0", "0xD1", "0xD2", "0xD3", "0xD4", "0xD5", "0xD6", "0xD7", "0xD8", "0xD9", "0xDA", "0xDB", "0xDC", "0xDD", "0xDE", "0xDF",
        "0xE0", "0xE1", "0xE2", "0xE3", "0xE4", "0xE5", "0xE6", "0xE7", "0xE8", "0xE9", "0xEA", "0xEB", "0xEC", "0xED", "0xEE", "0xEF",
        "0xF0", "0xF1", "0xF2", "0xF3", "0xF4", "0xF5", "0xF6", "0xF7", "0xF8", "0xF9", "0xFA", "0xFB", "0xFC", "0xFD", "0xFE"
    };

    std::string key_table[255] = { "None", 
        "LMB", "RMB", "Control-break processing", "MMB", "X1MB", "X2MB", "Undefined", "BACKSPACE", "TAB", "Reserved", "Reserved", "CLEAR", "ENTER", "Undefined", "Undefined",
        "SHIFT", "CTRL", "ALT", "PAUSE", "CAPS LOCK", "[IME] Kana | Hanguel | Hangul", "IME On", "IME Junja mode", "IME final mode", "[IME mode] Hanja | Kanji", "IME Off", "ESC", "IME convert", "IME nonconvert", "IME accept", "IME mode change request",
        "SPACEBAR", "0x21", "0x22", "0x23", "0x24", "0x25", "0x26", "0x27", "0x28", "0x29", "0x2A", "0x2B", "0x2C", "0x2D", "0x2E", "0x2F",
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Undefined", "Undefined", "Undefined", "Undefined", "Undefined", "Undefined",
        "Undefined", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
        "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Left Windows (Natural keyboard)", "Right Windows (Natural keyboard)", "Applications (Natural keyboard)", "Reserved", "Computer Sleep",
        "NUMPAD0", "NUMPAD1", "NUMPAD2", "NUMPAD3", "NUMPAD4", "NUMPAD5", "NUMPAD6", "NUMPAD7", "NUMPAD8", "NUMPAD9", "NUMPAD Multiply", "NUMPAD Add", "NUMPAD Separator", "NUMPAD Subtract", "NUMPAD Decimal", "NUMPAD Divide",
        "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15", "F16",
        "F17", "F18", "F19", "F20", "F21", "F22", "F23", "F24", "Unassigned", "Unassigned", "Unassigned", "Unassigned", "Unassigned", "Unassigned", "Unassigned", "Unassigned",
        "NUM LOCK", "SCROLL LOCK", "OEM specific", "OEM specific", "OEM specific", "OEM specific", "OEM specific", "Unassigned", "Unassigned", "Unassigned", "Unassigned", "Unassigned", "Unassigned", "Unassigned", "Unassigned", "Unassigned",
        "LSHIFT", "RSHIFT", "LCONTROL", "RCONTROL", "LMENU", "RMENU", "Browser Back", "Browser Forward", "Browser Refresh", "Browser Stop", "Browser Search", "Browser Favorites", "Browser Start and Home", "Volume Mute", "Volume Down", "Volume Up",
        "Next Track", "Previous Track", "Stop Media", "Play/Pause Media", "Start Mail", "Select Media", "Start Application 1", "Start Application 2", "Reserved", "Reserved", "Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the ';:' key", "For any country/region, the '+' key", "For any country/region, the ',' key", "For any country/region, the '-' key", "For any country/region, the '.' key", "Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '/?' key",
        "Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '`~' key", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved",
        "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Unassigned", "Unassigned", "Unassigned", "Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '[{' key", "Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the '\|' key", "Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the ']}' key", "Used for miscellaneous characters; it can vary by keyboard. For the US standard keyboard, the 'single-quote/double-quote' key", "Used for miscellaneous characters; it can vary by keyboard.",
        "Reserved", "OEM specific", "The <> keys on the US standard keyboard, or the \\\\| key on the non-US 102-key keyboard", "OEM specific", "OEM specific", "IME PROCESS", "OEM specific", "Used to pass Unicode characters as if they were keystrokes. The VK_PACKET key is the low word of a 32-bit Virtual Key value used for non-keyboard input methods. For more information, see Remark in KEYBDINPUT, SendInput, WM_KEYDOWN, and WM_KEYUP", "Unassigned", "OEM specific", "OEM specific", "OEM specific", "OEM specific", "OEM specific", "OEM specific", "OEM specific",
        "OEM specific", "OEM specific", "OEM specific", "OEM specific", "OEM specific", "OEM specific", "Attn", "CrSel", "ExSel", "Erase EOF", "Play", "Zoom", "Reserved", "PA1", "Clear"
    };

    std::string constant_table[255] = { "None",
        "VK_LBUTTON", "VK_RBUTTON", "VK_CANCEL", "VK_MBUTTON", "VK_XBUTTON1", "VK_XBUTTON2", "-", "VK_BACK", "VK_TAB", "-", "-", "VK_CLEAR", "VK_RETURN", "-", "-",
        "VK_SHIFT", "VK_CONTROL", "VK_MENU", "VK_PAUSE", "VK_CAPITAL", "VK_KANA | VK_HANGUEL | VK_HANGUL", "VK_IME_ON", "VK_JUNJA", "VK_FINAL", "VK_HANJA | VK_KANJI", "VK_IME_OFF", "VK_ESCAPE", "VK_CONVERT", "VK_NONCONVERT", "VK_ACCEPT", "VK_MODECHANGE",
        "VK_SPACE", "VK_PRIOR", "VK_NEXT", "VK_END", "VK_HOME", "VK_LEFT", "VK_UP", "VK_RIGHT", "VK_DOWN", "VK_SELECT", "VK_PRINT", "VK_EXECUTE", "VK_SNAPSHOT", "VK_INSERT", "VK_DELETE", "VK_HELP",
        "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-",
        "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-",
        "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "VK_LWIN", "VK_RWIN", "VK_APPS", "-", "VK_SLEEP",
        "VK_NUMPAD0", "VK_NUMPAD1", "VK_NUMPAD2", "VK_NUMPAD3", "VK_NUMPAD4", "VK_NUMPAD5", "VK_NUMPAD6", "VK_NUMPAD7", "VK_NUMPAD8", "VK_NUMPAD9", "VK_MULTIPLY", "VK_ADD", "VK_SEPARATOR", "VK_SUBTRACT", "VK_DECIMAL", "VK_DIVIDE",
        "VK_F1", "VK_F2", "VK_F3", "VK_F4", "VK_F5", "VK_F6", "VK_F7", "VK_F8", "VK_F9", "VK_F10", "VK_F11", "VK_F12", "VK_F13", "VK_F14", "VK_F15", "VK_F16",
        "VK_F17", "VK_F18", "VK_F19", "VK_F20", "VK_F21", "VK_F22", "VK_F23", "VK_F24", "-", "-", "-", "-", "-", "-", "-", "-",
        "VK_NUMLOCK", "VK_SCROLL", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-",
        "VK_LSHIFT", "VK_RSHIFT", "VK_LCONTROL", "VK_RCONTROL", "VK_LMENU", "VK_RMENU", "VK_BROWSER_BACK", "VK_BROWSER_BACK", "VK_BROWSER_REFRESH", "VK_BROWSER_STOP", "VK_BROWSER_SEARCH", "VK_BROWSER_FAVORITES", "VK_BROWSER_HOME", "VK_VOLUME_MUTE", "VK_VOLUME_DOWN", "VK_VOLUME_UP",
        "VK_MEDIA_NEXT_TRACK", "VK_MEDIA_PREV_TRACK", "VK_MEDIA_STOP", "VK_MEDIA_PLAY_PAUSE", "VK_LAUNCH_MAIL", "VK_LAUNCH_MEDIA_SELECT", "VK_LAUNCH_APP1", "VK_LAUNCH_APP2", "-", "-", "VK_OEM_1", "VK_OEM_PLUS", "VK_OEM_COMMA", "VK_OEM_MINUS", "VK_OEM_PERIOD", "VK_OEM_2",
        "VK_OEM_3", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-",
        "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "VK_OEM_4", "VK_OEM_5", "VK_OEM_6", "VK_OEM_7", "VK_OEM_8",
        "-", "-", "VK_OEM_102", "-", "-", "VK_PROCESSKEY", "-", "VK_PACKET", "-", "-", "-", "-", "-", "-", "-", "-",
        "-", "-", "-", "-", "-", "-", "VK_ATTN", "VK_CRSEL", "VK_EXSEL", "VK_EREOF", "VK_PLAY", "VK_ZOOM", "VK_NONAME", "VK_PA1", "VK_OEM_CLEAR"
    };

    void set(int a) {
        value = value_table[a];
        key = key_table[a];
        constant = constant_table[a];
    }

    std::string value{ "None" };
    std::string key{ "None" };
    std::string constant{ "None" };
} keys;

int main() {
    while (true) {
        Sleep(50);
        if (block) {
            std::cout << "Value: " + keys.value << std::endl;
            std::cout << "Key: " + keys.key << std::endl;
            std::cout << "Constant: " + keys.constant << std::endl;
            block = false;
        }
        if (!block) {
            for (int i : keys.keys) {
                if (GetAsyncKeyState(i)) {
                    keys.set(i);
                    system("cls");
                    block = true;
                }
            }
        }
    }
}