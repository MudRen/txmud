// Room: /u/w/wangs/b/kai156.c

inherit ROOM;

void create()
{
	set("short", "ǰ�ɽ�");
	set("long", @LONG
�����ǿ���ǵ�סլ����һ����ʯ���̳ɵĽַ������߿ɼ�
һЩ���סլ����ͷ�д�������Ʈ��������ζ����Զ��������
�һ������׵����������д��˼�ե���͵Ĵ���ζ��·�������
С���������ֳ�����ˣ�š�������Զ���ǿ��ⶫ���ˡ�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai157",
  "north" : __DIR__"kai147",
  "east" : __DIR__"kai180",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
