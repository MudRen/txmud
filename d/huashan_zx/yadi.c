// Room: /d/huashan_zx/yadi.c

inherit ROOM;

void create()
{
	set("short", "悬崖底");
	set("long", @LONG
这里是悬崖的底部，乱草丛中遍布奇形怪状的石头。
LONG
	);

	set("outdoors","huashan_zx");

	setup();
	replace_program(ROOM);
}
