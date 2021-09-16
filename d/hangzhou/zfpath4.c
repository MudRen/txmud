// Room: /d/hangzhou/zfpath4.c

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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zfchaifang",
  "south" : __DIR__"zfgarden",
  "east" : __DIR__"zfpath6",
  "north" : __DIR__"zfpath5",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
