// Room: /wiz/louth/a/shandong1.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
�����ǿ�����Ĵ�ɽ�������ܵ�ʯ�����ʮ��ƽ��������
���ż�ֻ��ȼ�Ļ�ѣ���������ϸϸ��ɳ�ӣ�����ȥ�������ʡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"caodi1",
  "north" : __DIR__"shandong2",
]));
	setup();
	replace_program(ROOM);
}
