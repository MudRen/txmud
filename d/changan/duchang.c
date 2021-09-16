// /d/changan/duchang.c

inherit DUCHANG;

void create()
{
        set("short", "长安赌坊");
        set("long", @LONG
这里就是全国闻名的长安赌坊。里面此起彼伏的叫喊声，银
子、元宝叮叮当当的碰撞声使你也不禁血液沸腾起来，真想也赌
(bet)他几把试试运气。门边的牌子(paizi)写着这里的赌规。
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
                "west" : __DIR__"duchang1",
]));
	set("objects",([
	__DIR__"npc/judge" : 1,
]));
        set(SAFE_ENV,1);
        setup();
}
