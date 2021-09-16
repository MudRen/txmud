// Room: /wiz/louth/c/mianguan.c

inherit ROOM;

void create()
{
	set("short", "面馆");
	set("long", @LONG
这里是成都的一家面馆，虽然门面不大，但是服务却非常周
到。面馆中央摆了一张很大的八仙桌，周围一圈做满了人，游人
们互相谈笑风声，有时候还会大声的笑起来。从这里向南走就是
锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jguanlu7",
]));
        set("objects",([
        __DIR__"npc/liboss" : 1,
]));


	setup();
	replace_program(ROOM);
}
