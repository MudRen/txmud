// Room: /d/tangmen/fyuan.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
������ǰԺ��С�㳡������ש�̾͵ĵ���ǳ����࣬������
�Ĵ�ʯ�������Ÿ߸ߵ���ˣ����������������ý������Ŷ���
�ġ��ơ��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gd3",
  "south" : __DIR__"gd2",
  "east" : __DIR__"yanwu",
  "west" : __DIR__"keting",
]));

	set("valid_startroom", 1);
	set(SAFE_ENV, 1);
	set("outdoors", "tangmen");
	setup();

	load_board("board_tangmen");
}
