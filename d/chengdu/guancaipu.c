// Room: /wiz/louth/c/guancaipu.c

inherit ROOM;

void create()
{
	set("short", "棺材铺");
	set("long", @LONG
这里是成都的棺材铺。里面摆了很多空的棺材，棺材铺的老
板满脸横肉，似乎在等着新的生意上门。往北离开就是锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jguanlu3",
]));
        set("objects",([
        __DIR__"npc/wuboss" : 1,
]));


	setup();
	replace_program(ROOM);
}
