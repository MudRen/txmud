// Room: /u/w/wangs/b/kai128.c

inherit ROOM;

void create()
{
	set("short", "水果店");
	set("long", @LONG
这家水果店面积不算太大，卖的水果却是应有尽有。店里整
齐的放着一些竹筐，里面装满了各色水果。这儿的水果为了保持
新鲜，每天都由各地果园及时的送来，很受顾客欢迎。不时的有
客人光顾水果店，买下一些水果。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai127",
]));

        set("objects",([
        __DIR__"npc/sgboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
