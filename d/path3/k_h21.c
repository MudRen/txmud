// Room: /d/path3/k_h21.c

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
  "southeast" : __DIR__"k_h22",
  "northwest" : __DIR__"k_h20",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
