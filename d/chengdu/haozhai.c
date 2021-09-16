// Room: /wiz/louth/c/haozhai.c

inherit ROOM;

void create()
{
	set("short", "王家大宅");
	set("long", @LONG
这里是蜀中有名的大地主王千顷的宅院，据说王家的地上千
顷，佃户上万，所以都叫他王千顷，本名反倒没什么人知道了。
宅子里雕梁画栋，美仑美奂，据说还是请的当年一个建造皇宫的
工匠设计的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wmlu8",
]));
        set("objects",([
        __DIR__"npc/dizhu_wang" : 1,
]));

	setup();
	replace_program(ROOM);
}
