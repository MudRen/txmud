// Room: /d/path2/hou_t4.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ����Ţ��С��·��·����һ��Сˮ���������ˮ����
�������ţ���Զ�����ǳ�Ƭ�ĸ����ء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hou_t3",
  "south" : __DIR__"hou_t5",
]));
        set("objects", ([
        NPC_DIR"stdnpc/stdnpc_4" : 5,
]));

	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
