// Room: /u/w/wangs/b/kai80.c

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
�������������������Ľ֣�����Զ�����ǿ��⸮�ı�־����
������ͭ�����ˣ�������һ�����Ĵ�������ǿ��⸮�ı��֡�
·�����Ǹ�С��ݣ�����ͷ��������ֻ��˵������˵�ÿ�ĭ��ɣ�
�����ݱ��̨�µ����ڱ�Ҳü��ɫ�裬������ա������Ǹ�Ǯׯ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai83",
  "south" : __DIR__"kai77",
  "west" : __DIR__"kai81",
  "east" : __DIR__"kai82",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
