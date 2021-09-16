// Room: /d/huanggong/zhaig.c

inherit ROOM;

void create()
{
	set("short", "斋宫");
	set("long", @LONG
这里是皇上每年祭奠先祖、及出兵打仗前，为祈求上天保佑
，而吃斋念佛的地方东面巨大的法台，供奉着佛祖释迦摩尼的法
像。纯金铸成的香炉，冒着袅袅的清烟，沁人心脾。两枚红烛宛
如婴儿的手臂，把整个大殿照的灯火通明。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huangjd",
  "north" : __DIR__"xigdm",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}