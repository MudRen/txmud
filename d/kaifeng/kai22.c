// Room: /u/w/wangs/b/kai22.c

inherit ROOM;

void create()
{
	set("short", "小茶馆");
	set("long", @LONG
这是一家很老的茶馆，以前开封还不是城的时候它就在这个
地方了。这里的桌椅板凳俱都用竹子制成，由于年代久远，全都
散发着一抹淡黄的油光，使这里更加的古色古香。开封人爱饮茶，
每天午后傍晚，这里便座无虚席，大家或饮茶聊天，或听说书先
生纵论古今，其乐也融融。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai21",
]));
        set("objects",([
        __DIR__"npc/tuobei" : 1,
]));

	setup();
	replace_program(ROOM);
}
