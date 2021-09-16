// Room: /d/shaolin/w_pei.c

inherit ROOM;

void create()
{
	set("short", "左配殿");
	set("long", @LONG
这里是少林寺的左配殿，是来膜拜的人最多的一个大殿，因
为这里供奉的正是西方极乐世界的阿弥陀佛，只见他面带慈祥的
微笑，手上结着光明印，在他身边站着观世音菩萨和大势至菩萨
二胁侍。下面香客，进香的进香，嗑头的嗑头，颂经的颂经，好
不热闹。从这里向东是大雄宝殿。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"baodian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
