// Room: /d/fengtian/du.c

inherit DUCHANG;

void create()
{
	set("short", "赌场");
	set("long", @LONG
塞北有名的银钩睹坊，当然这里当家的和龙门客栈的老板交
情很深，想来赌的话这里是个好去处，你看门口的人进进出出，
屋里的人更是昏天黑地，好赌的人来到这里就一定有温暖的感觉。
门边挂着一块木牌(pai)写着这里的赌规。
LONG
);

	set("item_desc", ([
                "paizi" : "
本赌场目前开放押(bet)「大小」,规则如下:
三粒骰子点数总和：
       四   至 十   为「小」(small)，
       十一 至 十八 为「大」(big)，
您也可以押全色 (all) 即三粒骰子点数相同。
如您押的结果和骰子摇出的结果相同，赌一赔一。
如您押全色押中了则一赔八，押100两赢800两！\n
本赌场只接受银子为赌注,多少不限。\n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ll1",
]));

	set("objects",([
	__DIR__"npc/judge" : 1,
]));

	setup();
}
