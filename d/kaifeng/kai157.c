// Room: /u/w/wangs/b/kai157.c

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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai158",
  "north" : __DIR__"kai156",
  "west" : __DIR__"kai181",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
