// Room: /u/w/wangs/b/kai160.c

inherit ROOM;

void create()
{
	set("short", "���ɽ�");
	set("long", @LONG
�����ǿ���ǵ�סլ����һ����ʯ���̳ɵĽַ������߿ɼ�
һЩ���סլ����ͷ�д�������Ʈ��������ζ����Զ��������
�һ������׵����������д��˼�ե���͵Ĵ���ζ��·�������
С���������ֳ�����ˣ�š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai161",
  "north" : __DIR__"kai159",
  "east" : __DIR__"kai183",
]));
        set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
