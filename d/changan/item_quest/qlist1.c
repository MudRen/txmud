// qlist1.c : quest list 1
#include <ansi.h>
#include <weapon.h>

mapping *quest_list = ({
        ([      "name":                 "¥…ÕÎ",
                "id":                   "ci wan",
                "type":                 "’“",
                "reward":               200,
        ]),
        ([      "name":                 "øæº¶Õ»",
                "id":                   "ji tui",
                "type":                 "’“",
                "reward":               200,
        ]),
        ([      "name":                 "∫Ï…’ ®◊”Õ∑",
                "id":                   "shizi tou",
                "type":                 "’“",
                "reward":               300,
        ]),
        ([      "name":                 "Õ≠∂§ª§ÕÛ",
                "id":                   "wrists",
                "type":                 "’“",
                "reward":               400,
        ]),
        ([      "name":                 "“¯∂§ª§ÕÛ",
                "id":                   "hu wan",
                "type":                 "’“",
                "reward":               380,
        ]),
        ([      "name":                 "»Ì∏÷Àø ÷Ã◊",
                "id":                   "steel armguard",
                "type":                 "’“",
                "reward":               380,
        ]),
        ([      "name":                 "°∂µ˜Œ¸¥Û∑®°∑",
                "id":                   "force book",
                "type":                 "’“",
                "reward":               280,
        ]),
        ([      "name":                 " Æ◊÷∏‰",
                "id":                   "shi zi gao",
                "type":                 "’“",
                "reward":               240,
        ]),
        ([      "name":                 "ª∞—",
                "id":                   "torch",
                "type":                 "’“",
                "reward":               220,
        ]),
        ([      "name":                 "°∂»≠∑®»Î√≈°∑",
                "id":                   "unarmed book",
                "type":                 "’“",
                "reward":               220,
        ]),
        ([      "name":                 "∏ﬂœ„",
                "id":                   "xiang",
                "type":                 "’“",
                "reward":               300,
        ]),
        ([      "name":                 "∑¢ƒËµƒ“©√Á",
                "id":                   "yao miao",
                "type":                 "’“",
                "reward":               200,
        ]),
});

mapping query()
{
        return quest_list[random(sizeof(quest_list))];
}

void create()
{
        seteuid(getuid());
}


