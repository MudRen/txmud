// Room: /wiz/louth/a/shidao9.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ɽ��С·��·�߳�������ݣ��Լ����������������
������һ��С·��С·�ľ�ͷ��һ��С��԰��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hyuan1",
  "out" : __DIR__"shidao3",
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
