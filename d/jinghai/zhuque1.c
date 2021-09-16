// Room: /d/jinghai/zhuque1.c

inherit ROOM;

void create()
{
	set("short", "碎石子路");
	set("long", @LONG
来到这里。发现脚下的石子路似乎才铺不久，碎石的尖锋垫
得你脚底生痛，路两边栽了一排排的杨树，你真想坐下来好好的
歇歇，可是一想到自已还有那么多事情没办就只有在肚里叹气的
份了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhuque5",
  "south" : __DIR__"zhuque4",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
