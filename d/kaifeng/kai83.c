// Room: /u/w/wangs/b/kai83.c

inherit ROOM;

void create()
{
	set("short", "���ⱱ��");
	set("long", @LONG
���ⱱ����һ������ϱ��Ĵ������Ϊ���������ž�ʡͨ��
��������Խ���ø��������·�ϳ�ˮ��������ҹ������������
�ͻ���ĳ��Ӵ�����ԴԴ���ϵķ�ɢ�����ҵ��̣��ִ��ſ����
����ӳ��и�����۵�������·�ϳ��Ƕ�ȥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai86",
  "south" : __DIR__"kai80",
  "west" : __DIR__"kai84",
  "east" : __DIR__"kai85",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
