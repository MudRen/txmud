// Room: /u/w/wangs/b/kai53.c

inherit ROOM;

void create()
{
	set("short", "��ͬ�ս�");
	set("long", @LONG
���ĳ�ǽ��������Ȼ����һ���䣬��������ַ��˿�����
����ȥ�������֣�������ɽ�Ͻ֣�����������������桢�ֻ�
��С�̷��������е�������ֹ��ϵ�Ǯ�һ�Ҿ�ʲô�ģ��е���
����һЩ��ٲ��ֵġ������������漣����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"kai50",
  "east" : __DIR__"kai54",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
