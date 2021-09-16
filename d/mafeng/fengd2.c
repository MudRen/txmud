// Room: /d/path3/fengd2.c

inherit ROOM;

void create()
{
	set("short", "半山树林");
	set("long",  @LONG
这里是一小片浓密的树林，参天的古树这天蔽日，地上是齐
脚深的枯枝败叶，山风吹过四处沙沙乱想，说不出的阴森恐怖。
LONG
);
	set("exits", ([
  "west" : __DIR__"fengd3",
  "east" : __DIR__"fengd1",
  "north" : __DIR__"fengd5",
]));

	set("outdoors", "mafeng");
	setup();
}