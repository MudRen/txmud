// Room: /d/hangzhou/linbedroom.c

inherit ROOM;

void create()
{
	set("short", "Ա���Է�");
	set("long", @LONG
��������Ա����Է����ּ���Ȼ�Ǻ��Ŵ󻧣�����Ա�����
��ȴ���Ǽ��ӣ���ǽ����һ�Ŵ󴲣�������һ��̴ľ���ӣ�
���滹����һ�Ѵ�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"linpath5",
]));

	setup();
	replace_program(ROOM);
}
