// Room: /wiz/louth/a/shandong2.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�����ǿ�����Ĵ�ɽ�������ܵ�ʯ�����ʮ��ƽ��������
���ż�ֻ��ȼ�Ļ�ѣ���������ϸϸ��ɳ�ӣ�����ȥ�������ʡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shandong1",
  "north" : __DIR__"shandong3",
]));
	replace_program(ROOM);
}
