// Room: /d/hangzhou/cross1.c

inherit ROOM;

void create()
{
	set("short", "·��");
	set("long", @LONG
�����񰲽ֺ͹�̩�ֵĽ���ڣ�������������һ��С·����
���������ڶ����յ̡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "hangzhou");
	set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"rockroad1",
  "west" : __DIR__"guotaiw1",
  "east" : __DIR__"guotaie1",
  "north" : __DIR__"minan05",
  //"southeast" : __DIR__"yongning01",
]));

	setup();
	replace_program(ROOM);
}
