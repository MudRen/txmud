// Room: /d/path2/hetao2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ǻƺӵĺ��״���ǧ����������ӿ�ĺ�ˮЯ���Ź�����
��ɳ������������δ�������ƽԭ��󺣱��ڶ�ȥ����վ�ڰ���
��Զ������������һ�ɺ��顣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_t19",
  "east"  : __DIR__"hetao3",
  "west"  : __DIR__"hetao1",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
