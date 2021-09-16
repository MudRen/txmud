// Room: /d/hangzhou/betroom.c

inherit DUCHANG;

void create()
{
	set("short", "赌场");
	set("long", @LONG
你正处身于杭州城最大的赌场中，看到眼前这热闹的场面，
你深切的感受到了“人为财死”这四个字。无论父子夫妻，朋友
兄弟，到了赌桌上就只剩下了输赢二字。门边的牌子(paizi)写
着这里的赌规。
LONG
	);

        set("item_desc", ([
                "paizi" : 
"\n本赌场目前开放押(bet)「大小」,规则如下:\n"
"三粒骰子点数总和：\n"
"       四   至 十   为「小」(small)，\n"
"       十一 至 十八 为「大」(big)，\n"
"您也可以押全色 (all) 即三粒骰子点数相同。\n"
"如您押的结果和骰子摇出的结果相同，赌一赔一。\n"
"如您押全色押中了则一赔八，押100两赢800两！\n\n"
"本赌场只接受银子为赌注,多少不限。\n",
        ]));
        set("exits", ([
                "north" : __DIR__"nroad5",
]));

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"minan04",
]));

	set("objects",([
	__DIR__"npc/judge" : 1,
]));
	setup();

}
