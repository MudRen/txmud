// Room: /d/hangzhou/zfpath5.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������ͨ���������õ�С·������ʯ�̳ɵ�С·�ǳ���ƽ��
·������ֲ�Ÿ����滨��ݣ����ҡ�ڣ���С·�򱱾���������
��������һ��СС�Ļ�԰��
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zfpath4",
  "west" : __DIR__"zfshiye",
  "north" : __DIR__"zfroom",
]));

	setup();
	replace_program(ROOM);
}
