// Room: /d/hangzhou/linpath5.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
��������һ�������ʯ��·�ϣ�·��Ȼ���ܿ�����ɨ�ĺ�
�Ǹɾ�����������������Ա����Է��ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"linbedroom",
  "north" : __DIR__"linpath4",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
