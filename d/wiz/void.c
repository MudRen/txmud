// Room: /obj/void.c

inherit ROOM;

void create()
{
	set("short", "虚幻");
	set("long", @LONG
混沌的雾气在你周围翻滚，你只觉得脚下发飘，头脑里浑浑
噩噩，不知身在何处。
LONG
	);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
