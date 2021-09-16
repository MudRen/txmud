// Room: chengxf2.c

inherit ROOM;

void create()
{
        set("short", "曲径");
	set("long", @LONG
这里是长安丞相府的曲径，你正走在架在小水池上的曲径长
廊上，小水池里满是荷花，扑面而来的正是阵阵的荷香，你甚至
开始怀疑自己是不是在南方。四下静悄悄地，偶而两声蛙鸣，使
这里感觉很是安逸。
LONG
	);

        set("exits", ([
  "south" : __DIR__"chengxf3",
  "west" : __DIR__"chengxf1",
]));
        set("outdoors","chengxf");
        setup();

	replace_program(ROOM);
}