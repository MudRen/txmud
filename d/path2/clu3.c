// Room: /d/path2/clu3.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������һƬ������ʯ���Ӳݵأ��������ÿ����ϵĿ�֦��ż
������������ѻ���Ϲϡ��Ľ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"da_hou9",
  "east" : __DIR__"clu2",
]));

	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
