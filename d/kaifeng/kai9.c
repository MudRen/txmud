// Room: /u/w/wangs/b/kai9.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·ͨ�򿪷���ڵ�һЩ���о��㣬���·����ȫ������
�������Ĵ�����·��żȻ�ܿ���������������ο�������·�ߵ�
����ָָ��㡣����������µĿ����������������ӵĳ���������
�����ʱΪ֮һ������������һ��СС��ʯ���ź�������к�
�ϣ��㲻�����������ϣ������غӷ���ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai16",
  "south" : __DIR__"kai4",
  "east" : __DIR__"kai11",
]));

	set("outdoors","kaifeng");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
	replace_program(ROOM);
}
