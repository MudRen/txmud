// Room: /d/hangzhou/zfpath2.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����ͨ�����ε�С·��ƽ�������ͷ��������ۣ��������˾�
�����
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zfpath1",
  "east" : __DIR__"zfjianlao",
]));

	setup();
	replace_program(ROOM);
}
