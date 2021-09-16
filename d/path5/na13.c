// Room: /d/path5/na13.c

inherit ROOM;

void create()
{
	set("short", "破旧窑洞");
	set("long", @LONG
这个破旧窑洞就是渔夫李老汉的家，里面十分简陋，除了必
须的生活用品和些渔具什么都没有。李老汉靠打渔挣得那点钱，
基本上都用在了久病不治的女儿红霞身上，治好女儿的是他最
大的心愿了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"na12",
  "east" : __DIR__"na14",
]));
	setup();
	replace_program(ROOM);
}
