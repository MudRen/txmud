// Room: /d/jinghai/moon20.c

inherit ROOM;

void create()
{
	set("short", "寝室");
	set("long", @LONG
这里是明月水寨的寨主的寝室，帐内摆放着几张大木板床，
墙上挂着一张黑黝黝的硬弓，不知道是什么质料做成的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"moon9",
]));

	set(SAFE_ENV,1);
        set("sleep_room", 1);
	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
