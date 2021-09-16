// Room: /d/shaolin/tianwangdian.c

inherit ROOM;

void create()
{
	set("short", "天王殿");
	set("long", @LONG
这里是少林寺的天王殿，正中供奉着天界之王的法像，两边
的墙壁上画着六道轮回的样子，不少善男信女在这里虔诚的膜拜
着，都希望往生在神圣的极乐净土。从这里向绕过圣像向北是中
院广场，向南是台阶通往前院广场。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taijie",
  "north" : __DIR__"m_square",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
