// duchang.c

inherit DUCHANG;

void create()
{
	set("short","星月赌馆");
	set("long", @LONG
这里就是成都最大的赌场星月赌馆。里面此起彼伏的叫喊声，
银子、元宝叮叮当当的碰撞声使你也不禁血液沸腾起来，真想也
赌(bet)他几把试试运气。门边的牌子(paizi)写着这里的赌规。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fdjie5",
]));
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

        set("objects",([
        __DIR__"npc/baoguan" : 1,
]));
        set("no_fight", 1);

	setup();
}
