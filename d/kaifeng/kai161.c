// Room: /u/w/wangs/b/kai161.c

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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai160",
  "southwest" : __DIR__"kai162",
]));

	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
