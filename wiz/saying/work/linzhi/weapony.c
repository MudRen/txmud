//weapony.c  林芝村的武器店
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "猎具店");
        set("long", @LONG
这是林芝村里的猎具店，因为接近原始森林，许多住户既做
农活也做猎人，而且传说森林中有凶狠的猛兽吃人，所以大家都
会来这里买一些器械。因为这些原因，这家猎具店的生意非常的
好。这里的物品都很适合在附近的环境中使用，你可以考虑买一
点来自己用。门口有一个牌子（Sign）。
LONG
        );
        set("exits", ([
        "west":__DIR__"lz_sroad1",
]));
        set("objects", ([
        __DIR__"npc/w_boss" : 1,
]));
        set("item_desc", ([
        "sign": (:look_sign:),
]));
        setup();
}
string look_sign(object me)
{
        return "招牌写著：欲先成其事 必先利其器
          本店专卖各式兵器，请随时光顾。\n";
}
