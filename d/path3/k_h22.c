// Room: /d/path3/k_h22.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
���ߵ����ֻ����������дУ��������¡����̲�ס���
�ĺ�������Ȼ����Ϣ������һ���ӷ����˺ܶࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h23",
  "northwest" : __DIR__"k_h21",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
