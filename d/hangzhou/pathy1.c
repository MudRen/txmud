// Room: /d/hangzhou/pathy1.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ����·С����������·�����������Զ���㵽������
���ϣ�����������ȥ����������������һ�����࣬����ֻС����
�����ĵ�����������˼��ɾ���
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yongnings1",
  "east" : __DIR__"pathy2",
]));

	setup();
	replace_program(ROOM);
}
