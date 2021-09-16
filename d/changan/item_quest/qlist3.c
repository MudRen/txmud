// qlist3.c : quest list 3
#include <ansi.h>

mapping *quest_list = ({
        ([      "name":                 HIW"œ‚¥‰÷Èª®"NOR,
                "id":                   "zhu hua",
                "type":                 "’“",
                "reward":               1000,
        ]),
        ([      "name":                 "Ú˛≈€",
                "id":                   "mang pao",
                "type":                 "’“",
                "reward":               1000,
        ]),
        ([      "name":                 "∫Ï∂–≥§»π",
                "id":                   "long skirt",
                "type":                 "’“",
                "reward":               800,
        ]),
        ([      "name":                 HIW"◊Í ØΩ‰÷∏"NOR,
                "id":                   "diamond ring",
                "type":                 "’“",
                "reward":               900,
        ]),
        ([      "name":                 "Õ≠‘ø≥◊",
                "id":                   "tong key",
                "type":                 "’“",
                "reward":               800,
        ]),
        ([      "name":                 HIW"Á≥”ÍΩ£"NOR,
                "id":                   "feiyu sword",
                "type":                 "’“",
                "reward":               800,
        ]),
        ([      "name":                 "«‡≤º…Æ≈€",
                "id":                   "seng pao",
                "type":                 "’“",
                "reward":               800,
        ]),
        ([      "name":                 "»≠∑®Õº∆◊",
                "id":                   "quanfa tupu",
                "type":                 "’“",
                "reward":               1000,
        ]),
        ([      "name":                 "“∞æ’ª®",
                "id":                   "mum",
                "type":                 "’“",
                "reward":               1000,
        ]),
        ([      "name":                 "œ∏ª®»π",
                "id":                   "skirt",
                "type":                 "’“",
                "reward":               800,
        ]),
        ([      "name":                 "Ã˙∏´",
                "id":                   "lumber axe",
                "type":                 "’“",
                "reward":               1000,
        ]),
        ([      "name":                 "◊œ¡È÷•",
                "id":                   "zi lingzhi",
                "type":                 "’“",
                "reward":               1000,
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

