// Room: /d/shaolin/w_court.c

inherit ROOM;

void create()
{
	set("short", "西跨院");
	set("long", @LONG
这里是少林寺的西跨院，因为离斋堂很近，所以感觉这里的
僧人都很忙碌，北面来来往往的挑水的，搬菜的，架火的，但却
丝毫不觉得混乱，大家似乎都知道自己在做什么，该做什么，这
也许就是天下名刹少林寺所特有的吧。从这里向西是柴房，向东
是过道，北面是斋堂，南面有一片绿油油的菜地。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhaitang",
  "south" : __DIR__"caidi",
  "east" : __DIR__"lroad3",
  "west" : __DIR__"chaifang",
]));
	set("valid_startroom", 1);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
