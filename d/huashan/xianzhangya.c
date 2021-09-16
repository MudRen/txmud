// Room: /d/huashan/xianzhangya.c

inherit ROOM;

void create()
{
	set("short", "仙掌崖");
	set("long", @LONG
一道山崖像一只大手侧立在你的身旁。这里就是仙掌崖。想
去天台峰的话，你还要继续努力了。崖下草地上长着几楮野山茶
花，看起来像是不错的品种。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"wushangdong",
  "southdown" : __DIR__"xiaolu6",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
