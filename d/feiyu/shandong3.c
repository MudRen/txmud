// Room: /wiz/louth/a/shandong3.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�����ǿ�����Ĵ�ɽ�������ܵ�ʯ�����ʮ��ƽ��������
���ż�ֻ��ȼ�Ļ�ѣ���������ϸϸ��ɳ�ӣ�����ȥ�������ʡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shandong4",
  "south" : __DIR__"shandong2",
  "north" : __DIR__"shandong5",
]));
	setup();
	replace_program(ROOM);
}
