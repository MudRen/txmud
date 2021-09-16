// Room: /u/w/wangs/b/kai132.c

inherit ROOM;

void create()
{
	set("short", "茶馆");
	set("long", @LONG
这个茶馆是开封城的闲人杂聚的场所，各地的名茶在这里都
可以品尝到，冲茶的方法也是全城最讲究的。茶馆里整齐的摆了
一些桌椅，茶客们一边品茶，一边绘声绘色交头接耳的议论，人
声鼎沸。这里的经常流传一些鲜为人知的小道消息，许多江湖人
士都爱来这儿打探。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai131",
]));
        set("objects",([
        __DIR__"npc/cboss": 1,
]));

	setup();
	replace_program(ROOM);
}
