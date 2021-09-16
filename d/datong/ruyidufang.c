// Room: /open/dt/ruyidufang.c

inherit DUCHANG;

void create()
{
	set("short", "如意赌坊");
	set("long", @LONG
如意赌坊是方圆数百里最大的赌场，所以有很多外地人也慕
名而来。赌场内十二个时辰都有人赌钱，从不歇业。场内人头涌
动，沸沸扬扬，几十名侍女身着艳装，像穿花蝴蝶一般在场内翩
然来去，不时向街赌徒们抛着媚眼，你不觉也想试试运气。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"youfujie2",
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
        __DIR__"npc/judge" : 1,
]));
        set(SAFE_ENV,1);

	setup();
}
