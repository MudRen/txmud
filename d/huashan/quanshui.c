// Room: /d/huashan/quanshui.c

inherit ROOM;

void create()
{
	set("short", "Ȫˮ");
	set("long", @LONG
·�ߵ�ʯ���������峺��Ȫˮ�����һ��СϪ������ɽ����
ȥ���������ˣ������������(drink)Щˮ�ȡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaolu5",
  "east" : __DIR__"shanquan",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
