// Room: /u/w/wangs/b/kai158.c

inherit ROOM;

void create()
{
	set("short", "ǰ�ɽ�");
	set("long", @LONG
�����ǿ���ǵ�סլ����һ����ʯ���̳ɵĽַ������߿ɼ�
һЩ���סլ����ͷ�д�������Ʈ��������ζ����Զ��������
�һ������׵����������д��˼�ե���͵Ĵ���ζ��·�������
С���������ֳ�����ˣ�š�����
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai159",
  "north" : __DIR__"kai157",
  "east" : __DIR__"business",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
